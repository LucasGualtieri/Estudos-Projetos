#include <iostream>
#include <string>

namespace InputOutput {
class InputOutput {
  public:
	template <typename T>
	void operator>>(T& value) {
		std::cin >> value;
	}

	template <typename T>
	void operator<<(T obj) {
		std::cout << obj;
	}
};

InputOutput IOcin;
InputOutput IOcout;
} // namespace InputOutput

// using namespace InputOutput;

int main() {
	int			age;
	std::string name;

	InputOutput::IOcout << "Enter your age: ";
	InputOutput::IOcin >> age;
	InputOutput::IOcout << "Enter your name: ";
	InputOutput::IOcin >> name;

	InputOutput::IOcout << "\nAge: ";
	InputOutput::IOcout << age;
	InputOutput::IOcout << "\nName: ";
	InputOutput::IOcout << name;
	InputOutput::IOcout << "\n";

	return 0;
}
