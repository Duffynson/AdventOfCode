#include "input.h"
#include "task15.h"

int Evaluate(std::string step) {
	int temp = 0;
	for (auto ch : step) {
		temp += (int)ch;
		temp = temp * 17;
		temp = temp % 256;
	}
	return temp;
}

void Task15::Part1() {
	std::vector<std::string> input = Utility::ReadAllLinesInFile("inputs/input15.txt");
	int res = 0;
	input = Utility::SplitStringByComma(input[0]);

	for (auto step : input) {
		res += Evaluate(step);
	}
	std::cout << res;
}

void Task15::Part2() {
	std::vector<std::string> input = Utility::ReadAllLinesInFile("inputs/input15.txt");
	int res = 0;
	input = Utility::SplitStringByComma(input[0]);
	std::map<int, std::vector<std::pair<std::string, char>>> boxes;

	for (auto step : input) {
		std::string label;
		int box = 0;
		char operation = ' ';
		char focal = ' ';
		for (auto ch : step) {
			if (isdigit(ch)) {
				focal = ch;
			}
			else if ((ch == '=' || ch == '-')) {
				operation = ch;
			}
			else {
				label.push_back(ch);
			}

		}
		box = Evaluate(label);
		//label.insert(0, std::to_string(temp));
		std::vector<std::pair<std::string, char>> currentBox;
		auto it = boxes.find(box);
		if (it != boxes.end()) {
			currentBox = it->second;
		}
		if (operation == '=') {
			bool replaced = false;
			for (auto& [currLabel, currFocal] : currentBox) {
				if (currLabel == label) {
					currLabel = label;
					currFocal = focal;
					replaced = true;
				}
			}
			if (!replaced) {
				currentBox.push_back(std::make_pair(label, focal));
			}
			if (it == boxes.end()) {
				boxes.insert({ box, currentBox });
			}
			else {
				boxes[box] = currentBox;
			}

		}
		else {
			for (int i = 0; i < currentBox.size();i++) {
				if (currentBox[i].first == label) {
					currentBox.erase(currentBox.begin() + i);
				}
			}
			boxes[box] = currentBox;
		}
	}

	for (auto it = boxes.begin(); it != boxes.end(); ++it) {
		int box = it->first + 1;
		std::vector<std::pair<std::string, char>> currVec = it->second;
		for(int i = 0; i< currVec.size(); ++i){
			int focal = currVec[i].second - '0';
			res += box*(i+1)*focal;
		}
	}

	std::cout << res;

}