#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include "Lexer.h"
#include "Parser.h"
#include "Semantic.h"
#include "IRGenerator.h"
#include "Optimizer.h"
#include "RuntimeEnvi.h"
#include "MemoryManager.h"
#include "StringModule.h"
#include "Debugging.h"
#include "CodeEmitter.h"
#include "Performance.h"
#include "Compiler.h"
#include "fnpi_compiler.h"

using namespace std;


Compiler compiler;
void Compiler::compile(const string& input_file) {
    ifstream file(input_file);
    if (!file.is_open()) {
        cerr << "Unable to open file";
        return;
    }

    string source_code((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();

  //  lex(source_code);
    parse(tokens);
    semantic_analysis();
    generate_ir();
    optimize();
    execute();
    debug();
    emit_code();
    profile_performance();
}



Lexer::Lexer(const string& source_code) : source_code(source_code) {
    keywords = {
        {"if", TokenType::KEYWORD_IF},
        {"elsif", TokenType::KEYWORD_ELSIF},
        {"else", TokenType::KEYWORD_ELS},
        {"for", TokenType::KEYWORD_FOR},
        {"foreach", TokenType::KEYWORD_FOREACH},
        {"while", TokenType::KEYWORD_WHILE},
        {"func", TokenType::KEYWORD_FUNC},
        {"return", TokenType::KEYWORD_RETURN},
        {"let", TokenType::KEYWORD_LET},
        {"const", TokenType::KEYWORD_CONST},
        {"print", TokenType::IDENTIFIER},
        {"nl", TokenType::IDENTIFIER}
    };
}

vector<Token> Lexer::tokenize() {
    vector<Token> tokens;
    int current_char_index = 0;
    int current_line = 1;
    int current_column = 1;

    while (current_char_index < source_code.size()) {
        skip_whitespace_and_comments();

        if (is_digit(peek_next_char())) {
            handle_number_literal(tokens);
        } else if (is_letter(peek_next_char())) {
            handle_identifier_or_keyword(tokens);
        } else if (is_symbol(peek_next_char())) {
            handle_symbol(tokens);
        } else if (peek_next_char() == '"') {
            handle_string_literal(tokens);
        } else {
            cerr << "Unexpected character at line " << current_line << ", column " << current_column << endl;
            exit(1);
        }
    }

    tokens.push_back(create_token(TokenType::EOF_TOKEN, ""));
    return tokens;
}

// Diğer metodları implemente edin...


void Lexer::skip_whitespace_and_comments() {
    while (is_whitespace(peek_next_char()) || peek_next_char() == '#') {
        if (peek_next_char() == '#') {
            // Yorumu atla
            while (peek_next_char() != '\n' && peek_next_char() != '\0') {
                current_char_index++;
                current_column++;
            }
        } else {
            current_char_index++;
            current_column++;
        }
    }
}

char Lexer::peek_next_char(int index) {
    if (current_char_index + index >= source_code.size()) {
        return '\0';
    }
    return source_code[current_char_index + index];
}

bool Lexer::is_whitespace(char c) {
    return c == ' ' || c == '\t' || c == '\r';
}

bool Lexer::is_digit(char c) {
    return c >= '0' && c <= '9';
}

bool Lexer::is_letter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool Lexer::is_symbol(char c) {
    return !is_whitespace(c) && !is_digit(c) && !is_letter(c);
}

Token Lexer::create_token(TokenType type, const std::string& value) {
    return {type, value, current_line, current_column};
}

void Lexer::handle_string_literal(std::vector<Token>& tokens) {
    current_char_index++; // İlk tırnak işareti atla
    current_column++;
    std::string string_literal;
    while (peek_next_char() != '"' && peek_next_char() != '\0') {
        string_literal += peek_next_char();
        current_char_index++;
        current_column++;
    }
    if (peek_next_char() == '"') {
        current_char_index++;
        current_column++;
    }
    tokens.push_back(create_token(TokenType::STRING, string_literal));
}

void Lexer::handle_number_literal(std::vector<Token>& tokens) {
    std::string number_literal;
    while (is_digit(peek_next_char())) {
        number_literal += peek_next_char();
        current_char_index++;
        current_column++;
    }
    tokens.push_back(create_token(TokenType::INTEGER, number_literal));
}

void Lexer::handle_identifier_or_keyword(std::vector<Token>& tokens) {
    std::string identifier;
    while (is_letter(peek_next_char()) || is_digit(peek_next_char())) {
        identifier += peek_next_char();
        current_char_index++;
        current_column++;
    }
    if (keywords.find(identifier) != keywords.end()) {
        tokens.push_back(create_token(keywords[identifier], identifier));
    } else {
        tokens.push_back(create_token(TokenType::IDENTIFIER, identifier));
    }
}

void Lexer::handle_symbol(std::vector<Token>& tokens) {
    char symbol = peek_next_char();
    current_char_index++;
    current_column++;
    switch(symbol) {
        case ':':
            tokens.push_back(create_token(TokenType::SYMBOL_COLON, ":"));
            break;
        case '{':
            tokens.push_back(create_token(TokenType::SYMBOL_BRACE_OPEN, "{"));
            break;
        case '}':
            tokens.push_back(create_token(TokenType::SYMBOL_BRACE_CLOSE, "}"));
            break;
        case ';':
            tokens.push_back(create_token(TokenType::SYMBOL_SEMICOLON, ";"));
            break;
        case ',':
            tokens.push_back(create_token(TokenType::SYMBOL_COMMA, ","));
            break;
        // Diğer sembolleri ekleyin...
        default:
            std::cerr << "Unexpected symbol at line " << current_line << ", column " << current_column << std::endl;
            exit(1);
    }
}


void Compiler::lex(const string& source_code) {
    Lexer lexer(source_code);
    tokens = lexer.tokenize();
	
}



vector<Parser::ASTNode> Parser::parse(vector<Token>& tokens) {
    this->tokens = tokens;
    current_token_index = 0;
    vector<ASTNode> ast_nodes;

    while (current_token_index < tokens.size()) {
        ASTNode* node_ptr = parse_statement();
        ASTNode node = *node_ptr;
        ast_nodes.push_back(node);
        delete node_ptr;
    }

    return ast_nodes;
}

Parser::ASTNode Parser::expression() {
    ASTNode node;
    node.node_type = NodeType::EXPRESSION;

    // İfade analizi yapın
    // Örneğin: a = 5 + 3 * 2;

    return node;
}

Parser::ASTNode Parser::statement() {
    ASTNode node;
    node.node_type = NodeType::STATEMENT;

    Token current_token = peek_next_token();

    if (current_token.type == TokenType::KEYWORD_IF) {
        node = if_statement();
    } else if (current_token.type == TokenType::KEYWORD_FOR) {
        node = for_loop();
    } else if (current_token.type == TokenType::KEYWORD_WHILE) {
        node = while_loop();
    } else if (current_token.type == TokenType::KEYWORD_FUNC) {
        node = function_declaration();
    } else if (current_token.type == TokenType::KEYWORD_PRINT) {
        node = print_statement();
    }else if (current_token.type == TokenType::KEYWORD_INPUT) {
        node = input_statement();
    } else {
        // Diğer bildirim türleri için analizi yapın
    }

    return node;
}

Parser::ASTNode Parser::function_declaration() {
    ASTNode node;
    node.node_type = NodeType::FUNCTION_DECLARATION;

    // Fonksiyon bildirimi analizi yapın
    // Örneğin: func carp: a, b{ return a * b; }

    return node;
}

Parser::ASTNode Parser::if_statement() {
    ASTNode node;
    node.node_type = NodeType::IF_STATEMENT;

    // Koşullu ifade analizi yapın
    // Örneğin: if: condition { ... } els: { ... }

    return node;
}

Parser::ASTNode Parser::for_loop() {
    ASTNode node;
    node.node_type = NodeType::FOR_LOOP;

    // For döngüsü analizi yapın
    // Örneğin: for: i = 0, i < 10, i++ { ... }

    return node;
}

Parser::ASTNode Parser::while_loop() {
    ASTNode node;
    node.node_type = NodeType::WHILE_LOOP;

    // While döngüsü analizi yapın
    // Örneğin: while: condition { ... }

    return node;
}

Parser::ASTNode Parser::print_statement() {
    ASTNode node;
    node.node_type = NodeType::PRINT_STATEMENT;

    // Yazdırma ifadesi analizi yapın
    // Örneğin: print: "Merhaba, dünya!", nl;
    // Merhaba Dünya yazıp nl ile yeni satıra geçer

    return node;
}

Parser::ASTNode Parser::input_statement() {
    ASTNode node;
    node.node_type = NodeType::INPUT_STATEMENT;

    // Yazdırma ifadesi analizi yapın
    // Örneğin: input: txt;  klavyeden girilen değeri txt değişkenine atar

    return node;
}
Token Parser::peek_next_token() {
    if (current_token_index >= tokens.size()) {
        return Token{TokenType::EOF_TOKEN, ""};
    }
    return tokens[current_token_index];
}

void Parser::consume_token(TokenType expected_type) {
    Token current_token = peek_next_token();
    if (current_token.type != expected_type) {
        cerr << "Unexpected token at index " << current_token_index << ". Expected " << static_cast<int>(expected_type) << ", got " << static_cast<int>(current_token.type) << endl;
        exit(1);
    }
    current_token_index++;
}




void Compiler::parse(vector<Token>& tokens) {
    Parser parser;
    ast_nodes = parser.parse(tokens);
}




class SemanticAnalysis {
private:
    struct FunctionInfo {
        vector<string> parameters;
        string return_type;
    };

    unordered_map<string, string> variable_types;
    unordered_map<string, FunctionInfo> function_table;
    FunctionInfo* current_function = nullptr;

    bool is_reserved_keyword(const string& word) {
        static const set<string> keywords = {
            "if", "elsif", "else", "for", "foreach", "while",
            "func", "return", "let", "const", "print", "input", "nl"
        };
        return keywords.find(word) != keywords.end();
    }

    void check_variable_type(Parser::ASTNode& node) {
        if (node.value.empty()) {
            semantic_error("Değişken adı boş olamaz");
        }
    }

    void check_expression_type(Parser::ASTNode& node) {
        if (node.children.size() == 3) {
            check_variable_type(node.children[0]);
            check_expression_type(node.children[1]);
            check_expression_type(node.children[2]);
        } else if (node.children.size() == 1) {
            check_expression_type(node.children[0]);
        }
    }

    void check_statement_type(Parser::ASTNode& node) {
        if (node.children.size() == 2) {
            check_variable_type(node.children[0]);
            check_expression_type(node.children[1]);
        }
    }

    void check_function_declaration_type(Parser::ASTNode& node) {
        if (node.children.size() == 3) {
            check_function_name_type(node.children[0]);
            check_parameter_types(node.children[1]);
            check_function_body_type(node.children[2]);
        }
    }

    void check_if_statement_type(Parser::ASTNode& node) {
        if (node.children.size() >= 2) {
            check_condition_type(node.children[0]);
            check_block_type(node.children[1]);
            if (node.children.size() == 3) {
                check_block_type(node.children[2]);
            }
        }
    }

    void check_for_loop_type(Parser::ASTNode& node) {
        if (node.children.size() != 4) {
            semantic_error("For döngüsü yanlış formatta");
        }
        check_expression_type(node.children[0]);
        check_expression_type(node.children[1]);
        check_expression_type(node.children[2]);
        check_block_type(node.children[3]);
    }

    void check_while_loop_type(Parser::ASTNode& node) {
        if (node.children.size() == 2) {
            check_condition_type(node.children[0]);
            check_block_type(node.children[1]);
        }
    }

    void check_print_statement_type(Parser::ASTNode& node) {
        for (auto& child : node.children) {
            check_expression_type(child);
        }
    }

    void check_function_name_type(Parser::ASTNode& node) {
        if (node.value.empty()) {
            semantic_error("Fonksiyon adı boş olamaz");
        }
        if (is_reserved_keyword(node.value)) {
            semantic_error("Fonksiyon adı anahtar kelime olarak kullanılamaz");
        }
    }

    void check_parameter_types(Parser::ASTNode& node) {
        for (const auto& param : node.children) {
            if (param.value != "let" && param.value != "const") {
                semantic_error("Parametre türü geçersiz");
            }
            if (param.children.size() != 1 || param.children[0].value.empty()) {
                semantic_error("Parametre adı geçersiz");
            }
        }
    }

    void check_function_body_type(Parser::ASTNode& node) {
        for (auto& statement : node.children) {
            check_statement_type(statement);
        }
    }

    void check_condition_type(Parser::ASTNode& node) {
        if (node.children.size() != 1) {
            semantic_error("Koşul yanlış formatta");
        }
        check_expression_type(node.children[0]);
    }

    void check_block_type(Parser::ASTNode& node) {
        for (auto& statement : node.children) {
            check_statement_type(statement);
        }
    }

    void check_expression_context(Parser::ASTNode& node) {
        // İfade bağlamı kontrolü
    }

    void check_statement_context(Parser::ASTNode& node) {
        if (!current_function) {
            semantic_error("İfade fonksiyon dışında kullanılamaz");
        }
    }

    void check_function_declaration_context(Parser::ASTNode& node) {
        // Fonksiyon bildirimi bağlamı kontrolü
    }

    void check_if_statement_context(Parser::ASTNode& node) {
        if (!current_function) {
            semantic_error("If ifadesi fonksiyon dışında kullanılamaz");
        }
    }

    void check_for_loop_context(Parser::ASTNode& node) {
        if (!current_function) {
            semantic_error("For döngüsü fonksiyon dışında kullanılamaz");
        }
    }

    void check_while_loop_context(Parser::ASTNode& node) {
        if (!current_function) {
            semantic_error("While döngüsü fonksiyon dışında kullanılamaz");
        }
    }

    void check_print_statement_context(Parser::ASTNode& node) {
        if (!current_function) {
            semantic_error("Print ifadesi fonksiyon dışında kullanılamaz");
        }
    }

public:
    void semantic_error(const string& message) {
        cerr << "Semantic Error: " << message << endl;
        exit(1);
    }

    void analyze(vector<Parser::ASTNode>& ast_nodes) {
        for (auto& node : ast_nodes) {
            check_types(node);
            check_context(node);
        }
    }

    void check_types(Parser::ASTNode& node) {
        switch (node.node_type) {
            case Parser::NodeType::EXPRESSION:
                check_expression_type(node);
                break;
            case Parser::NodeType::STATEMENT:
                check_statement_type(node);
                break;
            case Parser::NodeType::FUNCTION_DECLARATION:
                check_function_declaration_type(node);
                break;
            case Parser::NodeType::IF_STATEMENT:
                check_if_statement_type(node);
                break;
            case Parser::NodeType::FOR_LOOP:
                check_for_loop_type(node);
                break;
            case Parser::NodeType::WHILE_LOOP:
                check_while_loop_type(node);
                break;
            case Parser::NodeType::PRINT_STATEMENT:
                check_print_statement_type(node);
                break;
        }
    }

    void check_context(Parser::ASTNode& node) {
        switch (node.node_type) {
            case Parser::NodeType::EXPRESSION:
                check_expression_context(node);
                break;
            case Parser::NodeType::STATEMENT:
                check_statement_context(node);
                break;
            case Parser::NodeType::FUNCTION_DECLARATION:
                check_function_declaration_context(node);
                break;
            case Parser::NodeType::IF_STATEMENT:
                check_if_statement_context(node);
                break;
            case Parser::NodeType::FOR_LOOP:
                check_for_loop_context(node);
                break;
            case Parser::NodeType::WHILE_LOOP:
                check_while_loop_context(node);
                break;
            case Parser::NodeType::PRINT_STATEMENT:
                check_print_statement_context(node);
                break;
        }
    }
};

void Compiler::semantic_analysis() {
    semantic_analyzer.analyze(ast_nodes);
}

void Compiler::generate_ir() {
    ir_instructions = ir_generator.generate_ir(ast_nodes);
}

void Compiler::optimize() {
    optimized_instructions = optimizer.optimize(ir_instructions);
}

void Compiler::execute() {
    runtime_environment.initialize();
    runtime_environment.execute(optimized_instructions);
}

void Compiler::debug() {
    debugger.initialize(optimized_instructions);
    debugger.run_debugger();
}

void Compiler::emit_code() {
    string emitted_code = code_emitter.emit_code(optimized_instructions);
    cout << "Emitted code:" << endl << emitted_code << endl;
}

void Compiler::profile_performance() {
    profiler.start_profiling();
    runtime_environment.execute(optimized_instructions);
    profiler.end_profiling();
    profiler.print_profile_results();
}
/*
int main() {
    compiler.compile("example.pi");
    return 0;
}
*/