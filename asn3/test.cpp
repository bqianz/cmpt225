#include <iostream>
using namespace std;

int main(){

	int left, right;
	left = 0, right = 3;

	int arr[] = {0,1,2,3};

	cout<<arr[(left + right)/2]<<endl;
	return 0;
}