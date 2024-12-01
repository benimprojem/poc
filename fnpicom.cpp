#include <iostream>
#include <fstream>
#include <string>
#include "Compiler.h"

using namespace std;

int main() {
    Compiler compiler;
    compiler.compile("example.pi");
    return 0;
}
