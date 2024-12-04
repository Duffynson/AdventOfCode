#include "day3.h"

std::vector<std::pair<int, int>> extractAllMulArguments(const std::vector<std::string>& lines, bool doSkip);

void Day3::Task1() const {
	int result = 0;
	auto lines = ReadAllLinesInFile("inputs/input3.txt");
	auto input = extractAllMulArguments(lines, true);
	for (const auto& [x, y] : input) {
		result += x * y;
	}
	std::cout << result << std::endl;
}

void Day3::Task2() const {
	int result = 0;
	auto lines = ReadAllLinesInFile("inputs/input3.txt");
	auto input = extractAllMulArguments(lines, false);
	for (const auto& [x, y] : input) {
		result += x * y;
	}
	std::cout << result << std::endl;
}

std::vector<std::pair<int, int>> extractAllMulArguments(const std::vector<std::string>& lines, bool doSkip) {
    std::regex regexPattern(R"(mul\((\d{1,3}),\s*(\d{1,3})\))");
    std::vector<std::pair<int, int>> results;
    bool enabled = true;
    for (auto line : lines) {
        std::smatch match;

        while (std::regex_search(line, match, regexPattern)) {
            int x = std::stoi(match[1].str());
            int y = std::stoi(match[2].str());

            auto prefixString = match.prefix().str();
            auto doPosition = int(prefixString.rfind("do()"));
            auto dontPosition = int(prefixString.rfind("don't()"));
            if (doPosition > dontPosition) {
                enabled = true;
            }
            if (dontPosition > doPosition) {
                enabled = false;
            }
            if (enabled || doSkip) {
                results.emplace_back(x, y);
            }
            line = match.suffix().str();
        }
    }

    return results;
}