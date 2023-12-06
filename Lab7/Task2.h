#pragma once
std::map<char, size_t> computeFrequency(std::string& filename, size_t& totalNum);
void printFrequency(std::map<char, size_t> frequencies, size_t totalNum);