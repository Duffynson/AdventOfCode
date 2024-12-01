#pragma once
#include "../stdc++.h"

std::vector<std::string> ReadAllLinesInFile(const std::filesystem::path& path);
void parseStringToVectors(const std::string& str, std::vector<int>& left, std::vector<int>& right);
void parseStringsToSeparateVectors(const std::vector<std::string>& strings, std::vector<int>& left, std::vector<int>& right);


//template<typename T>
//std::vector<T> parseLine(const std::string& line, char delimeter) {
//	std::vector<T> result;
//	std::istringstream stream(line);
//	std::string token;
//
//	while (std::getline(stream, token, delimeter)) {
//        if constexpr (std::is_same_v<T, std::string>) {
//            result.push_back(token);
//        }
//        else {
//            try {
//                if constexpr (std::is_integral_v<T>) {
//                    result.push_back(std::stoi(token));
//                }
//                else if constexpr (std::is_floating_point_v<T>) {
//                    result.push_back(std::stof(token));
//                }
//                else {
//                    throw std::invalid_argument("Unsupported type");
//                }
//            }
//            catch (const std::exception& e) {
//                throw std::runtime_error("Failed to convert token: " + token);
//            }
//        }
//    }
//
//    return result;
//}
//
//
//template<typename T>
//std::vector<T> parseFileToLines(const std::string& filename) {
//    std::vector<std::vector<T>> parsedData;
//    std::ifstream file(filename);
//
//    if (!file.is_open()) {
//        throw std::runtime_error("Could not open file: " + filename);
//    }
//
//    std::string line;
//    while (std::getline(file, line)) {
//        parsedData.push_back(parseLine<T>(line, delimiter));
//    }
//
//    return parsedData;
//}