#include "deque.h"
#include <stdexcept>
#include <iostream>
using namespace std;

template <typename T>
Deque<T>::Deque(){
	header = new Node<T>;
	trailer = new Node<T>;
	header->next = trailer;
	trailer->prev= header;
}

// copy constructor – a constructor that creates a deep copy of its constant Deque reference parameter
template <typename T>
Deque<T>::Deque(const Deque &d) : Deque() {
	Node<T>* temp = d.trailer->prev;
	while(temp!=d.header){
		insertFront(temp->elem);
		temp = temp->prev;
	}
}


// operator= – overloads the assignment operator for Deque – (deep) copies its constant Deque reference parameter 
// into the calling object and returns a reference to the calling object after de-allocating any dynamic memory 
// associated with the original contents of the calling object; if the calling object is the same as the parameter 
// the operator should not copy it

template <typename T>
void Deque<T>::print_nodes(){
	Node<T>* temp = header->next;
	cout<<"header location "<<header<<endl;
	cout<<"temp->prev location"<<temp->prev<<endl;
	while(temp!=trailer){
		cout<<"Node location "<<temp<<", node element "<<temp->elem<<endl;
		temp=temp->next;
	}
	cout<<"trailer location "<<trailer<<endl;
	cout<<"temp location"<<temp<<endl;
}

template <typename T>
void Deque<T>::print_nodes_reverse(){
	Node<T>* temp = trailer->prev;
	cout<<"trailer location "<<trailer<<endl;
	cout<<"temp->next location "<<temp->next<<endl;
	while(temp!=header){
		cout<<"Node location "<<temp<<", node element "<<temp->elem<<endl;
		temp=temp->prev;
	}
	cout<<"header location "<<header<<endl;
	cout<<"temp location"<<temp<<endl;
}


template <typename T>
Deque<T>& Deque<T>::operator= (const Deque& d){
	if (this!=&d){
		if(is_null()){
			delete header;
			delete trailer;

			header = new Node<T>;
			trailer = new Node<T>;
			header->next = trailer;
			trailer->prev= header; 
		}

		while (!empty()){
			removeFront();
		}

		Node<T>* temp = d.trailer->prev;


		while(temp!=d.header){
			insertFront(temp->elem);
			temp = temp->prev;
		}
	}

	return *this;
}


// destructor – deallocates dynamic memory allocated by the deque
template <typename T>
Deque<T>::~Deque(){
	while (!empty()){
		removeFront();
	}
	delete header;
	delete trailer;
}

// empty – returns true if the deque is empty, false otherwise
template <typename T>
bool Deque<T>::empty() const{
	return (header->next==trailer);
}

// is_null - returns tue if header or trailer is null
template <typename T>
bool Deque<T>::is_null() const{
	return (header==NULL || trailer==NULL);
}


// removeFront – removes and returns the value at the front of the deque; if the deque is empty throws a 
// runtime_error (this error class is defined in the stdexcept library file)
template <typename T>
T& Deque<T>::removeFront(){
	if(empty()){
		throw runtime_error("Deque is empty.");
	}
	else{
		Node<T>* old = header; // temporary holder for original header
		header = old->next; // make new header a pointer to the next node
		return header->elem; // return value of removed node
		delete old;
	}
}

// removeBack – removes and returns the value at the back of the deque; if the deque is empty throws a runtime_error
template <typename T>
T& Deque<T>::removeBack(){
	if(empty()){
		throw runtime_error("Deque is empty.");
	}
	else{
		Node<T>* old = trailer;
		trailer = old->prev;
		return trailer->elem;
		delete old;
	}
}

// size – returns the number of items stored in the deque
template <typename T>
int Deque<T>::size() const{
	int i = 0;
	Node<T>* now = header->next;
	while(now!=trailer){
		now = now->next;
		i++;
	}
	return i;
}

// insertFront – inserts its parameter at the front of the deque
template <typename T>
void Deque<T>::insertFront(const T& e){
	Node<T>* new_header = new Node<T>;

	header->prev = new_header;
	new_header->next = header;
	header->elem = e;
	header = new_header;
}

// insertBack – inserts its parameter at the back of the deque
template <typename T>
void Deque<T>::insertBack(const T& e){
	Node<T>* new_trailer = new Node<T>;
	trailer->next = new_trailer;
	new_trailer->prev = trailer;
	trailer->elem = e;
	trailer = new_trailer;
}

// peekFront – returns the value at the front of the deque without removing it; if the deque is empty throws
// a runtime_error
template <typename T>
T& Deque<T>::peekFront() const {
	if(empty()){
		throw runtime_error("Deque is empty.");
	}
	else{
		return header->next->elem;
	}
}

// peekBack – returns the value at the back of the deque without removing it; if the deque is empty throws
// a runtime_error
template <typename T>
T& Deque<T>::peekBack() const {
	if(empty()){
		throw runtime_error("Deque is empty.");
	}
	else{
		return trailer->prev->elem;
	}
}

int main(){

	Deque<int> dq1;

	cout << dq1.empty() << " - 1" << endl;

	dq1.insertFront(42);
	dq1.insertBack(216);

	cout<<dq1.peekFront()<<" - 42"<<endl;
	cout<<dq1.peekBack()<<" - 216"<<endl;
	cout<<dq1.size()<<" - 2"<<endl;


	Deque<int> dq2(dq1);
	Deque<int> dq3;

	// cout<<endl;
	// dq1.print_nodes();
	// cout<<endl;
	// dq1.print_nodes_reverse();

	dq3 = dq1;
	cout << dq1.removeFront() << " - 42" << endl;
	cout << dq1.removeBack() << " - 216" << endl;
	cout << dq2.peekFront() << " - 42" << endl;
	cout << dq2.peekBack() << " - 216" << endl;
	cout << dq3.peekFront() << " - 42" << endl;
	cout << dq3.peekBack() << " - 216" << endl;

	return 0;
}