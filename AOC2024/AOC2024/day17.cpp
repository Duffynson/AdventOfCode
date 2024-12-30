#include "day17.h"

std::map<int64_t, char> comboOperands = { {0,'0'}, {1,'1'}, {2,'2'}, {3,'3'}, {4,'A'},{5,'B'},{6,'C'} };

int64_t adv(int64_t numerator, int64_t power) {
    return int64_t(numerator / std::pow(2, power));
}

std::string getProgramOutput(std::map<char, int64_t>& registers, std::vector<int64_t>& instructions, int64_t value) {
    std::string programResult;
    char A = 'A', B = 'B', C = 'C';
    int64_t idx = 0;
    registers[A] = value;
    while (idx < instructions.size()) {
        bool jump = false;
        int64_t opcode = instructions[idx];
        int64_t operand = instructions[idx + 1];
        int64_t comboOperand = operand > 3 ? registers[comboOperands[operand]] : comboOperands[operand] - '0';
        switch (opcode) {
        case 0:
            registers[A] = adv(registers[A], comboOperand);
            break;
        case 1:
            registers[B] = registers[B] ^ operand;
            break;
        case 2:
            registers[B] = comboOperand % 8;
            break;
        case 3:
            if (registers[A] == 0) {
                break;
            }
            idx = operand;
            jump = true;
            break;
        case 4:
            registers[B] = registers[B] ^ registers[C];
            break;
        case 5:
            programResult += std::to_string(comboOperand % 8);
            programResult += ',';
            break;
        case 6:
            registers[B] = adv(registers[A], comboOperand);
            break;
        case 7:
            registers[C] = adv(registers[A], comboOperand);
            break;
        }
        if (!jump) {
            idx += 2;
        }
    }
    programResult = programResult.substr(0, programResult.size() - 1);
    return programResult;
}

std::map<char, int64_t> parseRegisterStrings(const std::vector<std::string>& input) {
    std::map<char, int64_t> registerMap;

    for (const auto& line : input) {
        std::stringstream ss(line);
        std::string label, key;
        char reg;
        int64_t value;

        ss >> label >> reg >> key >> value;

        if (label == "Register" && key == ":") {
            registerMap[reg] = value;
        }
    }

    return registerMap;
}

std::vector<int64_t> stringToVector(const std::string& input) {
    size_t colonPos = input.find(':');

    std::string data = input.substr(colonPos + 1);

    std::vector<int64_t> result;
    std::stringstream ss(data);
    std::string token;

    while (std::getline(ss, token, ',')) {
        result.push_back(std::stoi(token));
    }

    return result;
}

void Day17::Task1() const {
	auto input = ReadAllLinesInFile("input.txt");
	std::vector<std::string> firstPart;
	std::vector<std::string> secondPart;
	splitByEmptyLine(input, firstPart, secondPart);
    auto registers = parseRegisterStrings(firstPart);
	auto instructions = stringToVector(secondPart[0]);
    int64_t value = registers['A'];
    std::string result = getProgramOutput(registers,instructions,value);
    std::cout << result << std::endl;
}

void generateCombinations(const std::vector<std::set<int64_t>>& tree,
    int64_t level, std::vector<int64_t>& currentCombination,
    std::vector<std::vector<int64_t>>& resultCombinations) {
    if (level == tree.size() || tree[level].empty()) {
        resultCombinations.push_back(currentCombination);
        return;
    }

    for (int64_t node : tree[level]) {
        currentCombination.push_back(node);
        generateCombinations(tree, level + 1, currentCombination, resultCombinations);
        currentCombination.pop_back(); 
    }
}

std::vector<int64_t> calculateEachCombination(std::vector<std::vector<int64_t>>& combinations) {
    std::vector<int64_t> result;
    for (const auto& combination : combinations) {
        int64_t combinationResult = 0;
        for (int64_t i : combination) {
            combinationResult += i;
        }
        result.push_back(combinationResult);
    }
    return result;
}

void shiftAllNumbers(std::vector<int64_t>& numbers) {
    for (int64_t i = 0; i < numbers.size(); i++) {
        numbers[i] = numbers[i] << 3;
    }
}


void Day17::Task2() const {
    std::string result;
    auto input = ReadAllLinesInFile("input.txt");
    std::vector<std::string> firstPart;
    std::vector<std::string> secondPart;
    splitByEmptyLine(input, firstPart, secondPart);
    auto registers = parseRegisterStrings(firstPart);
    auto instructions = stringToVector(secondPart[0]);
    int iterations = (int)instructions.size();
    std::vector<int64_t> numbers;
    for (int i = 0; i < 8; i++) {
        std::string desiredOutput = secondPart[0].substr(secondPart[0].size() - 1, secondPart[0].size());
        std::string output = getProgramOutput(registers, instructions, i);
        if (output == desiredOutput) {
            numbers.push_back(i);
        }
    }
    for (int i = 1; i < iterations; i++) {
        shiftAllNumbers(numbers);
        std::vector<int64_t> validNumbers;
        std::string desiredOutput = secondPart[0].substr(secondPart[0].size() - ((i + 1) * 2) + 1, secondPart[0].size());
        for (int64_t number : numbers) {
            for (int64_t x = 0; x < 8; x++) {
                std::string output = getProgramOutput(registers, instructions, number + x);
                if (output == desiredOutput) {
                    validNumbers.push_back(number + x);
                }
            }
        }
        numbers = validNumbers;
    }
    int64_t lowestNumber = INT64_MAX;
    for (int64_t number : numbers) {
        if (lowestNumber > number) {
            lowestNumber = number;
        }
    }
    std::cout << lowestNumber << std::endl;
}