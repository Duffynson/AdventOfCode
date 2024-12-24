#include "day15.h"

std::map<char, std::pair<int, int>> directionsMap = {
	{'^', {-1,0}},
	{'>', {0,1}},
	{'v', {1,0}},
	{'<', {0,-1}}
};

std::pair<int, int> findRobot(std::vector<std::string> grid) {
	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[i].size(); j++) {
			if (grid[i][j] == '@') {
				return { i,j };
			}
		}
	}
	return { 0,0 };
}

std::vector<std::string> widenGrid(const std::vector<std::string>& grid) {
	std::vector<std::string> newGrid;
	for (const auto& line : grid) {
		std::string newLine = "";
		for (const auto& point : line) {
			switch (point) {
				case '#':
					newLine += "##";
					break;
				case 'O':
					newLine += "[]";
					break;
				case '.':
					newLine += "..";
					break;
				case '@':
					newLine += "@.";
					break;
				default: 
					std::cout << "WTF";
					break;
			}
		}
		newGrid.push_back(newLine);
	}
	return newGrid;
}

void Day15::Task1() const {
	int64_t result = 0;
	auto input = ReadAllLinesInFile("input.txt");
	std::vector<std::string> grid;
	std::vector<std::string> directions;
	splitByEmptyLine(input, grid, directions);
	auto [x,y] = findRobot(grid);

	for (const auto& directionsLine : directions) {
		for (const auto& direction : directionsLine) {
			auto [dirX, dirY] = directionsMap[direction];
			int nextX = x + dirX;
			int nextY = y + dirY;
			if (grid[nextX][nextY] == '.') {
				grid[x][y] = '.';
				grid[nextX][nextY] = '@';
				x = nextX;
				y = nextY;
			}
			else if (grid[nextX][nextY] == 'O') {
				while (grid[nextX][nextY] == 'O') {
					nextX += dirX;
					nextY += dirY;
				}
				if (grid[nextX][nextY] == '.') {
					grid[x][y] = '.';
					x = x + dirX;
					y = y + dirY;
					grid[x][y] = '@';
					grid[nextX][nextY] = 'O';
				}
			}
		}
	}

	for (int x = 0; x < grid.size(); x++) {
		for (int y = 0; y < grid[x].size(); y++) {
			if (grid[x][y] == 'O') {
				result += 100 * x + y;
			}
		}
	}
	std::cout << result << std::endl;
}

void Day15::Task2() const {
	int64_t result = 0;
	auto input = ReadAllLinesInFile("input.txt");
	std::vector<std::string> grid;
	std::vector<std::string> directions;
	splitByEmptyLine(input, grid, directions);
	auto [x, y] = findRobot(grid);
	grid = widenGrid(grid);

	for (const auto& directionsLine : directions) {
		for (const auto& direction : directionsLine) {
			auto [dirX, dirY] = directionsMap[direction];
			int nextX = x + dirX;
			int nextY = y + dirY;
			if (grid[nextX][nextY] == '.') {
				grid[x][y] = '.';
				grid[nextX][nextY] = '@';
				x = nextX;
				y = nextY;
				continue;
			}
			else if (grid[nextX][nextY] == '[') {
				std::set<std::pair<int, int>> pointsToCheck;
				pointsToCheck.insert({ nextX + dirX, nextY + dirY });
				pointsToCheck.insert({ nextX + dirX, nextY + dirY + 1});
				bool free = true;
				while (free) {
					std::set<std::pair<int, int>> newPointsToCheck;
				}
				if (free) {
					grid[x][y] = '.';
					x = x + dirX;
					y = y + dirY;
					grid[x][y] = '@';
					grid[nextX][nextY] = 'O';
				}
			}
			else if (grid[nextX][nextY] == ']') {
				std::set<std::pair<int, int>> pointsToCheck;
				pointsToCheck.insert({ nextX + dirX, nextY + dirY });
				pointsToCheck.insert({ nextX + dirX, nextY + dirY - 1 });
				bool free = true;
				while (free) {
					nextX += dirX;
					nextY += dirY;
				}
			}
		}
	}

	for (int x = 0; x < grid.size(); x++) {
		for (int y = 0; y < grid[x].size(); y++) {
			if (grid[x][y] == '[') {
				result += 100 * x + y;
			}
		}
	}
	std::cout << result << std::endl;
}