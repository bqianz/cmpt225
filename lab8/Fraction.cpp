#include <iostream>
#include <sstream>
#include <stdexcept>
#include "Fraction.h"
using namespace std;

Fraction::Fraction(void){
	numerator = 0;
	denominator = 1;
}

Fraction::Fraction(int num, int den){
	if (den <= 0){
		throw invalid_argument("invalid denominator value");
	}
	numerator = num;
	denominator = den;
}

Fraction::~Fraction(void){
}

// Returns the greatest common divisor of two integers
int Fraction::gcd(int a, int b) const {
	while(b!=0){
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

// Simplifies the calling fraction
void Fraction::simplify(){
	int factor = gcd(numerator, denominator);
	numerator = numerator / factor;
	denominator = denominator / factor;
}

ostream& operator<<(ostream& os, const Fraction& f){
	os << f.numerator<<"/"<<f.denominator;
	return os;
}

int Fraction::getNumerator() const{
	return numerator;
}

bool Fraction::equals(const Fraction& f) const{
	int coVal = numerator * f.denominator;
	int paramVal = f.numerator * denominator;
	return (coVal == paramVal);
}

bool Fraction::operator==(const Fraction& f) const{
	int coVal = numerator * f.denominator;
	int paramVal = f.numerator * denominator;
	return (coVal == paramVal);
}

bool Fraction::operator!=(const Fraction& f) const{
	return !(*this==f);
}

bool Fraction::operator<(const Fraction& f) const {
	int coVal = numerator * f.denominator;
	int paramVal = f.numerator * denominator;
	return (coVal < paramVal);
}

bool Fraction::operator<=(const Fraction& f) const{
	return ((*this==f) || (*this<f));
}


bool Fraction::operator>(const Fraction& f) const{
	int coVal = numerator * f.denominator;
	int paramVal = f.numerator * denominator;
	return (coVal > paramVal);
}

bool Fraction::operator>=(const Fraction& f) const{
	return *this>f || *this==f;
}


int main(){
	Fraction fr1(3,4);
	Fraction fr2(6,8);
	Fraction fr3(5,8);
	Fraction fr4(7,9);
	
	//cout<<fr1<<"==" <<fr2<<": "<<(fr1==fr2)<<endl;

	// cout<< fr1 << " != " << fr2 <<": "<<(fr1!=fr2)<<endl;
	// cout<< fr1 << " != " << fr3 <<": "<<(fr1!=fr3)<<endl;

	// cout<<fr1<<" < "<<fr3<<": "<<(fr1<fr3)<<endl;
	// cout<<fr1<<" < "<<fr4<<": "<<(fr1<fr4)<<endl;

	// cout<<fr1<<" <= "<<fr2<<": "<<(fr1<=fr2)<<endl;
	// cout<<fr1<<" <= "<<fr3<<": "<<(fr1<=fr3)<<endl;
	// cout<<fr1<<" <= "<<fr4<<": "<<(fr1<=fr4)<<endl;

	// cout<<fr1<<" > "<<fr3<<": "<<(fr1>fr3)<<endl;
	// cout<<fr1<<" > "<<fr4<<": "<<(fr1>fr4)<<endl;

	cout<<fr1<<" >= "<<fr2<<": "<<(fr1>=fr2)<<endl;
	cout<<fr1<<" >= "<<fr3<<": "<<(fr1>=fr3)<<endl;
	cout<<fr1<<" >= "<<fr4<<": "<<(fr1>=fr4)<<endl;

	return 0;
}

