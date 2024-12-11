#include "parser.h"

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

std::string ReadOneLineFromFile(const std::filesystem::path& path) {
    if (!std::filesystem::exists(path)) {
        return {}; 
    }

    auto fileStream = std::ifstream{ path };
    auto line = std::string{};
    if (std::getline(fileStream, line)) {
        return line; 
    }

    return {};
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

void splitByEmptyLine(const std::vector<std::string>& input, std::vector<std::string>& firstPart, std::vector<std::string>& secondPart) {
    bool separatorFound = false; 

    for (const auto& line : input) {
        if (line.empty()) {
            separatorFound = true;
            continue;
        }

        if (!separatorFound) {
            firstPart.push_back(line);
        }
        else {
            secondPart.push_back(line);
        }
    }
}

std::vector<std::pair<int, int>> parseToIntPairs(const std::vector<std::string>& input, char delimiter) {
    std::vector<std::pair<int, int>> result;

    for (const auto& str : input) {
        std::istringstream ss(str);
        int x, y;
        char lineDelimiter;

        if (ss >> x >> lineDelimiter >> y && delimiter == lineDelimiter){
            result.emplace_back(x, y);
        }
    }

    return result;
}

std::vector<std::vector<int>> parseToIntVectors(const std::vector<std::string>& input) {
    std::vector<std::vector<int>> result;

    for (const auto& str : input) {
        std::vector<int> numbers;
        std::istringstream ss(str);
        std::string number;

        while (std::getline(ss, number, ',')) {
            numbers.push_back(std::stoi(number));
        }

        result.push_back(numbers);
    }

    return result;
}

std::map<int, std::set<int>> createMap(const std::vector<std::string>& input, char delimeter) {
    std::map<int, std::set<int>> result;

    for (const auto& line : input) {
        auto delimiterPos = line.find(delimeter);
        if (delimiterPos == std::string::npos) {
            continue;
        }

        int x = std::stoi(line.substr(0, delimiterPos));
        int y = std::stoi(line.substr(delimiterPos + 1));

        result[x].insert(y);
       
    }

    return result;
}

void processStrings(const std::vector<std::string>& input,
    std::vector<long long>& beforeColon,
    std::vector<std::vector<long long>>& afterColon) {
    for (const auto& line : input) {
        std::istringstream ss(line);
        std::string part;

        std::getline(ss, part, ':');
        beforeColon.push_back(std::stoll(part));

        std::vector<long long> temp;
        while (ss >> part) {
            temp.push_back(std::stoll(part));
        }

        afterColon.push_back(temp);
    }
}

std::vector<std::vector<int>> parseDigits(const std::vector<std::string>& strings) {
    std::vector<std::vector<int>> result;

    for (const std::string& str : strings) {
        std::vector<int> digits;
        for (char ch : str) {
            if (std::isdigit(ch)) { 
                digits.push_back(ch - '0');
            }
        }
        result.push_back(digits);
    }

    return result;
}

std::vector<long long> stringToVectorOfLongs(const std::string& str) {
    std::istringstream stream(str);
    std::vector<long long> numbers;
    int number;

    while (stream >> number) {
        numbers.push_back(number);
    }

    return numbers;
}
