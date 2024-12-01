#include "Parser.h"

std::vector<Parser::ASTNode> Parser::parse(std::vector<Token>& tokens) {
    this->tokens = tokens;
    current_token_index = 0;
    std::vector<ASTNode> ast_nodes;
    
    while (current_token_index < tokens.size()) {
        ASTNode* node_ptr = parse_statement();
        ASTNode node = *node_ptr;
        ast_nodes.push_back(node);
    }
    
    return ast_nodes;
}

Parser::ASTNode* Parser::parse_statement() {
    Token current = peek_next_token();
    
    switch (current.type) {
        case TokenType::KEYWORD_FUNC:
            return parse_function_declaration();
        case TokenType::KEYWORD_IF:
            return parse_if_statement();
        // Diğer statement tipleri...
        default:
            return parse_expression();
    }
}

Parser::ASTNode* Parser::parse_function_declaration() {
    ASTNode* node = new ASTNode();
    node->node_type = NodeType::FUNCTION_DECLARATION;
    
    // func topla:a,b,c{ ... }
    expect(TokenType::KEYWORD_FUNC);
    node->name = expect(TokenType::IDENTIFIER).value;
    expect(TokenType::COLON);
    
    // Parametreleri parse et
    while (current_token().type != TokenType::SYMBOL_BRACE_OPEN) {
        node->parameters.push_back(parse_parameter());
        if (current_token().type == TokenType::SYMBOL_COMMA) {
            consume_token(TokenType::SYMBOL_COMMA);
        }
    }
    
    // Fonksiyon gövdesini parse et
    node->body = parse_block();
    
    return node;
}

Parser::ASTNode* Parser::parse_if_statement() {
    ASTNode* node = new ASTNode();
    node->node_type = NodeType::IF_STATEMENT;
    
    expect(TokenType::KEYWORD_IF);
    expect(TokenType::COLON);
    node->condition = parse_expression();
    node->then_block = parse_block();
    
    if (current_token().type == TokenType::KEYWORD_ELS) {
        consume_token(TokenType::KEYWORD_ELS);
        expect(TokenType::COLON);
        node->else_block = parse_block();
    }
    
    return node;
} 

Parser::ASTNode* Parser::parse_expression() {
    ASTNode* node = new ASTNode();
    node->node_type = NodeType::EXPRESSION;
    // İfade analizi yapın
    return node;
}

Parser::ASTNode* Parser::parse_block() {
    ASTNode* node = new ASTNode();
    node->node_type = NodeType::BLOCK;  // Örneğin, bir blok türü ekleyin
    // Blok analizi yapın
    return node;
}

// Diğer parse fonksiyonlarının implementasyonları...