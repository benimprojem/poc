#include "Lexer.h"

Lexer::Lexer(const std::string& source_code) : source_code(source_code), current_char_index(0), current_line(1), current_column(1) {
    keywords = {
        {"if", TokenType::KEYWORD_IF},
        {"elsif", TokenType::KEYWORD_ELSIF},
        {"els", TokenType::KEYWORD_ELS},
        {"for", TokenType::KEYWORD_FOR},
        {"foreach", TokenType::KEYWORD_FOREACH},
        {"while", TokenType::KEYWORD_WHILE},
        {"loop", TokenType::KEYWORD_LOOP},
        {"func", TokenType::KEYWORD_FUNC},
        {"return", TokenType::KEYWORD_RETURN},
        {"let", TokenType::KEYWORD_LET},
        {"const", TokenType::KEYWORD_CONST},
        {"static", TokenType::KEYWORD_STATIC},
        {"struct", TokenType::KEYWORD_STRUCT},
        {"import", TokenType::KEYWORD_IMPORT},
        {"true", TokenType::BOOL_TRUE},
        {"false", TokenType::BOOL_FALSE}
    };
}

std::vector<Token> Lexer::tokenize() {
    std::vector<Token> tokens;
    while (current_char_index < source_code.length()) {
        char current_char = peek_next_char();
        
        if (is_whitespace(current_char)) {
            skip_whitespace_and_comments();
            continue;
        }
        
        if (is_digit(current_char)) {
            handle_number_literal(tokens);
        }
        else if (is_letter(current_char)) {
            handle_identifier_or_keyword(tokens);
        }
        else if (current_char == '"') {
            handle_string_literal(tokens);
        }
        else {
            handle_symbol(tokens);
        }
    }
    
    tokens.push_back(create_token(TokenType::EOF_TOKEN, ""));
    return tokens;
}

// Diğer yardımcı fonksiyonların implementasyonları... 