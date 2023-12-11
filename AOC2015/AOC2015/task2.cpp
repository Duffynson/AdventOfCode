#include "input.h"
#include "task2.h"

void Task2::Part1() {
	auto input = Utility::ReadAllLinesInFile("inputs/input2.txt");
	int res = 0;
	for (auto& line : input) {
		std::replace(line.begin(), line.end(), 'x', ' ');
	 }
	auto inputInts = Utility::SplitLinesAsInt64_t(input);
	for (auto line : inputInts) {
		int length = line[0];
		int width = line[1];
		int height = line[2];
		int a = length * width;
		int b = width * height;
		int c = height * length;
		int lowest = a;
		if (lowest > b)
			lowest = b;
		if (lowest > c)
			lowest = c;
		
		res += (2*a) + (2*b) + (2*c);
		res += lowest;
	}
	std::cout << res;
}

void Task2::Part2() {
	auto input = Utility::ReadAllLinesInFile("inputs/input2.txt");
	int res = 0;
	for (auto& line : input) {
		std::replace(line.begin(), line.end(), 'x', ' ');
	}
	auto inputInts = Utility::SplitLinesAsInt64_t(input);
	for (auto line : inputInts) {
		int length = line[0];
		int width = line[1];
		int height = line[2];
		std::sort(line.begin(), line.end());
		int lowest = line[0];
		int secondLowest = line[1];
		res += length * width * height;
		res += (2 * lowest) + (2 * secondLowest);
	}
	std::cout << res;
}