#include "day10.h"

std::vector<std::pair<int, int>> directions = {
		   {-1,0},
	{0,-1},       {0,1},
			{1,0}
};

void solveRecursively(int x, int y, std::vector<std::vector<int>>& grid, std::set<std::pair<int, int>>& endpoints) {
	int rows = grid.size();
	int cols = grid[0].size();

	for (auto [dirX, dirY] : directions) {
		int nextX = x + dirX;
		int nextY = y + dirY;

		if (nextX < 0 || nextX >= rows || nextY < 0 || nextY >= cols)
			continue;

		if (grid[nextX][nextY] - grid[x][y] == 1) {
			if (grid[nextX][nextY] == 9) {
				endpoints.insert({ nextX, nextY });
			}
			else {
				solveRecursively(nextX, nextY, grid, endpoints);
			}
		}
	}
}

void Day10::Task1() const {
	auto input = ReadAllLinesInFile("input.txt");
	auto grid = parseDigits(input);
	int result = 0;
	int rows = grid.size();
	int cols = grid[0].size();
	std::set<std::pair<std::pair<int,int>, std::pair<int,int>>> trailheads;
	for (int x = 0; x < rows; x++) {
		for (int y = 0; y < cols; y++) {
			if (grid[x][y] == 0) {
				std::set<std::pair<int, int>> endpoints;
				solveRecursively(x, y, grid, endpoints);
				for (const auto& end : endpoints) {
					trailheads.insert({ {x, y}, end });
				}
			}
		}
	}
	result = trailheads.size();
	std::cout << result << std::endl;
}

void solveRecursivelyPart2(int x, int y, std::vector<std::vector<int>>& grid, std::vector<std::pair<int, int>>& endpoints) {
	int rows = grid.size();
	int cols = grid[0].size();

	for (auto [dirX, dirY] : directions) {
		int nextX = x + dirX;
		int nextY = y + dirY;

		if (nextX < 0 || nextX >= rows || nextY < 0 || nextY >= cols)
			continue;

		if (grid[nextX][nextY] - grid[x][y] == 1) {
			if (grid[nextX][nextY] == 9) {
				endpoints.push_back({ nextX, nextY });
			}
			else {
				solveRecursivelyPart2(nextX, nextY, grid, endpoints);
			}
		}
	}
}

void Day10::Task2() const {
	auto input = ReadAllLinesInFile("input.txt");
	auto grid = parseDigits(input);
	int result = 0;
	int rows = grid.size();
	int cols = grid[0].size();
	std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> trailheads;
	for (int x = 0; x < rows; x++) {
		for (int y = 0; y < cols; y++) {
			if (grid[x][y] == 0) {
				std::vector<std::pair<int, int>> endpoints;
				solveRecursivelyPart2(x, y, grid, endpoints);
				for (const auto& end : endpoints) {
					trailheads.push_back({ {x, y}, end });
				}
			}
		}
	}
	result = trailheads.size();
	std::cout << result << std::endl;
}