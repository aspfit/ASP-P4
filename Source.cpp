#include <iostream>
using namespace std;

template <class T>
class Node {
public:
	T _info;
	Node *_next;

	Node() {
		this->_next = nullptr;
	}
	Node(T info, Node *next = nullptr) {
		this->_info = info;
		this->_next = next;
	}
};

template <class T>
class LinkedList {
private:
	Node<T> *_head;

	void AddFirst(T info) {
		Node<T> *temp = new Node<T>(info, this->_head);
		this->_head = temp;
	}

	void AddLast(T info) {
		Node<T> *temp = this->_head;
		Node<T> *end = new Node<T>(info);

		while (temp->_next != nullptr) {
			temp = temp->_next;
		}

		temp->_next = end;
	}

public:
	LinkedList() {
		this->_head = nullptr;
	}


	void AddSorted(T info) {
		if (this->_head == nullptr || this->_head->_info >= info) {
			this->AddFirst(info);
			return;
		}

		Node<T> *temp = this->_head;
		Node<T> *previous = nullptr;

		bool AddToLast = true;
		while (temp != nullptr) {
			if (temp->_info >= info) {
				Node<T> *added = new Node<T>(info, temp);
				previous->_next = added;
				AddToLast = false;
				break;
			}
			previous = temp;
			temp = temp->_next;
		}

		if (AddToLast)
			this->AddLast(info);
	}

	T RemoveFirst() {
		if (!IsEmpty()) {
			int firstItem = this->_head->_info;
			this->_head = this->_head->_next;
			return firstItem;
		}

		throw exception("Priority Queue is empty!");
	}

	void Print() {
		Node<T> *temp = this->_head;

		while (temp != nullptr) {
			cout << "#--> " << temp->_info << endl;
			temp = temp->_next;
		}
	}

	bool IsEmpty() {
		if (this->_head == nullptr)
			return true;

		return false;
	}
};

template <class T>
class PriorityQueue {
private:
	LinkedList<T> _pq;

public:

	void Add(T info) {
		this->_pq.AddSorted(info);
	}

	T Return() {
		return this->_pq.RemoveFirst();
	}

	void Print() {
		this->_pq.Print();
	}

	bool IsEmpty() {
		return this->_pq.IsEmpty();
	}
};


int main() {
	PriorityQueue<int> p;
	

	p.Add(2);
	p.Add(4);
	p.Add(5);
	p.Add(9);
	p.Add(7);
	p.Add(1);
	p.Add(3);
	p.Add(5);
	p.Add(10);
	p.Add(1);

	p.Print();

	cout << "Removed: " << p.Return() << endl;
	cout << "Removed: " << p.Return() << endl;
	cout << "Removed: " << p.Return() << endl;

	p.Print();

	getchar();
	return 0;
}
