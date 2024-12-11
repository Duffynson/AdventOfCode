#include "day5.h"

void Day5::Task1() const {
	int result = 0;
	auto input = ReadAllLinesInFile("inputs/input5.txt");
	std::vector<std::string> rulesStrings, updatesStrings;
	splitByEmptyLine(input, rulesStrings, updatesStrings);
	std::map<int, std::set<int>> rules = createMap(rulesStrings, '|');
	std::vector<std::vector<int>> updates= parseToIntVectors(updatesStrings);
	
	auto comp = [&rules](int a, int b) { return rules[a].contains(b); };

	for (auto update : updates) {
		if (std::is_sorted(update.begin(), update.end(), comp)) {
			result += update[update.size() / 2];
		}
	}

	std::cout << result << std::endl;
}

void Day5::Task2() const {
	int result = 0;
	auto input = ReadAllLinesInFile("inputs/input5.txt");
	std::vector<std::string> rulesStrings, updatesStrings;
	splitByEmptyLine(input, rulesStrings, updatesStrings);
	std::map<int, std::set<int>> rules = createMap(rulesStrings, '|');
	std::vector<std::vector<int>> updates = parseToIntVectors(updatesStrings);

	auto comp = [&rules](int a, int b) { return rules[a].contains(b); };

	for (auto update : updates) {
		if (!(std::is_sorted(update.begin(), update.end(), comp))) {
			std::sort(update.begin(), update.end(), comp);
			result += update[update.size() / 2];
		}
	}

	std::cout << result << std::endl;
}

