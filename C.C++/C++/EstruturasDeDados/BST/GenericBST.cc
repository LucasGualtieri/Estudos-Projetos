#include <iostream>
#include <sstream>
#include <utility>
#include <sstream>
#include <vector>
#include <cmath>
#include "../Stack.hpp"
#include "../Queue.hpp"
// #include <concepts>

// falta implementar os destrutores

using namespace std;

typedef const char* const literal;

// clear && g++ GenericBST.cc -std=c++20 && ./a.out

template <typename T>
class BST {
  private:

	class Node {
	  private:
	  public:
		T value;
		Node *left, *right;

		Node(T value) : value(value) {
			left = right = nullptr;
		}

		Node(T value, Node* left,  Node* right) {
			this->value = value;
			this->left = left;
			this->right = right;
		}

		friend string& operator+=(string& str, const Node& node) {
			ostringstream oss;
			oss << node.value;
			return str += oss.str();
		}

        friend string operator+(const Node node, const string& str) {
			ostringstream oss;
			oss << node.value;
            return oss.str() + str;
        }

		bool operator<(Node node) {
			return value < node.value;
		}

		bool operator>(Node node) {
			return value > node.value;
		}
	};

	Node* root;

  public:
	BST() : root(nullptr) {}

	template<typename... Items>
	BST(Items... list) : root(nullptr) {
		insert(list...);
	}

	/**
	 * Inserts an arbitrary length list of items into the tree. If the insertion of any of the elements fails, none of the items are inserted.
	 * 
	 * @param items List of N items of type T.
	 * @return True if the insertion of all elements was successful, otherwise, false.
	 */
	template<typename... Items>
	bool insert(Items... list) {

		bool result = true;

		vector<T> listOfItems = {list...};

		// auto insertList = [&](const T& item) {
		// 	if (!insert(item)) result = false;
		// };

		for (const T& x : listOfItems) {
			if (!insert(x)) {
				result = false;
				break;
			}
		}

		// auto removeList = [&](const T& item) { remove(item); };

		// (insertList(list), ...);
		// if (!result) (removeList(list), ...);

		if (!result) {
			for (const T& x : listOfItems) {
				remove(x);
				// if (!remove(x)) result = false;
			}
		}

		return result;
	}

	T remove(T value) { return T(); }

	bool insert(T value) {

		bool status = true;

		Node* parent = nullptr; // Pointer to parent node
		Node* node = root; // Pointer to pointer to Node

		while (node != nullptr) {
			parent = node;

			if (value < node->value) {
				node = node->left;
			}
			
			else if (value > node->value) {
				node = node->right;
			} 
			
			else return false;
		}

		node = new Node(value);

		if (root != nullptr) {
			if (value < parent->value) parent->left = node;
			else parent->right = node;
		}

		else root = node;

		status = node != nullptr;

		// if (status) size++;

		return status;
	}

  public:
	int height() {
		if (this->root == nullptr) return 0;
		return height(0, this->root);
	}

	int height(int level, Node* node) {

		if (node != nullptr) {
			level++;
			int leftLevel = height(level, node->left);
			int rightLevel = height(level, node->right);
			level = leftLevel > rightLevel ? leftLevel : rightLevel;
		}

		return level;
	}

	void DFSTraversal(auto fn) { // Same as InOrder

		Stack<Node*> stack(root);

		while (!stack.empty()) {

			Node* node = stack.pop();
			fn(node->value);

			if (node->right) stack.push(node->right);
			if (node->left) stack.push(node->left);
		}
	}
	
	void BFSTraversal(auto fn) { // Same as InOrder

		Queue<Node*> queue(root);

		while (!queue.empty()) {

			Node* node = queue.pop();
			fn(node->value);

			if (node->left) queue.push(node->left);
			if (node->right) queue.push(node->right);
		}
	}

	void InOrderTraversal(auto fn) const {
		Stack<pair<Node*, int>> stack;

		stack.push(pair(root, 0));

		while (!stack.empty()) {

			auto& [node, pathStatus] = stack.peek();

			if (node == nullptr) stack.pop();

			else if (pathStatus == 0) {
				// Sets left path as taken
				pathStatus = 1;
				stack.push(pair(node->left, 0));
			}

			else if (pathStatus == 1) {
				fn(node->value);
				// Sets right path as taken
				pathStatus = 2;
				stack.push(pair(node->right, 0));
			}

			else if (pathStatus == 2) stack.pop();
		}
	}
	
	void PreOrderTraversal(auto fn) const {
		Stack<pair<Node*, int>> stack;

		stack.push(pair(root, 0));

		while (!stack.empty()) {

			auto& [node, pathStatus] = stack.peek();

			if (node == nullptr) stack.pop();

			else if (pathStatus == 0) {
				fn(node->value);
				// Sets left path as taken
				pathStatus = 1;
				stack.push(pair(node->left, 0));
			}

			else if (pathStatus == 1) {
				// Sets right path as taken
				pathStatus = 2;
				stack.push(pair(node->right, 0));
			}

			else if (pathStatus == 2) stack.pop();
		}
	}
	
