#include "day14.h"

using RobotProperties = std::pair<std::pair<int, int>, std::pair<int, int>>;
using Robots = std::vector<RobotProperties>;

Robots parseRobotProperties(const std::vector<std::string>& input) {
    Robots robots;

    for (const auto& str : input) {
        std::pair<int, int> p;
        std::pair<int, int> v;

        std::istringstream iss(str);
        std::string segment;

        std::getline(iss, segment, ' ');
        if (segment.rfind("p=", 0) == 0) {
            std::istringstream p_stream(segment.substr(2));
            char comma;
            p_stream >> p.first >> comma >> p.second;
        }

        std::getline(iss, segment);
        if (segment.rfind("v=", 0) == 0) {
            std::istringstream v_stream(segment.substr(2));
            char comma;
            v_stream >> v.first >> comma >> v.second;
        }

        robots.emplace_back(p, v);
    }

    return robots;
}

void Day14::Task1() const {
    int result = 1;
    int seconds = 100;
    std::vector<int> quadrants = {0,0,0,0};
	auto input = ReadAllLinesInFile("input.txt");
    int rows = 103;
    int cols = 101;
	Robots robots = parseRobotProperties(input);
    for (auto robot : robots) {
        int16_t x = robot.first.first;
        int16_t y = robot.first.second;
        int16_t dirX = robot.second.first;
        int16_t dirY = robot.second.second;
        int16_t endX = (x + seconds * dirX) % cols;
        int16_t endY = (y + seconds * dirY) % rows;

        if (endX < 0) endX += cols;
        if (endY < 0) endY += rows;

        int16_t middleX = cols / 2;
        int16_t middleY = rows / 2;
        if (endX < middleX && endY < middleY) quadrants[0]++;
        if (endX > middleX && endY < middleY) quadrants[1]++;
        if (endX < middleX && endY > middleY) quadrants[2]++;
        if (endX > middleX && endY > middleY) quadrants[3]++;
    }
    for (auto quadrant : quadrants) {
        result *= quadrant;
    }
    std::cout << result << std::endl;
}

void Day14::Task2() const {
    auto input = ReadAllLinesInFile("input.txt");
    std::vector<int> quadrants = { 0,0,0,0 };
    int rows = 103;
    int cols = 101;
    int seconds = 0;
    Robots robots = parseRobotProperties(input);
    std::map<std::pair<int, int>, int> grid;
    int64_t previousSafetyScore = 0;
    while (true) {
        int64_t safetyScore = 1;
        seconds++;
        for (auto robot : robots) {
            int16_t x = robot.first.first;
            int16_t y = robot.first.second;
            int16_t dirX = robot.second.first;
            int16_t dirY = robot.second.second;
            int16_t endX = (x + seconds * dirX) % cols;
            int16_t endY = (y + seconds * dirY) % rows;
            if (endX < 0) endX += cols;
            if (endY < 0) endY += rows;
            grid[{endX, endY}]++;
            int16_t middleX = cols / 2;
            int16_t middleY = rows / 2;
            if (endX < middleX && endY < middleY) quadrants[0]++;
            if (endX > middleX && endY < middleY) quadrants[1]++;
            if (endX < middleX && endY > middleY) quadrants[2]++;
            if (endX > middleX && endY > middleY) quadrants[3]++;
        }
        for (int i = 0; i < quadrants.size(); i++) {
            safetyScore *= quadrants[i];
            quadrants[i] = 0;
        }
        if (safetyScore < int(previousSafetyScore * 0.6) && previousSafetyScore != 0) break;
        previousSafetyScore = safetyScore;
    }
    std::cout << seconds << std::endl;
}