#pragma once

#include "IRGenerator.h"
#include <string>
#include <vector>
#include <unordered_map>

class Optimizer {
private:
    std::string optimizedIRCode;
    std::vector<std::string> basicBlocks;
    std::unordered_map<std::string, int> registerUsageCounts;
    std::unordered_map<std::string, bool> constantValues;

public:
    Optimizer();
    
    std::string optimizeIR(const std::string& irCode);
    
    // Temel blokları oluşturur ve yönetir
    void createBasicBlocks(const std::string& irCode);
    void mergeBasicBlocks(std::vector<std::string>& blocks);
    
    // Kod hareketi optimizasyonu
    void eliminateDeadCode(const std::string& irCode);
    void removeUnreachableCode(const std::string& irCode);
    
    // Sabit ifade değerlendirme
    void evaluateConstants(const std::string& irCode);
    void propagateConstantValues(const std::string& irCode);
    
    // Değerlendirme optimizasyonu
    void expressionEvaluationOptimization(const std::string& irCode);
    void applyCommonSubexpressionElimination(const std::string& irCode);
    
    // Register tahsisi
    void registerAllocation(const std::string& irCode);
    void registerRenaming(const std::string& irCode);
    
    // Bellek yönetimi optimizasyonu
    void memoryManagementOptimization(const std::string& irCode);
    void deadStoreElimination(const std::string& irCode);
    
    // Kontrol akışı optimizasyonu
    void controlFlowOptimization(const std::string& irCode);
    void loopUnrolling(const std::string& irCode);
    void branchPrediction(const std::string& irCode);
    
    // Diğer optimizasyonlar
    void instructionCombining(const std::string& irCode);
    void strengthReduction(const std::string& irCode);
    void copyElision(const std::string& irCode);
    
    // Hata raporlama
    void reportOptimizationError(const std::string& message);
};


/*
Private üyeler:
optimizedIRCode: Optimize edilmiş IR kodunu tutar.
basicBlocks: Temel blokları tutar.
registerUsageCounts: Kayıt kullanım sayılarını tutar.
constantValues: Sabit değerleri tutar.
Temel blok yönetimi için metotlar:
createBasicBlocks
mergeBasicBlocks
Kod hareketi optimizasyonu için ek metot:
removeUnreachableCode
Sabit ifade değerlendirme için ek metot:
propagateConstantValues
Değerlendirme optimizasyonu için ek metot:
applyCommonSubexpressionElimination
Register tahsisi için ek metot:
registerRenaming
Bellek yönetimi optimizasyonu için ek metot:
deadStoreElimination
Kontrol akışı optimizasyonu için ek metotlar:
loopUnrolling
branchPrediction
Diğer optimizasyonlar için yeni metotlar:
instructionCombining
strengthReduction
copyElision
Hata raporlama için metot:
reportOptimizationError

*/