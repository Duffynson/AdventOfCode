#pragma once
#include "../stdc++.h"

std::vector<std::string> ReadAllLinesInFile(const std::filesystem::path& path);
void parseStringToVectors(const std::string& str, std::vector<int>& left, std::vector<int>& right);
void parseStringsToSeparateVectors(const std::vector<std::string>& strings, std::vector<int>& left, std::vector<int>& right);
std::vector<int> stringToVectorOfInts(const std::string& str);
std::vector<std::vector<int>> convertStringsToIntVectors(const std::vector<std::string>& strings);