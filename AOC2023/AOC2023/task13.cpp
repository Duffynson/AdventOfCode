#include "input.h"
#include "task13.h"

std::vector<std::string> FlipStringInput(std::vector<std::string> input) {
	std::vector<std::string> flippedInput;
	std::string tempString;
	for (int i = 0; i < input[0].size(); i++) {
		for (int x = 0; x < input.size(); x++) {
			tempString.push_back(input[x][i]);
		}
		flippedInput.push_back(tempString);
		tempString.clear();
	}
	return flippedInput;
}

int DifferentChars(std::string firstString,std::string secondString) {
	int res = 0;
	for (int i = 0; i < firstString.size(); i++) {
		if (firstString[i] != secondString[i]) {
			res++;
		}
	}
	return res;
}

void Task13::Part1() {
	std::vector<std::string> input = Utility::ReadAllLinesInFile("inputs/input13.txt");
	std::vector<std::vector<std::string>> inputByEmptyLine;
	std::vector<std::string> temp;
	int res = 0;
	for (auto line : input) {
		if (line.empty()) {
			inputByEmptyLine.push_back(temp);
			temp.clear();
		}
		else
			temp.push_back(line);
	}

	for (auto pattern : inputByEmptyLine) {
		bool found = false;
		for (int i = 0; i < pattern.size() - 1;i++) {
			bool reflection = true;
			if (pattern[i] == pattern[i + 1]) {
				for (int x = i, y = i + 1; x >= 0 && y < pattern.size(); x--, y++) {
					if (pattern[x] != pattern[y])
						reflection = false;
				}
				if (reflection) {
					found = true;
					res += 100 * (i + 1);
					break;
				}
			}
		}
		if (!found) {
			pattern = FlipStringInput(pattern);
			for (int i = 0; i < pattern.size() - 1; i++) {
				bool reflection = true;
				for (int x = i, y = i + 1; x >= 0 && y < pattern.size(); x--, y++) {
					if (pattern[x] != pattern[y])
						reflection = false;
				}
				if (reflection) {
					res += i + 1;
					break;
				}
			}
		}
		else
			continue;
	}

	std::cout << res;
}

void Task13::Part2() {
	std::vector<std::string> input = Utility::ReadAllLinesInFile("inputs/input13.txt");
	std::vector<std::vector<std::string>> inputByEmptyLine;
	std::vector<std::string> temp;
	int res = 0;

	for (auto line : input) {
		if (line.empty()) {
			inputByEmptyLine.push_back(temp);
			temp.clear();
		}
		else
			temp.push_back(line);
	}

	for (auto pattern : inputByEmptyLine) {
		bool found = false;
		for (int i = 0; i < pattern.size() - 1; i++) {
			bool reflection = true;
			if (pattern[i] == pattern[i + 1]) {
				bool alreadyFound = false;
				for (int x = i, y = i + 1; x >= 0 && y < pattern.size(); x--, y++) {
					if (pattern[x] != pattern[y]) {
						if (DifferentChars(pattern[x], pattern[y]) == 1) {
							alreadyFound = true;
						}
						else {
						reflection = false;
						}
					}
				}
				if (reflection && alreadyFound) {
					found = true;
					res += 100 * (i + 1);
					break;
				}
			}
			else if (DifferentChars(pattern[i], pattern[i + 1]) == 1) {
				bool clean = true;
				for (int x = i - 1, y = i + 2; x >= 0 && y < pattern.size(); x--, y++) {
					if (pattern[x] != pattern[y]) {
						clean = false;
					}
				}
				if (clean) {
					found = true;
					res += 100 * (i + 1);
					break;
				}
			}
		}
		if (!found) {
			pattern = FlipStringInput(pattern);
			for (int i = 0; i < pattern.size() - 1; i++) {
				bool reflection = true;
				if (pattern[i] == pattern[i + 1]) {
					bool alreadyFound = false;
					for (int x = i, y = i + 1; x >= 0 && y < pattern.size(); x--, y++) {
						if (pattern[x] != pattern[y]) {
							if (DifferentChars(pattern[x], pattern[y]) == 1) {
								alreadyFound = true;
							}
							else {
								reflection = false;
							}
						}
					}
					if (reflection && alreadyFound) {
						res += i + 1;
						break;
					}
				}
				else if (DifferentChars(pattern[i], pattern[i + 1]) == 1) {
					bool clean = true;
					for (int x = i - 1, y = i + 2; x >= 0 && y < pattern.size(); x--, y++) {
						if (pattern[x] != pattern[y]) {
							clean = false;
						}
					}
					if (clean) {
						found = true;
						res += i + 1;
						break;
					}
				}
			}
		}
		else
			continue;
	}

	std::cout << res;
}