#include <iostream>
#include <vector>
#include <list>
#include <unordered_map> // Include unordered_map for string to index mapping

using namespace std;

// clear && g++ GrafoString.cc && ./a.out

class Graph {
public:
    // Constructor accepting the number of vertices and a mapping of string to index
    Graph(int vertices, const unordered_map<string, int>& stringToIndex)
        : adjList(vertices), stringToIndex(stringToIndex)
	{

	}

    // Function to add an edge from vertex u to vertex v
    void addEdge(const string& u, const string& v, bool bidirectional = true) {
        int uIndex = stringToIndex.at(u); // Get index for vertex u
        int vIndex = stringToIndex.at(v); // Get index for vertex v
        adjList[uIndex].push_back(vIndex); // Add edge from u to v
        if (bidirectional) {
            adjList[vIndex].push_back(uIndex); // If bidirectional, add edge from v to u
        }
    }

    // Function to print adjacency list representation of graph
    void printGraph() {
        for (int i = 0; i < adjList.size(); ++i) {
            cout << indexToString[i] << " -> ";
            for (int vertex : adjList[i]) {
                cout << indexToString[vertex] << " ";
            }
            cout << endl;
        }
    }

private:
    vector<list<int>> adjList; // Adjacency list to store neighbors
    unordered_map<string, int> stringToIndex; // Mapping from string to index
    unordered_map<int, string> indexToString; // Mapping from index to string
};

int main() {
    // Define a mapping from string node names to index
    unordered_map<string, int> stringToIndex = {{"A", 0}, {"B", 1}, {"C", 2}, {"D", 3}, {"E", 4}};

    // Create a graph with 5 vertices and the string to index mapping
    Graph g(5, stringToIndex);

    // Add edges using string node names
    g.addEdge("A", "B");
    g.addEdge("A", "E");
    g.addEdge("B", "C");
    g.addEdge("B", "D");
    g.addEdge("B", "E");
    g.addEdge("C", "D");
    g.addEdge("D", "E");

    // Print the graph
    g.printGraph();

    return 0;
}
