#pragma once
#include <iostream>
#include <chrono>

namespace Timer {
	using Clock = std::chrono::high_resolution_clock;
	using TimePoint = std::chrono::time_point<Clock>;

	TimePoint startTime;
	int count = 1;

	void start() {
		startTime = Clock::now();
	}
	void stop() {
		auto endTime = Clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		std::cout << "Task " << count << " took: " << duration.count() << " ms" << std::endl;
		count++;
	}
	void reset() {
		count = 1;
	}
}