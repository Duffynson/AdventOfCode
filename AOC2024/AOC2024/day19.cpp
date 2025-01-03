#include "day19.h"

std::string trim(const std::string& str) {
    size_t start = str.find_first_not_of(" \t");
    size_t end = str.find_last_not_of(" \t");
    return (start == std::string::npos) ? "" : str.substr(start, end - start + 1);
}

std::set<std::string> splitString(const std::string& string, char delimiter) {
    std::set<std::string> result;
    std::stringstream ss(string);
    std::string token;

    while (std::getline(ss, token, delimiter)) {
        result.insert(trim(token));
    }

    return result;
}

std::map<std::string, bool> designPossibleCache;

bool isPossible(std::string design, const std::set<std::string>& patterns) {
    if (design == "") return true;
    if (designPossibleCache.find(design) != designPossibleCache.end()) {
        return designPossibleCache[design];
    }
    for (const auto& pattern : patterns) {
        if (design.starts_with(pattern) && isPossible(design.substr(pattern.size()), patterns)) {
            designPossibleCache[design] = true;
            return true;
        }
    }
    designPossibleCache[design] = false;
    return false;
}

std::map<std::string, int64_t> designsCountCache;

int64_t countPossible(const std::string& design, const std::set<std::string>& patterns) {
    if (design == "") return 1;
    if (designsCountCache.find(design) != designsCountCache.end()) {
        return designsCountCache[design];
    }
    int64_t count = 0;
    for (const auto& pattern : patterns) {
        if (design.starts_with(pattern)) {
            count += countPossible(design.substr(pattern.size()), patterns);
        }
    }
    designsCountCache[design] = count;
    return count;
}


void Day19::Task1() const {
	int result = 0;
	std::vector<std::string> firstPart;
	std::vector<std::string> designs;
    splitByEmptyLine(input, firstPart, designs);
    auto patterns = splitString(firstPart[0], ',');
    for (auto& design : designs) {
        if (isPossible(design, patterns)) {
            result++;
        }
    }
	std::cout << result << std::endl;
}

void Day19::Task2() const {
    int64_t result = 0;
    std::vector<std::string> firstPart;
    std::vector<std::string> designs;
    splitByEmptyLine(input, firstPart, designs);
    auto patterns = splitString(firstPart[0], ',');
    for (auto& design : designs) {
        result += countPossible(design, patterns);
    }
    std::cout << result << std::endl;
}