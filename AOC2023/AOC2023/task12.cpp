#include "input.h"
#include "task12.h"

void Task12::Part1() {
	auto input = Utility::ReadAllLinesInFile("inputs/input12.txt");
	int res = 0;

	for (auto line : input) {
		std::string records = line.substr(0, line.size() - (line.size() - line.find(' ')));
		std::vector<int64_t> numbers = Utility::SplitStringByCommasAsInt64_t(line.substr(line.find(' '), line.size()));
	}
	std::cout << res;
}

//7032 is the answer

void Task12::Part2() {
	std::cout << "Not done yet.";
}