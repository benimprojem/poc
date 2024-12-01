#include <iostream>
#include "Compiler.h"
#include "fnpi_compiler.h"


int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }
    
    Compiler compiler;
    compiler.compile(argv[1]);
    
    return 0;
} 