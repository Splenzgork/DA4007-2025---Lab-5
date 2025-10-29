#include <iostream>
#include "slm.h"
#include <fstream>
#include <sstream>

// Read the entire content of a file into a string:
std::string read_file(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        throw std::runtime_error("Could not open file: " + filename);
    }
    std::stringstream buf;
    buf << file.rdbuf();
    return buf.str();
} 

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <k> <filename> <length>" << std::endl;
        exit(1);
    }

    int k = std::stoi(argv[1]);
    std::string filename = argv[2];
    int length = std::stoi(argv[3]);
    try {
        std::string text = read_file(filename);

        SLM slm(k);
        slm.train(text);

        std::string new_text = slm.gen_text(length);
        std::cout << new_text << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        exit(1);
    }
} 

