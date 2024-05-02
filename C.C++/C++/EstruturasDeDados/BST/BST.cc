#include <iostream>
#include <utility>
// #include <concepts>

// falta implementar os destrutores

using namespace std;

typedef const char* const literal;

// clear && g++ BST.cc && ./a.out

template <typename T>
class Stack {
  private:
  public:
	class Cell {
	  private:
	  public:

		T value;
		Cell* bottom;

		Cell(T value, Cell* bottom) {
			this->value = value;
			this->bottom = bottom;
		}

		// T Value() { return value; }
	};

	Cell* top;
  
	Stack() : top(nullptr) {}

	// Inserts an element to the top of the stack.
	bool push(T value) {

		Cell* newCell = new Cell(value, top);

		if (newCell == nullptr) return false;

		top = newCell;

		return true;
	}

	// Removes the element at the top of the stack and returns it.
	T pop() {

		Cell* removedCell = top;
		T removedValue = top->value;

		top = top->bottom;

		delete removedCell;

		return removedValue;
	}

	// Returns a reference to the element at the top of the stack without removing it.
	T& peek() { return this->top->value; }

	// Checks whether the stack is empty.
	bool empty() { return top == nullptr; }

};

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

		// Node* getLeft() { return left; }

		// bool setLeft(T value) {
		// 	left = new Node(value);
		// 	return left != nullptr;
		// }

		// Node* getRight() { return right; }

		// bool setRight(T value) {
		// 	right = new Node(value);
		// 	return right != nullptr;
		// }

		// T Value() { return value; }

		friend string& operator+=(const string& str, const Node*& node) {
			return str += to_string(node->value);
		}

        friend string operator+(const Node node, const string& str) {
            return to_string(node.value) + str;
        }
	};

	class Iterator {
	private:
		Node* current, *aux;
		Stack<Node*> stack;

	public:
		Iterator(Node* root) : current(root) {
			// Start with the leftmost node
			while (current != nullptr) {
				stack.push(current);
				current = current->left;
			}
		}

		// Dereference operator
		T& operator*() const { return aux->value; }

		// Increment operator (prefix)
		Iterator& operator++() {

			if (current == nullptr) return *this; // Handling for end() iterator

			if (current != nullptr || !stack.empty()) {

				while (current != nullptr) {
					stack.push(current);
					current = current->left;
				}

				aux = current = stack.pop();
				current = current->right;
			}

			return *this;
		}

		// Inequality comparison operator
		bool operator!=(const Iterator& other) const { return current != other.current; }
	};

	T* elements;
    int size;
	Node* root;

  public:
	BST() : root(nullptr), size(0) {}

	template<typename... Values>
	bool insert(Values... args) {

		bool result = true;

		auto insertList = [&](const T& arg) {
			if (!insert(arg)) result = false;
		};

		auto removeList = [&](const T& arg) { remove(arg); };

		(insertList(args), ...);

		if (!result) (removeList(args), ...);

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

		if (status) size++;

		return status;
	}

	void displayInOrder() {

		string result = "{ ";

		Stack<Node*> stack;
		Node* node = root;

		while (node != nullptr || !stack.empty()) {
			while (node != nullptr) {
				stack.push(node);
				node = node->left;
			}

			node = stack.pop();
			result += *node + ", ";
			node = node->right;
		}

		int len = result.length();
		if (len > 2) result.erase(len - 2, 1);

		cout << result + "}" << endl;
	}

	void displayPreOrder() {

		string result = "{ ";

		Stack<Node*> stack;
		Node* node = root;

		while (node != nullptr || !stack.empty()) {
			while (node != nullptr) {
				stack.push(node);
				result += *(stack.peek()) + ", ";
				node = node->left;
			}

			node = stack.pop();
			node = node->right;
		}

		int len = result.length();
		if (len > 2) result.erase(len - 2, 1);

		cout << result + "}" << endl;
	}

	void displayPostOrder() {

		string result = "{ ";

		Stack<pair<Node*, bool>> stack;
		Node* curr = root;
		Node* lastVisited = nullptr;

		while (curr != nullptr || !stack.empty()) {
			while (curr != nullptr) {
				stack.push({curr, false});
				curr = curr->left;
			}

			auto [node, visited] = stack.peek();
			if (node->right != nullptr && lastVisited != node->right && !visited) {
				// Visit right subtree first if it exists and hasn't been visited
				curr = node->right;
				stack.peek().second = true; // Mark the node as visited
			} else {
				// Visit the node
				result += *node + ", ";
				lastVisited = node;
				stack.pop();
			}
		}

		int len = result.length();
		if (len > 2) result.erase(len - 2, 1);

		cout << result + "}" << endl;
	}

	string toString() const {

		string result = "{ ";

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
				result += *node + ", ";
				// Sets right path as taken
				pathStatus = 2;
				stack.push(pair(node->right, 0));
			}

			else if (pathStatus == 2) stack.pop();
		}

		int len = result.length();
		if (len > 2) result.erase(len - 2, 1);

		return result + "}";
	}

	Iterator begin() const {
		// if (root == nullptr) return end(); // If tree is empty, begin() is same as end()
		// Node* current = root;

		// Iterator i;

		// while (current->left != nullptr) {
		// 	i.stack.push(current);
		// 	current = current->left;
		// }

		// i.setCurrent(current);
		return Iterator(root);
	}

	Iterator end() const {
		return Iterator(nullptr);
	}

	friend ostream& operator<<(ostream& os, const BST<T>& bst) {
		os << bst.toString();
		return os;
	}
};

int main() {
	BST<int> tree;

	bool result = tree.insert(2, 1, 3, 6, 123, -123, 12);
	cout << (result ? "true" : "false") << endl;

	// cout << tree << endl;

	for (int x : tree) {
		cout << x << endl;
	}
}

// class Stack {
// 	Cell top;
// };