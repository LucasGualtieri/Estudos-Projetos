#ifndef TIME_ELAPSED_H
#define TIME_ELAPSED_H

#include <chrono>
#include <iostream>
#include <thread>

using namespace std::chrono;

class Timer {
	high_resolution_clock::time_point beginning;
	high_resolution_clock::time_point end;

  public:
	Timer() { }

	void start() {
		beginning = high_resolution_clock::now();
	}

	void stop() {
		end = high_resolution_clock::now();
	}

	double result() const {
		duration<double, std::micro> time_span = duration_cast<duration<double, std::micro>>(end - beginning);
		return time_span.count();
	}

	friend std::ostream& operator<<(std::ostream& os, const Timer& t) {
		os << t.result();
		return os;
	}

};

#endif