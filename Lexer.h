#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <vector>
#include <unordered_map>

enum class TokenType {
    // Veri tipleri
    TYPE_I8, TYPE_U8, TYPE_F8,
    TYPE_I16, TYPE_U16, TYPE_F16,
    TYPE_I32, TYPE_U32, TYPE_F32,
    TYPE_I64, TYPE_U64, TYPE_F64,
    TYPE_I128, TYPE_U128, TYPE_F128,
    
    // Anahtar kelimeler
    KEYWORD_CONST,
    KEYWORD_STATIC,
    KEYWORD_LET,
    KEYWORD_IF,
    KEYWORD_ELSIF,
    KEYWORD_ELS,
    KEYWORD_FOR,
    KEYWORD_FOREACH,
    KEYWORD_WHILE,
    KEYWORD_LOOP,
    KEYWORD_MATCH,
    KEYWORD_CONTINUE,
    KEYWORD_BREAK,
    KEYWORD_SWITCH,
    KEYWORD_FUNC,
    KEYWORD_RETURN,
    KEYWORD_STRUCT,
    KEYWORD_IMPORT,
    KEYWORD_PRINT,
    KEYWORD_INPUT,
    KEYWORD_NL,
    
    // Operatörler
    COLON,          // :
    ARROW,          // ->
    POINTER,        // *
    ADDRESS,        // &
    
    // Değerler
    INTEGER,
    FLOAT,
    STRING,
    CHAR,
    BOOL_TRUE,
    BOOL_FALSE,
    
    // Özel tokenlar
    IDENTIFIER,
    EOF_TOKEN,
    
    // Semboller
    SYMBOL_COLON,        // :
    SYMBOL_BRACE_OPEN,   // {
    SYMBOL_BRACE_CLOSE,  // }
    SYMBOL_SEMICOLON,    // ;
    SYMBOL_COMMA,        // ,
};

struct Token {
    TokenType type;
    std::string value;
    int line;
    int column;
};

class Lexer {
public:
    Lexer(const std::string& source_code);
    std::vector<Token> tokenize();

private:
    std::string source_code;
    std::unordered_map<std::string, TokenType> keywords;
    int current_char_index;
    int current_line;
    int current_column;

    void skip_whitespace_and_comments();
    char peek_next_char(int offset = 0);
    bool is_whitespace(char c);
    bool is_digit(char c);
    bool is_letter(char c);
    bool is_symbol(char c);
    Token create_token(TokenType type, const std::string& value);
    void handle_string_literal(std::vector<Token>& tokens);
    void handle_number_literal(std::vector<Token>& tokens);
    void handle_identifier_or_keyword(std::vector<Token>& tokens);
    void handle_symbol(std::vector<Token>& tokens);
};

#endif // LEXER_H
