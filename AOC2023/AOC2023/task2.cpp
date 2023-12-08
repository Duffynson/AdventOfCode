#include "input.h"
#include "task2.h"

struct Game {
	int blue = 0, red = 0, green = 0;
};

void Task2::Part1() {
	int res = 0;
	int redCap = 12, greenCap = 13, blueCap = 14;
	int currGame = 0;
	bool isViable = true;
	
	auto input = Utility::ReadAllLinesInFile("inputs/input2.txt");
	for (auto line : input) {
		int currentWord = 0;
		bool isFirst = true;
		int currNumber = 0;
		std::string currColour = "";
		std::istringstream iss(line);
		std::string word;
		while (iss >> word) {
			currentWord++;
			if (currentWord % 2 == 1 && !isFirst) {
				currNumber = stoi(word);
			}
			else if (currentWord % 2 == 0 && !isFirst) {
				currColour = word;
			}
			else if (currentWord == 2 && isFirst) {
				currGame = stoi(word);
				isFirst = false;
			}
			if (currentWord % 2 == 0) {
				if (currColour[0] == 'b') {
					if (currNumber > blueCap) {
						isViable = false;
						break;
					}
				}
				else if (currColour[0] == 'r') {
					if (currNumber > redCap) {
						isViable = false;
						break;
					}
				}
				else if (currColour[0] == 'g') {
					if (currNumber > greenCap) {
						isViable = false;
						break;
					}
				}
			}
		}
		if (isViable)
			res += currGame;
			isViable = true;
	}
	std::cout << res;
}

void Task2::Part2() {
	int res = 0;
	int currGame = 0;

	auto input = Utility::ReadAllLinesInFile("inputs/input2.txt");
	for (auto line : input) {
		int currentWord = 0, blueMax = 0, redMax = 0, greenMax = 0;
		bool isFirst = true;
		int currNumber = 0;
		std::string currColour = "";
		std::istringstream iss(line);
		std::string word;
		while (iss >> word) {
			currentWord++;
			if (currentWord % 2 == 1 && !isFirst) {
				currNumber = stoi(word);
			}
			else if (currentWord % 2 == 0 && !isFirst) {
				currColour = word;
			}
			else if (currentWord == 2 && isFirst) {
				currGame = stoi(word);
				isFirst = false;
			}
			if (currentWord % 2 == 0) {
				if (currColour[0] == 'b') {
					if (currNumber > blueMax) {
						blueMax = currNumber;
					}
				}
				else if (currColour[0] == 'r') {
					if (currNumber > redMax) {
						redMax = currNumber;
					}
				}
				else if (currColour[0] == 'g') {
					if (currNumber > greenMax) {
						greenMax = currNumber;
					}
				}
			}
		}
		res += (greenMax * redMax * blueMax);

	}
	std::cout << res;
}