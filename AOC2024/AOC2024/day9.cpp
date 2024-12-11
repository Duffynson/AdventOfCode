#include "day9.h"

void Day9::Task1() const {
	long long result = 0;
	auto input = ReadOneLineFromFile("input.txt");
	std::vector<int> diskMap;
	int ID = 0;
	for (int i = 0; i < input.size(); i++) {
		if (i % 2 == 0) {
			int x = int(input[i] - '0');
			for (int j = 0; j < x; j++) {
				diskMap.push_back(ID);
			}
			ID++;
		}
		else {
			int x = int(input[i] - '0');
			for (int j = 0; j < x; j++) {
				diskMap.push_back(-1);
			}
		}
	}

	int size = diskMap.size();
	for (int i = 0; i < size; i++) {
		if (diskMap[i] == -1) {
			int idx = size - 1;
			while (diskMap[idx] == -1) {
				idx--;
			}
			if (idx < i) {
				break;
			}
			int lastFileBlock = diskMap[idx];
			diskMap[i] = lastFileBlock;
			diskMap[idx] = -1;
		}
	}

	for (int i = 0; i < size; i++) {
		if (diskMap[i] == -1) break;
		result += i * diskMap[i];
	}
	std::cout << result << std::endl;
}

void Day9::Task2() const {
	long long result = 0;
	auto input = ReadOneLineFromFile("input.txt");
	std::vector<int> diskMap;
	int ID = 0;
	for (int i = 0; i < input.size(); i++) {
		if (i % 2 == 0) {
			int x = int(input[i] - '0');
			for (int j = 0; j < x; j++) {
				diskMap.push_back(ID);
			}
			ID++;
		}
		else {
			int x = int(input[i] - '0');
			for (int j = 0; j < x; j++) {
				diskMap.push_back(-1);
			}
		}
	}

	int end = input.size() - 1;
	int diskMapEndIdx = diskMap.size();
	while (end > 0) {
		diskMapEndIdx -= int(input[end]- '0');
		if (end % 2 == 0) {
			for (int i = 0; i < diskMap.size(); i++) {
				if (i > diskMapEndIdx) break;
				if (diskMap[i] == -1) {
					int spaceSize = 0;
					int spaceStart = i;
					while (diskMap[spaceStart] == -1) {
						spaceSize++;
						spaceStart++;
					}
					int fileSize = int(input[end] - '0');
					if (spaceSize >= fileSize) {
						spaceStart = i;
						int fileStart = diskMapEndIdx;
						for (int j = 0; j < fileSize; j++) {
							diskMap[spaceStart] = diskMap[fileStart];
							diskMap[fileStart] = -1;
							spaceStart++;
							fileStart++;
						}
						break;
					}
				}
			}
		}
		end--;
	}

	for (int i = 0; i < diskMap.size(); i++) {
		if (diskMap[i] == -1) continue;
		result += i * diskMap[i];
	}

	std::cout << result << std::endl;
}

//int size = diskMap.size();
//int idxFront = 0;
//int idxBack = input.size() - 1;
//bool numberChange = false;
//for (int i = 0; i < size; i++) {
//	idxBack = input.size() - 1;
//	if (diskMap[i] != -1 && numberChange) {
//		idxFront++;
//		numberChange = false;
//	}
//	if (diskMap[i] == -1) {
//		if (!numberChange) {
//			idxFront++;
//			numberChange = true;
//		}
//		int freeSpaceSize = int(input[idxFront] - '0');
//		int backFileSize = int(input[idxBack] - '0');
//		int backOffset = 0;
//		while (true) {
//			backFileSize = int(input[idxBack] - '0');
//			if (freeSpaceSize >= backFileSize && idxBack % 2 == 0 && diskMap[size - 1 - backOffset] != -1) break;
//			backOffset += int(input[idxBack] - '0');
//			idxBack--;
//		}
//		int freeSpaceStart = i;
//		int idx = size - 1 - backOffset;
//		for (int j = 0; j < backFileSize; j++) {
//			diskMap[freeSpaceStart] = diskMap[idx];
//			diskMap[idx] = -1;
//			freeSpaceStart++;
//			idx--;
//		}
//		input[idxFront] = '0' + (freeSpaceSize - backFileSize);
//		i += backFileSize - 1;
//	}
//}
//
//for (int i = 0; i < size; i++) {
//	if (diskMap[i] == -1) continue;
//	result += i * diskMap[i];
//}