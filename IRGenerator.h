#ifndef IRGENERATOR_H
#define IRGENERATOR_H

#include <iostream>
#include <vector>
#include <string>
#include "Parser.h"

class IRGenerator {
public:
    enum class InstructionType {
        ADD,
        SUB,
        MUL,
        DIV,
        MOD,
        ASSIGN,
        JUMP,
        JUMP_IF,
        LABEL,
        PRINT,
        FUNCTION_CALL,
        RETURN
    };

    struct IRInstruction {
        InstructionType type;
        std::string operand1;
        std::string operand2;
        std::string result;
    };

    std::vector<IRInstruction> generate_ir(const std::vector<Parser::ASTNode>& ast_nodes);

private:
    void generate_expression_ir(const Parser::ASTNode& node, std::vector<IRInstruction>& ir_instructions);
    void generate_statement_ir(const Parser::ASTNode& node, std::vector<IRInstruction>& ir_instructions);
    void generate_function_declaration_ir(const Parser::ASTNode& node, std::vector<IRInstruction>& ir_instructions);
    void generate_if_statement_ir(const Parser::ASTNode& node, std::vector<IRInstruction>& ir_instructions);
    void generate_for_loop_ir(const Parser::ASTNode& node, std::vector<IRInstruction>& ir_instructions);
    void generate_while_loop_ir(const Parser::ASTNode& node, std::vector<IRInstruction>& ir_instructions);
    void generate_print_statement_ir(const Parser::ASTNode& node, std::vector<IRInstruction>& ir_instructions);

    IRInstruction create_instruction(InstructionType type, const std::string& operand1 = "", const std::string& operand2 = "", const std::string& result = "");
};

#endif // IRGENERATOR_H
