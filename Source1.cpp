#include <iostream>
using namespace std;

class Node {
	int info;
	Node *next;
public:
	Node() : next(nullptr), info(0) {}
	Node(int tempInfo, Node *tempNext = nullptr) : info(tempInfo), next(tempNext){}
	int getInfo() const { return info; }
	Node* getNext() const { return next; }
	void setNext(Node* tempNext) { next = tempNext; }
};


class PriorityQueue {
	Node *head;
public:
	PriorityQueue() : head(nullptr) {}
	void addFirst(int tempInfo) {
		head = new Node(tempInfo, head);
	}
	void push(int tempInfo) {
		if (head == nullptr) {
			addFirst(tempInfo);
			return;
		}

		Node *currentNode(head), *parentNode(nullptr);
		while (currentNode != nullptr && currentNode->getInfo() > tempInfo) {
			parentNode = currentNode;
			currentNode = currentNode->getNext();
		}

		parentNode->setNext(new Node(tempInfo, currentNode));
	}
	void pop() {
		if (!isEmpty()) {
			Node *tempNode(head->getNext());
			delete head;
			head = tempNode;
		}
 	}
	bool isEmpty() {
		return head == nullptr;
	}
};

int main() {



	return 0;
}
