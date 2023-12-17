#include "input.h"
#include "task16.h"

enum Direction {
	left,right,up,down
};

struct Coords {
	int x=0, y =0;
};

Coords GetNextPosition(Coords coords, Direction dir, std::vector<std::string> &input) {
	if (dir == right) {
		if (coords.x + 1 >= input[0].size()) {
			return { coords.x, coords.y };
		}
		else {
			return { coords.x + 1, coords.y };
		}
	}
	else if (dir == left) {
		if (coords.x - 1 < 0) {
			return { coords.x, coords.y };
		}
		else {
			return { coords.x - 1, coords.y };
		}
	}
	else if (dir == up) {
		if (coords.y - 1 < 0) {
			return { coords.x, coords.y };
		}
		else {
			return { coords.x, coords.y - 1 };
		}
	}
	else {
		if (coords.y + 1 >= input.size()) {
			return { coords.x,coords.y };
		}
		else {
			return { coords.x,coords.y + 1 };
		}
	}
}

Direction ChangeDirection(Direction dir, char ch) {
	if (ch == '/') {
		if (dir == left) {
			return down;
		}
		else if (dir == right) {
			return up;
		}
		else if (dir == up) {
			return right;
		}
		else
			return left;
	}
	else if (ch == '\\') {
		if (dir == left) {
			return up;
		}
		else if (dir == right) {
			return down;
		}
		else if (dir == up) {
			return left;
		}
		else
			return right;
	}
	return dir;
}

std::vector<Direction> SplitBeam(Direction dir, char ch) {
	if (ch == '-') {
		if (dir == up || dir == down) {
			return { left,right };
		}
	}
	else if (ch == '|') {
		if (dir == left || dir == right) {
			return { up,down };
		}
	}
	return { dir };
}


void Task16::Part1() {
	std::vector<std::string> input = Utility::ReadAllLinesInFile("inputs/input16.txt");
	int res = 0;
	
	std::vector<std::pair<Coords, Direction>> beams;
	std::vector<Coords> beamLevels;
	//beam going from top-left corner to the right
	beams.push_back({ {-1,0},right });
	size_t idx = 0;
	std::vector<Direction> split;
	while (idx != beams.size()) {
		Coords coordsC = beams[idx].first;
		Direction dir = beams[idx].second;
		Coords coordsN = GetNextPosition(coordsC, dir, input);
		char nextChar = input[coordsN.y][coordsN.x];
		while (coordsC.x != coordsN.x || coordsC.y != coordsN.y) {
			if (nextChar == '/' || nextChar == '\\') {
				dir = ChangeDirection(dir, nextChar);
			}
			else if (nextChar == '-' || nextChar == '|') {
				split = SplitBeam(dir, nextChar);
				if (split.size() == 2) {
					bool cycledFirst = false;
					for (auto beam : beams) {
						if (beam.first.x == coordsN.x && beam.first.y == coordsN.y) {
							cycledFirst = true;
							break;
						}
					}
					if (!cycledFirst) {
						dir = split[0];
						beams.push_back({ coordsN,split[1] });
					}
					else {
						break;
					}

				/*	bool cycled = false;
					for (auto beam : beams) {
						if (beam.first.x == coordsN.x && beam.first.y == coordsN.y && dir == beam.second) {
							cycled = true;
							break;
						}
					}
					if (!cycled && cycledFirst) {
						dir = split[1];
					}*/
				}
				else
					dir = split[0];
				split.clear();
			}

			bool energized = false;
			for(int i = 0; i <beamLevels.size();i++){
				if (beamLevels[i].x == coordsN.x && beamLevels[i].y == coordsN.y) {
					energized = true;
					break;
				}
			}
			if(!energized)
				beamLevels.push_back(coordsN);

			coordsC = coordsN;
			coordsN = GetNextPosition(coordsC, dir, input);
			nextChar = input[coordsN.y][coordsN.x];
		}
		idx++;
	}
	
	res = beamLevels.size();
	std::cout << res;
}

void Task16::Part2() {
	std::cout << "Not done yet.";
}