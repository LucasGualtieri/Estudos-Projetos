#include <iostream>
#include <unordered_map>
#include <unordered_set>

// clear && g++ Teste2.cc && ./a.out

using namespace std;

int main() {
    // Using unordered_map
    unordered_map<int, string> idToName;
    idToName[1] = "Alice";
    idToName[2] = "Bob";
    idToName[3] = "Charlie";

    // cout << "ID 1 is: " << idToName.find(1) << endl;
    cout << "ID 1 is: "
	<< (idToName[2].length() == 0 ? "não encontrado" : idToName[2])
	<< endl;

    // Using unordered_set
    unordered_set<int> uniqueIds;
    uniqueIds.insert(1);
    uniqueIds.insert(2);
    uniqueIds.insert(2); // This will not be added again, as elements are unique

    // cout << "uniqueIds.end(): " << uniqueIds.end() << endl;
    cout << "Unique IDs contains 2: "
	<< ((uniqueIds.find(2) != uniqueIds.end()) ? "true" : "false")
	<< endl;

    return 0;
}

