#include "day22.h"

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

}