	void PostOrderTraversal(auto fn) const {
		Stack<pair<Node*, int>> stack;

		stack.push(pair(root, 0));

		while (!stack.empty()) {

			auto& [node, pathStatus] = stack.peek();

			if (node == nullptr) stack.pop();

			else if (pathStatus == 0) {
				// Sets left path as taken
				pathStatus = 1;
				stack.push(pair(node->left, 0));
			}

			else if (pathStatus == 1) {
				// Sets right path as taken
				pathStatus = 2;
				stack.push(pair(node->right, 0));
			}

			else if (pathStatus == 2) {
				fn(node->value);
				stack.pop();
			}
		}
	}

	vector<vector<T>> levelOrder() {

		vector<vector<int>> levels(height());

		Queue<Node*> queue(root);
		int level = 0;

		while (!queue.empty()) {

			for (int i = queue.size(); i > 0; i--) {
				Node* node = queue.pop();

				if (node->left) queue.push(node->left);
				if (node->right) queue.push(node->right);

				levels[level].push_back(node->value);
			}

			level++;
		}

		return levels;
    }

	// vector<vector<T>> levelOrder() {

	// 	vector<vector<int>> levels(getHeight());

	// 	Queue<Node*> queue(root);
	// 	int level = 0, elementsCount = queue.size();

	// 	while (!queue.empty()) {

	// 		Node* node = queue.pop();
	// 		elementsCount--;

	// 		if (node != nullptr) {
	// 			queue.push(node->left);
	// 			queue.push(node->right);

	// 			levels[level].push_back(node->value);
	// 		}

	// 		if (elementsCount == 0) {
	// 			elementsCount = queue.size();
	// 			level++;
	// 		}
	// 	}

	// 	return levels;
	// }

	string toString() const {

		string result = "{ ";

		InOrderTraversal([&result](Node* node) {
			result += *node + ", ";
		});

		int len = result.length();
		if (len > 2) result.erase(len - 2, 1);

		return result + "}";
	}

	friend ostream& operator<<(ostream& os, const BST<T>& bst) {
		os << bst.toString();
		return os;
	}
};

class Person {
  public:
	string nome;
	int ID;

	Person() : nome("null"), ID(-1) {}
	Person(string nome, int ID) : nome(nome), ID(ID) {}

	static int compare(Person p1, Person p2) {
		return p1.compareTo(p2);
	}

	string str() const {
		return "[ " + nome + ", " + to_string(ID) + " ]";
	}

	int compareTo(Person p) {
		return nome.compare(p.nome);
		// return (nome.compare(p.nome) > 0) - (nome.compare(p.nome) < 0);
		// return ID - p.ID;
	}

	friend string& operator+=(string& str, const Person& p) {
		return str += p.str();
	}

	friend string operator+(const string& str, const Person& p) {
		return str + p.str();
	}

	friend string operator+(const Person& p, const string& str) {
		return p.str() + str;
	}

	bool operator<(Person p) {
		return compareTo(p) < 0;
	}

	bool operator>(Person p) {
		return compareTo(p) > 0;
	}

	friend ostream& operator<<(ostream& os, const Person& p) {
		os << p.str();
		return os;
	}

};

string printLevels(vector<vector<int>> levels) {

	string result;

	for (int i = 0; i < levels.size(); i++) {

		result += "Level: " + to_string(i) + " { ";

		for (int x : levels[i]) {
			result += to_string(x) + ", ";
		}

		int len = result.length();
		if (len > 2) result.erase(len - 2, 1);

		result += "}\n";
	}

	return result;
}

int main() {

	// BST<Person> personTree;

	// personTree.insert(
	// 	Person("Beatriz", 1),
	// 	Person("Lucas", 2),
	// 	Person("Gabriel", 3),
	// 	Person("Felipe", 4),
	// 	Person("Arjuna", 5),
	// 	Person("Gontcha", 6),
	// 	Person("Igor", 7)
	// );

	// cout << personTree << endl;

	BST<int> tree(5, 3, 7, 1, 4, 6, 8);

	// cout << tree << endl;

	cout << "In order { ";
	tree.InOrderTraversal([](int x) {
		cout << x << ", ";
	});
	cout << "}" << endl;

	cout << "Pre order { ";
	tree.PreOrderTraversal([](int x) {
		cout << x << ", ";
	});
	cout << "}" << endl;

	cout << "Post order { ";
	tree.PostOrderTraversal([](int x) {
		cout << x << ", ";
	});
	cout << "}\n" << endl;

	vector<vector<int>> levels = tree.levelOrder();
	cout << printLevels(levels) << endl;

	cout << "{ ";
	tree.DFSTraversal([](int x) {
		cout << x << ", ";
	});
	cout << "}" << endl;

	cout << "{ ";
	tree.BFSTraversal([](int x) {
		cout << x << ", ";
	});
	cout << "}" << endl;

}