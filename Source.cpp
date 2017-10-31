#include <iostream>

using namespace std;



class Node {

	int info;

	Node *next;

public:

	Node() : next(nullptr), info(0) {}

	Node(int tempInfo, Node *tempNext = nullptr) : info(tempInfo), next(tempNext) {}

	int getInfo() const { return info; }

	Node* getNext() const { return next; }

	void setNext(Node* tempNext) { next = tempNext; }

};





class PriorityQueue {

	Node *head;
	void addFirst(int tempInfo) {

		head = new Node(tempInfo, head);

	}

public:

	PriorityQueue() : head(nullptr) {}

	

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


		if (parentNode == nullptr)
			addFirst(tempInfo);
		else
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
	void print()
	{
		Node *currentNode = head;
		while (currentNode != nullptr)
		{
			cout << "Info: " << currentNode->getInfo()<<endl;
			currentNode = currentNode->getNext();
		}
	}

};



int main() {

	PriorityQueue red;
	red.push(2);

	
	red.push(1);
	
	red.push(9);
	
	red.push(10);
	red.push(45);
	red.push(1);
	

	red.print();






	return 0;

}
