#pragma once

#include <string>
#include <unordered_map>
#include <vector>

class RuntimeEnvironment {
private:
    std::unordered_map<std::string, void*> loadedModules;
    std::vector<std::string> systemCallHistory;
    std::unordered_map<std::string, int> errorCounts;
    bool isDebuggingEnabled;
    std::unordered_map<std::string, double> performanceProfile;

public:
    RuntimeEnvironment();
    
    // Çalışma zamanı ortamını başlatır
    void initializeRuntime();
    
    // Standart kütüphane modülleri
    void loadStandardLibraries();
    void loadCustomModule(const std::string& moduleName);
    void unloadModule(const std::string& moduleName);
    
    // Sistem çağrıları
    void handleSystemCalls(const std::string& instruction);
    std::string getSystemCallHistory();
    
    // Hata yönetimi
    void manageErrors(const std::string& errorType);
    int getErrorCount(const std::string& errorType);
    
    // Debugging desteği
    void enableDebuggingMode();
    void disableDebuggingMode();
    bool isDebuggingModeEnabled();
    
    // Performans profili
    void collectPerformanceProfile(const std::string& operation);
    double getOperationTime(const std::string& operation);
    void resetPerformanceProfile();
    
    // Bellek yönetimi
    void* allocateMemory(size_t size);
    void freeMemory(void* ptr);
    
    // Girdi/Çıktı işlemleri
    std::string readInput();
    void writeOutput(const std::string& output);
    
    // Hata raporlama
    void reportRuntimeError(const std::string& message);
    
    // Özel çalışma zamanı işlemleri
    void executeFunction(const std::string& functionName);
    void executeScript(const std::string& script);
};

/*
Private üyeler:
loadedModules: Yüklü modülleri tutar.
systemCallHistory: Sistem çağrılarını tutar.
errorCounts: Hata sayılarını tutar.
isDebuggingEnabled: Debugging modunun etkin olup olmadığını tutar.
performanceProfile: Performans profili bilgilerini tutar.
Constructor ekledik:
RuntimeEnvironment(): Sınıfın başlangıç durumunu ayarlar.
Modül yönetimi için yeni metotlar ekledik:
loadCustomModule: Özel modülleri yükler.
unloadModule: Modülleri kaldırır.
Sistem çağrıları için yeni metot ekledik:
getSystemCallHistory: Sistem çağrı geçmişini döndürür.
Hata yönetimi için yeni metot ekledik:
getErrorCount: Belirli bir hata türünün sayısını döndürür.
Debugging desteği için yeni metotlar ekledik:
disableDebuggingMode: Debugging modunu devre dışı bırakır.
isDebuggingModeEnabled: Debugging modunun etkin olup olmadığını kontrol eder.
Performans profili için yeni metotlar ekledik:
getOperationTime: Belirli bir işlemin süresini döndürür.
resetPerformanceProfile: Performans profilini sıfırlar.
Bellek yönetimi için yeni metotlar ekledik:
allocateMemory: Bellek ayırır.
freeMemory: Belleği serbest bırakır.
Girdi/Çıktı işlemleri için yeni metotlar ekledik:
readInput: Kullanıcı girdisini okur.
writeOutput: Çıktıyı yazar.
Hata raporlama için metot ekledik:
reportRuntimeError
Özel çalışma zamanı işlemleri için yeni metotlar ekledik:
executeFunction: Belirli bir fonksiyonu çalıştırır.
executeScript: Belirli bir betiği çalıştırır.
*/