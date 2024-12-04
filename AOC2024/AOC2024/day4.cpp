#include "day4.h"

void Day4::Task1() const {
	auto input = ReadAllLinesInFile("inputs/input4.txt");
	int result = 0;

	std::vector<std::pair<int, int>> directions = {
		{-1, -1}, {-1, 0}, {-1, 1},
		{0, -1},         {0, 1}, 
		{1, -1}, {1, 0}, {1, 1}
	};

	for (int x = 0; x < input.size(); x++) {
		for (int y = 0; y < input[x].size(); y++) {
			if (input[x][y] == 'X') {
				for (const auto& [dx, dy] : directions) {
					if (!(x + (dx * 3) < 0 || x + (dx * 3) >= input.size())) {
						if (!(y + (dy * 3) < 0 || y + (dy * 3) >= input[x].size())) {
							if (input[x + dx][y + dy] == 'M' && input[x + (dx * 2)][y + (dy * 2)] == 'A' && input[x + (dx * 3)][y + (dy * 3)] == 'S') {		
								result++;
							}
						}
					}
				}
			}
		}
	}
	std::cout << result << std::endl;
}

void Day4::Task2() const {
	auto input = ReadAllLinesInFile("inputs/input4.txt");
	int result = 0;

	std::vector<std::pair<int, int>> directions = {
		{-1, -1}, {-1, 1}
	};

	int charValue = 0;
	for (int x = 0; x < input.size(); x++) {
		for (int y = 0; y < input[x].size(); y++) {
			if (input[x][y] == 'A') {
				charValue = 0;
				for (const auto& [dx, dy] : directions) {
					if (!(x + dx < 0 || x + dx >= input.size()) && !(x + (-dx) < 0 || x + (-dx) >= input.size())) {
						if (!(y + dy < 0 || y + dy >= input[x].size()) && !(y + (-dy) < 0 || y + (-dy) >= input[x].size())) {
							if (input[x + dx][y + dy] == input[x + (-dx)][y + (-dy)]) {
								break;
							}
							charValue += int(input[x + dx][y + dy]);
							charValue += int(input[x + (-dx)][y + (-dy)]);
						}
					}
				}
				if (charValue == int('M') * 2 + int('S') * 2) {
					result++;
				}
			}
		}
	}
	std::cout << result << std::endl;
}