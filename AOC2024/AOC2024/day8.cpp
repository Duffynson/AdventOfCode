#include "day8.h"

void Day8::Task1() const {
	int result = 0;
	auto input = ReadAllLinesInFile("input.txt");
	int rows = input.size();
	int cols = input[0].size();
	std::set<std::tuple<int, int, char>> antennas;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (input[i][j] != '.') {
				antennas.insert({ i, j, input[i][j] });
			}
		}
	}
	std::set<std::pair<int, int>> antiNodes;
	for (auto [x, y, frequency] : antennas) {
		for (auto [i,j, frequency2] : antennas) {
			if (x == i && y == j) continue;
			if (frequency == frequency2) {
				int firstAntiNodeX = x + (x - i);
				int firstAntiNodeY = y + (y - j);
				int secondAntiNodeX = i + (i - x);
				int secondAntiNodeY = j + (j - y);
				if (firstAntiNodeX < 0 || firstAntiNodeX >= rows || firstAntiNodeY < 0 || firstAntiNodeY >= cols) continue;
				else { 
					antiNodes.insert({ firstAntiNodeX, firstAntiNodeY }); 
				}
				if (secondAntiNodeX < 0 || secondAntiNodeX >= rows || secondAntiNodeY < 0 || secondAntiNodeY >= cols) continue;
				else { 
					antiNodes.insert({ secondAntiNodeX, secondAntiNodeY }); 
				}
			}
		}
	}
	result = antiNodes.size();
	std::cout << result << std::endl;
}

void Day8::Task2() const {
	int result = 0;
	auto input = ReadAllLinesInFile("input.txt");
	int rows = input.size();
	int cols = input[0].size();
	std::set<std::tuple<int, int, char>> antennas;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (input[i][j] != '.') {
				antennas.insert({ i, j, input[i][j] });
			}
		}
	}
	std::set<std::pair<int, int>> antiNodes;
	for (auto [x, y, frequency] : antennas) {
		for (auto [i, j, frequency2] : antennas) {
			if (x == i && y == j) continue;
			if (frequency == frequency2) {
				int firstAntiNodeX = x;
				int firstAntiNodeY = y;
				while (firstAntiNodeX >= 0 && firstAntiNodeX < rows && firstAntiNodeY >= 0 && firstAntiNodeY < cols) {
					antiNodes.insert({ firstAntiNodeX, firstAntiNodeY });
					firstAntiNodeX += x - i;
					firstAntiNodeY += y - j;
				}
				int secondAntiNodeX = i;
				int secondAntiNodeY = j;
				while (secondAntiNodeX >= 0 && secondAntiNodeX < rows && secondAntiNodeY >= 0 && secondAntiNodeY < cols) {
					antiNodes.insert({ secondAntiNodeX, secondAntiNodeY });
					secondAntiNodeX += i - x;
					secondAntiNodeY += j - y;
				}
			}
		}
	}
	result = antiNodes.size();
	std::cout << result << std::endl;
}