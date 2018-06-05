#include <iostream>
#include "LinkedList.h"
using namespace std;

// Segmentation error (printBackwards not correct, size not updated)
void removeTest1(){
	LinkedList list;
	int arr[] = {1,3,5,7,3,5,7,9};
	int n = 8;
	
	for(int i=0;i<n;++i){
		list.insertTail(arr[i]);
	}

	list.printForwards();

	cout<<"remove 3s:"<<list.remove(3)<<endl;
	cout<<"Forwards:"<<endl;
	list.printForwards();
	cout<<"Backwards:"<<endl;
	list.printBackwards();
	cout<<"List has length "<<list.size()<<endl;
}

// logic error (does not remove if the element in question is at first place)
void removeTest2(){
	LinkedList list;
	int n = 8;
	int arr[n] = {1,3,5,7,3,5,7,9};
	
	for(int i=0;i<n;++i){
		list.insertTail(arr[i]);
	}

	list.printForwards();

	cout<<"remove 1s:"<<list.remove(1)<<endl;
	list.printForwards();
	cout<<"Backwards:"<<endl;
	list.printBackwards();
	cout<<"List has length "<<list.size()<<endl;
}

// both logic error and runtime error (when number being removed is at last place)
void removeTest3(){
	LinkedList list;
	int n = 8;
	int arr[n] = {1,3,5,7,3,5,7,9};
	
	for(int i=0;i<n;++i){
		list.insertTail(arr[i]);
	}

	list.printForwards();

	cout<<"remove 9s:"<<list.remove(9)<<endl;
	list.printForwards();
	cout<<"Backwards:"<<endl;
	list.printBackwards();
	cout<<"List has length "<<list.size()<<endl;
}

// logic error (when array is length 1)
void removeTest4(){
	LinkedList list;
	list.insertTail(3);
	// list contains the array {3}

	list.printForwards();

	cout<<"remove 3s:"<<list.remove(3)<<endl;
	list.printForwards();
	cout<<"Backwards:"<<endl;
	list.printBackwards();
	cout<<"List has length "<<list.size()<<endl;
}

// logic error ( removing continuous numbers);
void removeTest5(){
	LinkedList list;
	int n = 8;
	int arr[n] = {1,3,3,5,1,2,3,4};
	
	for(int i=0;i<n;++i){
		list.insertTail(arr[i]);
	}

	list.printForwards();

	cout<<"remove 3s:"<<list.remove(3)<<endl;
	list.printForwards();
	cout<<"Backwards:"<<endl;
	list.printBackwards();
	cout<<"List has length "<<list.size()<<endl;
}

// segmentation error (when array is empty)
void removeTest6(){
	LinkedList list;
	// empty list;

	list.printForwards();

	cout<<"remove 3s:"<<list.remove(3)<<endl;
	list.printForwards();
	cout<<"Backwards:"<<endl;
	list.printBackwards();
	cout<<"List has length "<<list.size()<<endl;
}

int main(){
	// cout<<"Test1:"<<endl;
	// removeTest1();
	// cout<<"Test2:"<<endl;
	// removeTest2();
	// cout<<"Test3:"<<endl;
	// removeTest3();
	// cout<<"Test4:"<<endl;
	// removeTest4();
	// cout<<"Test5:"<<endl;
	// removeTest5();
	cout<<"Test6:"<<endl;
	removeTest6();


	return 0;
}

