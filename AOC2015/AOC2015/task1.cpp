#include "input.h"
#include "task1.h"

void Task1::Part1(){
	auto input = Utility::ReadAllLinesInFile("inputs/input1.txt");
	int res = 0;
	for (auto ch : input[0]) {
		if (ch == '(')
			res++;
		else
			res--;
	}
	std::cout << res;
}

void Task1::Part2() {
	auto input = Utility::ReadAllLinesInFile("inputs/input1.txt");
	std::string firstLine = input[0];
	int res = 0;
	for (int i = 0; i < firstLine.size(); i++) {
		if (firstLine[i] == '(')
			res++;
		else
			res--;
		if (res < 0) {
			res = i + 1;
			break;
		}
	}
	std::cout << res;
}