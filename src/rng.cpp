#include "rng.h"

RandomGenerator::RandomGenerator() {
    std::random_device r;
    rng = std::mt19937(r());
} 

int RandomGenerator::Index(const std::vector<double>& weights) {
    std::vector<double> w = weights;

    double sum = 0.0;
    for (double norm_w: w) {
        sum += norm_w;
    }

    for (double& norm_w : w) {
        norm_w /= sum;
    }

    std::discrete_distribution<int> dist(w.begin(), w.end());
    return dist(rng);
}

