#include <biblioteca_cpp.h>

class Base {
  public:
	virtual void foo() {
		cout << "I'm in Base" << endl;
	}
};

class Derived: extends Base {
  public:
	void foo() override {
		cout << "I'm in Derived" << endl;
	}
};

int main() {

	Base* ptr = new Derived();
	ptr->foo(); // Calls the overridden function in Derived class
	delete ptr;

	return 0;
}
