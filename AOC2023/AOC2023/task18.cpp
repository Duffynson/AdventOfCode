#include "input.h"
#include "task18.h"

struct Coords {
	int x = 0, y = 0;
};

std::map<char, Coords> directions = {
	{'R',{1,0}},
	{'L',{-1,0}},
	{'U',{0,-1}},
	{'D',{0,1}}
};

std::map<char, Coords> directions2 = {
	{'0',{1,0}},
	{'1',{0,1}},
	{'2',{-1,0}},
	{'3',{0,-1}}
};

void Task18::Part1() {
	std::vector<std::string> input = Utility::ReadAllLinesInFile("inputs/input18.txt");
	int b = 0;

	std::vector<Coords> points = { {0,0} };
	for (std::string line : input) {
		char dir = line[0];
		int i = std::stoi(line.substr(1, line.size() - line.find('(')));
		Coords delta = directions.find(dir)->second;
		b += i;
		int dr = delta.y;
		int dc = delta.x;
		size_t lastIndex = points.size() - 1;
		Coords lastPoint = points[lastIndex];
		int c = lastPoint.x;
		int r = lastPoint.y;
		points.push_back({ c + dc * i,r + dr * i });
	}

	size_t len = points.size();
	int sum = 0;
	for (int i = 0; i < len; i++) {
		sum += points[i].x * (points[(i + len - 1) % len].y - points[(i + 1) % len].y);
	}
	int A = std::abs(sum) / 2;

	int i = A - b / 2 + 1;

	int res = i + b;
	std::cout << res;
}

void Task18::Part2() {
	std::vector<std::string> input = Utility::ReadAllLinesInFile("inputs/input18.txt");
	int64_t b = 0;

	std::vector<Coords> points = { {0,0} };
	for (std::string line : input) {
		std::string hex = line.substr(line.find('(') + 2, line.find(')') - line.find('(') - 2);
		char dir = hex[hex.size() - 1];
		hex.pop_back();
		int i = std::stoi(hex,nullptr,16);
		auto [dc,dr] = directions2.find(dir)->second;
		b += i;
		auto [r, c] = points.back();
		points.push_back({ c + dc * i,r + dr * i });
	}

	size_t len = points.size();
	int64_t sum = 0;
	for (int i = 0; i < len; ++i) {
		sum += points[i].x * (points[(i + len - 1) % len].y - points[(i + 1) % len].y);
	}
	int64_t A = std::abs(sum) / 2;

	int64_t i = A - b / 2 + 1;

	int64_t res = i + b;
	std::cout << res;
}

//last answer 446522379
//821843187


//correct 64294334780659