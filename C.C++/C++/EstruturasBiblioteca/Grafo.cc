#include <iostream>
#include <vector>
#include <list>

// clear && g++ Grafo.cc && ./a.out

using namespace std;

class Graph {
public:
    Graph(int vertices) : adjList(vertices) {}

    // Function to add an edge from vertex u to vertex v
    void addEdge(int u, int v, bool bidirectional = true) {
        adjList[u].push_back(v);
        if (bidirectional) {
            adjList[v].push_back(u);
        }
    }

    // Function to print adjacency list representation of graph
    void printGraph() {
        for (int i = 0; i < adjList.size(); ++i) {
            cout << i << " -> ";
            for (int vertex : adjList[i]) {
                cout << vertex << " ";
            }
            cout << endl;
        }
    }

private:
    vector<list<int>> adjList;
};

int main() {
    // Create a graph with 5 vertices
    Graph g(5);

    // Add edges
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    // Print the graph
    g.printGraph();

    return 0;
}