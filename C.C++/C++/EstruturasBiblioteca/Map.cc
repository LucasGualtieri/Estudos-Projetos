#include <iostream>
#include <map>
#include <string>

// Define the Dog class
class Dog {
public:
    // Default constructor
    Dog() : name(""), age(0) {}

    // Parameterized constructor
    Dog(std::string name, int age) : name(name), age(age) {}

    // Getter methods
    std::string getName() const { return name; }
    int getAge() const { return age; }

private:
    std::string name;
    int age;
};

int main() {
    // Define a map with string keys (dog names) and Dog objects as values
    std::map<std::string, Dog> dogs;

    // Insert some Dog objects into the map
    dogs["Buddy"] = Dog("Buddy", 5);
    dogs["Max"] = Dog("Max", 3);
    dogs["Bella"] = Dog("Bella", 4);

    // Iterate over the map to print the details of each Dog object in order
    for (const auto& pair : dogs) {
        const Dog& dog = pair.second; // Retrieve the Dog object
        std::cout << "Name: " << dog.getName() << ", Age: " << dog.getAge() << std::endl;
    }

    return 0;
}
