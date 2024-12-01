#ifndef RUNTIMEENVI_H
#define RUNTIMEENVI_H

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <functional>
#include "IRGenerator.h"

class RuntimeEnvironment {
public:
    void initialize();
    void execute(const std::vector<IRGenerator::IRInstruction>& instructions);

private:
    std::unordered_map<std::string, int> variables;
    std::unordered_map<std::string, std::function<int(int, int)>> functions;

    int execute_instruction(const IRGenerator::IRInstruction& instruction);
    int execute_expression(const IRGenerator::IRInstruction& instruction);
    void execute_statement(const IRGenerator::IRInstruction& instruction);
    void execute_function_declaration(const IRGenerator::IRInstruction& instruction);
    void execute_if_statement(const IRGenerator::IRInstruction& instruction);
    void execute_for_loop(const IRGenerator::IRInstruction& instruction);
    void execute_while_loop(const IRGenerator::IRInstruction& instruction);
    void execute_print_statement(const IRGenerator::IRInstruction& instruction);

    int get_variable_value(const std::string& variable_name);
    void set_variable_value(const std::string& variable_name, int value);
    int call_function(const std::string& function_name, int arg1, int arg2);
};

#endif // RUNTIMEENVI_H
