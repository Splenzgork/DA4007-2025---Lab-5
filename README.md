# Small Language Model (SLM) – “Artificial Idiot”

# Overview
This C++ software implements a *Small Language Model (SLM)* that generates random text based on statistical patterns learned from an input text. It operates on *k-grams* — sequences of `k` characters — and predicts the next character based on the frequency distribution of characters that follow each *k-gram*.  

The project uses two main classes:
- `SLM`: Reads text, collects k-gram counts and next-character distributions, and generates text.
- `RandomGenerator`: Wraps a random number generator and provides methods for weighted sampling.

---------------------------------------------------------------------------------------------------------------------

# How It Works

1. # Training
   - For a given text and k-gram length `k`, the model scans the text for all overlapping k-grams.
   - For each k-gram `w`, it records:
     - `n(w)` = total occurrences of `w`
     - `n(w, c)` = number of times character `c` follows `w`
   - The conditional probability distribution over character is estimated as:

     P(c | w) = n(w, c) / n(w)

2. # Text Generation
   - Randomly select a starting k-gram based on frequency.
   - Iteratively sample the next character using `RandomGenerator` according to the learned probabilities.
   - Slide the k-gram window by one character and repeat until the desired output length is reached.

---------------------------------------------------------------------------------------------------------------------

# Compilation

From the `src` directory run:

make

This produces an slm executable. 

To clean up object files and the executable run:

make clean

# Usage

./slm k filename length

Arguments:

k – Length of k-gram (integer > 0)

filename – Text file to train the model on

length – Number of characters to generate 

---------------------------------------------------------------------------------------------------------------------

# Requirements

-C++17 or later

-Unix environment