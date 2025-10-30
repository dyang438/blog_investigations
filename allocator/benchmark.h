#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <vector>
#include <iostream>
#include <chrono>
#include <algorithm>
#include "config.h"
#include "ParentClass.h"
#include "ChildClass.h"

template <typename AllocatorType>
void run_benchmark(const char* allocator_name) {
    std::vector<long long> times;

    for (int run = 0; run < NUM_RUNS; run++) {
        auto start = std::chrono::high_resolution_clock::now();

        ParentClass parent = ParentClass("parent_1");
        AllocatorType child_alloc = AllocatorType(ALLOCATOR_CAPACITY);

        for (int i = 0; i < NUM_CHILDREN; i++) {
            std::string child_name = "child_" + std::to_string(i);
            ChildClass* child = child_alloc.allocate();
            if (child == nullptr) {
                std::cout << "Allocator full at " << i << " children\n";
                break;
            }

            new (child) ChildClass(child_name, i, parent);
            child->name_map_insert();
        }

        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        times.push_back(duration.count());
    }

    // Calculate statistics
    long long min_time = *std::min_element(times.begin(), times.end());
    long long max_time = *std::max_element(times.begin(), times.end());
    long long sum = 0;
    for (auto t : times) sum += t;
    long long avg_time = sum / NUM_RUNS;

    std::cout << "\n=== " << allocator_name << " Performance ===\n";
    std::cout << "Runs: " << NUM_RUNS << "\n";
    std::cout << "Min:  " << min_time << " µs\n";
    std::cout << "Max:  " << max_time << " µs\n";
    std::cout << "Avg:  " << avg_time << " µs\n";
}

#endif // BENCHMARK_H
