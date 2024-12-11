#include "day11.h"

void solveDay11(int iterationCount);

void Day11::Task1() const {
	solveDay11(25);
}

void Day11::Task2() const {
	solveDay11(75);
}

void solveDay11(int iterationCount) {
	long long result = 0;
	auto input = ReadOneLineFromFile("input.txt");
	std::vector<long long> stones = stringToVectorOfLongs(input);
	std::unordered_map<long long, long long> stoneCounts;
	for (const auto& stone : stones) {
		stoneCounts[stone]++;
	}
	while (iterationCount > 0) {
		std::unordered_map<long long, long long> currentStoneCounts;
		for (auto [stoneNumber, occurences] : stoneCounts) {
			if (stoneNumber == 0) {
				currentStoneCounts[1] += occurences;
				continue;
			}
			int numberLength = std::floor(std::log10(std::abs(stoneNumber))) + 1;
			if (numberLength % 2 == 0) {
				int middle = pow(10, numberLength / 2);
				currentStoneCounts[stoneNumber / middle] += occurences;
				currentStoneCounts[stoneNumber % middle] += occurences;
				continue;
			}
			currentStoneCounts[stoneNumber * 2024] += occurences;
		}
		stoneCounts = currentStoneCounts;
		iterationCount--;
	}
	for (const auto& [stone, occurences] : stoneCounts) {
		result += occurences;
	}
	std::cout << result << std::endl;
}