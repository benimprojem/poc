#include "MemoryManager.h"
#include <iostream>
#include <cstdlib>  // malloc, free, calloc, realloc

void* MemoryManager::memloc(size_t size) {
    void* ptr = malloc(size);  // Belirtilen boyutta bellek ayır
    if (!ptr) {
        std::cerr << "Memory allocation failed!" << std::endl;
        exit(1);
    }
    return ptr;  // Ayırılan bellek adresini döndür
}

void MemoryManager::free(void* ptr) {
    ::free(ptr);  // Belirtilen bellek adresini serbest bırak
}

void* MemoryManager::memcal(size_t num, size_t size) {
    void* ptr = calloc(num, size);  // Belirtilen boyutta bellek ayır ve sıfırla
    if (!ptr) {
        std::cerr << "Memory allocation failed!" << std::endl;
        exit(1);
    }
    return ptr;  // Ayırılan bellek adresini döndür
}

void* MemoryManager::memreal(void* ptr, size_t new_size) {
    void* new_ptr = realloc(ptr, new_size);  // Mevcut belleği yeni boyuta ayarla
    if (!new_ptr) {
        std::cerr << "Memory reallocation failed!" << std::endl;
        exit(1);
    }
    return new_ptr;  // Yeni bellek adresini döndür
}

// Diğer fonksiyonların implementasyonları... 