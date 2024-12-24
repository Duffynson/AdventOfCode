#include "day24.h"

using KnownValues = std::map<std::string, int>;
using LogicGatesValues = std::map<std::string, std::pair<std::string, std::string>>;
using LogicGatesOperations = std::map<std::pair<std::string, std::string>, std::string>;
using LogicGates = std::map<std::string, std::pair<std::pair<std::string, std::string>,std::string>>;

KnownValues createValuesMap(std::vector<std::string>& input) {
    KnownValues result;
    for (const auto& entry : input) {
        std::istringstream ss(entry);
        std::string key;
        int value;

        std::getline(ss, key, ':');
        ss >> value;

        key.erase(key.find_last_not_of(" \t") + 1);

        result[key] = value;
    }
    return result;
}

void populateLogicGates(const std::vector<std::string>& input, LogicGates& logicGates) {
    for (const auto& entry : input) {
        std::istringstream ss(entry);
        std::string left, op, right, arrow, key;

        ss >> left >> op >> right >> arrow >> key;

        logicGates[key] = { {left,right}, op };
    }
}

int getValueFromOperation(const std::string& operation, int left, int right) {
    if (operation == "AND") {
        return left && right;
    }
    if (operation == "OR") {
        return left || right;
    }
    if (operation == "XOR") {
        return left ^ right;
    }
    return -1;
}

void Day24::Task1() const {
    int64_t result = 0;
	auto input = ReadAllLinesInFile("input.txt");
	std::vector<std::string> firstPart;
	std::vector<std::string> secondPart;
	splitByEmptyLine(input, firstPart, secondPart);
	KnownValues knownValues = createValuesMap(firstPart);
    LogicGates logicGates;
    populateLogicGates(secondPart, logicGates);
    while (logicGates.size() > 0) {
        for (auto [key, value] : logicGates) {
            std::string left = value.first.first;
            std::string right = value.first.second;
            if (knownValues.find(left) != knownValues.end() && knownValues.find(right) != knownValues.end()) {
                int leftValue = knownValues[left];
                int rightValue = knownValues[right];
                std::string operation = logicGates[key].second;
                knownValues[key] = getValueFromOperation(operation, leftValue, rightValue);
                logicGates.erase(key);
                break;
            }
        }
    }
    std::vector<int> values;
    for (const auto& [key, value] : knownValues) {
        if (key.find("z") == 0) {
            values.push_back(value);
        }
    }
    for (int i = 0; i < values.size(); i++) {
        if (values[i] == 1) {
            result += std::pow(2, i);
        }
    }
    std::cout << result << std::endl;
}

void Day24::Task2() const {

}