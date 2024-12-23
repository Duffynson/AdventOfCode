#pragma once
#include "../stdc++.h"

std::vector<std::string> ReadAllLinesInFile(const std::filesystem::path& path);
std::string ReadOneLineFromFile(const std::filesystem::path& path);
void parseStringToVectors(const std::string& str, std::vector<int>& left, std::vector<int>& right);
void parseStringsToSeparateVectors(const std::vector<std::string>& strings, std::vector<int>& left, std::vector<int>& right);
std::vector<int> stringToVectorOfInts(const std::string& str);
std::vector<std::vector<int>> convertStringsToIntVectors(const std::vector<std::string>& strings);
void splitByEmptyLine(const std::vector<std::string>& input, std::vector<std::string>& firstPart, std::vector<std::string>& secondPart);
std::vector<std::pair<int, int>> parseToIntPairs(const std::vector<std::string>& input, char delimiter);
std::vector<std::vector<int>> parseToIntVectors(const std::vector<std::string>& input);
std::map<int, std::set<int>> createMap(const std::vector<std::string>& input, char delimeter);
void processStrings(const std::vector<std::string>& input, std::vector<long long>& beforeColon, std::vector<std::vector<long long>>& afterColon);
std::vector<std::vector<int>> parseDigits(const std::vector<std::string>& strings);
std::vector<long long> stringToVectorOfLongs(const std::string& str);
std::vector<int> parseStringsToVector(const std::vector<std::string>& input);