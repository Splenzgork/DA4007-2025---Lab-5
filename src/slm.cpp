#include "slm.h"
#include "rng.h"
#include <iostream>
#include <stdexcept>
#include <algorithm>


SLM::SLM(int k) : k_(k), rng_() {
    if (k <= 0) {
        throw std::invalid_argument("Provide a positive k value.");
    }
} 


void SLM::train(const std::string& text) {
    int l = text.size();
    if (l < k_ + 1) {
        throw std::invalid_argument("Text length must be bigger than k.");
    }

    for (int i = 0; i <= l - k_ - 1; i++) {
        std::string kgram = text.substr(i, k_);
        char next = text[i + k_];

        k_counts[kgram][next]++;
        k_totals[kgram]++;
    }
} 


std::string SLM::start() {
    if (k_totals.empty()) {
        throw std::runtime_error("Model has not been trained.");
    }

    std::vector<std::string> kgrams;
    std::vector<double> weights;

    for (const auto& pair : k_totals) {
        kgrams.push_back(pair.first);
        weights.push_back(static_cast<double>(pair.second));
    }

    return rng_.Item(kgrams, weights);
} 


char SLM::next(const std::string& kgram) {
    auto it = k_counts.find(kgram);
    if (it == k_counts.end()) {
        throw std::invalid_argument("K-gram not found in model.");
    }

    const auto& next_map = it->second;
    std::vector<char> next_chars;
    std::vector<double> weights;

    for (const auto& pair : next_map) {
        next_chars.push_back(pair.first);
        weights.push_back(static_cast<double>(pair.second));
    }

    return rng_.Item(next_chars, weights);
} 


std::string SLM::gen_text(int length) {
    if (length <= 0) {
        return "";
    }

    std::string result;
    std::string ch = start();
    
    for (int i=0; i < length; i++) {
        char next_char = next(ch);
        result += next_char;
        ch = ch.substr(1) + next_char;
    }
    return result;
} 