#include <string>
#include <stdexcept>
#include <iostream>
#include <fstream>

using namespace std;

// Function Prototypes
template <class T>
T* readFile(string, int&);

template <class T>
void print_array(T*, int, ostream&);

template <class T>
int mergesort(T*, int);

template <class T>
int merge(T*, int, int, int);



// template <class T>
// bool is_empty(T* arr){
// 	return arr==NULL;
// }

void test3();

int main(){
	test3();
	return 0 ;
}




void test3(){
	int n = 0;
	string* arr3 = readFile<string>("a3test3.txt",n);
	cout<<"Before mergesort:"<<endl;
	print_array(arr3,n,cout);

	cout<<"mergesort comparisons = "<<mergesort<string>(arr3,n) <<endl;

	cout<<"After mergesort:"<<endl;
	print_array(arr3,n,cout);
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
int mergesort(T* arr, int n){
	int count = 0;
	int l, m, r, current_size;
	for(current_size=1;current_size < n ; current_size = current_size*2){
		// select l, m, r to make halves of size current_size
		for(l=0;l<n-1;l=l+2*current_size){
			// m-(l-1) = current_size
			m = min(l + current_size - 1, n-1);
			r = min(l - 1 + 2*current_size,n-1);
			count = count + merge(arr, l,m,r);
		}
	}
	return count;
}

// function to merge two halves arr[l..m] and arr[m+1...r]
template <class T>
int merge(T* arr, int l, int m, int r){
	int local_count = 0;

	int n1 = m-l+1; // length of first half
	int n2 = r-m; // length of second half

	// copy data to temporary arrays
	T L[n1], R[n2];
	for(int i = 0; i < n1; i++){
		L[i] = arr[l+i];
	}

	for(int i = 0; i < n2; i++){
		R[i] = arr[m+i+1];
	}


	// copy data from temporary arrays to array
	int j(0), k(0), i(l);
	while(j<n1 && k<n2){
		if(L[j] < R[k]){
			arr[i] = L[j];
			j++;
		}
		else{
			arr[i] = R[k];
			k++;
		}
		local_count++;
		i++;
	}

	//copy rest of array
	while(j<n1){
		arr[i] = L[j];
		j++;
		i++;
	}
	while(k<n2){
		arr[i] = R[k];
		k++;
		i++;
	}

	return local_count;
}