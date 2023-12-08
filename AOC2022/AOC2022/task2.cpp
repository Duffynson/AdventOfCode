#include "input.h"
#include "task2.h"

std::map < std::string, int> results = {
	{"A X", 4},
	{"B X", 1},
	{"C X", 7},
	{"A Y", 8},
	{"B Y", 5},
	{"C Y", 2},
	{"A Z", 3},
	{"B Z", 9},
	{"C Z", 6},
};

void Task2::Part1() {
	auto input = Utility::ReadAllLinesInFile("inputs/input2.txt");
	int res = 0;
	for (auto& line : input) {
		int points = results.find(line)->second;
		res += points;
	}
	std::cout << res;
}

std::map < std::string, int> results2 = {
	{"A X", 3},
	{"B X", 1},
	{"C X", 2},
	{"A Y", 4},
	{"B Y", 5},
	{"C Y", 6},
	{"A Z", 8},
	{"B Z", 9},
	{"C Z", 7},
};

void Task2::Part2() {
	auto input = Utility::ReadAllLinesInFile("inputs/input2.txt");
	int res = 0;
	for (auto& line : input) {
		int points = results2.find(line)->second;
		res += points;
	}
	std::cout << res;
}