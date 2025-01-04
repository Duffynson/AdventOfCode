#include "day20.h"

const std::vector<std::pair<int, int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
const std::vector<std::pair<int, int>> cheatingDirections = { {-2,0}, {2,0}, {0,2}, {0,-2} };

void Day20::Task1() const {
	int result = 0;
	auto grid = input;
	int rows = (int)grid.size(), cols = (int)grid[0].size();
	std::pair<int, int> startPosition;
	bool found = false;
	for (int x = 0; x < rows; x++) {
		for (int y = 0; y < cols; y++) {
			if (grid[x][y] == 'S') {
				startPosition = { x,y };
				found = true;
				break;
			}
		}
		if (found) break;
	}

	std::map<std::pair<int, int>, int> distances;
	distances[startPosition] = 0;
	auto [x,y] = startPosition;
	while (grid[x][y] != 'E') {
		int value = distances[{x, y}];
		for (const auto& direction : directions) {
			auto [dx, dy] = direction;
			int nx = x + dx;
			int ny = y + dy;
			if (grid[nx][ny] != '#' && distances.find({ nx,ny }) == distances.end()) {
				distances[{nx, ny}] = value + 1;
				x = nx;
				y = ny;
				break;
			}
		}
	}

	for (int x = 0; x < rows; x++) {
		for (int y = 0; y < cols; y++) {
			if (grid[x][y] == '#') continue;
			for (const auto& [dx,dy] : cheatingDirections) {
				int nx = x + dx;
				int ny = y + dy;
				if (nx < 0 || nx >= rows || ny < 0 || ny >= cols) continue;
				if (grid[nx][ny] == '#') continue;
				if (distances[{x, y}] - distances[{nx, ny}] >= 102) result++;
			}
		}
	}

	std::cout << result << std::endl;
}

void Day20::Task2() const {
	int result = 0;
	auto grid = input;
	int rows = (int)grid.size(), cols = (int)grid[0].size();
	std::pair<int, int> startPosition;
	bool found = false;
	for (int x = 0; x < rows; x++) {
		for (int y = 0; y < cols; y++) {
			if (grid[x][y] == 'S') {
				startPosition = { x,y };
				found = true;
				break;
			}
		}
		if (found) break;
	}

	std::map<std::pair<int, int>, int> distances;
	distances[startPosition] = 0;
	auto [x, y] = startPosition;
	while (grid[x][y] != 'E') {
		int value = distances[{x, y}];
		for (const auto& direction : directions) {
			auto [dx, dy] = direction;
			int nx = x + dx;
			int ny = y + dy;
			if (grid[nx][ny] != '#' && distances.find({ nx,ny }) == distances.end()) {
				distances[{nx, ny}] = value + 1;
				x = nx;
				y = ny;
				break;
			}
		}
	}

	for (int x = 0; x < rows; x++) {
		for (int y = 0; y < cols; y++) {
			if (grid[x][y] == '#') continue;
			for (int range = 2; range < 21; range++) {
				for (int dx = 0; dx < range + 1; dx++) {
					int dy = range - dx;
					std::set<std::pair<int, int>> moves = { {x + dx,y + dy},{x + dx,y - dy}, {x - dx,y + dy},{x - dx,y - dy} };
					for (const auto& [nx, ny] : moves) {
						if (nx < 0 || nx >= rows || ny < 0 || ny >= cols) continue;
						if (grid[nx][ny] == '#') continue;
						if (distances[{x, y}] - distances[{nx, ny}] >= 100 + range) result++;
					}
				}
			}
		}
	}

	std::cout << result << std::endl;
}