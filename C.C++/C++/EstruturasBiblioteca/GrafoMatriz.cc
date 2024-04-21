#include <iostream>
#include <vector>
// #include <list>

// clear && g++ GrafoMatriz.cc && ./a.out

using namespace std;

class Graph {
public:
    Graph(int vertices) : adjMatrix(vertices) {
		for (vector<int>& i : adjMatrix) {
			i = vector<int>(vertices);
		}

		// for (vector<int>& i : adjMatrix) {
		// 	for (int j = 0; j < vertices; j++) {
		// 		i[j] = 0;
		// 	}
		// }
	}

    // Function to add an edge from vertex u to vertex v
    void addEdge(int u, int v, bool bidirectional = true) {
        adjMatrix[u][v] = 1;
        if (bidirectional) {
        	adjMatrix[v][u] = 1;
        }
    }

	// Function to print adjacency list representation of graph
    // void printGraph() {
    //     for (int i = 0; i < adjList.size(); ++i) {
    //         cout << i << " -> ";
    //         for (int vertex : adjList[i]) {
    //             cout << vertex << " ";
    //         }
    //         cout << endl;
    //     }
    // }

    // Function to print adjacency matrix representation of graph
    void printGraph() {

		cout << "    ";
	
		for (int i = 0; i < adjMatrix.size(); i++) {
			cout << i << " ";
		}

		cout << endl;

        for (int i = 0; i < adjMatrix.size(); i++) {
            cout << i << " | ";
            for (int j = 0; j < adjMatrix[i].size(); j++) {
                cout << adjMatrix[i][j] << " ";
				// cout << "ldkjff";
            }
            cout << endl;
        }
    }

    // Function to print os edges do grafo
    void printEdges() {

		for (int i = 0; i < adjMatrix.size(); ++i) {
            cout << i << " -> ";

            for (int j = 0; j < adjMatrix[i].size(); j++) {
				if (adjMatrix[i][j] != 0) {
					cout << "(" << i << "," << j << ")" << " ";
				}
            }
            cout << endl;
        }
    }

private:
    vector<vector<int>> adjMatrix;
    // vector<list<int>> adjMatrix;
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
    // g.printGraph();
	// cout << "-------------" << endl;
    g.printEdges();

    return 0;
}