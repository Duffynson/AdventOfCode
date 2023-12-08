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

