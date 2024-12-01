#ifndef SEMANTIC_H
#define SEMANTIC_H

#include <vector>
#include <string>
#include <unordered_map>
#include "Parser.h"

class SemanticAnalyzer {
public:
    void analyze(std::vector<Parser::ASTNode>& ast_nodes);
    void report_error(const std::string &message, int line, int column);
    void report_warning(const std::string& message, int line, int column);

private:
    std::unordered_map<std::string, std::string> variables;
    std::unordered_map<std::string, std::string> functions;
};

#endif // SEMANTIC_H
