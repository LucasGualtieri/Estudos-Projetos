#include <iostream>
#include <sstream>
#include <utility>
#include <sstream>
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
	~Stack() {
		while (!empty()) pop();
	}

	/**
	 * Inserts an element to the top of the stack.
	 * 
	 * @param element item of type T.
	 * @return True if the insertion is successful, otherwise, false.
	 */
	bool push(T element) {

		Cell* newCell = new Cell(element, top);

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

	/**
	 * Inserts an arbitrary length list of items into the tree. If the insertion of any of the elements fails, none of the items are inserted.
	 * 
	 * @param items List of N items of type T.
	 * @return True if the insertion of all elements was successful, otherwise, false.
	 */
	template<typename... Items>
	bool insert(Items... list) {

		bool result = true;

		auto insertList = [&](const T& item) {
			if (!insert(item)) result = false;
		};

		auto removeList = [&](const T& item) { remove(item); };

		(insertList(list), ...);

		if (!result) (removeList(list), ...);

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
				fn(node);
				// Sets right path as taken
				pathStatus = 2;
				stack.push(pair(node->right, 0));
			}

			else if (pathStatus == 2) stack.pop();
		}
	}

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

int main() {

	BST<Person> personTree;

	personTree.insert(
		Person("Beatriz", 1),
		Person("Lucas", 2),
		Person("Gabriel", 3),
		Person("Felipe", 4),
		Person("Arjuna", 5),
		Person("Gontcha", 6),
		Person("Igor", 7)
	);

	cout << personTree << endl;

	BST<int> ageTree;

	ageTree.insert(21, 22, 19, 35, 21, 20, 21);

	cout << ageTree << endl;
	cout << ageTree << endl;

}