#include "input.h"
#include "task9.h"

int64_t SumOfVector(std::vector<int64_t> input) {
	int64_t res = 0;
	for (auto num : input) {
		if (num == 0) {
			continue;
		}
		res++;
	}
	return res;
}

void Task9::Part1() {
	auto input = Utility::ReadAllLinesInFile("inputs/input9.txt");
	std::vector<std::vector<int64_t>> inputAsNumbers = Utility::SplitLinesAsInt64_t(input);
	int64_t res = 0;
	for (auto line : inputAsNumbers) {
		std::vector<std::vector<int64_t>> dataset;
		dataset.push_back(line);
		size_t lastElem = dataset.size() - 1;
		std::vector<int64_t> lastVec = dataset[lastElem];
		while (SumOfVector(lastVec)) {
			std::vector<int64_t> tempVec;
			for (int i = 0; i < dataset[lastElem].size() - 1; i++) {
				int64_t res = dataset[lastElem][i + 1] - dataset[lastElem][i];
				tempVec.push_back(res);
			}
			dataset.push_back(tempVec);
			lastElem = dataset.size() - 1;
			lastVec = dataset[lastElem];
		}
		int64_t tempRes = 0;
		for (int i = dataset.size() - 1; i > 0 ; i--) {
			std::vector<int64_t> lastVec = dataset[i];
			std::vector<int64_t> prevVec = dataset[i - 1];
			int64_t prevNum = prevVec[prevVec.size() - 1];
			tempRes = prevNum + tempRes;
		}
		res += tempRes;
	}
	std::cout << res;
}

void Task9::Part2() {
	auto input = Utility::ReadAllLinesInFile("inputs/input9.txt");
	std::vector<std::vector<int64_t>> inputAsNumbers = Utility::SplitLinesAsInt64_t(input);
	int64_t res = 0;
	for (auto line : inputAsNumbers) {
		std::vector<std::vector<int64_t>> dataset;
		dataset.push_back(line);
		size_t lastElem = dataset.size() - 1;
		std::vector<int64_t> lastVec = dataset[lastElem];
		while (SumOfVector(lastVec)) {
			std::vector<int64_t> tempVec;
			for (int i = 0; i < dataset[lastElem].size() - 1; i++) {
				int64_t res = dataset[lastElem][i + 1] - dataset[lastElem][i];
				tempVec.push_back(res);
			}
			dataset.push_back(tempVec);
			lastElem = dataset.size() - 1;
			lastVec = dataset[lastElem];
		}
		int64_t tempRes = 0;
		for (int i = dataset.size() - 1; i > 0; i--) {
			std::vector<int64_t> lastVec = dataset[i];
			std::vector<int64_t> prevVec = dataset[i - 1];
			int64_t prevNum = prevVec[0];
			tempRes = prevNum - tempRes;
		}
		res += tempRes;
	}
	std::cout << res;
}