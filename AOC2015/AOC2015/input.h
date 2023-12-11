#pragma once
#include "stdc++.h"

namespace Utility{
	std::vector<std::string> ReadAllLinesInFile(const std::filesystem::path& path);
	std::vector<std::vector<int64_t>> SplitLinesAsInt64_t(const std::vector<std::string>);
}