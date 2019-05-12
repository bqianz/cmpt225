// read string from file and print string without spaces
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
	ifstream ifs("textfile.txt");
	string content((istreambuf_iterator<char>(ifs)),(istreambuf_iterator<char>()));
	cout<<content<<'\n';

	return 0;
}