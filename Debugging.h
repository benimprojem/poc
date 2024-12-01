#ifndef DEBUGGING_H
#define DEBUGGING_H

#include <iostream>
#include <string>
#include <unordered_map>
#include "IRGenerator.h"

class Debugging {
public:
    void initialize(const std::vector<IRGenerator::IRInstruction>& instructions);
    void set_breakpoint(int line_number);
    void run_debugger();
    void step();
    void print_variables();
    void print_call_stack();

private:
    std::unordered_map<int, IRGenerator::IRInstruction> instruction_map;
    int current_instruction_index;
    std::vector<std::string> call_stack;
    std::unordered_map<std::string, int> variables;
    std::unordered_map<int, bool> breakpoints;
};

#endif // DEBUGGING_H
