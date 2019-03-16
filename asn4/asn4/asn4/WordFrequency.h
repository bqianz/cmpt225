#pragma once
#include<string>

using namespace std;
class WordFrequency
{
public:
	// creates a WordFrequency object and sets word to the empty string and frequency to 1
	WordFrequency();

	// creates a WordFrequency object and assigns its string parameter ot word and sets frequency to 1
	WordFrequency(string);

	WordFrequency& operator = (const WordFrequency&);

	// incremetns frequency
	void increment();

	// returns frequency
	int getFrequency() const;

	// returns word
	string getWord() const;

private:
	string word;
	int frequency;
};

