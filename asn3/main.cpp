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
int insertionsort(T* arr, int n); //done

template <class T>
int quicksort(T*, int); // done

template <class T>
void quicksort_helper(T*, int, int, int&);

template <class T>
int quicksort_partition(T*, int, int, int&);

template <class T>
int mergesort(T*, int); //done

template <class T>
int merge(T*, int, int, int);

template <class T>
int shellsort(T*, int);

// template <class T>
// bool is_empty(T* arr){
// 	return arr==NULL;
// }

void test1(), test2(), test3(), test4();

int main(){
	test1();
	test2();
	test3();
	test4();
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

void test3(){
	int n = 0;
	string* arr3 = readFile<string>("a3test3.txt",n);
	cout<<"Before mergesort:"<<endl;
	print_array(arr3,n,cout);

	cout<<"mergesort comparisons = "<<mergesort<string>(arr3,n) <<endl;

	cout<<"After mergesort:"<<endl;
	print_array(arr3,n,cout);
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