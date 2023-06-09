#include <iostream>
using namespace std;

// A CPP program that uses override keyword so
// that any difference in function signature is
// caught during compilation

// https://www.geeksforgeeks.org/override-keyword-c/

/*
	In short, it serves the following functions. It helps to check if:

	There is a method with the same name in the parent class.
	The method in the parent class is declared as “virtual”
	which means it was intended to be rewritten.
	The method in the parent class has the same signature as
	the method in the subclass.
*/

class Base {
  public:
	// user wants to override this in
	// the derived class
	virtual void func() { cout << "I am in base" << endl; }
};

class derived: public Base {
  public:
	// did a silly mistake by putting
	// an argument "int a"
	void func(int a) override {
		cout << "I am in derived class" << endl;
	}
};

int main() {
	Base	b;
	derived d;
	cout << "Compiled successfully" << endl;
	return 0;
}