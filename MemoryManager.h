#ifndef MEMORY_MANAGER_H
#define MEMORY_MANAGER_H

#include <string>
#include <unordered_map>

class MemoryManager {
public:
    void* memloc(size_t size);
    void free(void* ptr);
    void* memcal(size_t num, size_t size);
    void* memreal(void* ptr, size_t new_size);
    void* get_address(const std::string& var_name);
    void set_pointer(const std::string& ptr_name, void* address);
    void* get_pointer_value(const std::string& ptr_name);
    
private:
    std::unordered_map<std::string, void*> pointers;
    std::unordered_map<std::string, void*> variables;
};

#endif // MEMORY_MANAGER_H
