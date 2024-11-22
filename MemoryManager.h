#pragma once

#include <string>
#include <unordered_map>
#include <vector>

class MemoryManager {
private:
    std::unordered_map<std::string, int> memoryLayout;
    std::vector<std::string> allocatedObjects;
    int totalMemoryUsed;

public:
    MemoryManager();
    
    // Bellek tahsisi
    int allocateMemory(const std::string& objectCode);
    
    // Bellek tahsisi ve serbest bırakma
    void deallocateMemory(const std::string& objectCode);
    
    // Garbage collection (isteğe bağlı)
    void performGarbageCollection();
    
    // Bellek yönetiminden obje koduna çevirme
    std::string convertToObjectCode(const std::string& memoryOperations);
    
    // Bellek istatistikleri
    int getTotalMemoryUsed() const;
    int getAvailableMemory() const;
    std::vector<std::string> getAllocatedObjects() const;
    
    // Bellek yönetimi optimizasyonu
    void optimizeMemoryAllocation();
    void compactMemory();
    
    // Hata raporlama
    void reportMemoryError(const std::string& message);
    
    // Bellek yönetimi için yardımcı metotlar
    int calculateMemorySize(const std::string& objectCode);
    bool isMemoryAvailable(int size);
    void updateMemoryLayout(const std::string& objectCode, int size);
};


/*
Private üyeler:
memoryLayout: Bellek düzenini tutar.
allocatedObjects: Tahsis edilen nesneleri tutar.
totalMemoryUsed: Toplam kullanılan bellek miktarını tutar.
Constructor ekledik:
MemoryManager(): Sınıfın başlangıç durumunu ayarlar.
Bellek tahsisi için metot güncellendi:
allocateMemory(const std::string& objectCode): Bellek tahsis eder ve tahsis edilen belleğin başlangıç adresini döndürür.
Bellek istatistikleri için yeni metotlar ekledik:
getTotalMemoryUsed(): Toplam kullanılan bellek miktarını döndürür.
getAvailableMemory(): Kullanılabilir bellek miktarını döndürür.
getAllocatedObjects(): Tahsis edilen nesnelerin listesini döndürür.
Bellek yönetimi optimizasyonu için yeni metotlar ekledik:
optimizeMemoryAllocation(): Bellek tahsisini optimize eder.
compactMemory(): Belleği sıkıştırır.
Hata raporlama için metot ekledik:
reportMemoryError
Bellek yönetimi için yardımcı metotlar ekledik:
calculateMemorySize: Nesnenin bellek boyutunu hesaplar.
isMemoryAvailable: Belirli bir boyutta bellek olup olmadığını kontrol eder.
updateMemoryLayout: Bellek düzenini günceller.

*/