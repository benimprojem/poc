#include "Compiler.h"
#include <fstream>
#include <iostream>

void Compiler::compile(const std::string& input_file) {
    std::ifstream file(input_file);
    if (!file.is_open()) {
        std::cerr << "Unable to open file: " << input_file << std::endl;
        return;
    }
    
    std::string source_code((std::istreambuf_iterator<char>(file)),
                           std::istreambuf_iterator<char>());
    file.close();
    
    lex(source_code);
    parse(tokens);
    semantic_analysis();
    generate_ir();
    optimize();
    execute();
    debug();
    emit_code();
    profile_performance();
}

void Compiler::lex(const std::string& source_code) {
    Lexer lexer(source_code);
    tokens = lexer.tokenize();
}

void Compiler::parse(std::vector<Token>& tokens) {
    Parser parser;
    ast_nodes = parser.parse(tokens);
}

// Diğer compiler fonksiyonlarının implementasyonları... 