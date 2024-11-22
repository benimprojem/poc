#pragma once

#include <string>
#include <unordered_map>
#include <vector>
#include <chrono>

class PerformanceProfiler {
private:
    bool isProfilingActive;
    std::chrono::steady_clock::time_point profilingStartTime;
    std::unordered_map<std::string, std::chrono::duration<double>> functionExecutionTimes;
    std::unordered_map<std::string, size_t> memoryUsage;
    std::vector<std::string> optimizationSuggestions;

public:
    PerformanceProfiler();
    
    // Profil oluşturma
    void startProfiling();
    void stopProfiling();
    
    // Zaman profili
    void recordFunctionExecution(const std::string& functionName, double executionTime);
    std::string getExecutionTimeReport();
    
    // Bellek profili
    void recordMemoryUsage(const std::string& memoryLocation, size_t usage);
    std::string getMemoryUsageReport();
    
    // Genel performans raporu
    std::string getPerformanceReport();
    
    // Optimizasyon önerileri
    void addOptimizationSuggestion(const std::string& suggestion);
    std::string suggestOptimizations();
    
    // Özel profilleme işlemleri
    void profileFunction(const std::string& functionName);
    void profileMemoryUsage(const std::string& memoryLocation);
    
    // Hata raporlama
    void reportProfilingError(const std::string& message);
};

/*

Private üyeler:
isProfilingActive: Profil oluşturmanın etkin olup olmadığını tutar.
profilingStartTime: Profil oluşturmanın başlangıç zamanını tutar.
functionExecutionTimes: Fonksiyonların çalışma sürelerini tutar.
memoryUsage: Bellek kullanımını tutar.
optimizationSuggestions: Optimizasyon önerilerini tutar.
Constructor ekledik:
PerformanceProfiler(): Sınıfın başlangıç durumunu ayarlar.
Zaman profili için yeni metotlar ekledik:
recordFunctionExecution: Fonksiyon çalışma sürelerini kaydeder.
getExecutionTimeReport: Çalışma süresi raporunu döndürür.
Bellek profili için yeni metotlar ekledik:
recordMemoryUsage: Bellek kullanımını kaydeder.
getMemoryUsageReport: Bellek kullanım raporu döndürür.
Genel performans raporu için mevcut metodu genişlettik:
getPerformanceReport: Hem zaman hem de bellek profillerini içeren genel raporu döndürür.
Optimizasyon önerileri için yeni metot ekledik:
addOptimizationSuggestion: Yeni optimizasyon önerileri ekler.
Özel profilleme işlemleri için yeni metotlar ekledik:
profileFunction: Belirli bir fonksiyonu profiller.
profileMemoryUsage: Belirli bir bellek konumunun kullanımını profiller.
Hata raporlama için metot ekledik:
reportProfilingError

*/