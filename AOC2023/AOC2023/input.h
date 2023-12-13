#pragma once
#include "stdc++.h"

namespace Utility{
	std::vector<std::string> ReadAllLinesInFile(const std::filesystem::path& path);
	std::vector<std::vector<int64_t>> SplitLinesAsInt64_t(const std::vector<std::string>);
	std::string SplitStringByComma(std::string input);
	std::vector<int64_t> SplitStringAsInt64_t(std::string input);
	std::vector<int64_t> SplitStringByCommasAsInt64_t(std::string input);
}