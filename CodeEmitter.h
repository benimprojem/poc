#ifndef CODEEMITTER_H
#define CODEEMITTER_H

#include <iostream>
#include <vector>
#include <string>
#include "IRGenerator.h"

class CodeEmitter {
public:
    std::string emit_code(const std::vector<IRGenerator::IRInstruction>& instructions);

private:
    std::string emit_instruction(const IRGenerator::IRInstruction& instruction);
    std::string emit_expression(const IRGenerator::IRInstruction& instruction);
    std::string emit_statement(const IRGenerator::IRInstruction& instruction);
    std::string emit_function_declaration(const IRGenerator::IRInstruction& instruction);
    std::string emit_if_statement(const IRGenerator::IRInstruction& instruction);
    std::string emit_for_loop(const IRGenerator::IRInstruction& instruction);
    std::string emit_while_loop(const IRGenerator::IRInstruction& instruction);
    std::string emit_print_statement(const IRGenerator::IRInstruction& instruction);
};

#endif // CODEEMITTER_H
