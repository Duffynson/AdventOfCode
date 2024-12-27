#include "day16.h"

const std::vector<std::pair<int, int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

void Day16::Task1() const {
	int result = 0;
	auto grid = ReadAllLinesInFile("input.txt");

	std::pair<int, int> start;
	std::pair<int, int> end;
	std::set<std::pair<int, int>> unvisitedNodes;
	std::map<std::pair<int, int>, int> nodeValues;

	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[i].size(); j++) {
			if (grid[i][j] == '#') {
				continue;
			}
			unvisitedNodes.insert({ i,j });
			nodeValues[{i, j}] = INT_MAX;
			if (grid[i][j] == 'S') {
				start = { i,j };
				nodeValues[{i, j}] = 0;
			}
			if (grid[i][j] == 'E') {
				end = { i,j };
			}
		}
	}

	std::map<std::pair<int, int>, std::pair<int, int>> nodeDirections;
	nodeDirections[start] = {0,1};
	while (!unvisitedNodes.empty()) {
		std::pair<int, int> xy;
		int x = INT_MAX;
		for (const auto& [key, value] : nodeValues) {
			if (value < x && unvisitedNodes.find(key) != unvisitedNodes.end()) {
				x = value;
				xy = key;
			}
		}
		for (const auto& [dirX, dirY] : directions) {
			int nextX = xy.first + dirX;
			int nextY = xy.second + dirY;
			if (grid[nextX][nextY] != '#') {
				auto previousDirection = nodeDirections[xy];
				if (previousDirection.first == dirX && previousDirection.second == dirY) {
					int temp = nodeValues[xy] + 1;
					if (nodeValues[{nextX, nextY}] > temp) {
						nodeValues[{nextX, nextY}] = temp;
						nodeDirections[{nextX, nextY}] = { dirX,dirY };
					}
				}
				else {
					int temp = nodeValues[xy] + 1001;
					if (nodeValues[{nextX, nextY}] > temp) {
						nodeValues[{nextX, nextY}] = temp;
						nodeDirections[{nextX, nextY}] = { dirX,dirY };
					}
				}
			}
		}
		unvisitedNodes.erase(xy);
	}

	result = nodeValues[end];
	std::cout << result << std::endl;
}

void Day16::Task2() const {
	int result = 0;
	auto grid = ReadAllLinesInFile("input.txt");

	std::pair<int, int> start;
	std::pair<int, int> end;
	std::set<std::pair<int, int>> unvisitedNodes;
	std::map<std::pair<int, int>, int> nodeValues;

	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[i].size(); j++) {
			if (grid[i][j] == '#') {
				continue;
			}
			unvisitedNodes.insert({ i,j });
			nodeValues[{i, j}] = INT_MAX;
			if (grid[i][j] == 'S') {
				start = { i,j };
				nodeValues[{i, j}] = 0;
			}
			if (grid[i][j] == 'E') {
				end = { i,j };
			}
		}
	}

	std::map<std::pair<int, int>, std::pair<int, int>> nodeDirections;
	std::set<std::pair<std::pair<int, int>, std::pair<int, int>>> previousNodes;
	nodeDirections[start] = { 0,1 };
	while (!unvisitedNodes.empty()) {
		std::pair<int, int> xy;
		int x = INT_MAX;
		for (const auto& [key, value] : nodeValues) {
			if (value < x && unvisitedNodes.find(key) != unvisitedNodes.end()) {
				x = value;
				xy = key;
			}
		}
		for (const auto& [dirX, dirY] : directions) {
			int nextX = xy.first + dirX;
			int nextY = xy.second + dirY;
			if (unvisitedNodes.find({ nextX,nextY }) == unvisitedNodes.end()) {
				continue;
			}
			if (grid[nextX][nextY] != '#') {
				auto previousDirection = nodeDirections[xy];
				previousNodes.insert({ xy,{nextX,nextY} });
				if (previousDirection.first == dirX && previousDirection.second == dirY) {
					int temp = nodeValues[xy] + 1;
					if (nodeValues[{nextX, nextY}] > temp) {
						nodeValues[{nextX, nextY}] = temp;
						nodeDirections[{nextX, nextY}] = { dirX,dirY };
					}
				}
				else {
					int temp = nodeValues[xy] + 1001;
					if (nodeValues[{nextX, nextY}] > temp) {
						nodeValues[{nextX, nextY}] = temp;
						nodeDirections[{nextX, nextY}] = { dirX,dirY };
					}
				}
			}
		}
		unvisitedNodes.erase(xy);
	}
	
	std::pair<int, int> current = end;
	while (current != end) {
		for (const auto& [dirX, dirY] : directions) {
			std::pair<int,int> next = { current.first + dirX, current.second + dirY };
		}
	}
	std::cout << result << std::endl;
}