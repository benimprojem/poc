#pragma once

#include <string>
#include <map>
#include <vector>

#define _int 0
#define _float 1
#define _string 2
#define _null 3
#define _bool 4
#define _list 5

#define NODE_OK 100

#define _undef -100
#define UNDEFINED_SYMBOL -1
#define NODE_TYPE_ERROR -2
#define LIST_TYPE_ERROR -3
#define SEMANTIC_ERROR -4
#define BREAK_OUT_OF_CONTEXT -5
#define CONTINUE_OUT_OF_CONTEXT -6
#define OVERWRITE_TYPE_ERROR -7
#define DYNAMIC_TYPE_ERROR -8
#define CONCURRENCY_ERROR -9
#define POINTER_ERROR -10
#define LIST_OPERATION_ERROR -11
#define DICT_OPERATION_ERROR -12
#define SET_OPERATION_ERROR -13
#define TUPLE_OPERATION_ERROR -14

enum class Type {
    INT,
    FLOAT,
    STRING,
    NULL_,
    BOOL,
    LIST,
    VOID,
    DICT, // Sözlük tipi için
    SET,  // Küme tipi için
    TUPLE // Demet tipi için
};

struct Symbol {
    std::string name;
    Type type;
    bool isGlobal;
    int scopeLevel;
	bool isMutable; // Değişkenin değiştirilebilir olup olmadığını kontrol etmek için
};

class SemanticAnalyzer {
private:
    std::map<std::string, Symbol> symbolTable;
    std::vector<Type> functionTypes;
    int currentScopeLevel;
    std::vector<int> contextStack;

public:
    SemanticAnalyzer();
    
    // Tip kontrolü için metotlar
    Type checkType(Type leftType, Type rightType);
    Type checkArithmeticOperation(Type leftType, Type rightType);
    Type checkComparisonOperation(Type leftType, Type rightType);
    Type checkLogicalOperation(Type leftType, Type rightType);
    
    // Değişkan tanımlama ve kontrolü
    void declareVariable(std::string name, Type type, bool isGlobal);
    bool isVariableDeclared(std::string name);
    
    // Fonksiyon tanımlama ve kontrolü
    void declareFunction(std::string name, Type returnType);
    bool isFunctionDefined(std::string name);
    
    // Bağlam kontrolü
    void enterScope();
    void exitScope();
    
    // Hata kontrolü
    void reportError(std::string message);
    
    // Program yapısı ziyaretleri
    void visit_ProgramNode(ProgramNode* node);
    void visit_BlockNode(BlockNode* node);
    void visit_VariableDeclarationNode(VariableDeclarationNode* node);
    void visit_FunctionDeclarationNode(FunctionDeclarationNode* node);
    
    // Döngü kontrolü
    void visit_ForLoopNode(ForLoopNode* node);
    void visit_WhileLoopNode(WhileLoopNode* node);
    void visit_DoWhileLoopNode(DoWhileLoopNode* node);
    
    // Python tarzı dinamik tip kontrolü için
    void checkDynamicTypeAssignment(Symbol& symbol, Type newType);

    // Go tarzı eşzamanlılık kontrolü için
    void checkConcurrencyUsage();

    // C tarzı pointer kontrolü için
    void checkPointerUsage();

    // Özel POC diline özgü kontrol işlemleri
    void checkListOperations();
    void checkDictOperations();
    void checkSetOperations();
    void checkTupleOperations();
	
    // İf-else kontrolü
    void visit_IfStatementNode(IfStatementNode* node);
    void visit_ElseIfStatementNode(ElseIfStatementNode* node);
    void visit_ElseStatementNode(ElseStatementNode* node);
    
    // Switch kontrolü
    void visit_SwitchStatementNode(SwitchStatementNode* node);
    
    // Return kontrolü
    void visit_ReturnStatementNode(ReturnStatementNode* node);
    
    // Break ve continue kontrolü
    void visit_BreakStatementNode(BreakStatementNode* node);
    void visit_ContinueStatementNode(ContinueStatementNode* node);
    
    // Liste manipülasyonu
    void visit_ListCreationNode(ListCreationNode* node);
    void visit_ListAppendNode(ListAppendNode* node);
    void visit_ListRemoveNode(ListRemoveNode* node);
    
    // String manipülasyonu
    void visit_StringConcatenateNode(StringConcatenateNode* node);
    void visit_StringLengthNode(StringLengthNode* node);
    void visit_StringSubstringNode(StringSubstringNode* node);
    
    // Bool operasyonları
    void visit_BoolAndNode(BoolAndNode* node);
    void visit_BoolOrNode(BoolOrNode* node);
    void visit_BoolNotNode(BoolNotNode* node);
    
    // Arithmetik operasyonları
    void visit_AdditionNode(AdditionNode* node);
    void visit_SubtractionNode(SubtractionNode* node);
    void visit_MultiplicationNode(MultiplicationNode* node);
    void visit_DivisionNode(DivisionNode* node);
    void visit_ModulusNode(ModulusNode* node);
    
    // Comparison operasyonları
    void visit_EqualityCheckNode(EqualityCheckNode* node);
    void visit_InequalityCheckNode(InequalityCheckNode* node);
    void visit_LessThanNode(LessThanNode* node);
    void visit_GreaterThanNode(GreaterThanNode* node);
    void visit_LessThanOrEqualToNode(LessThanOrEqualToNode*node);
    void visit_GreaterThanOrEqualToNode(GreaterThanOrEqualToNode* node);
    
    // Logical operasyonları
    void visit_LogicalAndNode(LogicalAndNode* node);
    void visit_LogicalOrNode(LogicalOrNode* node);
    void visit_LogicalNotNode(LogicalNotNode* node);
    
    // Void fonksiyonu kontrolü
    void visit_VoidFunctionCallNode(VoidFunctionCallNode* node);
    
    // Tip dönüşümü
    void visit_TypeCastNode(TypeCastNode* node);
    
    // Null kontrolü
    void visit_NullCheckNode(NullCheckNode* node);
    
    // Liste eleman erişimleri
    void visit_ListElementAccessNode(ListElementAccessNode* node);
    
    // String manipülasyonu
    void visit_StringManipulationNode(StringManipulationNode* node);
    
    // Fonksiyon çağrısı kontrolü
    void visit_FunctionCallNode(FunctionCallNode* node);
    
    // Geleneksel tip dönüşümü
    void visit_TraditionalTypeConversionNode(TraditionalTypeConversionNode* node);
    
    // Özel işlem kontrolü
    void visit_SpecialOperationNode(SpecialOperationNode* node);
	
	void checkIdentifier(ASTNode* node);
    void checkParameterList(ASTNode* node);
    void checkBlock(ASTNode* node);
	
	// SemanticAnalyzer sınıfına yeni bir metot ekleyin
	void checkFunctionDefinition(ASTNode* node) {
		if (node->type == NodeType::FUNCTION_DECLARATION) {
			// Fonksiyon adı kontrolü
			checkIdentifier(node->children[0].get());
			
			// Parametre kontrolü
			checkParameterList(node->children[1].get());
			
			// Fonksiyon gövdesi kontrolü
			checkBlock(node->children[2].get());
		}
	}

    // ... (diğer eksik metodlar)

};
