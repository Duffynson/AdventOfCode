#include "day16.h"

void Day16::Task1() const {
	int result = 0;
	auto grid = ReadAllLinesInFile("input.txt");

	std::pair<int, int> start;
	std::pair<int, int> end;

	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[i].size(); j++) {
			if (grid[i][j] == 'S') {
				start = { i,j };
			}
			if (grid[i][j] == 'E') {
				end = { i,j };
			}
		}
	}

	std::cout << result << std::endl;
}

void Day16::Task2() const {

}