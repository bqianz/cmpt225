#pragma once

#include <stdexcept>
#include <iostream>

using namespace std;

class LinkedList;

// class Node{
// public:
// 	Node(int val = 0, Node* nd1 = NULL, Node* nd2 = NULL) : data(val), previous(nd1), next(nd2) {};
// private:
// 	int data;
// 	Node* previous;
// 	Node* next;
// 	friend class LinkedList;
// }

class Node{
public:
	int data;
	Node* previous;
	Node* next;
	Node(int val, Node* nd1, Node* nd2) : data(val), previous(nd1),next(nd2) {};
	Node(int val) : data (val), previous(NULL), next(NULL) {};
};

class LinkedList{
public:
	LinkedList();
	Linkedlist(const LinkedList& list);
	LinkedList& operator=(const LinkedList& list);
	~LinkedList();

	void insertHead(int val);
	void insertTail(int val);

	int remove(int x);
	void printForwards() const;
	void printBackwards() const;

	int size() const;
	bool empty() const;
private:
	int n;
	Node* head;
	Node* tail;

	void copyList(const LinkedList& list);
	void removeAll();
};