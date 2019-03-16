#include "pch.h"
#include "WordFrequency.h"

WordFrequency::WordFrequency()
{
	word = "";
	frequency = 1;
}

WordFrequency::WordFrequency(string param)
{
	word = param;
	frequency = 1;
}

WordFrequency & WordFrequency::operator=(const WordFrequency & original)
{
	frequency = original.frequency;
	word = original.word;

	return *this;
}

void WordFrequency::increment()
{
	frequency++;
}

int WordFrequency::getFrequency() const
{
	return frequency;
}


string WordFrequency::getWord() const
{
	return word;
}