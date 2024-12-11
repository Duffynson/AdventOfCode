#include "day2.h"

void Day2::Task1() const {
	auto input = ReadAllLinesInFile("input.txt");
	auto lines = convertStringsToIntVectors(input);
	int result = 0;
	bool ascendingOrDescending = false;
	int difference;
	for (auto& line : lines) {
		bool validLevel = true;
		ascendingOrDescending = (std::is_sorted(line.begin(), line.end()) || std::is_sorted(line.begin(), line.end(), std::greater<int>()));
		for (int i = 0; i < line.size() - 1; i++) {
			difference = abs(line[i] - line[i + 1]);
			if (difference > 3 || difference == 0) {
				validLevel = false;
				break;
			}
		}
		if (validLevel && ascendingOrDescending) {
			result++;
		}
	}
	std::cout << result << std::endl;
}

void Day2::Task2() const {
	auto input = ReadAllLinesInFile("input.txt");
	auto lines = convertStringsToIntVectors(input);
	int result = 0;
	bool ascendingOrDescending = false;
	int difference;
	for (auto& line : lines) {
		bool safeLevel = false;
		for (int i = 0; i < line.size(); i++) {
			bool safeDifference = true;
			std::vector<int> subLine;
			subLine.insert(subLine.end(), line.begin(), line.begin() + i);
			subLine.insert(subLine.end(), line.begin() + i + 1, line.end());
			ascendingOrDescending = (std::is_sorted(subLine.begin(), subLine.end()) || std::is_sorted(subLine.begin(), subLine.end(), std::greater<int>()));
			for (int j = 0; j < subLine.size() - 1; j++) {
				difference = abs(subLine[j] - subLine[j + 1]);
				if (difference > 3 || difference == 0) {
					safeDifference = false;
				}
			}
			if (ascendingOrDescending && safeDifference) {
				safeLevel = true;
			}
		}
		if (safeLevel) {
			result++;
		}
	}
	std::cout << result << std::endl;
}