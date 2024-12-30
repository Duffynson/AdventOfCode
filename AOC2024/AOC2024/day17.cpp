#include "day17.h"
std::string getProgramOutput(std::map<char, int>& registers, std::vector<int>& instructions, int value);

std::map<char, int> parseRegisterStrings(const std::vector<std::string>& input) {
    std::map<char, int> registerMap;

    for (const auto& line : input) {
        std::stringstream ss(line);
        std::string label, key;
        char reg;
        int value;

        ss >> label >> reg >> key >> value;

        if (label == "Register" && key == ":") {
            registerMap[reg] = value;
        }
    }

    return registerMap;
}

std::vector<int> stringToVector(const std::string& input) {
    size_t colonPos = input.find(':');

    std::string data = input.substr(colonPos + 1);

    std::vector<int> result;
    std::stringstream ss(data);
    std::string token;

    while (std::getline(ss, token, ',')) {
        result.push_back(std::stoi(token));
    }

    return result;
}

std::map<int, char> comboOperands = { {0,'0'}, {1,'1'}, {2,'2'}, {3,'3'}, {4,'A'},{5,'B'},{6,'C'}};

int adv(int numerator, int power) {
    return int(numerator / std::pow(2, power));
}

void Day17::Task1() const {
    std::string result;
    char A = 'A', B = 'B', C = 'C';
	auto input = ReadAllLinesInFile("input.txt");
	std::vector<std::string> firstPart;
	std::vector<std::string> secondPart;
	splitByEmptyLine(input, firstPart, secondPart);
    auto registers = parseRegisterStrings(firstPart);
	auto instructions = stringToVector(secondPart[0]);
    int idx = 0;
    while (idx < instructions.size()) {
        bool jump = false;
        int opcode = instructions[idx];
        int operand = instructions[idx + 1];
        int comboOperand = operand > 3 ? registers[comboOperands[operand]] : comboOperands[operand] - '0';
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
            result += std::to_string(comboOperand % 8);
            result += ',';
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
    result = result.substr(0, result.size() - 1);
    std::cout << result << std::endl;
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
    std::vector<std::vector<int>> numbers;
    numbers.resize(iterations);
    for (int i = 0; i < iterations; i++) {
        std::string desiredOutput = secondPart[0].substr(secondPart[0].size() - ((i + 1) * 2) + 1, secondPart[0].size());
        for (int x = 0; x < 8; x++) {
            
        }
        std::string output = getProgramOutput(registers, instructions, i);
        std::cout << i << " : " << output << std::endl;
    }
}

std::string getProgramOutput(std::map<char, int>& registers, std::vector<int>& instructions, int value) {
    std::string programResult;
    char A = 'A', B = 'B', C = 'C';
    int idx = 0;
    registers[A] = value;
    while (idx < instructions.size()) {
        bool jump = false;
        int opcode = instructions[idx];
        int operand = instructions[idx + 1];
        int comboOperand = operand > 3 ? registers[comboOperands[operand]] : comboOperands[operand] - '0';
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