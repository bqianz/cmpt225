#pragma once
#include <iostream>

class Fraction{
public:
	Fraction();
	Fraction(int n, int d);
	~Fraction();

	void simplify();
	int getNumerator() const;
	bool equals(const Fraction&) const;

	bool operator==(const Fraction &) const;
	bool operator!=(const Fraction&) const;
	bool operator<(const Fraction&) const;
	bool operator<=(const Fraction&) const;
	bool operator>(const Fraction&) const;
	bool operator>=(const Fraction&) const;

private:
	int numerator;
	int denominator;
	int gcd(int a, int b) const;

	friend std::ostream& operator<<(std::ostream& os, const Fraction& f);
};