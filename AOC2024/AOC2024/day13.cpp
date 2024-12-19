#include "day13.h"

using ClawMachine = std::tuple<std::pair<int, int>, std::pair<int, int>, std::pair<int, int>>;
using ClawMachines = std::vector<ClawMachine>;

ClawMachines parseClawMachines(const std::vector<std::string>& input) {
    ClawMachines clawMachines;
    std::vector<std::pair<int, int>> currentGroup;

    for (const auto& line : input) {
        if (line.empty()) {
            if (currentGroup.size() == 3) {
                clawMachines.emplace_back(
                    currentGroup[0],  
                    currentGroup[1],  
                    currentGroup[2]   
                );
            }
            currentGroup.clear();
            continue;
        }

        auto xPos = line.find("X");
        auto yPos = line.find("Y");
        if (xPos == std::string::npos || yPos == std::string::npos) continue;

        int x = std::stoi(line.substr(xPos + 2));
        int y = std::stoi(line.substr(yPos + 2));

        currentGroup.emplace_back(x, y);
    }

    return clawMachines;
}

void Day13::Task1() const {
    int result = 0;
	auto input = ReadAllLinesInFile("input.txt");
    ClawMachines clawMachines = parseClawMachines(input);
    for (auto clawMachine : clawMachines) {
        auto [a1, a2] = std::get<0>(clawMachine);
        auto [b1, b2] = std::get<1>(clawMachine);
        auto [res1, res2] = std::get<2>(clawMachine);
        int det = a1 * b2 - a2 * b1;
        int a = std::abs((res1 * b2 - res2 * b1) / det);
        int b = std::abs((res1 * a2 - res2 * a1) / det);
        if (a1 * a + b1 * b == res1 && a2 * a + b2 * b == res2) {
            result += a * 3 + b;
        }
    }
    std::cout << result << std::endl;
}

void Day13::Task2() const {
    int64_t result = 0;
    int64_t offset = 10000000000000;
    auto input = ReadAllLinesInFile("input.txt");
    ClawMachines clawMachines = parseClawMachines(input);
    for (auto clawMachine : clawMachines) {
        auto [a1, a2] = std::get<0>(clawMachine);
        auto [b1, b2] = std::get<1>(clawMachine);
        auto [res1, res2] = std::get<2>(clawMachine);
        int64_t offsetRes1 = res1 + offset;
        int64_t offsetRes2 = res2 + offset;
        int64_t det = a1 * b2 - a2 * b1;
        int64_t a = std::abs((offsetRes1 * b2 - offsetRes2 * b1) / det);
        int64_t b = std::abs((offsetRes1 * a2 - offsetRes2 * a1) / det);
        if (a1 * a + b1 * b == offsetRes1 && a2 * a + b2 * b == offsetRes2) {
            result += a * 3 + b;
        }
    }
    std::cout << result << std::endl;
}