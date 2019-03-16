#include "pch.h"
#include "HashTable.h"
#include <iostream>


HashTable::HashTable()
{
	arraySize = 101;
	currSize = 0;

	table = new WordFrequency*[arraySize]();
}


HashTable::HashTable(int n)
{
	arraySize = calculateArraySize(n);
	currSize = 0;

	table = new WordFrequency*[arraySize]();
}

// tbc
HashTable::HashTable(const HashTable& ht)
{
	arraySize = ht.arraySize;
	currSize = ht.currSize;
	
	table = new WordFrequency*[arraySize]();

	// ht.print_contents() work so ht is not empty
	// but ht.table contains null wordfrequency pointers
	
	for (int i = 0; i < arraySize; i++)
	{
		if (ht.table[i]== NULL)
		{
			continue;
		}
		table[i] = new WordFrequency;
		*table[i] = *ht.table[i];
	}
}

HashTable & HashTable::operator=(const HashTable & ht1)
{
	if(this!=&ht1)
	{
		deleteTable(table, arraySize);
		*this = HashTable(ht1);
	}
	
	return *this;
}


HashTable::~HashTable()
{
	deleteTable(table, arraySize);
}

void HashTable::insert(string str)
{
	if (search(str) == 0)
	{	
		
		// increase array size and rehash with new modulo
		if(float(currSize + 1) / float(arraySize) > 0.67)
		{
			int oldSize = arraySize;
			arraySize = calculateArraySize(oldSize);

			WordFrequency** newTable = new WordFrequency*[arraySize]();
			int j;
			for (int i = 0; i < oldSize; i++)
			{
				if (table[i] != NULL)
				{
					j = hash(table[i]->getWord(), arraySize);
					newTable[j] = new WordFrequency(table[i]->getWord());
				}
			}
			deleteTable(table, oldSize);
			table = newTable;
		}
		int hv = hash(str, arraySize);
		int index = quadraticProbe(hv);
		table[index] = new WordFrequency(str);
		currSize++;
	}

	else
	{
		table[searchIndex(str)]->increment();
	}
}

int HashTable::search(string str) const
{
	int index = hash(str, arraySize);
	int original = index, p = 1;
	while(table[index] != NULL)
	{	
		if((table[index]->getWord()) == str)
		{
			return table[index]->getFrequency();
		}
		index = (original + p * p) % arraySize;
		p++;
		
	}
	return 0;
}

int HashTable::size() const
{
	return currSize;
}

int HashTable::maxSize() const
{
	return arraySize;
}

float HashTable::loadFactor() const
{
	return float(currSize) / float(arraySize);
}

// uses "new"
WordFrequency * HashTable::dump() const
{
	WordFrequency* result = new WordFrequency[currSize];
	int j = 0;
	for (int i = 0; i < arraySize; i++) 
	{
		if (table[i]!=NULL)
		{
			result[j] = *table[i];
			j++;
		}
	}
	return result;
}

void HashTable::dump_print() const
{
	WordFrequency* d = dump();
	for (int i = 0; i < currSize; i++)
	{
		cout << d[i].getWord()<<" ";
	}
	delete[] d;
}

// with 6k + 1 optimization
bool HashTable::isPrime(int n) const
{
	if (n < 4) {
		return n > 1;
	}
	else if (n % 2 == 0 || n % 3 == 0) {
		return false;
	}

	int i = 5;
	while (i*i <= n) {
		if (n % i == 0 || n % (i + 2) == 0) {
			return false;
		}
		i += 6;
	}
	return true;
}


int HashTable::searchIndex(string str) const
{
	for (int i = 0; i < arraySize; i++)
	{
		if (table[i] != NULL)
		{
			if (str == table[i]->getWord())
			{
				return i;
			}
		}
	}
	return -1;
}

int HashTable::calculateArraySize(int n)
{
	int result = 2 * n + 1;
	while (!isPrime(result))
	{
		result += 2;
	}
	return result;
}

void HashTable::deleteTable(WordFrequency** tb, int s)
{
	for (int i = 0; i < s; i++) {
		if (tb[i] != NULL)
		{
			delete tb[i];
		}
	}
	delete[] tb;
}

int HashTable::quadraticProbe(int original) const
{
	int newIndex = original;
	int p = 1;
	while (table[newIndex] != NULL)
	{
		newIndex = (original + p * p) % arraySize;
		p++;
	}

	return newIndex;
}

int HashTable::hash(string str, int array_size) const
{
	int value = str[0] - 96;
	int len = str.length();
	for (int i = 1; i < len; i++)
	{
		value = (value * 32 + str[i] - 96) % array_size;
	}

	return value;
}

void HashTable::print_contents() const
{
	int len = maxSize();
	cout << "Number of elements ht contains is " << size() << '\n';
	cout << "Array size is " << maxSize() << '\n';

	cout << "Position | Body | Frequency " << '\n';
	for (int i = 0; i < len; i++)
	{
		if (table[i] != NULL)
		{
			cout << i << " | " << table[i]->getWord() << " | " << table[i]->getFrequency() << '\n';
		}
	}
	cout << '\n';
}

