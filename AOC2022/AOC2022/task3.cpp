#include "task3.h"
#include "input.h"

void Task3::Part1() {
	auto input = Utility::ReadAllLinesInFile("inputs/input3.txt");
	int res = 0;
	for (auto line : input) {
		char commonChar;
		std::string firstHalf = line.substr(0, line.size() / 2);
		std::string secondHalf = line.substr(line.size() / 2, line.size());
		bool found = false;
		for (int i = 0; i < firstHalf.size(); i++) {
			for (int x = 0; x < secondHalf.size(); x++) {
				if (firstHalf[i] == secondHalf[x]) {
					commonChar = firstHalf[i];
					found = true;
					break;
				}
			}
			if (found)
				break;
		}
		if (std::islower(commonChar)) {
			res += (int)commonChar - 96;
		}
		else
			res += (int)commonChar - 38;
	}
	std::cout << res;
}

void Task3::Part2() {
	auto input = Utility::ReadAllLinesInFile("inputs/input3.txt");
	int res = 0;
	for (int j = 0; j < input.size() - 2; j+=3) {
		char commonChar;
		std::string firstLine = input[j];
		std::string secondLine = input[j + 1];
		std::string thirdLine = input[j + 2];
		bool found = false;
		for (int i = 0; i < firstLine.size(); i++) {
			for (int x = 0; x < secondLine.size(); x++) {
				for (int y = 0; y < thirdLine.size(); y++){
					if (firstLine[i] != secondLine[x])
						break;
					else {
						if (firstLine[i] == secondLine[x] && secondLine[x] == thirdLine[y]) {
							commonChar = firstLine[i];
							found = true;
							break;
						}
					}
				}
				if (found)
					break;
			}
			if (found)
				break;
		}
		if (std::islower(commonChar)) {
			res += (int)commonChar - 96;
		}
		else
			res += (int)commonChar - 38;
	}
	std::cout << res;
}