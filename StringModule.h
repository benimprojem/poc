#ifndef STRING_MODULE_H
#define STRING_MODULE_H

#include <string>

class StringModule {
public:
    size_t len(const std::string& str);
    std::string slice(const std::string& str, int start, int end);
    std::string trim(const std::string& str);
    char at(const std::string& str, int index);
    std::string to_utf8(const std::string& str);
    std::string from_utf8(const std::string& str);
};

#endif // STRING_MODULE_H 