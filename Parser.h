#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <string>
#include "Lexer.h"
#include <stdexcept>
#include "Lexer.h"

class Parser {
public:
    enum class NodeType {
        FUNCTION_DECLARATION,
        VARIABLE_DECLARATION,
        STRUCT_DECLARATION,
        IF_STATEMENT,
        ELSIF_STATEMENT,
        ELS_STATEMENT,
        FOR_LOOP,
        FOREACH_LOOP,
        WHILE_LOOP,
        LOOP_STATEMENT,
        FUNCTION_CALL,
        PRINT_STATEMENT,
        NUMBER_LITERAL,
        STRING_LITERAL,
        CHAR_LITERAL,
        BOOL_LITERAL,
        POINTER_DECLARATION,
        ADDRESS_OF,
        DEREFERENCE,
        EXPRESSION,
        STATEMENT,
        INPUT_STATEMENT,
        BLOCK
    };

    struct ASTNode {
        NodeType node_type;
        std::string value;
        std::vector<ASTNode> children;
        std::vector<ASTNode> parameters;
        ASTNode* condition = nullptr;
        ASTNode* then_block = nullptr;
        ASTNode* else_block = nullptr;
        std::string name;
        ASTNode* body = nullptr;
    };

    std::vector<ASTNode> parse(std::vector<Token>& tokens);
    ASTNode statement();
    ASTNode expression();
    ASTNode if_statement();
    ASTNode for_loop();
    ASTNode while_loop();
    ASTNode function_declaration();
    ASTNode print_statement();
    ASTNode input_statement();

private:
    std::vector<Token> tokens;
    int current_token_index;

    Token expect(TokenType type) {
        Token current = peek_next_token();
        if (current.type != type) {
            throw std::runtime_error("Unexpected token type");
        }
        current_token_index++;
        return current;
    }

    Token peek_next_token();
    void consume_token(TokenType expected_type);
    ASTNode* parse_function_declaration();
    ASTNode* parse_if_statement();
    ASTNode* parse_expression();
    ASTNode* parse_statement();
    ASTNode* parse_block();
    ASTNode parse_parameter();

    Token current_token() {
        return tokens[current_token_index];
    }
};

#endif // PARSER_H
