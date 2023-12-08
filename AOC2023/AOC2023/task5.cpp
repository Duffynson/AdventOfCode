#include "input.h"
#include "task5.h"

void Task5::Part1() {
	auto input = Utility::ReadAllLinesInFile("inputs/input5.txt");
	std::string firstLine = input[0];
	input.erase(input.begin(), input.begin()+2);
	firstLine = firstLine.substr(7, firstLine.size());
	std::vector<long long int> seeds;
	std::stringstream ss(firstLine);
	long long int currSeed;
	while (ss >> currSeed) {
		seeds.push_back(currSeed);
	}
	for (auto &seed : seeds) {
		bool changed = false;
		for (const auto& line : input) {
			if (line == "" || !(isdigit(line[0]))) {
				changed = false;
				continue;
			}
			std::vector<long long int> currentMapLine;
			long long int currNumber;
			std::stringstream ss(line);
			while (ss >> currNumber) {
				currentMapLine.push_back(currNumber);
			}
			long long int destination = currentMapLine[0];
			long long int source = currentMapLine[1];
			long long int range = currentMapLine[2];
			if (source <= seed && seed < source + range && !changed) {
				seed = destination + (seed - source);
				changed = true;
			}
		}
	}
	long long int lowest = INT_MAX;
	for (auto x : seeds) {
		if (x < lowest)
			lowest = x;
	}
	std::cout << lowest;
}

void Task5::Part2() {
	auto input = Utility::ReadAllLinesInFile("inputs/input5.txt");
	std::string firstLine = input[0];
	firstLine = firstLine.substr(7, firstLine.size());
	std::vector<int64_t> inputSeeds;
	std::stringstream ss(firstLine);
	int64_t currSeed;
	while (ss >> currSeed) {
		inputSeeds.push_back(currSeed);
	}
	std::vector<std::pair<int64_t, int64_t>>seeds;
	for (size_t i = 0; i < inputSeeds.size(); i += 2) {
		seeds.push_back({ inputSeeds[i], inputSeeds[i] + inputSeeds[i + 1] });
	}
	input.erase(input.begin(), input.begin() + 2);

	std::vector<std::pair<int64_t, int64_t>> newSeeds;
	std::vector<std::pair<int64_t, int64_t>>currentlyMapped;
	for (auto& line : input) {
		newSeeds.clear();
		if (line.empty()) {
			seeds.insert(seeds.end(), currentlyMapped.begin(), currentlyMapped.end());
			currentlyMapped.clear();
			continue;
		}
		if (!isdigit(line[0]))
			continue;
		std::vector<int64_t> currentMapLine;
		int64_t currNumber = 0;
		std::stringstream ss(line);
		while (ss >> currNumber) {
			currentMapLine.push_back(currNumber);
		}
		int64_t destination = currentMapLine[0];
		int64_t source = currentMapLine[1];
		int64_t length = currentMapLine[2];
		for (auto& seed : seeds) {
			int64_t start = seed.first;
			int64_t end = seed.second;
			int64_t overlapStart = std::max(start, source);
			int64_t overlapEnd = std::min(end, source + length);
			if (overlapStart < overlapEnd) {
				currentlyMapped.push_back(std::pair{ overlapStart - source + destination, overlapEnd - source + destination });
				if (overlapStart > start) {
					newSeeds.push_back(std::pair{ start, overlapStart -1 });
				}
				if (end > overlapEnd) {
					newSeeds.push_back(std::pair{ overlapEnd + 1, end });
				}
				continue;
			}
			else {
				newSeeds.push_back(std::pair{ start,end });
			}
		}
		seeds = newSeeds;
	}
	seeds.insert(seeds.end(), currentlyMapped.begin(), currentlyMapped.end());


	int64_t lowest = INT_MAX;
	for (auto x : seeds) {
		if (x.first < lowest)
			lowest = x.first;
		if (x.second < lowest)
			lowest = x.second;
	}
	std::cout << lowest;
}