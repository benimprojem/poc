#pragma once

#include "optimizer.h"
#include <string>
#include <vector>
#include <unordered_map>

class CodeEmitter {
private:
    std::string machineCode;
    std::unordered_map<std::string, int> registerAllocation;
    std::unordered_map<std::string, int> memoryLayout;

public:
    CodeEmitter();
    
    // Makine kodunu üretilir
    std::string emitMachineCode(const std::string& optimizedIR);
    
    // Register tahsisi ve yönetimi
    void assignRegisters();
    void freeRegister(const std::string& registerName);
    
    // Bellek yönetimi
    void manageMemory();
    int allocateMemory(int size);
    void deallocateMemory(const std::string& variableName);
    
    // Kontrol akışı optimizasyonu
    void optimizeControlFlow();
    void applyBranchPrediction();
    void performLoopUnrolling();
    
    // Makine kodundan obje koduna çevirme
    std::string convertToObjectCode();
    
    // Özel makine kodu üreten metotlar
    std::string generateLoadInstruction(const std::string& registerName, const std::string& memoryAddress);
    std::string generateStoreInstruction(const std::string& registerName, const std::string& memoryAddress);
    std::string generateArithmeticInstruction(TokenType op, const std::string& destReg, const std::string& srcReg1, const std::string& srcReg2);
    std::string generateJumpInstruction(const std::string& label);
    std::string generateConditionalJumpInstruction(TokenType condition, const std::string& reg1, const std::string& reg2, const std::string& label);
    
    // Hata raporlama
    void reportCodeEmissionError(const std::string& message);
};

/*
Private üyeler:
machineCode: Üretilen makine kodunu tutar.
registerAllocation: Kayıt tahsisini tutar.
memoryLayout: Bellek düzenini tutar.
Constructor ekledik:
CodeEmitter(): Sınıfın başlangıç durumunu ayarlar.
Register tahsisi ve yönetimi için yeni metotlar:
assignRegisters(): Kayıt tahsisini yapar.
freeRegister(const std::string& registerName): Kullanılmayan kayıtları serbest bırakır.
Bellek yönetimi için yeni metotlar:
manageMemory(): Genel bellek yönetimini yapar.
allocateMemory(int size): Belirli bir boyuta sahip bellek alanı ayırır.
deallocateMemory(const std::string& variableName): Değişken için ayrılan belleği serbest bırakır.
Kontrol akışı optimizasyonu için yeni metotlar:
applyBranchPrediction(): Dal tahminini uygular.
performLoopUnrolling(): Döngü açılımını gerçekleştirir.
Özel makine kodu üreten metotlar ekledik:
generateLoadInstruction
generateStoreInstruction
generateArithmeticInstruction
generateJumpInstruction
generateConditionalJumpInstruction
Hata raporlama için metot ekledik:
reportCodeEmissionError
*/