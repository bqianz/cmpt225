#include <string>
#include <stdexcept>
#include <iostream>
#include <fstream>

using namespace std;

// Function Prototypes
template <class T>
T* readFile(string infile, int &n);

template <class T>
int insertionsort(T* arr, int n);

template <class T>
void print_array(T* arr, int n, ostream& os);

void test1(), test2(), test3(), test4();

int main(){

	test1();
	// float* arr2 = readFile<float>("a3test2.txt",n);
	// cout<<"Quicksort comparisons = "<<quicksort<float>(arr2,n)<<endl;

	// string* arr3 = readFile<string>("a3test3.txt",n);
	// cout<<"Mergesort comparisons = "<<mergesort<string>(arr3,n)<<endl;

	// cout<<"Shell sort comparisons = "<<shellsort<string>(arr3,n)<<endl;

	return 0 ;
}

void test1(){
	int n = 0;
	int* arr1 = readFile<int>("a3test1.txt",n);
	cout<<"Before Insertion sort:"<<endl;
	print_array(arr1,n,cout);

	int iterations = insertionsort<int>(arr1,n);

	cout<<"After Insertion sort:"<<endl;
	print_array(arr1,n,cout);
	cout<<"Insertion sort comparisons = "<<iterations<<endl;
}

template <class T>
T* readFile(string infile, int& n){
	T* result;
	T next;
	n = 0;

	ifstream ist(infile.c_str()); //open file

	// Check if file opened correctly
	if(ist.fail()){
		throw runtime_error(infile + " not found");
	}

	// Find file size
	while(ist >> next){
		n++;
	}

	// Read file into array
	ist.close();
	ist.open(infile.c_str());
	result = new T[n];
	for(int i = 0; i<n;++i){
		ist >> result[i];
	}

	ist.close();

	return result;
}

template <class T>
void print_array(T* arr, int n, ostream& os){
	for(int i = 0; i < n-1; i++){
		os<<arr[i]<<", ";
	}
	os<<arr[n-1]<<endl;
}


template <class T>
int insertionsort(T* arr, int n){
	int count = 0;
	for(int i=1; i<n; i++){
		T current = arr[i];
		int j = i-1;
		while(j>-1 && arr[j] > current){
			arr[j+1] = arr[j];
			j--;
			count++;
		}
		arr[j+1] = current;
	}
	return count;
}