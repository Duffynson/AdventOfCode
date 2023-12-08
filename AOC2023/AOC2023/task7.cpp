#include "input.h"
#include "task7.h"

std::map<char, int> possibleChars = {
	{'A', 14},
	{'K', 13},
	{'Q', 12},
	{'J', 11},
	{'T', 10},
	{'9', 9},
	{'8', 8},
	{'7', 7},
	{'6', 6},
	{'5', 5},
	{'4', 4},
	{'3', 3},
	{'2', 2},
};

void Task7::Part1() {
	auto input = Utility::ReadAllLinesInFile("inputs/input7.txt");
	for (auto& line : input) {
		std::map<char, int> occurences;
		for (int i = 0; i < 5; i++) {
			occurences[line[i]]++;
		}
		int max = 0;
		int secondMax = 0;
		for (const auto& occurence : occurences) {
			if (occurence.second > max) {
				secondMax = max;
				max = occurence.second;
			}
			else if (occurence.second > secondMax) {
				secondMax = occurence.second;
			}
		}
		/*assign a character at the end of the string for each result
		five of a kind - a
		four of a kind - b
		full house - c
		three of a kind - d
		two pair - e
		one pair - f
		high card - g
		*/
		if (max == 5) {
			line.push_back('a');
			continue;
		}
		if (max == 4) {
			line.push_back('b');
			continue;
		}
		if (max == 3) {
			if (secondMax == 2) {
				line.push_back('c');
				continue;
			}
			else {
				line.push_back('d');
				continue;
			}
		}
		if (max == 2) {
			if (secondMax == 2) {
				line.push_back('e');
				continue;
			}
			else {
				line.push_back('f');
				continue;
			}
		}
		line.push_back('g');
	}
	//order the input based on the logic
	//index 0 in the vector being the line with lowest rank
	bool ordered = false;
	while (!ordered) {
		ordered = true;
		for (int i = 0; i < input.size() - 1; i++) {
			auto line = input[i];
			auto nextLine = input[i + 1];
			int currLineEnd = line.size() - 1;
			int nextLineEnd = nextLine.size() - 1;
			int currEndChar = line[currLineEnd];
			int nextEndChar = nextLine[nextLineEnd];
			if (nextEndChar > currEndChar) {
				auto tempLine = input[i];
				input[i] = nextLine;
				input[i + 1] = tempLine;
				ordered = false;
				continue;
			}
			if (nextEndChar == currEndChar) {
				for (int idx = 0; idx < 5; idx++) {
					int currLineChar = possibleChars.find(line[idx])->second;
					int nextLineChar = possibleChars.find(nextLine[idx])->second;
					if (currLineChar == nextLineChar)
						continue;
					if (currLineChar > nextLineChar) {
						auto tempLine = input[i];
						input[i] = nextLine;
						input[i + 1] = tempLine;
						ordered = false;
						break;
					}
					else {
						break;
					}
				}
			}
		}
	}

	size_t firstBreak;
	std::vector<int> orderedBids;
	for (auto& line : input) {
		firstBreak = line.find(' ');
		std::string lineBid = line.substr(firstBreak + 1, line.size() - firstBreak - 2);
		orderedBids.push_back(stoi(lineBid));
	}
	int64_t res = 0;
	for (int i = 0; i < orderedBids.size(); i++) {
		res += orderedBids[i] * (i + 1);
	}

	std::cout << res;
}

std::map<char, int> possibleCharsPart2 = {
	{'A', 14},
	{'K', 13},
	{'Q', 12},
	{'J', 1},
	{'T', 10},
	{'9', 9},
	{'8', 8},
	{'7', 7},
	{'6', 6},
	{'5', 5},
	{'4', 4},
	{'3', 3},
	{'2', 2},
};

void Task7::Part2() {
	auto input = Utility::ReadAllLinesInFile("inputs/input7.txt");
	for (auto& line : input) {
		std::map<char, int> occurences;
		for (int i = 0; i < 5; i++) {
			occurences[line[i]]++;
		}
		int max = 0;
		int secondMax = 0;
		int jokers = 0;
		for (const auto& occurence : occurences) {
			if (occurence.first == 'J') {
				jokers += occurence.second;
				continue;
			}
			if (occurence.second > max) {
				secondMax = max;
				max = occurence.second;
			}
			else if (occurence.second > secondMax) {
				secondMax = occurence.second;
			}
		}
		max += jokers;
		/*assign a character at the end of the string for each result
		five of a kind - a
		four of a kind - b
		full house - c
		three of a kind - d
		two pair - e
		one pair - f
		high card - g
		*/
		if (max == 5) {
			line.push_back('a');
			continue;
		}
		if (max == 4) {
			line.push_back('b');
			continue;
		}
		if (max == 3) {
			if (secondMax == 2) {
				line.push_back('c');
				continue;
			}
			else {
				line.push_back('d');
				continue;
			}
		}
		if (max == 2) {
			if (secondMax == 2) {
				line.push_back('e');
				continue;
			}
			else {
				line.push_back('f');
				continue;
			}
		}
		line.push_back('g');
	}
	//order the input based on the logic
	//index 0 in the vector being the line with lowest rank
	bool ordered = false;
	while (!ordered) {
		ordered = true;
		for (int i = 0; i < input.size() - 1; i++) {
			auto line = input[i];
			auto nextLine = input[i + 1];
			int currLineEnd = line.size() - 1;
			int nextLineEnd = nextLine.size() - 1;
			int currEndChar = line[currLineEnd];
			int nextEndChar = nextLine[nextLineEnd];
			if (nextEndChar > currEndChar) {
				auto tempLine = input[i];
				input[i] = nextLine;
				input[i + 1] = tempLine;
				ordered = false;
				continue;
			}
			if (nextEndChar == currEndChar) {
				for (int idx = 0; idx < 5; idx++) {
					int currLineChar = possibleCharsPart2.find(line[idx])->second;
					int nextLineChar = possibleCharsPart2.find(nextLine[idx])->second;
					if (currLineChar == nextLineChar)
						continue;
					if (currLineChar > nextLineChar) {
						auto tempLine = input[i];
						input[i] = nextLine;
						input[i + 1] = tempLine;
						ordered = false;
						break;
					}
					else {
						break;
					}
				}
			}
		}
	}

	size_t firstBreak;
	std::vector<int> orderedBids;
	for (auto& line : input) {
		firstBreak = line.find(' ');
		std::string lineBid = line.substr(firstBreak + 1, line.size() - firstBreak - 2);
		orderedBids.push_back(stoi(lineBid));
	}
	int64_t res = 0;
	for (int i = 0; i < orderedBids.size(); i++) {
		res += orderedBids[i] * (i + 1);
	}

	std::cout << res;
}