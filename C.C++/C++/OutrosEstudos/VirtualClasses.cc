#include <iostream>
#include <string>

using namespace std;

class VirtualClass {
public:
    virtual ~VirtualClass() {}
    virtual string method() const = 0;
};

class Class : public VirtualClass {
public:
	virtual string method() const override {
		cout << "Hello world!" << endl;
		return "Class method";
	}
};

template <typename T>
class ExtHash {
public:
    T test;
    void foo() {
        cout << test.method() << endl;
    }   
};

int main() {
    ExtHash<Class> hash;
    hash.foo();
}
