#include "utils/parser.h"

std::vector<std::string> ReadAllLinesInFile(const std::filesystem::path& path) {
    auto lines = std::vector<std::string>{};
    if (!std::filesystem::exists(path)) {
        return lines;
    }

    auto fileStream = std::ifstream{ path };
    auto currentLine = std::string{};
    while (std::getline(fileStream, currentLine)) {
        lines.emplace_back(currentLine);
    }

    return lines;
}

void parseStringToVectors(const std::string& str, std::vector<int>& left, std::vector<int>& right) {
    std::istringstream stream(str);
    int first, second;

    if (stream >> first >> second) {
        left.push_back(first);
        right.push_back(second);
    }
    else {
        throw std::runtime_error("Invalid format: " + str);
    }
}

void parseStringsToSeparateVectors(const std::vector<std::string>& strings, std::vector<int>& left, std::vector<int>& right) {
    for (const auto& str : strings) {
        parseStringToVectors(str, left, right);
    }
}

std::vector<int> stringToVectorOfInts(const std::string& str) {
    std::istringstream stream(str);
    std::vector<int> numbers;
    int number;

    while (stream >> number) {
        numbers.push_back(number);
    }

    return numbers;
}

std::vector<std::vector<int>> convertStringsToIntVectors(const std::vector<std::string>& strings) {
    std::vector<std::vector<int>> result;

    for (const auto& str : strings) {
        result.push_back(stringToVectorOfInts(str));
    }

    return result;
}