#include "day21.h"

using PadPaths = std::map<std::pair<char, char>, std::string>;
using Pad = std::vector<std::string>;

std::map<std::pair<int, int>, char> directionalChars = { {{-1,0},'^'},{{1,0},'v'}, {{0,-1},'<'},{{0,1},'>'} };
const Pad numpad = { "789","456","123","#0A"};
const Pad keypad = { "#^A","<v>" };

void populateNumpadMap(PadPaths& numpadPaths,const Pad& numpad) {
	for (int x = 0; x < numpad.size(); x++) {
		for (int y = 0; y < numpad[x].size(); y++) {
			char start = numpad[x][y];
			if (start == '#') continue;
			for (int ex = 0; ex < numpad.size(); ex++) {
				for (int ey = 0; ey < numpad[ex].size(); ey++) {
					if (x == ex && y == ey) continue;
					std::string directionsString;
					char end = numpad[ex][ey];
					if (end == '#') continue;
					int diffx = ex - x;
					int diffy = ey - y;
					int dirx = 0;
					int diry = 0;
					std::pair<int, int> directions;
					if (x != 3) {
						if (diffy != 0) {
							diry = diffy / std::abs(diffy);
							directions = { 0, diry };
							for (int i = 0; i < std::abs(diffy); i++) {
								directionsString += directionalChars[directions];

							}
						}
						if (diffx != 0) {
							dirx = diffx / std::abs(diffx);
							directions = { dirx, 0 };
							for (int i = 0; i < std::abs(diffx); i++) {
								directionsString += directionalChars[directions];
							}
						}
					}
					else {
						if (diffx != 0) {
							dirx = diffx / std::abs(diffx);
							directions = { dirx, 0 };
							for (int i = 0; i < std::abs(diffx); i++) {
								directionsString += directionalChars[directions];
							}
						}
						if (diffy != 0) {
							diry = diffy / std::abs(diffy);
							directions = { 0, diry };
							for (int i = 0; i < std::abs(diffy); i++) {
								directionsString += directionalChars[directions];

							}
						}
					}
					numpadPaths[{start, end}] = directionsString;
				}
			}
		}
	}

}

void populateKeypadMap(PadPaths& keypadPaths, const Pad& keypad) {
	for (int x = 0; x < keypad.size(); x++) {
		for (int y = 0; y < keypad[x].size(); y++) {
			char start = keypad[x][y];
			if (start == '#') continue;
			for (int ex = 0; ex < keypad.size(); ex++) {
				for (int ey = 0; ey < keypad[ex].size(); ey++) {
					if (x == ex && y == ey) continue;
					std::string directionsString;
					char end = keypad[ex][ey];
					if (end == '#') continue;
					int diffx = ex - x;
					int diffy = ey - y;
					int dirx = 0;
					int diry = 0;
					std::pair<int, int> directions;
					if (x == 1) {
						if (diffy != 0) {
							diry = diffy / std::abs(diffy);
							directions = { 0, diry };
							for (int i = 0; i < std::abs(diffy); i++) {
								directionsString += directionalChars[directions];

							}
						}
						if (diffx != 0) {
							dirx = diffx / std::abs(diffx);
							directions = { dirx, 0 };
							for (int i = 0; i < std::abs(diffx); i++) {
								directionsString += directionalChars[directions];
							}
						}
					}
					else {
						if (diffx != 0) {
							dirx = diffx / std::abs(diffx);
							directions = { dirx, 0 };
							for (int i = 0; i < std::abs(diffx); i++) {
								directionsString += directionalChars[directions];
							}
						}
						if (diffy != 0) {
							diry = diffy / std::abs(diffy);
							directions = { 0, diry };
							for (int i = 0; i < std::abs(diffy); i++) {
								directionsString += directionalChars[directions];

							}
						}
					}
					keypadPaths[{start, end}] = directionsString;
				}
			}
		}
	}
}

void Day21::Task1() const {
	int result = 0;
	PadPaths numpadPaths;
	PadPaths keypadPaths;
	populateNumpadMap(numpadPaths, numpad);
	populateKeypadMap(keypadPaths, keypad);

	std::cout << result << std::endl;
}

void Day21::Task2() const {


}