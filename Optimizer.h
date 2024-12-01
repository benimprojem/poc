#ifndef OPTIMIZER_H
#define OPTIMIZER_H

#include <iostream>
#include <vector>
#include "IRGenerator.h"

class Optimizer {
public:
    std::vector<IRGenerator::IRInstruction> optimize(const std::vector<IRGenerator::IRInstruction>& ir_instructions);

private:
    void constant_folding(std::vector<IRGenerator::IRInstruction>& ir_instructions);
    void dead_code_elimination(std::vector<IRGenerator::IRInstruction>& ir_instructions);
    void copy_elimination(std::vector<IRGenerator::IRInstruction>& ir_instructions);
    void register_allocation(std::vector<IRGenerator::IRInstruction>& ir_instructions);
};

#endif // OPTIMIZER_H
