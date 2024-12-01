#ifndef PERFORMANCE_H
#define PERFORMANCE_H

#include <iostream>
#include <chrono>
#include <vector>
#include "IRGenerator.h"

class Performance {
public:
    void start_profiling();
    void end_profiling();
    void print_profile_results();

private:
    std::chrono::steady_clock::time_point start_time;
    std::chrono::steady_clock::time_point end_time;
    std::vector<std::chrono::steady_clock::time_point> instruction_times;
};

#endif // PERFORMANCE_H
