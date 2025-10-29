// Wraps a random number generator and provides methods for weighted sampling.

#pragma once 
#include <random> 
#include <vector>

class RandomGenerator {
public:
    RandomGenerator(); // Initialize the random number generator.
    
    int Index(const std::vector<double>& weights); // Get a sampled index according to the given weights.

    template<typename T>
    T Item(const std::vector<T>& items, const std::vector<double>& weights) {
        int index = Index(weights);
        return items[index];
    } // Get a sampled item according to the given weights.

private:
    std::mt19937 rng; // rng engine

};


