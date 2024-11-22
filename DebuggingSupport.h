#pragma once

#include <string>
#include <vector>
#include <unordered_map>

class DebuggingSupport {
private:
    bool isDebuggingModeActive;
    std::vector<std::string> errorHistory;
    std::unordered_map<std::string, int> errorCounts;
    std::unordered_map<std::string, std::vector<int>> errorLines;

public:
    DebuggingSupport();
    
    // Debugging modunu etkinleştirme ve devre dışı bırakma
    void enableDebuggingMode();
    void disableDebuggingMode();
    
    // Hata mesajları ve konumlandırma bilgileri
    void printErrorMessage(const std::string& errorMessage, const std::string& fileName, int lineNumber);
    
    // Debugging sırasında hata konumlandırma bilgileri
    void locateErrorPosition(const std::string& errorMessage, const std::string& fileName, int lineNumber);
    
    // Hata takibi ve analizi
    void trackError(const std::string& errorMessage, const std::string& fileName, int lineNumber);
    int getErrorCount(const std::string& errorMessage);
    std::vector<int> getErrorLines(const std::string& errorMessage, const std::string& fileName);
    
    // Debugging bilgileri
    void printDebugInfo(const std::string& message);
    void printVariableValue(const std::string& variableName, const std::string& value);
    
    // Breakpoint yönetimi
    void setBreakpoint(const std::string& fileName, int lineNumber);
    void removeBreakpoint(const std::string& fileName, int lineNumber);
    bool isBreakpointReached(const std::string& fileName, int lineNumber);
    
    // Step-by-step execution
    void stepInto();
    void stepOver();
    void stepOut();
    
    // Watchpoint yönetimi
    void setWatchpoint(const std::string& variableName);
    void removeWatchpoint(const std::string& variableName);
    bool isWatchpointTriggered(const std::string& variableName);
    
    // Hata raporlama
    void reportDebuggingError(const std::string& message);
};

/*
Private üyeler:
isDebuggingModeActive: Debugging modunun etkin olup olmadığını tutar.
errorHistory: Hata geçmişini tutar.
errorCounts: Hata sayılarını tutar.
errorLines: Hata satırlarını tutar.
Constructor ekledik:
DebuggingSupport(): Sınıfın başlangıç durumunu ayarlar.
Debugging modunu etkinleştirme ve devre dışı bırakma için yeni metotlar ekledik:
enableDebuggingMode()
disableDebuggingMode()
Hata takibi ve analizi için yeni metotlar ekledik:
trackError: Hataları takip eder.
getErrorCount: Belirli bir hata türünün sayısını döndürür.
getErrorLines: Belirli bir hata türünün görüldüğü satırları döndürür.
Debugging bilgileri için yeni metotlar ekledik:
printDebugInfo: Debugging bilgileri yazdırır.
printVariableValue: Değişken değerlerini yazdırır.
Breakpoint yönetimi için yeni metotlar ekledik:
setBreakpoint: Breakpoint ayarlar.
removeBreakpoint: Breakpoint kaldırır.
isBreakpointReached: Breakpoint'e ulaşıldığını kontrol eder.
Step-by-step execution için yeni metotlar ekledik:
stepInto(): Bir adım ilerler.
stepOver(): Bir satır atlar.
stepOut(): Fonksiyonun sonuna kadar ilerler.
Watchpoint yönetimi için yeni metotlar ekledik:
setWatchpoint: Watchpoint ayarlar.
removeWatchpoint: Watchpoint kaldırır.
isWatchpointTriggered: Watchpoint'in tetiklendiğini kontrol eder.
Hata raporlama için metot ekledik:
reportDebuggingError
*/