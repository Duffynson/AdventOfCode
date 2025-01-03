#include "utils/timer.h"
#include "dayIncludes.h"

void runSolution(const Day& day) {
	Timer::start();
	day.Task1();
	Timer::stop();
	Timer::start();
	day.Task2();
	Timer::stop();
	Timer::reset();
}

int main() {
	Day18 day;
	runSolution(day);
}
