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

    // Extract two integers, skipping any extra whitespace
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