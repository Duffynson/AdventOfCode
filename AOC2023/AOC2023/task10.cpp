#include "input.h"
#include "task10.h"

void Task10::Part1() {
	auto input = Utility::ReadAllLinesInFile("inputs/input10.txt");
	std::pair<int64_t, int64_t> startCoords;
	//from the start go either left or up

	for (int y = 0; y < input.size(); y++) {
		for (int x = 0; x < input[y].size(); x++) {
			if (input[y][x] == 'S') {
				startCoords = { x,y };
			}
		}
	}
	std::map<std::pair<int64_t, int64_t>, char> path;
	std::pair<int64_t, int64_t> nextCharCoords = { startCoords.first - 1, startCoords.second };
	char nextChar = input[nextCharCoords.second][nextCharCoords.first];
	std::pair<int64_t, int64_t> currCharCoords = startCoords;
	char currChar = input[startCoords.second][startCoords.first];
	path.insert({ currCharCoords,currChar });
	while(nextChar != 'S'){
		switch (nextChar) {
		case '-':
			if (currCharCoords.first > nextCharCoords.first){
				//go left
				currCharCoords = nextCharCoords;
				currChar = nextChar;
				nextCharCoords = {currCharCoords.first - 1, currCharCoords.second};
				nextChar = input[nextCharCoords.second][nextCharCoords.first];
				path.insert({ currCharCoords, currChar });
			}
			else {
				//go right
				currCharCoords = nextCharCoords;
				currChar = nextChar;
				nextCharCoords = { currCharCoords.first + 1, currCharCoords.second };
				nextChar = input[nextCharCoords.second][nextCharCoords.first];
				path.insert({ currCharCoords, currChar });
			}
			break;
		case '|':
			if (currCharCoords.second > nextCharCoords.second) {
				//go up
				currCharCoords = nextCharCoords;
				currChar = nextChar;
				nextCharCoords = { currCharCoords.first, currCharCoords.second - 1 };
				nextChar = input[nextCharCoords.second][nextCharCoords.first];
				path.insert({ currCharCoords, currChar });
			}
			else {
				//go down
				currCharCoords = nextCharCoords;
				currChar = nextChar;
				nextCharCoords = { currCharCoords.first, currCharCoords.second + 1 };
				nextChar = input[nextCharCoords.second][nextCharCoords.first];
				path.insert({ currCharCoords, currChar });
			}
			break;
		case '7':
			if (currCharCoords.second == nextCharCoords.second) {
				//go down
				currCharCoords = nextCharCoords;
				currChar = nextChar;
				nextCharCoords = { currCharCoords.first, currCharCoords.second + 1 };
				nextChar = input[nextCharCoords.second][nextCharCoords.first];
				path.insert({ currCharCoords, currChar });
			}
			else {
				//go left
				currCharCoords = nextCharCoords;
				currChar = nextChar;
				nextCharCoords = { currCharCoords.first - 1, currCharCoords.second };
				nextChar = input[nextCharCoords.second][nextCharCoords.first];
				path.insert({ currCharCoords, currChar });
			}
			break;
		case 'J':
			if (currCharCoords.second == nextCharCoords.second) {
				//go up
				currCharCoords = nextCharCoords;
				currChar = nextChar;
				nextCharCoords = { currCharCoords.first, currCharCoords.second - 1 };
				nextChar = input[nextCharCoords.second][nextCharCoords.first];
				path.insert({ currCharCoords, currChar });
			}
			else {
				//go left
				currCharCoords = nextCharCoords;
				currChar = nextChar;
				nextCharCoords = { currCharCoords.first - 1, currCharCoords.second };
				nextChar = input[nextCharCoords.second][nextCharCoords.first];
				path.insert({ currCharCoords, currChar });
			}
			break;
		case 'L':
			if (currCharCoords.second == nextCharCoords.second) {
				//go up
				currCharCoords = nextCharCoords;
				currChar = nextChar;
				nextCharCoords = { currCharCoords.first, currCharCoords.second - 1 };
				nextChar = input[nextCharCoords.second][nextCharCoords.first];
				path.insert({ currCharCoords, currChar });
			}
			else {
				//go right
				currCharCoords = nextCharCoords;
				currChar = nextChar;
				nextCharCoords = { currCharCoords.first + 1, currCharCoords.second };
				nextChar = input[nextCharCoords.second][nextCharCoords.first];
				path.insert({ currCharCoords, currChar });
			}
			break;
		case 'F':
			if (currCharCoords.second == nextCharCoords.second) {
				//go down
				currCharCoords = nextCharCoords;
				currChar = nextChar;
				nextCharCoords = { currCharCoords.first, currCharCoords.second + 1 };
				nextChar = input[nextCharCoords.second][nextCharCoords.first];
				path.insert({ currCharCoords, currChar });
			}
			else {
				//go right
				currCharCoords = nextCharCoords;
				currChar = nextChar;
				nextCharCoords = { currCharCoords.first + 1, currCharCoords.second };
				nextChar = input[nextCharCoords.second][nextCharCoords.first];
				path.insert({ currCharCoords, currChar });
			}
			break;
		default:
			break;
		}
	}
	std::cout << (path.size() / 2);
}

