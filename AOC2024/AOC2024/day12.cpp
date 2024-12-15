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
        bool topLeft = isInPlot(plot, { x - 1, y - 1 });
        bool topMid = isInPlot(plot, { x - 1, y });
        bool topRight = isInPlot(plot, { x - 1, y + 1 });
        bool midLeft = isInPlot(plot, { x, y - 1 });
        bool midRight = isInPlot(plot, { x, y + 1 });
        bool botLeft = isInPlot(plot, { x + 1, y - 1 });
        bool botMid = isInPlot(plot, { x + 1, y});
        bool botRight = isInPlot(plot, { x + 1, y + 1 });
        if (midLeft && botMid && !topRight) result++;
        if (midRight && topMid && !botLeft) result++;
        if (midRight && botMid && !topLeft) result++;
        if (midLeft && topMid && !botRight) result++;
        if (topMid && midRight && !topRight) result++;
        if (topMid && midLeft && !topLeft) result++;
        if (botMid && midRight && !botRight) result++;
        if (botMid && midLeft && !botLeft) result++;
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
    std::vector<std::set<std::pair<int, int>>> fences;
    for (int i = 0; i < allPlots.size(); i++) {
        std::set<std::pair<int, int>> fence;
        for (auto [x, y] : allPlots[i]) {
            for (const auto& dir : directions) {
                int newRow = x + dir.first;
                int newCol = y + dir.second;
                if (newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols) {
                    fence.insert({newRow, newCol});
                    continue;
                }
                if (input[x][y] == input[newRow][newCol]) {
                    continue;
                }
                fence.insert({ newRow, newCol });
            }
        }
        fences.push_back(fence);
    }


    for (int i = 0; i < fences.size(); i++) {
        std::pair<int, int> direction = { 0,1 };
        auto fence = fences[i];
        auto firstFence = *fence.begin();
        auto previousFence = firstFence;
        std::set<std::pair<int, int>> seen;
        seen.insert(firstFence);
        int sides = 0;
        while (true) {
            std::pair<int, int> nextFence = {previousFence.first + direction.first, previousFence.second + direction.second};
            if (firstFence.first == nextFence.first && firstFence.second == nextFence.second) {
                sides++;
                break;
            }
            if (fence.find(nextFence) != fence.end()) {
                seen.insert(nextFence);
                previousFence = nextFence;
                continue;
            }
            else {
                for (auto [x, y] : directions) {
                    if (direction.first == x && direction.second == y) {
                        continue;
                    }
                    nextFence = { previousFence.first + x, previousFence.second + y };
                    if (seen.find(nextFence) != seen.end()) {
                        continue;
                    }
                    if (fence.find(nextFence) != fence.end()) {
                        seen.insert(nextFence);
                        sides++;
                        direction = { x,y };
                        break;
                    }
                }
            }
            previousFence = nextFence;
        }
        result += sides * allPlots[i].size();
    }

    std::cout << result << std::endl;
}