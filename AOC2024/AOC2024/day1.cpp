#include "day1.h"

void Day1::Task1() const {
	int result = 0;
	auto lines = ReadAllLinesInFile("inputs/input1.txt");
	std::vector<int> leftNumbers;
	std::vector<int> rightNumbers;
	parseStringsToSeparateVectors(lines, leftNumbers, rightNumbers);
	std::sort(leftNumbers.begin(), leftNumbers.end());
	std::sort(rightNumbers.begin(), rightNumbers.end());

	for (size_t i = 0; i < leftNumbers.size(); i++) {
		result += std::abs(leftNumbers[i] - rightNumbers[i]);
	}
	std::cout << result << std::endl;
}

void Day1::Task2() const {
	int result = 0;
	auto lines = ReadAllLinesInFile("inputs/input1.txt");
	std::vector<int> leftNumbers;
	std::vector<int> rightNumbers;
	parseStringsToSeparateVectors(lines, leftNumbers, rightNumbers);
	std::sort(leftNumbers.begin(), leftNumbers.end());

	std::sort(rightNumbers.begin(), rightNumbers.end());

	for (int number : leftNumbers) {
		result += number * std::count(rightNumbers.begin(), rightNumbers.end(), number);
	}
	std::cout << result << std::endl;
}