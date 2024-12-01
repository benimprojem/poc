#include "StringModule.h"
#include <algorithm>

size_t StringModule::len(const std::string& str) {
    return str.length();
}

std::string StringModule::slice(const std::string& str, int start, int end) {
    if (start < 0) start = str.length() + start;
    if (end < 0) end = str.length() + end;
    return str.substr(start, end - start);
}

std::string StringModule::trim(const std::string& str) {
    auto start = str.begin();
    while (start != str.end() && std::isspace(*start)) {
        start++;
    }
    
    auto end = str.end();
    do {
        end--;
    } while (std::distance(start, end) > 0 && std::isspace(*end));
    
    return std::string(start, end + 1);
}

char StringModule::at(const std::string& str, int index) {
    if (index < 0) index = str.length() + index;
    return str.at(index);
}

// UTF-8 fonksiyonlarının implementasyonları... 