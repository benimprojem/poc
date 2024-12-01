#ifndef COMPILER_H
#define COMPILER_H

#include <iostream>
#include <fstream>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <vector>
#include "Lexer.h"
#include "Parser.h"
#include "Semantic.h"
#include "MemoryManager.h"
#include "StringModule.h"

class Compiler {
public:
    void compile(const string& input_file);
    void semantic_analysis();

private:
    vector<Token> tokens;
    vector<Parser::ASTNode> ast_nodes;
    SemanticAnalyzer semantic_analyzer;
    IRGenerator ir_generator;
    Optimizer optimizer;
    RuntimeEnvironment runtime_environment;
    MemoryManager memory_manager;
    Debugging debugger;
    CodeEmitter code_emitter;
    Performance profiler;
    StringModule string_module;
    vector<IRGenerator::IRInstruction> ir_instructions;
    vector<IRGenerator::IRInstruction> optimized_instructions;

    void lex(const string& source_code);
    void parse(vector<Token>& tokens);
    void generate_ir();
    void optimize();
    void execute();
    void debug();
    void emit_code();
    void profile_performance();
    void semantic_analysis();
};

#endif // COMPILER_H
