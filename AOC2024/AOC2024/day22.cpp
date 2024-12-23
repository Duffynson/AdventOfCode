#include "day22.h"

using Sequence = std::vector<int>;
using Sequences = std::map<Sequence, int>;

void Day22::Task1() const {
	auto input = ReadAllLinesInFile("input.txt");
	int64_t result = 0;
	auto secretNumbers = parseStringsToVector(input);
	int newNumbers = 2000;
	int pruneNumber = 16777216;
	for (auto& secretNumber : secretNumbers) {
		int64_t currentSecretNumber = secretNumber;
		for (int i = 0; i < newNumbers; i++) {
			currentSecretNumber = (currentSecretNumber ^ (currentSecretNumber * 64)) % pruneNumber;
			currentSecretNumber = (currentSecretNumber ^ (currentSecretNumber / 32)) % pruneNumber;
			currentSecretNumber = (currentSecretNumber ^ (currentSecretNumber * 2048)) % pruneNumber;
		}
		result += currentSecretNumber;
	}
	std::cout << result << std::endl;
}

void Day22::Task2() const {
	auto input = ReadAllLinesInFile("input.txt");
	int result = 0;
	auto secretNumbers = parseStringsToVector(input);
	int newNumbers = 2000;
	int pruneNumber = 16777216;
	std::vector<Sequences> allSequences;
	for (auto& secretNumber : secretNumbers) {
		Sequences currentSequences;
		int previousPrice = 0;
		Sequence sequence;
		int64_t currentSecretNumber = secretNumber;
		for (int i = 0; i < newNumbers; i++) {
			previousPrice = currentSecretNumber % 10;
			currentSecretNumber = (currentSecretNumber ^ (currentSecretNumber * 64)) % pruneNumber;
			currentSecretNumber = (currentSecretNumber ^ (currentSecretNumber / 32)) % pruneNumber;
			currentSecretNumber = (currentSecretNumber ^ (currentSecretNumber * 2048)) % pruneNumber;
			int currentPrice = currentSecretNumber % 10;
			if (i > 3) {
				if (currentSequences.find(sequence) == currentSequences.end()) {
					currentSequences[sequence] = previousPrice;
				}
				sequence.erase(sequence.begin());
				sequence.push_back(currentPrice - previousPrice);
				continue;
			}
			sequence.push_back(currentPrice - previousPrice);
		}
		allSequences.push_back(currentSequences);
	}
	Sequences firstBuyer = allSequences[0];
	for (auto& [sequence, value] : firstBuyer) {
		int currentMaximum = 0;
		for (auto& buyer : allSequences) {
			if (buyer.find(sequence) != buyer.end()) {
				currentMaximum += buyer[sequence];
			}
		}
		if (result < currentMaximum) {
			result = currentMaximum;
		}
	}

	std::cout << result << std::endl;
}