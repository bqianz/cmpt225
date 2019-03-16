// asn4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <typeinfo>
#include "HashTable.h"
#include "words.h"
using namespace std;


void test_default_constructor()
{
	HashTable ht;
	cout << "Default HashTable has array size " << ht.maxSize() << "\n";
}

void test_param_constructor(int n)
{
	HashTable ht(n);
	cout << "Default HashTable has array size " << ht.maxSize() << "\n";
}

void test_copy()
{
	string str1 = "hi", str2 = "me";

	HashTable ht1(1);

	ht1.insert(str1);
	cout << str1 << " inserted into ht1." << '\n';
	ht1.print_contents();

	ht1.insert(str2);
	cout << str2 << " inserted into ht1." << '\n';
	ht1.print_contents();

	HashTable ht2(ht1);
	cout << "ht2 copied from ht1." << '\n';

	// insert repeating word
	ht2.insert(str1);
	cout << str1 << " inserted into ht2." << '\n';

	cout << "ht1:" << '\n';
	ht1.print_contents();

	cout << "ht2:" << '\n';
	ht2.print_contents();
}

void test_equal()
{
	string str1 = "hi", str2 = "me";

	HashTable ht1(1);

	ht1.insert(str1);
	cout << str1 << " inserted into ht1." << '\n';
	ht1.print_contents();

	ht1.insert(str2);
	cout << str2 << " inserted into ht1." << '\n';
	ht1.print_contents();

	HashTable ht2=ht1;
	cout << "ht2 assigned from ht1" << '\n'<<'\n';

	// insert repeating word
	ht2.insert(str1);
	cout << str1 << " inserted into ht2." << '\n';

	cout << "ht1:" << '\n';
	ht1.print_contents();

	cout << "ht2:" << '\n';
	ht2.print_contents();

	HashTable ht3 = ht2;

	ht3.insert(str1);

	cout << "ht1:" << '\n';
	ht1.print_contents();

	cout << "ht2:" << '\n';
	ht2.print_contents();

	cout << "ht3:" << '\n';
	ht3.print_contents();



}



void test()
{
	vector<string> words = readWords("readme.txt");
	HashTable ht1(words.size());
	for (unsigned int i = 0; i < words.size(); i++)
	{
		ht1.insert(words[i]);
	}
	ht1.dump_print();
}

void test_self()
{
	string str1 = "hi", str2 = "me", str3 = "bye", str4 = "is";

	HashTable ht(1);

	// test regular insert
	ht.insert(str1);
	cout << str1 << " inserted." << '\n';
	ht.print_contents();

	ht.insert(str2);
	cout << str2 << " inserted." << '\n';
	ht.print_contents();

	// test increasing array size during insert
	ht.insert(str3);
	cout << str3 << " inserted." << '\n';
	ht.print_contents();

	ht.insert(str4);
	cout << str4 << " inserted." << '\n';
	ht.print_contents();

	// test insert repeating
	ht.insert(str4);
	cout << str4 << " inserted." << '\n';
	ht.print_contents();

	// test search
	cout << "Frequency of " << str4 << " is " << ht.search(str4) << '\n';
}


int main()
{
	test_();
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
