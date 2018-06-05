#include "LinkedList.h"

// Default constructor, creates an empty list
LinkedList::LinkedList(){
	head = tail = NULL;
	n = 0;
}

// Copy constructor
// PARAM: list = list to be copied
// POST: creates a copy of list
LinkedList::Linkedlist(const LinkedList& list){
	copyList(list);
}

LinkedList& LinkedList::operator=(const LinkedList& list){
	if(this!=&list){
		removeAll();
		copyList(list);
	}
	return *this;
}

LinkedList::~LinkedList(){
	removeAll();
}

// param: val = value to be inserted
//post val is inserted at the head of the list
void LinkedList::insertHead(int val){
	if(tail==NULL){
		head = new Node(val,NULL,head);
		tail = head;
	}
	else{
		head -> previous = new Node(val,NULL,head);
		head = head -> previous;
	}
	n++;
}

void LinkedList::insertTail(int val){
	if(tail==NULL){
		tail = new Node(val);
		head = tail;
	}
	else{
		tail->next = new Node(val,tail,NULL);
		tail = tail->next;
	}
	n++;
}

// POST: print contents of calling object from head to tail
void LinkedList::printForwards() const{
	Node* temp = head;
	while(temp!=NULL){
		cout<<temp->data<<endl;
		temp = temp->next;
	}
}

void LinkedList::printBackwards() const{
	Node* temp = tail;
	while(temp!=NULL){
		cout<<temp->data<<endl;
		temp = temp->previous;
	}
}

int LinkedList::size() const{
	return n;
}

bool LinkedList::empty() const{
	return head == NULL && tail == NULL;
}

void LinkedList::copyList(const LinkedList& list){
	// if list is not empty
	if(list.head!=NULL){
		// copy first element and set head and tail
		Node* original = list.head;
		head = new Node(original -> data);
		tail = head;
		original = original->next;
		Node* temp = head;

		// copy rest
		while(original!=NULL){
			temp->next = new Node(original->data,temp,NULL);
			original = original->next;
			temp = temp -> next;
			tail = temp;
		}
	}
	n = list.n;
}

void LinkedList::removeAll(){
	Node* temp = head;
	while (head != NULL){
		head = temp->next;
		delete temp;
		temp = head;
	}
	n = 0;
	head = tail = NULL;
}

// int LinkedList::remove(int x){
// 	int count = 0;
// 	Node* temp = head;
// 	while(temp->next!=NULL){
// 		// Splice out target Node
// 		if(temp->next->data == x){
// 			Node* target = temp->next;
// 			temp->next = temp->next->next;
// 			delete target;
// 			count++;
// 		}
// 		temp = temp->next;
// 	}
// 	return count;
// }

// corrected
int LinkedList::remove(int x){
	int count = 0;

	Node* temp = head;

	//if removing from middle
	while(temp!=NULL){


		if(temp->data == x){
			// removing from array of length 1
			if(n==1){
				delete temp;
				head = tail = NULL;
			}

			// removing from front
			else if(temp==head){
				head = head->next;
				head->previous = NULL;
				delete temp;
				temp = head;
			}

			//removing from back
			else if(temp==tail){
				tail = tail->previous;
				tail->next = NULL;
				delete temp;
				temp = tail;
			}

			//removing from middle
			else{
				Node* temp_prev = temp->previous;
				temp_prev->next = temp->next;
				temp->next->previous = temp_prev;
				delete temp;
				temp = temp_prev->next;
			}
			count++;
			n--;
		}

		else{
			temp = temp->next;
		}

	}
	return count;
}