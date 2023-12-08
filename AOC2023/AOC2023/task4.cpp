#include "input.h"
#include "task4.h"

void Task4::Part1() {
	auto input = Utility::ReadAllLinesInFile("inputs/input4.txt");
	int res = 0;
	for (const auto& line : input) {
		int currentRes = 0;
		bool first = true;
		std::size_t colon = line.find(':') + 2;
		std::size_t verticalLine = line.find('|');

		std::string winningNumbers = line.substr(colon, verticalLine - (colon + 1));
		std::string myNumbers = line.substr(verticalLine + 2, line.size() - verticalLine);
		int currNumber;
		std::vector<int> winningNums;
		std::vector<int> myNums;
		std::stringstream iss(winningNumbers);
		while (iss >> currNumber) {
			winningNums.push_back(currNumber);
		}
		std::stringstream oss(myNumbers);
		while (oss >> currNumber) {
			myNums.push_back(currNumber);
		}
		for (auto x : winningNums) {
			for (auto y : myNums) {
				if (x == y && !first) {
					currentRes *= 2;
					break;
				}
				if (x == y && first) {
					first = false;
					currentRes++;	
					break;
				}
			}
		}
		res += currentRes;
	}

	std::cout << res;
}

void Task4::Part2() {
	auto input = Utility::ReadAllLinesInFile("inputs/input4.txt");
	int res = 0;
	std::vector<int> copies(input.size());
	for (const auto& line : input) {
		int currentRes = 0;
		std::size_t colon = line.find(':') + 2;
		std::size_t verticalLine = line.find('|');
		std::size_t d = line.find('d');
		int gameNumber = stoi(line.substr(d + 1, colon - 4));

		std::string winningNumbers = line.substr(colon, verticalLine - (colon + 1));
		std::string myNumbers = line.substr(verticalLine + 2, line.size() - verticalLine);
		int currNumber;
		std::vector<int> winningNums;
		std::vector<int> myNums;
		std::stringstream iss(winningNumbers);
		while (iss >> currNumber) {
			winningNums.push_back(currNumber);
		}
		std::stringstream oss(myNumbers);
		while (oss >> currNumber) {
			myNums.push_back(currNumber);
		}
		for (auto x : winningNums) {
			for (auto y : myNums) {
				if (x == y) {
					currentRes++;
					break;
				}
			}
		}
		int idx = gameNumber - 1;
			for (int i = gameNumber; i <= idx + currentRes; i++) {
				copies[i]++;
				copies[i] += copies[idx];
			}
	}
	for (auto x : copies) {
		res += x;
	}
	
	std::cout << res + input.size();
}