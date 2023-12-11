#include "input.h"
#include "task11.h"

struct Coords {
	int x, y;
};

void Task11::Part1() {
	auto input = Utility::ReadAllLinesInFile("inputs/input11.txt");
	int64_t res = 0;
	
	for (int i = 0; i < input.size(); i++) {
		std::string currLine = input[i];
		int numberOfDots = 0;
		for (int x = 0; x < currLine.size(); x++) {
			if (input[i][x] == '.') {
				numberOfDots++;
			}
		}
		if (numberOfDots == currLine.size()) {
			input.insert(input.begin() + i, currLine);
			i++;
		}	
	}

	for (int x = 0; x < input[0].size(); x++) {
		int numberOfDots = 0;
		for (int i = 0; i < input.size(); i++) {
			if (input[i][x] == '.') {
				numberOfDots++;
			}
		}
		if (numberOfDots == input.size()) {
			for (int y = 0; y < input.size(); y++) {
				input[y].insert(input[y].begin() + x, '.');
			}
			x++;
		}
	}

	std::vector<Coords> galaxies;
	for (int i = 0; i < input.size(); i++) {
		for(int x = 0; x < input[i].size();x++){
			if (input[i][x] == '#') {
				galaxies.push_back({ x,i });
			}
		}
	}
	for (int i = 0; i < galaxies.size(); i++) {
		for (int x = i + 1; x < galaxies.size(); x++) {
			Coords currentGalaxy = galaxies[i];
			Coords nextGalaxy = galaxies[x];
			res += (std::abs(nextGalaxy.x - currentGalaxy.x) + (nextGalaxy.y - currentGalaxy.y));
		}
	}


	std::cout << res;
}

void Task11::Part2() {
	auto input = Utility::ReadAllLinesInFile("inputs/input11.txt");
	int64_t res = 0;
	std::vector<int> columnsOfDots;
	std::vector<int> rowsOfDots;

	for (int i = 0; i < input.size(); i++) {
		std::string currLine = input[i];
		int numberOfDots = 0;
		for (int x = 0; x < currLine.size(); x++) {
			if (input[i][x] == '.') {
				numberOfDots++;
			}
		}
		if (numberOfDots == currLine.size()) {
			input.insert(input.begin() + i, currLine);
			rowsOfDots.push_back(i);
			i++;
		}
	}

	for (int x = 0; x < input[0].size(); x++) {
		int numberOfDots = 0;
		for (int i = 0; i < input.size(); i++) {
			if (input[i][x] == '.') {
				numberOfDots++;
			}
		}
		if (numberOfDots == input.size()) {
			for (int y = 0; y < input.size(); y++) {
				input[y].insert(input[y].begin() + x, '.');
			}
			columnsOfDots.push_back(x);
			x++;
		}
	}

	std::vector<Coords> galaxies;
	for (int i = 0; i < input.size(); i++) {
		for (int x = 0; x < input[i].size(); x++) {
			if (input[i][x] == '#') {
				galaxies.push_back({ x,i });
			}
		}
	}

	for (int i = 0; i < galaxies.size(); i++) {
		for (int x = i + 1; x < galaxies.size(); x++) {
			Coords currentGalaxy = galaxies[i];
			Coords nextGalaxy = galaxies[x];
			for (int j = 0; j < rowsOfDots.size(); j++) {
				if (nextGalaxy.y > rowsOfDots[j] && currentGalaxy.y < rowsOfDots[j]) {
					res += 999998;
				}
			}
			for (int j = 0; j < columnsOfDots.size(); j++) {
				if ((nextGalaxy.x > columnsOfDots[j] && currentGalaxy.x < columnsOfDots[j]) || (currentGalaxy.x > columnsOfDots[j] && nextGalaxy.x < columnsOfDots[j])) {
					res += 999998;
				}
			}
			res += (std::abs(nextGalaxy.x - currentGalaxy.x) + (nextGalaxy.y - currentGalaxy.y));
		}
	}


	std::cout << res;
}