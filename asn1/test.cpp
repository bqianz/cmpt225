#include <iostream>
#include "StringSet.h"
using namespace std;



int main(){
	StringSet basic1, basic2;
	basic1.insert("hello");
	basic1.insert("world");
	basic2.insert("hello");
	basic2.insert("there");
	StringSet result(basic1.difference(basic2));
	cout<<result.size()<<'\n';
	cout<<result.find("hello")<<'\n';
	cout<<result.find("there");
	return 0;
}