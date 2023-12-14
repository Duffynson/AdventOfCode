#include "input.h"
#include "task14.h"

const long long N = 4000000000;

void Task14::Part1() {
	std::vector<std::string> input = Utility::ReadAllLinesInFile("inputs/input14.txt");
	input = Utility::FlipStringInput(input);
	int res = 0;

	for (std::string &line : input) {
		int index = 0;
		for (int i = 0; i < line.size(); i++) {
			if (line[i] == 'O') {
				if (index != i) {
					line[index] = 'O';
					line[i] = '.';
				}
				res += (int)line.size() - index;
				index++;
			}
			else if (line[i] == '#') {
				index = i + 1;
			}
			else
				continue;
		}
	}

	std::cout << res;
}

//N W S E

std::vector<std::string> Cycle(std::vector<std::string> input) {
	for (int i = 0; i < 4; i++) {
		input = Utility::FlipStringInput(input);
		for (std::string& line : input) {
			int index = 0;
			for (int i = 0; i < line.size(); i++) {
				if (line[i] == 'O') {
					if (index != i) {
						line[index] = 'O';
						line[i] = '.';
					}
					index++;
				}
				else if (line[i] == '#') {
					index = i + 1;
				}
				else
					continue;
			}
			std::reverse(line.begin(), line.end());
		}
	}
	return input;
}

void Task14::Part2() {
	std::vector<std::string> input = Utility::ReadAllLinesInFile("inputs/input14.txt");
	int res = 0;

	std::set<std::vector<std::string>> seenPossibilities;
	std::vector<std::vector<std::string>> arrayOfInputs;
	int idx = 0;
	while (true) {
		idx++;
		input = Cycle(input);
		if (seenPossibilities.find(input) != seenPossibilities.end())
			break;
		seenPossibilities.insert(input);
		arrayOfInputs.push_back(input);
	}
	int first = 0;
	for (int i = 0; i < arrayOfInputs.size(); i++) {
		if (input == arrayOfInputs[i]) {
			first = i + 1;
		}
	}

	input = arrayOfInputs[(1000000000 - first) % (idx - first) + first - 1];

	for (int i = 0; i < input.size();i++) {
		for (int j = 0; j < input[i].size(); j++) {
			if (input[i][j] == 'O') {
				res += (int)input.size() - i;
			}
		}
	}

	std::cout << res;
}