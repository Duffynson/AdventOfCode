#pragma once
#include "utils/parser.h"

class Day {
public:
	Day(){}
	virtual void Task1() const = 0;
	virtual void Task2() const = 0;

protected:
	std::vector<std::string> input = ReadAllLinesInFile("input.txt");
};