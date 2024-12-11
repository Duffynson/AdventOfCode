#include "day7.h"

bool solvePart1(long long target, std::vector<long long> numbers) {
	if (numbers.size() == 1) {
		return target == numbers[0];
	}
	long long a = numbers[0];
	long long b = numbers[1];
	std::vector<long long> x(numbers.begin() + 2, numbers.end());
	std::vector<long long> sum = { a + b };
	std::vector<long long> mul = { a * b };
	std::vector<long long> sumNumbers(sum.begin(), sum.end());
	std::vector<long long> mulNumbers(mul.begin(), mul.end());
	sumNumbers.insert(sumNumbers.end(), x.begin(), x.end());
	mulNumbers.insert(mulNumbers.end(), x.begin(), x.end());
	return solvePart1(target, sumNumbers) || solvePart1(target, mulNumbers);
}

bool solvePart2(long long target, std::vector<long long> numbers) {
	if (numbers.size() == 1) {
		return target == numbers[0];
	}
	long long a = numbers[0];
	long long b = numbers[1];
	std::vector<long long> x(numbers.begin() + 2, numbers.end());
	std::vector<long long> sum = { a + b };
	std::vector<long long> mul = { a * b };
	std::string as = std::to_string(a);
	std::string bs = std::to_string(b);
	std::string abs = as + bs;
	std::vector<long long> con = { std::stoll(abs) };
	std::vector<long long> sumNumbers(sum.begin(), sum.end());
	std::vector<long long> mulNumbers(mul.begin(), mul.end());
	std::vector<long long> conNumbers(con.begin(), con.end());
	sumNumbers.insert(sumNumbers.end(), x.begin(), x.end());
	mulNumbers.insert(mulNumbers.end(), x.begin(), x.end());
	conNumbers.insert(conNumbers.end(), x.begin(), x.end());
	return solvePart2(target, sumNumbers) || solvePart2(target, mulNumbers) || solvePart2(target, conNumbers);
}

void Day7::Task1() const {
	long long result = 0;
	auto input = ReadAllLinesInFile("input.txt");
	std::vector<long long> testValues;
	std::vector<std::vector<long long>> numbers;
	processStrings(input, testValues, numbers);
	for (int i = 0; i < testValues.size(); i++) {
		if (solvePart1(testValues[i], numbers[i])) {
			result += testValues[i];
		}
	}
	std::cout << result << std::endl;
}

void Day7::Task2() const {
	long long result = 0;
	auto input = ReadAllLinesInFile("input.txt");
	std::vector<long long> testValues;
	std::vector<std::vector<long long>> numbers;
	processStrings(input, testValues, numbers);
	for (int i = 0; i < testValues.size(); i++) {
		if (solvePart2(testValues[i], numbers[i])) {
			result += testValues[i];
		}
	}
	std::cout << result << std::endl;
}