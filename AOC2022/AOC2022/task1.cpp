#include "input.h"
#include "task1.h"

void Task1::Part1(){
	auto input = Utility::ReadAllLinesInFile("inputs/input1.txt");
	int64_t max = 0;
	int64_t currentElf = 0;
	for (auto& line : input) {
		if (line.empty()) {
			if (currentElf > max) {
				max = currentElf;
			}
			currentElf = 0;
			continue;
		}
		currentElf += stoi(line);
	}
	std::cout << max;
}

void Task1::Part2() {
	auto input = Utility::ReadAllLinesInFile("inputs/input1.txt");
	int64_t max = 0;
	int64_t max2 = 0;
	int64_t max3 = 0;
	int64_t currentElf = 0;
	for (auto& line : input) {
		if (line.empty()) {
			if (currentElf > max) {
				max3 = max2;
				max2 = max;
				max = currentElf;
			}
			else if (currentElf > max2){
				max3 = max2;
				max2 = currentElf;
			}
			else if (currentElf > max3){
				max3 = currentElf;
			}
			currentElf = 0;
			continue;
		}
		currentElf += stoi(line);
	}
	std::cout << max + max2 + max3;
}