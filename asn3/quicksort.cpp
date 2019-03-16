#include <string>
#include <stdexcept>
#include <iostream>
#include <fstream>

using namespace std;

// Function Prototypes
template <class T>
T* readFile(string infile, int&);

template <class T>
int quicksort(T*, int);

template <class T>
void quicksort_helper(T*, int, int, int&);

template <class T>
int quicksort_partition(T*, int, int, int&);

template <class T>
void print_array(T*, int, ostream&);

void test2();




int main(){
	test2();
	return 0 ;
}





// function definitions
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
int quicksort(T* arr, int length){
	int count = 0;
	quicksort_helper(arr, 0, length-1, count);
}

template <class T>
void quicksort_helper(T* arr, int first, int last, int& count){
	if(first < last){
		int split = quicksort_partition(arr, first, last, count);

		quicksort_helper(arr, first, split-1, count);
		quicksort_helper(arr, split+1, last, count);
	}
}

template <class T>
int quicksort_partition(T* arr, int first, int last, int& count){
	// pivot position and pivot value
	int pivot_position = (first+last)/2;
	T pivot_value = arr[pivot_position];

	// initiate left and right marks
	int left = first;
	int right = last;

	while(true){

		// find left and right to operate on
		while(arr[left] < pivot_value){
			left++;
			count++;
		}
		while(arr[right] > pivot_value){
			right--;
			count++;
		}

		if(left>=right){
			return right;
		}

		T temp = arr[left];
		arr[left] = arr[right];
		arr[right] = temp;
	}
}

void test2(){
	int n = 0;
	float* arr2 = readFile<float>("a3test2.txt",n);
	cout<<"Before Quick Sort:"<<endl;
	print_array(arr2,n,cout);

	int count = quicksort<float>(arr2,n);

	cout<<"After Quick Sort:"<<endl;
	print_array(arr2,n,cout);


	cout<<"Quicksort comparisons count = "<<count<<endl;
}