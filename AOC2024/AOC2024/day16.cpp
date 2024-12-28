#include "day16.h"
#define GREEN "\033[32m"
#define RESET "\033[0m"

const std::vector<std::pair<int, int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

void Day16::Task1() const {
	int result = 0;
	auto grid = ReadAllLinesInFile("input.txt");

	std::pair<int, int> start;
	std::pair<int, int> end;
	std::set<std::pair<int, int>> unvisitedNodes;
	std::map<std::pair<int, int>, int> nodeValues;

	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[i].size(); j++) {
			if (grid[i][j] == '#') {
				continue;
			}
			unvisitedNodes.insert({ i,j });
			nodeValues[{i, j}] = INT_MAX;
			if (grid[i][j] == 'S') {
				start = { i,j };
				nodeValues[{i, j}] = 0;
			}
			if (grid[i][j] == 'E') {
				end = { i,j };
			}
		}
	}

	std::map<std::pair<int, int>, std::pair<int, int>> nodeDirections;
	nodeDirections[start] = {0,1};
	while (!unvisitedNodes.empty()) {
		std::pair<int, int> xy;
		int x = INT_MAX;
		for (const auto& [key, value] : nodeValues) {
			if (value < x && unvisitedNodes.find(key) != unvisitedNodes.end()) {
				x = value;
				xy = key;
			}
		}
		for (const auto& [dirX, dirY] : directions) {
			int nextX = xy.first + dirX;
			int nextY = xy.second + dirY;
			if (grid[nextX][nextY] != '#') {
				auto previousDirection = nodeDirections[xy];
				if (previousDirection.first == dirX && previousDirection.second == dirY) {
					int temp = nodeValues[xy] + 1;
					if (nodeValues[{nextX, nextY}] > temp) {
						nodeValues[{nextX, nextY}] = temp;
						nodeDirections[{nextX, nextY}] = { dirX,dirY };
					}
				}
				else {
					int temp = nodeValues[xy] + 1001;
					if (nodeValues[{nextX, nextY}] > temp) {
						nodeValues[{nextX, nextY}] = temp;
						nodeDirections[{nextX, nextY}] = { dirX,dirY };
					}
				}
			}
		}
		unvisitedNodes.erase(xy);
	}

	result = nodeValues[end];
	std::cout << result << std::endl;
}

using Node = std::tuple<int, int, int, int>;

void Day16::Task2() const {
	int result = 0;
	auto grid = ReadAllLinesInFile("input.txt");

	int rows = grid.size();
	int cols = grid[0].size();

	int sr, sc;
	for (int r = 0; r < rows; ++r) {
		for (int c = 0; c < cols; ++c) {
			if (grid[r][c] == 'S') {
				sr = r;
				sc = c;
				break;
			}
		}
	}

	std::priority_queue<std::pair<int, Node>, std::vector<std::pair<int, Node>>, std::greater<>> pq;
	std::map<Node, int> lowestCost;
	std::map<Node, std::set<Node>> backtrack;
	std::set<Node> endStates;

	auto start = std::make_tuple(sr, sc, 0, 1);
	pq.emplace(0, start);
	lowestCost[start] = 0;

	int bestCost = INT_MAX;

	while (!pq.empty()) {
		auto current = pq.top();
		int cost = current.first;
		auto state = current.second;
		pq.pop();

		auto [r, c, dr, dc] = state;

		if (cost > lowestCost[state]) continue;

		if (grid[r][c] == 'E') {
			if (cost > bestCost) break;
			bestCost = cost;
			endStates.insert(state);
		}

		std::vector<std::tuple<int, int, int, int, int>> moves = {
			{cost + 1, r + dr, c + dc, dr, dc},
			{cost + 1000, r, c, dc, -dr},
			{cost + 1000, r, c, -dc, dr}
		};

		for (const auto& move : moves) {
			auto [newCost, nr, nc, ndr, ndc] = move;

			if (nr < 0 || nr >= rows || nc < 0 || nc >= cols || grid[nr][nc] == '#')
				continue;

			std::tuple<int, int, int, int> newState = { nr, nc, ndr, ndc };
			int lowest = lowestCost.count(newState) ? lowestCost[newState] : INT_MAX;

			if (newCost > lowest) continue;

			if (newCost < lowest) {
				backtrack[newState].clear();
				lowestCost[newState] = newCost;
			}

			backtrack[newState].insert(state);
			pq.emplace(newCost, newState);
		}
	}

	std::deque<std::tuple<int, int, int, int>> states(endStates.begin(), endStates.end());
	std::set<std::tuple<int, int, int, int>> seen(endStates.begin(), endStates.end());

	while (!states.empty()) {
		auto key = states.front();
		states.pop_front();

		for (const auto& last : backtrack[key]) {
			if (seen.count(last)) continue;
			seen.insert(last);
			states.push_back(last);
		}
	}

	std::set<std::pair<int, int>> path;
	for (const auto& state : seen) {
		int r = std::get<0>(state);
		int c = std::get<1>(state);
		path.emplace(r, c);
	}

	std::cout << path.size() << std::endl;
}