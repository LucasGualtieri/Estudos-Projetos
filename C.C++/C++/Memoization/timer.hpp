#ifndef TIME_ELAPSED_H
#define TIME_ELAPSED_H

#include <chrono>
#include <iostream>
#include <thread>
#include <iomanip> 

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
		duration<double> duration = end - beginning;
		return duration.count();
	}

	friend std::ostream& operator<<(std::ostream& os, const Timer& t) {
		os << std::fixed << std::setprecision(6) << t.result();
		return os;
	}

};

#endif