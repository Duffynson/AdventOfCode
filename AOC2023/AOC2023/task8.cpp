#include "input.h"
#include "task8.h"

void Task8::Part1() {
	auto input = Utility::ReadAllLinesInFile("inputs/input8.txt");
	std::string directions = input[0];
	int res = 0;
	input.erase(input.begin(), input.begin() + 2);
	std::map<std::string, std::pair<std::string, std::string>> network;
	for (const auto& line : input) {
		std::string startNode = line.substr(0, 3);
		std::string left = line.substr(line.find('(') + 1, 3);
		std::string right = line.substr(line.find(',') + 2, 3);
		network.insert({ startNode, std::pair(left,right) });
	}
	std::string start = "AAA";
	bool solved = false;
	std::string rightDirection;
	std::string leftDirection;
	while (!solved) {
		for (const auto& direction : directions) {
			auto it = network.find(start);
			if (it != network.end()) {
				rightDirection = it->second.second;
				leftDirection = it->second.first;
			}
			else {
				solved = true;
				break;
			}
			if (direction == 'R') {
				if (rightDirection == "ZZZ") {
					res++;
					solved = true;
					break;
				}
				start = rightDirection;
				res++;
			}
			else {
				if (leftDirection == "ZZZ") {
					res++;
					solved = true;
					break;
				}
				start = leftDirection;
				res++;
			}
		}
	}
	std::cout << res;
}

void Task8::Part2() {
	auto input = Utility::ReadAllLinesInFile("inputs/input8.txt");
	std::string directions = input[0];
	input.erase(input.begin(), input.begin() + 2);
	std::map<std::string, std::pair<std::string, std::string>> network;
	std::vector<std::string> starts;
	for (const auto& line : input) {
		std::string startNode = line.substr(0, 3);
		std::string left = line.substr(line.find('(') + 1, 3);
		std::string right = line.substr(line.find(',') + 2, 3);
		network.insert({ startNode, std::pair(left,right) });
		if (startNode[2] == 'A')
			starts.push_back(startNode);
	}
	std::vector<int64_t> results;
	std::string rightDirection;
	std::string leftDirection;
	for (auto& start : starts) {
		int64_t res = 0;
		bool solved = false;
		while (!solved) {
			for (const auto& direction : directions) {
				auto it = network.find(start);
				if (it != network.end()) {
					rightDirection = it->second.second;
					leftDirection = it->second.first;
				}
				else {
					solved = true;
					break;
				}
				if (direction == 'R') {
					res++;
					if (rightDirection[2] == 'Z') {
						results.push_back(res);
						solved = true;
						break;
					}
					start = rightDirection;
				}
				else {
					res++;
					if (leftDirection[2] == 'Z') {
						results.push_back(res);
						solved = true;
						break;
					}
					start = leftDirection;
				}
			}
		}
	}
	int64_t lcm = results[0];
	for (int i = 1; i < results.size(); i++) {
		int64_t num = results[i];
		lcm = std::lcm(lcm, num);
	}

	std::cout << lcm;
}