#pragma once

#include "lexer.h"
#include <vector>
#include <memory>

class ASTNode;
class ASTBuilder;

class Parser {
private:
    Token currentToken;
    std::unique_ptr<ASTBuilder> astBuilder;

public:
    Parser();

    void SetNextToken(Token token);
    bool Eat(TokenType type);
    
    // Diğer parse fonksiyonları...
    
    // Python'a özgü eklemeler
    ASTNode* ParseExpression();
    ASTNode* ParseFunctionDefinition();
    ASTNode* ParseClassDefinition();
    ASTNode* ParseListCreation();
    ASTNode* ParseDictCreation();
    ASTNode* ParseSetCreation();
    ASTNode* ParseTupleCreation();
    ASTNode* ParseRangeCreation();
    ASTNode* ParseSliceCreation();
    
    // Go'ya özgü eklemeler
    ASTNode* ParsePackageDeclaration();
    ASTNode* ParseImportStatement();
    ASTNode* ParseInterfaceDefinition();
    ASTNode* ParseStructDefinition();
    ASTNode* ParseEnumDefinition();
    
    // C'ye özgü eklemeler
    ASTNode* ParseUnionType();
    ASTNode* ParseTypedef();
    ASTNode* ParseMacroDefinition();
    ASTNode* ParseInlineFunction();
    
    // Genişletilmiş kontrol işlemleri
    bool CheckScopeLevel();
    bool CheckVariableDeclaration();
    bool CheckFunctionSignature();
    bool CheckReturnStatement();
    bool CheckBreakContinueStatement();
    bool CheckSwitchCase();
    bool CheckMatchStatement();
    
    // Özel POC diline özgü kontrol işlemleri
    bool CheckListType();
    bool CheckDictType();
    bool CheckSetType();
    bool CheckTupleType();
    bool CheckRangeType();
    bool CheckSliceType();
    
    // Mantıksal operatörler için özel kontrol
    bool CheckLogicalOperation();
    bool CheckArithmeticOperation();
    bool CheckComparisonOperation();
    
    // Hata raporlama
    void ReportSyntaxError(const char* message);
};
