#pragma once

#include <string>
#include <vector>
#include <memory>

#define MAX_TOKEN_LENGTH 100
#define TOKEN_TYPES 1024

typedef struct Token {
    TokenType type;
    char value[MAX_TOKEN_LENGTH];
} Token;

typedef enum TokenType {
    TK_EOF = 0,
    TK_NUMBER,
    TK_ID,
    TK_STRING,
    TK_CHAR,
    TK_BOOL,
    TK_INT,
    TK_FLOAT,
    TK_IF,
    TK_ELIF,
    TK_ELSE,
    TK_WHILE,
    TK_FOR,
    TK_RETURN,
    TK_BREAK,
    TK_CONTINUE,
    TK_SWITCH,
    TK_CASE,
    TK_DEFAULT,
    TK_CLASS,
    TK_STRUCT,
    TK_PUBLIC,
    TK_PRIVATE,
    TK_PROTECTED,
    TK_STATIC,
    TK_CONST,
    TK_VOLATILE,
    TK_AUTO,
    TK_NULLPTR,
    TK_AND,
    TK_OR,
    TK_XOR,
    TK_NOT,
    TK_SHL,
    TK_SHR,
    TK_SLL,
    TK_SLR,
    TK_PLUS,
    TK_MINUS,
    TK_TIMES,
    TK_DIVIDE,
    TK_MOD,
    TK_EQ,
    TK_NEQ,
    TK_LTEQ,
    TK_GTEQ,
    TK_LT,
    TK_GT,
    TK_LPAREN,
    TK_RPAREN,
    TK_LBRACKET,
    TK_RBRACKET,
    TK_LBRACE,
    TK_RBRACE,
    TK_SEMICOLON,
    TK_COMMA,
    TK_COLON,
    TK_ASSIGN,
    TK_QUESTION,
    TK_ARROW,
    TK_DOT,
    TK_SCOPE,
    TK_HASH,
    TK_LIST,
    TK_DICT,
    TK_SET,
    TK_TUPLE,
    TK_RANGE,
    TK_SLICE,
    TK_Y1_0,
    TK_Y1_1,
    TK_Y1_2,
    TK_Y1_3,
    TK_Y1_4,
    TK_Y1_5,
    TK_Y1_6,
    TK_Y1_7,
    TK_Y1_8,
    TK_Y1_9
} TokenType;

typedef enum {
    TK_COMMENT = TOKEN_TYPES + 1,
    TK_MULTI_COMMENT_START,
    TK_MULTI_COMMENT_END
} ExtendedTokenType;


class Tokenizer {
private:
    std::string sourceCode;
    std::vector<Token> tokens;
    int currentTokenIndex;

public:
    Tokenizer(const std::string& sourceCode);
    Token getNextToken();
    // ... (diğer metodlar)


void initializePOCTokenTypes();

// Özel POC diline özgü token türleri
void initializeSpecialTokens();
};
