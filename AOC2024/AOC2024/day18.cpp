#include "day18.h"

const std::vector<std::pair<int, int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

void Day18::Task1() const {
	int result = 0;
	int gridSize = 71;
	int bytes = 1024;
	int endIndex = gridSize - 1;
	int rows = gridSize, cols = gridSize;
	std::vector<std::string> grid(gridSize, std::string(gridSize, '.'));
	auto positions = parseToIntPairs(input, ',');
	for (int i = 0; i < bytes; i++) {
		auto [y, x] = positions[i];
		grid[x][y] = '#';
	}

	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
	std::set<std::pair<int, int>> seen;
	std::map<std::pair<int, int>, int> values;
	for (int x = 0; x < rows; x++) {
		for (int y = 0; y < cols; y++) {
			if (grid[x][y] == '.') {
				values[{x, y}] = INT_MAX;
			}
		}
	}
	values[{0, 0}] = 0;
	pq.emplace(0,0);
	while (!pq.empty()) {
		auto current = pq.top();
		seen.insert(current);
		pq.pop();
		for (const auto& direction : directions) {
			int nr = current.first + direction.first;
			int nc = current.second + direction.second;
			if (nr < 0 || nr >= rows || nc < 0 || nc >= cols || grid[nr][nc] == '#') {
				continue;
			}
			int temp = values[current] + 1;
			if (values[{nr,nc}] > temp){
				values[{nr, nc}] = temp;
				if (seen.find({ nr,nc }) == seen.end()) {
					pq.emplace(nr,nc);
				}
			}
		}
	}
	result = values[{endIndex,endIndex}];
	std::cout << result << std::endl;
}

void Day18::Task2() const {
	std::pair<int,int> result;
	int gridSize = 71;
	int safeBytes = 1024;
	int endIndex = gridSize - 1;
	int rows = gridSize, cols = gridSize;
	std::vector<std::string> grid(gridSize, std::string(gridSize, '.'));
	auto positions = parseToIntPairs(input, ',');
	for (int i = 0; i < safeBytes; i++) {
		auto [y, x] = positions[i];
		grid[x][y] = '#';
	}
	int bytes = positions.size();
	for (int i = safeBytes; i < bytes; i++) {
		auto [y, x] = positions[i];
		grid[x][y] = '#';
		std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
		std::set<std::pair<int, int>> seen;
		std::map<std::pair<int, int>, int> values;
		for (int x = 0; x < rows; x++) {
			for (int y = 0; y < cols; y++) {
				if (grid[x][y] == '.') {
					values[{x, y}] = INT_MAX;
				}
			}
		}
		values[{0, 0}] = 0;
		pq.emplace(0, 0);
		while (!pq.empty()) {
			auto current = pq.top();
			seen.insert(current);
			pq.pop();
			for (const auto& direction : directions) {
				int nr = current.first + direction.first;
				int nc = current.second + direction.second;
				if (nr < 0 || nr >= rows || nc < 0 || nc >= cols || grid[nr][nc] == '#') {
					continue;
				}
				int temp = values[current] + 1;
				if (values[{nr, nc}] > temp) {
					values[{nr, nc}] = temp;
					if (seen.find({ nr,nc }) == seen.end()) {
						pq.emplace(nr, nc);
					}
				}
			}
		}
		if (values[{endIndex, endIndex}] == INT_MAX) {
			result = positions[i];
			break;
		}
	}
	std::cout << result.first << "," << result.second << std::endl;

}