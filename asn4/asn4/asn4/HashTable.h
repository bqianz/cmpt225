#pragma once
#include "WordFrequency.h"

class HashTable
{
public:
	// creates a hash table of default size: 101; sets all array elements to NULL
	HashTable();

	/* creates a hash table to store n items, where the value of n is given by the constructor's single
	integer parameter, the size of the underlying array shold be the smallest prime number equal to
	or greater than 2n; sts all array elements to NULL
	*/
	HashTable(int);

	// constructor that creates a deep copy of its HashTable reference parameter
	HashTable(const HashTable&);

	// deallocates any dynamic memory associated with the object
	~HashTable();

	/* overloads the assignment operator for HashTable objects - (deep) copies its HashTable reference parameter
	into the calling object after de-allocating any dynamic memory associated with the original contents of
	the calling object; if the calling object is the same as the paramter the operator should not copy it.
	*/
	HashTable& operator = (const HashTable&);

	/* searches the hash table for the method's string paramter, if a matching word is not present, it inserts a pointer
	to a new WordFrequency object into the hash table with a frequency of 1, otherwise it increments the word's
	frequency; if the hash table's load factor is greater than 0.67, it
		(1) creates a new hash table the size of which should be a prime number of approximately twice the size
		of the original table and
		(2) inserts the original contents to the new table at the appropriate location
	*/
	void insert(string);

	/* returns the frequency of the word if its string parameter is contained as a word in the hash table.
	otherwise return 0.
	*/
	int search(string) const;

	// returns the number of items stored in the hash table
	int size() const;

	// retuns the size of the hash table's underlying array
	int maxSize() const;
	
	// returns the load factor of the hash table
	float loadFactor() const;

	/* returns a pointer to an array of WordFrequency objects, the array contains objects (not pointers to objects)
	and contains the contents of the hash table - the size of the array should therefore equal the number of pointers
	to WordFrequency objects stored in the table
	*/
	WordFrequency* dump() const;

	void dump_print() const;

	int hash(string str, int array_size) const;

	void print_contents() const;


private:
	// an array of WordFrequency pointers
	WordFrequency** table;

	// size of underlying array
	int arraySize;

	// current number of items in the hash table
	int currSize;






	// private methods
	bool isPrime(int) const;

	int searchIndex(string) const;

	int calculateArraySize(int);

	void deleteTable(WordFrequency**, int);

	int quadraticProbe(int) const;

};

