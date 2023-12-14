#include "input.h"

std::vector<std::string> Utility::ReadAllLinesInFile(const std::filesystem::path& path){
		auto lines = std::vector<std::string>{};
		if (!std::filesystem::exists(path)){
			return lines;
		}

		auto fileStream = std::ifstream{ path };
		auto currentLine = std::string{};
		while (std::getline(fileStream, currentLine)){
			lines.emplace_back(currentLine);
		}

		return lines;
	}

std::vector<std::vector<int64_t>> Utility::SplitLinesAsInt64_t(const std::vector<std::string> input) {
	std::vector<std::vector<int64_t>> input64_t;
	for (auto line : input) {
		int64_t tempNum;
		std::vector<int64_t> tempVec;
		std::stringstream iss(line);
		while (iss >> tempNum) {
			tempVec.push_back(tempNum);
		}
		input64_t.push_back(tempVec);
	}
	return input64_t;
}

std::string Utility::SplitStringByComma(std::string input) {
	std::replace(input.begin(), input.end(), ',', ' ');
	return input;
}

std::vector<int64_t> Utility::SplitStringAsInt64_t(std::string input) {
	std::vector<int64_t> res;
	int64_t tempNum;
	std::stringstream iss(input);
	while (iss >> tempNum) {
		res.push_back(tempNum);
	}
	return res;
}

std::vector<int64_t> Utility::SplitStringByCommasAsInt64_t(std::string input) {
	input = Utility::SplitStringByComma(input);
	return Utility::SplitStringAsInt64_t(input);
}

std::vector<std::string> Utility::FlipStringInput(std::vector<std::string> input) {
	std::vector<std::string> flippedInput;
	std::string tempString;
	for (int i = 0; i < input[0].size(); i++) {
		for (int x = 0; x < input.size(); x++) {
			tempString.push_back(input[x][i]);
		}
		flippedInput.push_back(tempString);
		tempString.clear();
	}
	return flippedInput;
}