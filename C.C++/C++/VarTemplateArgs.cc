#include <iostream>

using namespace std;

// clear && g++ VarTemplateArgs.cc && ./a.out

// template<typename... Args>
// void processArgs(Args... args) {

// 	auto processArg = [](const auto& arg) {
// 		cout << arg <<endl;
// 		// cout << "Argument: " << arg <<endl;
// 	};

// 	// Calls the lambda for every arg
// 	(processArg(args), ...);
// }

template<typename... Args>
void processArgs(Args... args) {
	([](const auto& arg) { cout << arg <<endl;}(args), ...);
}

// The & symbol indicates that arg is a
// reference to an object rather than a copy
// of the object itself. Using a reference
// allows the lambda function to operate
// directly on the original object,
// avoiding unnecessary copying.
// And becasuse it's const we're making sure its value won't change

int main() {

	processArgs(1, "two", 3.0, true);

	return 0;
}