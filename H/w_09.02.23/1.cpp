#include <iostream>
using namespace std;

class Node {
	int data;
public:
	Node* next, * prev;
	Node(int d) :data(d), next(0), prev(0) {};
	int getData() const { return data; }
	void setData(int d) { data = d; }
	friend ostream& operator<<(ostream& os, const Node& N);
};

ostream& operator<<(ostream& os, const Node& N) {
	os << N.data;
	return os;
}

class List {
	Node* head, * tail;
public:
	List() { head = tail = 0; }
	~List() { DeleteAll(); }
	void AddToHead(int el);
	void AddToTail(int el);
	void DeleteFromHead();
	void DeleteFromTail();
	void DeleteAll();
	void Show();
	friend ostream& operator<<(ostream& os, List& list);
};

void List::AddToHead(int el) {
	Node* temp = new Node(el);
	temp->next = head;
	if (head)
		head->prev = temp;
	else
		tail = temp;
	head = temp;
}

void List::AddToTail(int el) {
	Node* temp = new Node(el);
	temp->prev = tail;
	if (tail)
		tail->next = temp;
	else
		head = temp;
	tail = temp;
}

void List::DeleteFromHead() {
	if (head) {
		Node* temp = head;
		head = head->next;
		if (head)
			head->prev = 0;
		else
			tail = 0;
		delete temp;
	}
}

void List::DeleteFromTail() {
	if (tail) {
		Node* temp = tail;
		tail = tail->prev;
		if (tail)
			tail->next = 0;
		else
			head = 0;
		delete temp;
	}
}

void List::DeleteAll() {
	while (head) DeleteFromHead();
}


void List::Show() {
	if (!head)
		cout << "list is empty";
	else {
		Node* temp = head;
		while (temp) {
			cout << *temp << "\t";
			temp = temp->next;
		}
	}
}

ostream& operator<<(ostream& os, List& list) {
	if (!list.head)
		os << "list is empty";
	else {
		Node* temp = list.head;
		while (temp) {
			os << *temp << "\t";
			temp = temp->next;
		}
	}
	return os;
}


int main() {

	List list;
	list.AddToHead(10);
	list.AddToHead(5);

	cout << list << endl;
	return 0;
}
