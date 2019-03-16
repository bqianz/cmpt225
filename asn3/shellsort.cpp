#include <string>
#include <stdexcept>
#include <iostream>
#include <fstream>

using namespace std;

// Function Prototypes
template <class T>
T* readFile(string infile, int &n);

template <class T>
void print_array(T* arr, int n, ostream& os);

template <class T>
int shellsort(T*, int);

void test4();

int main(){
	test4();
	return 0;
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
int shellsort(T* arr, int n){
	int count = 0;
	for(int gap = n/2; gap > 0 ; gap = gap/2){
		// operate on each element of arr[gap...n]
		for(int i = gap; i < n; i++){
			T temp = arr[i];

			int j = i;

			// find correct position j for temp
			while(arr[j-gap] > temp && j>=gap){ // compare arr[j - gap] and temp
				arr[j] = arr[j-gap];
				j = j - gap;
				count++;
			}
			
			arr[j] = temp;
			// the subsequence arr[..., j-gap, j, j+gap, ... i] is sorted
		}
		// arr is gap-sortd
	}
	return count;
}

void test4(){
	int n = 0;
	string* arr4 = readFile<string>("a3test3.txt",n);
	cout<<"Before shellsort:"<<endl;
	print_array(arr4,n,cout);

	cout<<"shellsort comparisons = "<<shellsort<string>(arr4,n) <<endl;

	cout<<"After shellsort:"<<endl;
	print_array(arr4,n,cout);
}