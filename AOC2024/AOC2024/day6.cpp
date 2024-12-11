#include "day6.h"

std::map<char, std::pair<int,int>> directions = {
	{'<', {0,-1}},
	{'^', {-1,0}},
	{'>', {0,1}},
	{'v', {1,0}}
	
};

std::pair<int, int> turnRight(std::pair<int,int> direction) {
	return { direction.second, -(direction.first) };
}

std::pair<int, int> getStartPosition(const std::vector<std::string>& grid) {
	for (int x = 0; x < grid.size(); x++) {
		for (int y = 0; y < grid[0].size(); y++) {
			if (grid[x][y] != '#' && grid[x][y] != '.') {
				return { x,y };
			}
		}
	}
}

std::set<std::pair<int, int>> getGuardPath(const std::vector<std::string>& grid) {
	int result = 0;
	std::pair<int, int> currentPosition = getStartPosition(grid);
	std::pair<int, int> currentDirection = directions.find(grid[currentPosition.first][currentPosition.second])->second;
	std::set<std::pair<int, int>> path;
	int rows = grid.size();
	int columns = grid[0].size();

	while (true) {
		path.insert({ currentPosition.first,currentPosition.second });
		int x = currentPosition.first + currentDirection.first;
		int y = currentPosition.second + currentDirection.second;
		if (x < 0 || x >= rows || y < 0 || y >= columns) {
			break;
		}
		if (grid[x][y] == '#') {
			currentDirection = turnRight(currentDirection);
			continue;
		}
		currentPosition.first = x;
		currentPosition.second = y;
	}
	return path;
}

void Day6::Task1() const {
	auto input = ReadAllLinesInFile("input.txt");
	auto path = getGuardPath(input);
	int result = path.size();
	std::cout << result << std::endl;
}

void Day6::Task2() const {
	int result = 0;
	auto input = ReadAllLinesInFile("input.txt");
	auto path = getGuardPath(input);
	//std::set<std::pair<int, int>> path = { {6,3}, {7,6}, {7,7}, {8,1}, {8,3}, {9,7} };
	for (auto [x, y] : path) {
		auto position = getStartPosition(input);
		auto direction = directions.find(input[position.first][position.second])->second;
		std::set<std::tuple<int, int, int, int>> currentPath;
		if (input[x][y] == '.') {
			input[x][y] = '#';
			while (true) {
				currentPath.insert({ position.first, position.second, direction.first, direction.second });
				int xx = position.first + direction.first;
				int yy = position.second + direction.second;
				if (xx < 0 || xx >= input.size() || yy < 0 || yy >= input[0].size()) {
					break;
				}
				if (input[xx][yy] == '#') {
					std::pair<int, int> rightDirection = turnRight(direction);
					std::pair<int, int> rightPosition = { position.first + rightDirection.first, position.second + rightDirection.second };
					std::tuple<int, int, int, int> target = { rightPosition.first, rightPosition.second, rightDirection.first, rightDirection.second };
					if (currentPath.find(target) != currentPath.end()) {
						result++;
						break;
					}
					direction = turnRight(direction);
				}
				else {
					position.first = xx;
					position.second = yy;
				}
			}
			input[x][y] = '.';
		}
	}
	std::cout << result << std::endl;
}