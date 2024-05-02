#include <iostream>

using namespace std;
// class Comparable {
//   public:

// };

struct Base {
	virtual int g();
	// virtual ~Base() {}
};

struct Person : Base {
//   int g() {
// 	return 1;
//   }
};

 
// struct A : Base {
// 	// OK: declares three member virtual functions, two of them pure
// 	virtual int f() = 0, g() override = 0, h();

// 	// OK: destructor can be pure too
// 	~A() = 0;

// 	// Error: pure-specifier on a function definition
// 	virtual int b() = 0 {}
// };

int main() {
	cout << "Hello world!" << endl;

	struct Person p;
}


















