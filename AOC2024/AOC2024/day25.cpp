#include "day25.h"

void sortLocksAndKeys(const std::vector<std::vector<std::string>>& input, std::vector<std::vector<int>>& locks, std::vector<std::vector<int>>& keys) {
	for (const auto& schematic : input) {
		bool isLock = schematic[0][0] == '#' ? true : false;
		int size = schematic[0].size();
		std::vector<int> heights(size, 0);
		for (int x = 1; x < schematic.size() - 1; x++) {
			for (int y = 0; y < schematic[x].size(); y++) {
				if (schematic[x][y] == '#') {
					heights[y]++;
				}
			}
		}
		if (isLock) {
			locks.push_back(heights);
		}
		else {
			keys.push_back(heights);
		}
		
	}
}

void Day25::Task1() const {
	int result = 0;
	auto input = ReadAllLinesInFile("input.txt");
	auto locksAndKeys = splitByEmptyLines(input);
	int size = locksAndKeys[0].size() - 2;
	std::vector<std::vector<int>> locks;
	std::vector<std::vector<int>> keys;
	sortLocksAndKeys(locksAndKeys, locks, keys);

	for (const auto& lock : locks) {
		for (const auto& key : keys) {
			bool valid = true;
			for (int i = 0; i < lock.size(); i++) {
				if (lock[i] + key[i] > size) {
					valid = false;
				}
			}
			if (valid) { 
				result++;
			}
		}
	}

	std::cout << result << std::endl;
}


void Day25::Task2() const {
	std::cout << "Task 2 doesn't exist." << std::endl;
}