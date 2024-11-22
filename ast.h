#pragma once

#include <string>
#include <vector>
#include <memory>

enum class NodeType {
    PROGRAM,
    BLOCK,
    VARIABLE_DECLARATION,
    FUNCTION_DECLARATION,
    FUNCTION_CALL,
    RETURN_STATEMENT,
    IF_STATEMENT,
    ELSE_IF_STATEMENT,
    ELSE_STATEMENT,
    WHILE_LOOP,
    DO_WHILE_LOOP,
    FOR_LOOP,
    BREAK_STATEMENT,
    CONTINUE_STATEMENT,
    SWITCH_STATEMENT,
    CASE_STATEMENT,
    DEFAULT_CASE,
    CLASS_DECLARATION,
    STRUCT_DECLARATION,
    ENUM_DECLARATION,
    TYPE_CAST,
    ARRAY_ACCESS,
    INDEX_ASSIGNMENT,
    FUNCTION_ARGUMENT_LIST,
    VARIABLE_NAME,
    NUMBER,
    STRING,
    BOOLEAN,
    NULL_VALUE,
    COMMA,
    COLON,
    SEMICOLON,
    EQUALS,
    PLUS,
    MINUS,
    STAR,
    SLASH,
    PERCENTAGE,
    LESS_THAN,
    GREATER_THAN,
    LESS_OR_EQUAL,
    GREATER_OR_EQUAL,
    EQUALS_EQUALS,
    NOT_EQUALS,
    TK_AND,
    TK_OR,
    TK_XOR,
    QUESTION_MARK,
    ARROW,
    OPEN_PARENTHESIS,
    CLOSE_PARENTHESIS,
    OPEN_BRACKET,
    CLOSE_BRACKET,
    OPEN_CURLY_BRACKET,
    CLOSE_CURLY_BRACKET,
    HASH,
    SCOPE,
	LIST_CREATION,
    LIST_APPEND,
    LIST_REMOVE,
    STRING_CONCATENATE,
    STRING_LENGTH,
    STRING_SUBSTRING,
    BOOL_AND,
    BOOL_OR,
    BOOL_NOT,
    ADDITION,
    SUBTRACTION,
    MULTIPLICATION,
    DIVISION,
    MODULUS,
    EQUALITY_CHECK,
    INEQUALITY_CHECK,
    LESS_THAN_OR_EQUAL,
    GREATER_THAN_OR_EQUAL,
    LOGICAL_AND,
    LOGICAL_OR,
    LOGICAL_NOT,
    VOID_FUNCTION_CALL,
    NULL_CHECK,
    LIST_ELEMENT_ACCESS,
    STRING_MANIPULATION,
    TRADITIONAL_TYPE_CONVERSION,
    SPECIAL_OPERATION,
    UNDERSCORE
};

struct ASTNode {
    NodeType type;
    std::string value;
    std::vector<std::shared_ptr<ASTNode>> children;
};
// Özel node tiplerini ekleyin
struct ProgramNode : public ASTNode {
    ProgramNode() : ASTNode{NodeType::PROGRAM} {}
};

struct BlockNode : public ASTNode {
    BlockNode() : ASTNode{NodeType::BLOCK} {}
};

struct VariableDeclarationNode : public ASTNode {
    VariableDeclarationNode() : ASTNode{NodeType::VARIABLE_DECLARATION} {}
};

struct FunctionDeclarationNode : public ASTNode {
    FunctionDeclarationNode() : ASTNode{NodeType::FUNCTION_DECLARATION} {}
};

struct ForLoopNode : public ASTNode {
    ForLoopNode() : ASTNode{NodeType::FOR_LOOP} {}
};

struct WhileLoopNode : public ASTNode {
    WhileLoopNode() : ASTNode{NodeType::WHILE_LOOP} {}
};

struct DoWhileLoopNode : public ASTNode {
    DoWhileLoopNode() : ASTNode{NodeType::DO_WHILE_LOOP} {}
};

struct IfStatementNode : public ASTNode {
    IfStatementNode() : ASTNode{NodeType::IF_STATEMENT} {}
};

struct ElseIfStatementNode : public ASTNode {
    ElseIfStatementNode() : ASTNode{NodeType::ELSE_IF_STATEMENT} {}
};

struct ElseStatementNode : public ASTNode {
    ElseStatementNode() : ASTNode{NodeType::ELSE_STATEMENT} {}
};

struct SwitchStatementNode : public ASTNode {
    SwitchStatementNode() : ASTNode{NodeType::SWITCH_STATEMENT} {}
};

