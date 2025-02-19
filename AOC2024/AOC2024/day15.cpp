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
	grid = widenGrid(grid);
	auto [x, y] = findRobot(grid);

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
			if (dirX == 0) {
				while (grid[nextX][nextY] == '[' || grid[nextX][nextY] == ']') {
					nextX += dirX;
					nextY += dirY;
				}
				if (grid[nextX][nextY] == '.') {
					char previousChar = grid[x][y];
					grid[x][y] = '.';
					x += dirX;
					y += dirY;
					int tempX = x;
					int tempY = y;
					char nextChar = grid[x][y];
					grid[x][y] = previousChar;
					while (!(tempX == nextX && tempY == nextY)) {
						previousChar = nextChar;
						tempX += dirX;
						tempY += dirY;
						nextChar = grid[tempX][tempY];
						grid[tempX][tempY] = previousChar;
					}
				}
			}
			else {
				if (grid[nextX][nextY] == '[') {
					std::map<std::pair<int, int>, char> blocksToMove;
					std::set<std::pair<int, int>> lastLayer;
					blocksToMove[{nextX, nextY}] = grid[nextX][nextY];
					blocksToMove[{nextX, nextY + 1}] = grid[nextX][nextY + 1];
					lastLayer.insert({ nextX, nextY });
					lastLayer.insert({ nextX, nextY + 1 });
					bool safeToMove = true;
					while (safeToMove) {
						std::set<std::pair<int, int>> nextLayer;
						int countOfEmptySpaces = 0;
						for (auto [blockX, blockY] : lastLayer) {
							int nextBlockX = blockX + dirX;
							int nextBlockY = blockY + dirY;
							if (grid[nextBlockX][nextBlockY] == '.') {
								countOfEmptySpaces++;
							}
							else if (grid[nextBlockX][nextBlockY] == '#') {
								safeToMove = false;
								break;
							}
							else if (grid[nextBlockX][nextBlockY] == '[') {
								blocksToMove[{nextBlockX, nextBlockY}] = grid[nextBlockX][nextBlockY];
								blocksToMove[{nextBlockX, nextBlockY + 1}] = grid[nextBlockX][nextBlockY + 1];
								nextLayer.insert({ nextBlockX,nextBlockY });
								nextLayer.insert({ nextBlockX,nextBlockY + 1 });
							}
							else {
								blocksToMove[{nextBlockX, nextBlockY}] = grid[nextBlockX][nextBlockY];
								blocksToMove[{nextBlockX, nextBlockY - 1}] = grid[nextBlockX][nextBlockY - 1];
								nextLayer.insert({ nextBlockX,nextBlockY });
								nextLayer.insert({ nextBlockX,nextBlockY - 1 });
							}
						}
						if (countOfEmptySpaces == lastLayer.size()) {
							//move all blocks
							grid[x][y] = '.';
							x = nextX;
							y = nextY;
							for (const auto& [coords, value] : blocksToMove) {
								grid[coords.first][coords.second] = '.';
							}
							grid[x][y] = '@';
							for (const auto& [coords, value] : blocksToMove) {
								grid[coords.first + dirX][coords.second + dirY] = value;
							}
							break;
						}
						lastLayer = nextLayer;
						nextLayer.clear();
					}
				}
				else if (grid[nextX][nextY] == ']') {
					std::map<std::pair<int, int>, char> blocksToMove;
					std::set<std::pair<int, int>> lastLayer;
					blocksToMove[{nextX, nextY}] = grid[nextX][nextY];
					blocksToMove[{nextX, nextY - 1}] = grid[nextX][nextY - 1];
					lastLayer.insert({ nextX, nextY });
					lastLayer.insert({ nextX, nextY - 1 });
					bool safeToMove = true;
					while (safeToMove) {
						std::set<std::pair<int, int>> nextLayer;
						int countOfEmptySpaces = 0;
						for (auto [blockX, blockY] : lastLayer) {
							int nextBlockX = blockX + dirX;
							int nextBlockY = blockY + dirY;
							if (grid[nextBlockX][nextBlockY] == '.') {
								countOfEmptySpaces++;
							}
							else if (grid[nextBlockX][nextBlockY] == '#') {
								safeToMove = false;
								break;
							}
							else if (grid[nextBlockX][nextBlockY] == '[') {
								blocksToMove[{nextBlockX, nextBlockY}] = grid[nextBlockX][nextBlockY];
								blocksToMove[{nextBlockX, nextBlockY + 1}] = grid[nextBlockX][nextBlockY + 1];
								nextLayer.insert({ nextBlockX,nextBlockY });
								nextLayer.insert({ nextBlockX,nextBlockY + 1 });
							}
							else {
								blocksToMove[{nextBlockX, nextBlockY}] = grid[nextBlockX][nextBlockY];
								blocksToMove[{nextBlockX, nextBlockY - 1}] = grid[nextBlockX][nextBlockY - 1];
								nextLayer.insert({ nextBlockX,nextBlockY });
								nextLayer.insert({ nextBlockX,nextBlockY - 1 });
							}
						}
						if (countOfEmptySpaces == lastLayer.size()) {
							//move all blocks
							grid[x][y] = '.';
							x = nextX;
							y = nextY;
							for (const auto& [coords, value] : blocksToMove) {
								grid[coords.first][coords.second] = '.';
							}
							grid[x][y] = '@';
							for (const auto& [coords, value] : blocksToMove) {
								grid[coords.first + dirX][coords.second + dirY] = value;
							}
							break;
						}
						lastLayer = nextLayer;
						nextLayer.clear();
					}
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