#include "input.h"
#include "task10.h"

enum Directions {
	left = 0, right, up, down
};

struct Coords {
	int64_t x = 0;
	int64_t y = 0;
};

Coords GoInDirection(Directions direction) {
	Coords coords;
	switch (direction) {
	case left:
		return Coords{ -1,0 };
	case right:
		return Coords{ 1,0 };
	case down:
		return Coords{ 0,1 };
	case up:
		return Coords{ 0,-1 };
	default:
		std::cout << "Invalid direction!" << std::endl;
		return Coords{ 0,0 };
	}
}

char ReplaceSWith(Coords startCoords, const std::vector<std::string>& input) {
	bool topValid = false;
	bool bottomValid = false;
	bool leftValid = false;
	bool rightValid = false;
	if (startCoords.y != 0) {
		if (input[startCoords.y - 1][startCoords.x] == '|' || input[startCoords.y - 1][startCoords.x] == 'F' || input[startCoords.y - 1][startCoords.x] == '7') {
			topValid = true;
		}
	}
	if(startCoords.y != input.size()){
		if (input[startCoords.y + 1][startCoords.x] == '|' || input[startCoords.y + 1][startCoords.x] == 'L' || input[startCoords.y + 1][startCoords.x] == 'J') {
			bottomValid = true;
		}
	}
	if (startCoords.x != input[0].size()) {
		if (input[startCoords.y][startCoords.x + 1] == '-' || input[startCoords.y][startCoords.x + 1] == 'J' || input[startCoords.y][startCoords.x + 1] == '7') {
			rightValid = true;
		}
	}
	if (startCoords.x != 0){
		if (input[startCoords.y][startCoords.x - 1] == '-' || input[startCoords.y][startCoords.x - 1] == 'F' || input[startCoords.y][startCoords.x - 1] == 'L') {
			leftValid = true;
		}
	}
	if (bottomValid && topValid) {
		return '|';
	}
	else if (bottomValid && rightValid) {
		return 'F';
	}
	else if (leftValid && rightValid) {
		return '-';
	}
	else if (topValid && rightValid) {
		return 'L';
	}
	else if (topValid && leftValid) {
		return 'J';
	}
	else if (bottomValid && leftValid) {
		return '7';
	}
	else {
		return 'x';
	}
}

Coords ChooseDirection(Coords startCoords, std::vector<std::string>& input) {
	if (startCoords.y != 0) {
		if (input[startCoords.y - 1][startCoords.x] == '|' || input[startCoords.y - 1][startCoords.x] == 'F' || input[startCoords.y - 1][startCoords.x] == '7') {
			return Coords{ 0,-1 };
		}
	}
	if (startCoords.y != input.size()) {
		if (input[startCoords.y + 1][startCoords.x] == '|' || input[startCoords.y + 1][startCoords.x] == 'L' || input[startCoords.y + 1][startCoords.x] == 'J') {
			return Coords{ 0, 1 };
		}
	}
	if (startCoords.x != input[0].size()) {
		if (input[startCoords.y][startCoords.x + 1] == '-' || input[startCoords.y][startCoords.x + 1] == 'J' || input[startCoords.y][startCoords.x + 1] == '7') {
			return Coords{ 1, 0 };
		}
	}
	if (startCoords.x != 0) {
		if (input[startCoords.y][startCoords.x - 1] == '-' || input[startCoords.y][startCoords.x - 1] == 'F' || input[startCoords.y][startCoords.x - 1] == 'L') {
			return Coords{ -1,0 };
		}
	}
	return Coords{0,0};
}