struct ReturnStatementNode : public ASTNode {
    ReturnStatementNode() : ASTNode{NodeType::RETURN_STATEMENT} {}
};

struct BreakStatementNode : public ASTNode {
    BreakStatementNode() : ASTNode{NodeType::BREAK_STATEMENT} {}
};

struct ContinueStatementNode : public ASTNode {
    ContinueStatementNode() : ASTNode{NodeType::CONTINUE_STATEMENT} {}
};
struct ListCreationNode : public ASTNode {
    ListCreationNode() : ASTNode{NodeType::LIST_CREATION} {}
};

struct ListAppendNode : public ASTNode {
    ListAppendNode() : ASTNode{NodeType::LIST_APPEND} {}
};

struct ListRemoveNode : public ASTNode {
    ListRemoveNode() : ASTNode{NodeType::LIST_REMOVE} {}
};
struct BoolAndNode : public ASTNode {
    BoolAndNode() : ASTNode{NodeType::BOOL_AND} {}
};

struct BoolOrNode : public ASTNode {
    BoolOrNode() : ASTNode{NodeType::BOOL_OR} {}
};

struct BoolNotNode : public ASTNode {
    BoolNotNode() : ASTNode{NodeType::BOOL_NOT} {}
};

struct AdditionNode : public ASTNode {
    AdditionNode() : ASTNode{NodeType::ADDITION} {}
};

struct SubtractionNode : public ASTNode {
    SubtractionNode() : ASTNode{NodeType::SUBTRACTION} {}
};

struct MultiplicationNode : public ASTNode {
    MultiplicationNode() : ASTNode{NodeType::MULTIPLICATION} {}
};

struct DivisionNode : public ASTNode {
    DivisionNode() : ASTNode{NodeType::DIVISION} {}
};

struct ModulusNode : public ASTNode {
    ModulusNode() : ASTNode{NodeType::MODULUS} {}
};

struct EqualityCheckNode : public ASTNode {
    EqualityCheckNode() : ASTNode{NodeType::EQUALITY_CHECK} {}
};

struct InequalityCheckNode : public ASTNode {
    InequalityCheckNode() : ASTNode{NodeType::INEQUALITY_CHECK} {}
};

struct LessThanNode : public ASTNode {
    LessThanNode() : ASTNode{NodeType::LESS_THAN} {}
};

struct GreaterThanNode : public ASTNode {
    GreaterThanNode() : ASTNode{NodeType::GREATER_THAN} {}
};

struct LessThanOrEqualToNode : public ASTNode {
    LessThanOrEqualToNode() : ASTNode{NodeType::LESS_THAN_OR_EQUAL} {}
};

struct GreaterThanOrEqualToNode : public ASTNode {
    GreaterThanOrEqualToNode() : ASTNode{NodeType::GREATER_THAN_OR_EQUAL} {}
};

struct LogicalAndNode : public ASTNode {
    LogicalAndNode() : ASTNode{NodeType::LOGICAL_AND} {}
};

struct LogicalOrNode : public ASTNode {
    LogicalOrNode() : ASTNode{NodeType::LOGICAL_OR} {}
};

struct LogicalNotNode : public ASTNode {
    LogicalNotNode() : ASTNode{NodeType::LOGICAL_NOT} {}
};

struct VoidFunctionCallNode : public ASTNode {
    VoidFunctionCallNode() : ASTNode{NodeType::VOID_FUNCTION_CALL} {}
};

struct TypeCastNode : public ASTNode {
    TypeCastNode() : ASTNode{NodeType::TYPE_CAST} {}
};

struct NullCheckNode : public ASTNode {
    NullCheckNode() : ASTNode{NodeType::NULL_CHECK} {}
};

struct ListElementAccessNode : public ASTNode {
    ListElementAccessNode() : ASTNode{NodeType::LIST_ELEMENT_ACCESS} {}
};


struct StringConcatenateNode : public ASTNode {
    StringConcatenateNode() : ASTNode{NodeType::STRING_CONCATENATE} {}
};

struct StringLengthNode : public ASTNode {
    StringLengthNode() : ASTNode{NodeType::STRING_LENGTH} {}
};

struct StringSubstringNode : public ASTNode {
    StringSubstringNode() : ASTNode{NodeType::STRING_SUBSTRING} {}
};
struct StringManipulationNode : public ASTNode {
    StringManipulationNode() : ASTNode{NodeType::STRING_MANIPULATION} {}
};

struct FunctionCallNode : public ASTNode {
    FunctionCallNode() : ASTNode{NodeType::FUNCTION_CALL} {}
};

