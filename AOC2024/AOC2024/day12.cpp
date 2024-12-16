#include "day12.h"

const std::vector<std::pair<int, int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

const std::vector<std::pair<int, int>> diagonalDirections = { 
       {-1, -1}, {-1, 0}, {-1, 1},
        {0, -1},          {0, 1},
        {1, -1}, {1, 0},  {1, 1}
};

std::set<std::pair<int, int>> maximizePlot(const std::set<std::pair<int,int>>& plot, int multiplier) {
    std::set<std::pair<int, int>> result;
    for (const auto& [x, y] : plot) {
        for (int i = 0; i < multiplier; i++) {
            for (int j = 0; j < multiplier; j++) {
                int newX = x * multiplier + i;
                int newY = y * multiplier + j;
                result.insert({ newX,newY });
            }
        }
    }
    return result;
}

bool isInPlot(const std::set<std::pair<int, int>>& plot, std::pair<int,int> point) {
    if (plot.find(point) != plot.end()) {
        return true;
    }
    return false;
}

int countPlotCorners(const std::set<std::pair<int, int>>& plot) {
    int result = 0;
    for (const auto& [x, y] : plot) {
        int neighbors = 0;
        for (const auto& [dirX, dirY] : diagonalDirections) {
            if (isInPlot(plot, { x + dirX, y + dirY })) {
                neighbors++;
            }
        }
        if (neighbors == 3 || neighbors == 7 || neighbors == 4) {
            result++;
        }
    }
    return result;
}


void dfs(int row, int col, const std::vector<std::string>& grid, std::set<std::pair<int, int>>& visited, std::vector<std::pair<int, int>>& currentPlot, char letter) {
    int rows = grid.size();
    int cols = grid[0].size();

    visited.insert({ row, col });
    currentPlot.push_back({ row, col });

    for (const auto& dir : directions) {
        int newRow = row + dir.first;
        int newCol = col + dir.second;

        if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && grid[newRow][newCol] == letter && visited.find({ newRow, newCol }) == visited.end()) {
            dfs(newRow, newCol, grid, visited, currentPlot, letter);
        }
    }
}

void Day12::Task1() const {
    int result = 0;
	auto input = ReadAllLinesInFile("input.txt");
	int rows = input.size();
	int cols = input[0].size();
    std::set<std::pair<int, int>> visited;
	std::vector<std::vector<std::pair<int, int>>> allPlots;
	for (int x = 0; x < rows; x++) {
		for (int y = 0; y < cols; y++) {
			if (visited.find({ x, y }) == visited.end()) {
				char letter = input[x][y];
				std::vector<std::pair<int, int>> currentPlot;
                dfs(x, y, input, visited, currentPlot, letter);
                allPlots.push_back(currentPlot);
			}
		}
	}
    for (int i = 0; i < allPlots.size(); i++) {
        int perimeter = 0;
        for (auto [x,y] : allPlots[i]) {
            for (const auto& dir : directions) {
                int newRow = x + dir.first;
                int newCol = y + dir.second;
                if (newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols) {
                    perimeter++;
                    continue;
                }
                if (input[x][y] == input[newRow][newCol]) {
                    continue;
                }
                perimeter++;
            }
        }
        result += perimeter * allPlots[i].size();
    }
    std::cout << result << std::endl;
}

void Day12::Task2() const {
    int result = 0;
    auto input = ReadAllLinesInFile("input.txt");
    int rows = input.size();
    int cols = input[0].size();
    std::set<std::pair<int, int>> visited;
    std::vector<std::vector<std::pair<int, int>>> allPlots;
    for (int x = 0; x < rows; x++) {
        for (int y = 0; y < cols; y++) {
            if (visited.find({ x, y }) == visited.end()) {
                char letter = input[x][y];
                std::vector<std::pair<int, int>> currentPlot;
                dfs(x, y, input, visited, currentPlot, letter);
                allPlots.push_back(currentPlot);
            }
        }
    }

    for (const auto& plot : allPlots) {
        std::set<std::pair<int, int>> currentPlot(plot.begin(), plot.end());
        std::set<std::pair<int, int>> maximizedPlot = maximizePlot(currentPlot, 2);
        int x = countPlotCorners(maximizedPlot);
        result += x * plot.size();
    }

    std::cout << result << std::endl;
}