void Task10::Part2() {
	auto input = Utility::ReadAllLinesInFile("inputs/input10.txt");
	std::pair<int64_t, int64_t> startCoords;
	//from the start go either left or up

	for (int y = 0; y < input.size(); y++) {
		for (int x = 0; x < input[y].size(); x++) {
			if (input[y][x] == 'S') {
				startCoords = { x,y };
			}
		}
	}
	std::map<std::pair<int64_t, int64_t>, char> path;
	std::pair<int64_t, int64_t> nextCharCoords = { startCoords.first - 1, startCoords.second };
	char nextChar = input[nextCharCoords.second][nextCharCoords.first];
	std::pair<int64_t, int64_t> currCharCoords = startCoords;
	char currChar = input[startCoords.second][startCoords.first];
	path.insert({ currCharCoords,currChar });
	while (nextChar != 'S') {
		switch (nextChar) {
		case '-':
			if (currCharCoords.first > nextCharCoords.first) {
				//go left
				currCharCoords = nextCharCoords;
				currChar = nextChar;
				nextCharCoords = { currCharCoords.first - 1, currCharCoords.second };
				nextChar = input[nextCharCoords.second][nextCharCoords.first];
				path.insert({ currCharCoords, currChar });
			}
			else {
				//go right
				currCharCoords = nextCharCoords;
				currChar = nextChar;
				nextCharCoords = { currCharCoords.first + 1, currCharCoords.second };
				nextChar = input[nextCharCoords.second][nextCharCoords.first];
				path.insert({ currCharCoords, currChar });
			}
			break;
		case '|':
			if (currCharCoords.second > nextCharCoords.second) {
				//go up
				currCharCoords = nextCharCoords;
				currChar = nextChar;
				nextCharCoords = { currCharCoords.first, currCharCoords.second - 1 };
				nextChar = input[nextCharCoords.second][nextCharCoords.first];
				path.insert({ currCharCoords, currChar });
			}
			else {
				//go down
				currCharCoords = nextCharCoords;
				currChar = nextChar;
				nextCharCoords = { currCharCoords.first, currCharCoords.second + 1 };
				nextChar = input[nextCharCoords.second][nextCharCoords.first];
				path.insert({ currCharCoords, currChar });
			}
			break;
		case '7':
			if (currCharCoords.second == nextCharCoords.second) {
				//go down
				currCharCoords = nextCharCoords;
				currChar = nextChar;
				nextCharCoords = { currCharCoords.first, currCharCoords.second + 1 };
				nextChar = input[nextCharCoords.second][nextCharCoords.first];
				path.insert({ currCharCoords, currChar });
			}
			else {
				//go left
				currCharCoords = nextCharCoords;
				currChar = nextChar;
				nextCharCoords = { currCharCoords.first - 1, currCharCoords.second };
				nextChar = input[nextCharCoords.second][nextCharCoords.first];
				path.insert({ currCharCoords, currChar });
			}
			break;
		case 'J':
			if (currCharCoords.second == nextCharCoords.second) {
				//go up
				currCharCoords = nextCharCoords;
				currChar = nextChar;
				nextCharCoords = { currCharCoords.first, currCharCoords.second - 1 };
				nextChar = input[nextCharCoords.second][nextCharCoords.first];
				path.insert({ currCharCoords, currChar });
			}
			else {
				//go left
				currCharCoords = nextCharCoords;
				currChar = nextChar;
				nextCharCoords = { currCharCoords.first - 1, currCharCoords.second };
				nextChar = input[nextCharCoords.second][nextCharCoords.first];
				path.insert({ currCharCoords, currChar });
			}
			break;
		case 'L':
			if (currCharCoords.second == nextCharCoords.second) {
				//go up
				currCharCoords = nextCharCoords;
				currChar = nextChar;
				nextCharCoords = { currCharCoords.first, currCharCoords.second - 1 };
				nextChar = input[nextCharCoords.second][nextCharCoords.first];
				path.insert({ currCharCoords, currChar });
			}
			else {
				//go right
				currCharCoords = nextCharCoords;
				currChar = nextChar;
				nextCharCoords = { currCharCoords.first + 1, currCharCoords.second };
				nextChar = input[nextCharCoords.second][nextCharCoords.first];
				path.insert({ currCharCoords, currChar });
			}
			break;
		case 'F':
			if (currCharCoords.second == nextCharCoords.second) {
				//go down
				currCharCoords = nextCharCoords;
				currChar = nextChar;
				nextCharCoords = { currCharCoords.first, currCharCoords.second + 1 };
				nextChar = input[nextCharCoords.second][nextCharCoords.first];
				path.insert({ currCharCoords, currChar });
			}
			else {
				//go right
				currCharCoords = nextCharCoords;
				currChar = nextChar;
				nextCharCoords = { currCharCoords.first + 1, currCharCoords.second };
				nextChar = input[nextCharCoords.second][nextCharCoords.first];
				path.insert({ currCharCoords, currChar });
			}
			break;
		default:
			break;
		}
	}
	for (int y = 0; y < input.size(); y++) {
		for (int x = 0; x < input[y].size(); x++) {
			if (path.find({ x,y }) == path.end()) {
				input[y][x] = '.';
			}
		}
	}

	input[startCoords.second][startCoords.first] = 'J';
	std::vector<char> outsideChars;
	for (auto line : input) {
		bool within = false;
		int up = 0;
		for (auto ch : line) {
			if (ch == '|') {
				if (up == 0) {
					within = !within;
				}
			}
			else if (ch == '-') {
			}
			else if (ch == 'L' || ch == 'F') {
				if (up == 0) {
					if (ch == 'L')
						up = 1;
					else
						up = 2;
				}
			}
			else if (ch == '7' || ch == 'J') {
				if (up == 1 || up == 2) {
					if (ch != (up == 1 ? 'J' : '7')) {
						within = !within;
					}
				}
				up = 0;
			}
			else if (ch == '.') {	
				if (!within) {
					outsideChars.push_back(ch);
				}
			}
		}
	}

	int res = input.size() * input[0].size() - path.size() - outsideChars.size();
	std::cout << res;
}