struct TraditionalTypeConversionNode : public ASTNode {
    TraditionalTypeConversionNode() : ASTNode{NodeType::TRADITIONAL_TYPE_CONVERSION} {}
};

struct SpecialOperationNode : public ASTNode {
    SpecialOperationNode() : ASTNode{NodeType::SPECIAL_OPERATION} {}
};


// ... (diğer node tipleri için benzer şekilde)


class ASTBuilder {
public:
    ASTBuilder();

    // AST yapısını oluşturan metotlar...
    std::shared_ptr<ASTNode> program(const char* source);
    std::shared_ptr<ASTNode> block(std::vector<std::shared_ptr<ASTNode>> statements);
    std::shared_ptr<ASTNode> variableDeclaration(const char* name, std::shared_ptr<ASTNode> type);
    std::shared_ptr<ASTNode> functionDeclaration(const char* name, std::vector<std::shared_ptr<ASTNode>> parameters, std::vector<std::shared_ptr<ASTNode>> body);
    std::shared_ptr<ASTNode> functionCall(const char* name, std::vector<std::shared_ptr<ASTNode>> arguments);
    std::shared_ptr<ASTNode> returnStatement(std::shared_ptr<ASTNode> expression);
    std::shared_ptr<ASTNode> ifStatement(std::shared_ptr<ASTNode> condition, std::shared_ptr<ASTNode> body, std::shared_ptr<ASTNode> elseBody = nullptr);
    std::shared_ptr<ASTNode> whileLoop(std::shared_ptr<ASTNode> condition, std::vector<std::shared_ptr<ASTNode>> body);
    std::shared_ptr<ASTNode> forLoop(const char* varName, const char* initExpr, const char* condExpr, const char* stepExpr, std::vector<std::shared_ptr<ASTNode>> body);
    std::shared_ptr<ASTNode> classDeclaration(const char* name, std::vector<std::shared_ptr<ASTNode>> members);
    std::shared_ptr<ASTNode> structDeclaration(const char* name, std::vector<std::shared_ptr<ASTNode>> members);
    std::shared_ptr<ASTNode> enumDeclaration(const char* name, std::vector<std::shared_ptr<ASTNode>> values);
    std::shared_ptr<ASTNode> typeCast(std::shared_ptr<ASTNode> expression, std::string type);
    std::shared_ptr<ASTNode> arrayAccess(std::shared_ptr<ASTNode> array, std::shared_ptr<ASTNode> index);
    std::shared_ptr<ASTNode> indexAssignment(const char* varName, std::shared_ptr<ASTNode> array, std::shared_ptr<ASTNode> index, std::shared_ptr<ASTNode> value);
    std::shared_ptr<ASTNode> functionArgumentList(std::vector<std::shared_ptr<ASTNode>> arguments);
    std::shared_ptr<ASTNode> variableName(const char* name);
    std::shared_ptr<ASTNode> number(double value);
    std::shared_ptr<ASTNode> string(const char* value);
    std::shared_ptr<ASTNode> boolean(bool value);
    std::shared_ptr<ASTNode> nullValue();
    std::shared_ptr<ASTNode> comma();
    std::shared_ptr<ASTNode> colon();
    std::shared_ptr<ASTNode> semicolon();
    std::shared_ptr<ASTNode> equals();
    std::shared_ptr<ASTNode> plus();
    std::shared_ptr<ASTNode> minus();
    std::shared_ptr<ASTNode> star();
    std::shared_ptr<ASTNode> slash();
    std::shared_ptr<ASTNode> percentage();
    std::shared_ptr<ASTNode> lessThan();
    std::shared_ptr<ASTNode> greaterThan();
    std::shared_ptr<ASTNode> lessOrEqual();
    std::shared_ptr<ASTNode> greaterOrEqual();
    std::shared_ptr<ASTNode> equalsEquals();
    std::shared_ptr<ASTNode> notEquals();
    std::shared_ptr<ASTNode> tk_and();
    std::shared_ptr<ASTNode> tk_or();
    std::shared_ptr<ASTNode> tk_xor();
    std::shared_ptr<ASTNode> questionMark();
    std::shared_ptr<ASTNode> arrow();
    std::shared_ptr<ASTNode> openParenthesis();
    std::shared_ptr<ASTNode> closeParenthesis();
    std::shared_ptr<ASTNode> openBracket();
    std::shared_ptr<ASTNode> closeBracket();
    std::shared_ptr<ASTNode> openCurlyBrace();
    std::shared_ptr<ASTNode> closeCurlyBrace();
    std::shared_ptr<ASTNode> hash();
    std::shared_ptr<ASTNode> scope();
    std::shared_ptr<ASTNode> underscore();
};
