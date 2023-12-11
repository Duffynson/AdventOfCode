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
