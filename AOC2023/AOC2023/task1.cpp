#include "input.h"
#include "task1.h"

void Task1::Part1(){
	int res = 0;
	std::vector<char> digits;
	auto input = Utility::ReadAllLinesInFile("inputs/input1.txt");
	for (auto line : input) {
		for (auto i : line) {
			if (std::isdigit(i))
				digits.push_back(i);
		}
		char first = digits[0];
		char last = digits[digits.size() - 1];
		std::string tmp = std::string(1,first) + last;
		int temp = std::stoi(tmp);
		res += temp;
		digits.clear();
	}
	std::cout << res;
}

void Task1::Part2() {
	int res = 0;
	std::vector<char> digits;
	auto input = Utility::ReadAllLinesInFile("inputs/input1.txt");
	for (auto line : input) {
		for (int x = 0; x < 3; x++) {
			size_t one = line.find("one");
			if (one != std::string::npos)
				line.replace(one, 3, "o1e");
			size_t two = line.find("two");
			if (two != std::string::npos)
				line.replace(two, 3, "t2o");
			size_t three = line.find("three");
			if (three != std::string::npos)
				line.replace(three, 5, "t3e");
			size_t four = line.find("four");
			if (four != std::string::npos)
				line.replace(four, 4, "f4r");
			size_t five = line.find("five");
			if (five != std::string::npos)
				line.replace(five, 4, "f5e");
			size_t six = line.find("six");
			if (six != std::string::npos)
				line.replace(six, 3, "s6x");
			size_t seven = line.find("seven");
			if (seven != std::string::npos)
				line.replace(seven, 5, "s7n");
			size_t eight = line.find("eight");
			if (eight != std::string::npos)
				line.replace(eight, 5, "e8t");
			size_t nine = line.find("nine");
			if (nine != std::string::npos)
				line.replace(nine, 4, "n9e");
		}

		for (auto i : line) {
			if (std::isdigit(i))
				digits.push_back(i);
		}
		char first = digits[0];
		char last = digits[digits.size() - 1];
		std::string tmp = std::string(1, first) + last;
		int temp = std::stoi(tmp);
		res += temp;
		digits.clear();
	}
	std::cout << res;
}