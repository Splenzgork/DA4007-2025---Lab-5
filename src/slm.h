// Reads text, collects k-gram counts and next-character distributions, and generates text.

#pragma once
#include <string>
#include <map>
#include <vector>
#include "rng.h"

class RandomGenerator;

class SLM {
public: 
    SLM(int k); // Construct an SLM with k-grams of length k.

    void train(const std::string& text); // Train the SLM on the given text.

    char next(const std::string& kgram); // Generate the next character for the given k-gram.

    std::string gen_text(int length); // Generate text of the given length using the SLM.

private:
    int k_;
    
    std::map<std::string, int> k_totals; // Total counts for each k-gram.
    
    std::map<std::string, std::map<char, int>> k_counts; // Counts of next characters for each k-gram.

    std::string start(); // Get a random k-gram from the trained data to start.
    RandomGenerator rng_; // Random number generator for sampling.
    
};

