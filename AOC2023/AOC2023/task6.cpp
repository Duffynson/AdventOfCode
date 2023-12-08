#include "input.h"
#include "task6.h"

void Task6::Part1() {
	auto input = Utility::ReadAllLinesInFile("inputs/input6.txt");
	int res = 1;
	std::string timesLine = input[0].substr(input[0].find(':') + 1, input[0].size());
	std::string distancesLine = input[1].substr(input[1].find(':') + 1, input[1].size());
	
	std::vector<int> times;
	std::vector<int> distances;
	std::stringstream tls(timesLine);
	int currentTime;
	while (tls >> currentTime) {
		times.push_back(currentTime);
	}
	std::stringstream dls(distancesLine);
	int currentDistance;
	while (dls >> currentDistance) {
		distances.push_back(currentDistance);
	}
	for (int i = 0; i < times.size(); i++) {
		int wins = 0;
		int time = times[i];
		int distance = distances[i];
		for (int x = 0; x < time; x++) {
			if (x * (time - x) > distance)
				wins++;
		}
		res *= wins;
	}
	std::cout << res;
}

void Task6::Part2() {
	auto input = Utility::ReadAllLinesInFile("inputs/input6.txt");
	std::string timesLine = input[0].substr(input[0].find(':') + 1, input[0].size());
	timesLine.erase(remove(timesLine.begin(), timesLine.end(), ' '), timesLine.end());
	std::string distancesLine = input[1].substr(input[1].find(':') + 1, input[1].size());
	distancesLine.erase(remove(distancesLine.begin(), distancesLine.end(), ' '), distancesLine.end());

	int64_t time = std::stol(timesLine);
	int64_t distanceRecord = std::stoll(distancesLine);
	int64_t wins = 0;

	for (int64_t timeHeld = 1; timeHeld <= time; timeHeld++) {
		int64_t velocity = timeHeld;
		int64_t distance = velocity * (time - timeHeld);
		if (distance > distanceRecord)
			wins++;
	}


	std::cout << wins;
}