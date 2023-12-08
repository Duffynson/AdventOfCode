#include "task3.h"
#include "input.h"

void Task3::Part1() {
	auto input = Utility::ReadAllLinesInFile("inputs/input3.txt");
	int rows = input.size();
	int columns = input[0].size();
	long int res = 0;

	for (int y = 0; y < rows; y++) {
		std::string number = "";
		bool adjacent = false;
		for (int x = 0; x < columns; x++) {
			char currentChar = input[y][x];
			if (isdigit(currentChar)) {
				number.push_back(currentChar);
				for (int y1 = y - 1; y1 <= y + 1; y1++) {
					for (int x1 = x - 1; x1 <= x + 1; x1++) {
						if (y1 >= 0 && x1 >= 0 && x1 < rows && y1 < columns) {
							char currChar = input[y1][x1];
							if (currChar != '.' && !(isdigit(currChar)))
								adjacent = true;
						}
					}
				}
			}
			if (number != "" && adjacent && !(isdigit(input[y][x+1])) && x+1 <= columns) {
				res += stoi(number);
				number.clear();
				adjacent = false;
			}
			if (number != "" && !(isdigit(currentChar)))
				number.clear();
		}
	}
	std::cout << res;
	
}

struct Coords {
	int x = 0, y = 0;
};

void Task3::Part2() {
	auto input = Utility::ReadAllLinesInFile("inputs/input3.txt");
	int rows = input.size();
	int columns = input[0].size();
	long int res = 0;
	std::vector<int> numbersStars;
	std::vector<Coords> starsCoords;
	int sameStar = 0;
	Coords starCoords;

	for (int y = 0; y < rows; y++) {
		std::string number = "";
		bool adjacentToStar = false;
		for (int x = 0; x < columns; x++) {
			char currentChar = input[y][x];
			if (isdigit(currentChar)) {
				number.push_back(currentChar);
				for (int y1 = y - 1; y1 <= y + 1; y1++) {
					for (int x1 = x - 1; x1 <= x + 1; x1++) {
						if (y1 >= 0 && x1 >= 0 && x1 < rows && y1 < columns) {
							char currChar = input[y1][x1];
							if (currChar == '*') {
								starCoords = { y1,x1 };
								adjacentToStar = true;
								break;
							}
						}
					}
				}
			}
			if (adjacentToStar && number != "" && !(isdigit(input[y][x + 1])) && x + 1 <= columns) {
				numbersStars.push_back(stoi(number));
				starsCoords.push_back(starCoords);
				adjacentToStar = false;
			}
			if (number != "" && !(isdigit(currentChar)))
				number.clear();
		}
	}

	bool found = true;
	while (starsCoords.size()) {
		auto first = starsCoords[0];
		for (int i = 0; i < starsCoords.size(); i++) {
			auto number = starsCoords[i];
			if (first.x == number.x && first.y == number.y && i != 0) {
				found = true;
				starsCoords.erase(starsCoords.begin() + i);
				if (starsCoords.size() == 1) {
					starsCoords.clear();
				}
				else
					starsCoords.erase(starsCoords.begin() + 0);
				res += numbersStars[0] * numbersStars[i];
				numbersStars.erase(numbersStars.begin() + i);
				if (numbersStars.size() == 1) {
					numbersStars.clear();
				}
				else
					numbersStars.erase(numbersStars.begin() + 0);
				break;
			}
		}
		if (!found) {
			starsCoords.erase(starsCoords.begin() + 0);
			numbersStars.erase(numbersStars.begin() + 0);
		}
		found = false;
	}
	std::cout << res;
}