void Task10::Part1() {
	auto input = Utility::ReadAllLinesInFile("inputs/input10.txt");
	std::pair<int64_t, int64_t> startCoords;
	std::map<std::pair<int64_t, int64_t>, char> path;

	bool found = false;
	for (int y = 0; y < input.size(); y++) {
		for (int x = 0; x < input[y].size(); x++) {
			if (input[y][x] == 'S') {
				startCoords = { x,y };
				break;
			}
		}
		if (found)
			break;
	}

	// choose where to go from start
	Coords goFromStart = ChooseDirection({ startCoords.first,startCoords.second }, input);

	std::pair<int64_t, int64_t> nextCharCoords = { startCoords.first + goFromStart.x, startCoords.second + goFromStart.y};
	char nextChar = input[nextCharCoords.second][nextCharCoords.first];
	std::pair<int64_t, int64_t> currCharCoords = startCoords;
	char currChar = input[startCoords.second][startCoords.first];
	path.insert({ currCharCoords,currChar });
	Coords directionCoords;
	while(nextChar != 'S'){
		switch (nextChar) {
		case '-':
			if (currCharCoords.first > nextCharCoords.first){
				//go left
				directionCoords = GoInDirection(left);
			}
			else {
				//go right
				directionCoords = GoInDirection(right);
			}
			break;
		case '|':
			if (currCharCoords.second > nextCharCoords.second) {
				//go up
				directionCoords = GoInDirection(up);
			}
			else {
				//go down
				directionCoords = GoInDirection(down);
			}
			break;
		case '7':
			if (currCharCoords.second == nextCharCoords.second) {
				//go down
				directionCoords = GoInDirection(down);
			}
			else {
				//go left
				directionCoords = GoInDirection(left);
			}
			break;
		case 'J':
			if (currCharCoords.second == nextCharCoords.second) {
				//go up
				directionCoords = GoInDirection(up);
			}
			else {
				//go left
				directionCoords = GoInDirection(left);
			}
			break;
		case 'L':
			if (currCharCoords.second == nextCharCoords.second) {
				//go up
				directionCoords = GoInDirection(up);
			}
			else {
				//go right
				directionCoords = GoInDirection(right);
			}
			break;
		case 'F':
			if (currCharCoords.second == nextCharCoords.second) {
				//go down
				directionCoords = GoInDirection(down);
			}
			else {
				//go right
				directionCoords = GoInDirection(right);
			}
			break;
		default:
			break;
		}
		currCharCoords = nextCharCoords;
		currChar = nextChar;
		nextCharCoords = { currCharCoords.first + directionCoords.x, currCharCoords.second + directionCoords.y};
		nextChar = input[nextCharCoords.second][nextCharCoords.first];
		path.insert({ currCharCoords, currChar });
	}
	std::cout << (path.size() / 2);
}

void Task10::Part2() {
	auto input = Utility::ReadAllLinesInFile("inputs/input10.txt");
	std::pair<int64_t, int64_t> startCoords;
	std::map<std::pair<int64_t, int64_t>, char> path;

	for (int y = 0; y < input.size(); y++) {
		for (int x = 0; x < input[y].size(); x++) {
			if (input[y][x] == 'S') {
				startCoords = { x,y };
			}
		}
	}
	//choose where to go from start
	Coords goFromStart = ChooseDirection({ startCoords.first,startCoords.second }, input);

	std::pair<int64_t, int64_t> nextCharCoords = { startCoords.first + goFromStart.x, startCoords.second + goFromStart.y };
	char nextChar = input[nextCharCoords.second][nextCharCoords.first];
	std::pair<int64_t, int64_t> currCharCoords = startCoords;
	char currChar = input[startCoords.second][startCoords.first];
	path.insert({ currCharCoords,currChar });
	Coords directionCoords;
	while (nextChar != 'S') {
		switch (nextChar) {
		case '-':
			if (currCharCoords.first > nextCharCoords.first) {
				//go left
				directionCoords = GoInDirection(left);
			}
			else {
				//go right
				directionCoords = GoInDirection(right);
			}
			break;
		case '|':
			if (currCharCoords.second > nextCharCoords.second) {
				//go up
				directionCoords = GoInDirection(up);
			}
			else {
				//go down
				directionCoords = GoInDirection(down);
			}
			break;
		case '7':
			if (currCharCoords.second == nextCharCoords.second) {
				//go down
				directionCoords = GoInDirection(down);
			}
			else {
				//go left
				directionCoords = GoInDirection(left);
			}
			break;
		case 'J':
			if (currCharCoords.second == nextCharCoords.second) {
				//go up
				directionCoords = GoInDirection(up);
			}
			else {
				//go left
				directionCoords = GoInDirection(left);
			}
			break;
		case 'L':
			if (currCharCoords.second == nextCharCoords.second) {
				//go up
				directionCoords = GoInDirection(up);
			}
			else {
				//go right
				directionCoords = GoInDirection(right);
			}
			break;
		case 'F':
			if (currCharCoords.second == nextCharCoords.second) {
				//go down
				directionCoords = GoInDirection(down);
			}
			else {
				//go right
				directionCoords = GoInDirection(right);
			}
			break;
		default:
			break;
		}
		currCharCoords = nextCharCoords;
		currChar = nextChar;
		nextCharCoords = { currCharCoords.first + directionCoords.x, currCharCoords.second + directionCoords.y };
		nextChar = input[nextCharCoords.second][nextCharCoords.first];
		path.insert({ currCharCoords, currChar });
	}

	//Replace everything that is not within the path with .
	for (int y = 0; y < input.size(); y++) {
		for (int x = 0; x < input[y].size(); x++) {
			if (path.find({ x,y }) == path.end()) {
				input[y][x] = '.';
			}
		}
	}

	input[startCoords.second][startCoords.first] = ReplaceSWith(Coords{ startCoords.first, startCoords.second }, input);
	
	int res = 0;
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
				if (within) {
					res++;
				}
			}
		}
	}

	std::cout << res;
}