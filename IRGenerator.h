#pragma once

#include "ast.h"
#include "lexer.h"
#include <string>
#include <vector>
#include <unordered_map>

class IRGenerator {
private:
    std::string irCode;
    std::vector<std::string> labels;
    std::unordered_map<std::string, int> variableRegisters;
    int registerCounter;

public:
    IRGenerator();

    std::string generateIR(ASTNode* root);

    // Ast düğümlerini işleyen yardımcı metotlar
    void generateExpressionIR(ASTNode* node);
    void generateStatementIR(ASTNode* node);
    void generateBlockIR(ASTNode* node);
    void generateFunctionIR(ASTNode* node);
    void generateClassIR(ASTNode* node);

    // Özel IR kodları üreten metotlar
    std::string generateLoadInstruction(const std::string& variableName);
    std::string generateStoreInstruction(const std::string& variableName);
    std::string generateBinaryOpInstruction(TokenType op, const std::string& leftReg, const std::string& rightReg);
    std::string generateUnaryOpInstruction(TokenType op, const std::string& reg);
    std::string generateJumpInstruction(const std::string& label);
    std::string generateConditionalJumpInstruction(TokenType condition, const std::string& leftReg, const std::string& rightReg, const std::string& label);

    // Kayıt yönetimi
    std::string allocateRegister();
    void freeRegister(const std::string& reg);

    // Etiket yönetimi
    std::string createLabel();

    // Hata raporlama
    void reportIRGenerationError(const std::string& message);
};
