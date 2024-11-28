#include "parser.h"
#include "ast.h"
#include "semantic.h"
#include "IRGenerator.h"
#include "optimizer.h"
#include "CodeEmitter.h"
#include "MemoryManager.h"
#include "RuntimeEnvironment.h"
#include "DebuggingSupport.h"
#include "PerformanceProfiling.h"
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }

    std::string inputFile = argv[1];

    // Lexer oluşturma ve kelime anahtarları algoritması
    Tokenizer tokenizer(inputFile);
    Token token;
    while ((token = tokenizer.getNextToken()) != TK_EOF) {
        // Parser ile sözdizimi kontrolü
        Parser parser;
        ASTNode* astRoot = parser.parse(token);

        // Semantic analiz
        SemanticAnalyzer semanticAnalyzer;
        astRoot->accept(semanticAnalyzer);

        // IR kodları oluşturma
        IRGenerator irGenerator;
        std::string irCode = irGenerator.generateIR(astRoot);

        // Kod optimizasyonu
        Optimizer optimizer;
        std::string optimizedIR = optimizer.optimizeIR(irCode);

        // Makine kodu oluşturma
        CodeEmitter codeEmitter;
        std::string machineCode = codeEmitter.emitMachineCode(optimizedIR);

        // Bellek yönetimi
        MemoryManager memoryManager;
        std::string objectCode = memoryManager.allocateMemory(machineCode);

        // Performans profili ve optimizasyon önerileri
        PerformanceProfiler profiler;
        profiler.startProfiling();
        profiler.recordFunctionExecution("main", 0.0); // Başlangıç zamanı 0 olarak ayarlandı
        std::string report = profiler.getPerformanceReport();
        std::cout << "Performance Report:" << std::endl;
        std::cout << report << std::endl;
        profiler.stopProfiling();

        // Debugging desteği etkinleştirme
        DebuggingSupport debugger;
        debugger.enableDebuggingMode();

        // Runtime ortamı başlatma
        RuntimeEnvironment runtimeEnv;
        runtimeEnv.initializeRuntime();

        // Makine kodu çalıştırma
        runtimeEnv.runObjectCode(objectCode);

        // Hata kontrolü ve temizleme
        if (runtimeEnv.manageErrors()) {
            std::cerr << "Execution completed with errors." << std::endl;
            return 1;
        }

        // Bellek temizleme
        memoryManager.freeMemory(objectCode);

        // Debugging modunu devre dışı bırakma
        debugger.disableDebuggingMode();

        // Performans profili temizleme
        profiler.resetPerformanceProfile();
    }

    return 0;
}
