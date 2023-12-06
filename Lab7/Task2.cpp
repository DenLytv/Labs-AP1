#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "Task2.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Too many arguments!" << std::endl;
        return 1;
    }
    std::string filename = argv[1];
    size_t totalNum = 0;
    std::map<char, size_t> frequencies = computeFrequency(filename, totalNum);
    printFrequency(frequencies, totalNum);
    return 0;
}

std::map<char, size_t> computeFrequency(std::string& filename, size_t& totalNum) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }
    std::string line = "";
    std::map<char, size_t> frequencies{};
    while (getline(file, line)) 
    {
        for (const char& ch : line) 
        {
            if (ispunct(ch)) 
            {
                ++frequencies[ch];
                ++totalNum;
            }
        }
    }
    file.close();
    return frequencies;
}

void printFrequency(std::map<char, size_t> frequencies, size_t totalNum) 
{
    std::cout << "Frequency of punctuation marks:" << std::endl;
    for (const auto& pair : frequencies)
    {
        char ch = pair.first;
        int count = pair.second;
        double percentage = (static_cast<double>(count) / totalNum) * 100;

        std::cout << ch << " : " << count << " (" << percentage << "%)" << std::endl;
    }
}