#include "std_lib_facilities.h"

/*

Design and implement a rational number class, Rational. A rational number has two parts: a numerator and a
denominator, for example, 5/6 (five-sixths, also known as approximately .83333). Look up the definition if you need to.
Provide 

assignment, 
addition, 
subtraction, 
multiplication, 
division 
equality 
Also, provide a conversion to double. 

Why would people want to use a Rational class?

*/

class Rational
{
public:
	Rational(int num, int den) : numerator{ num }, denominator{ den } {
		int del = 2;
		while (del < num&& del < den) {
			if (numerator % del == 0 && denominator % del == 0) {
				numerator /= del;
				denominator /= del;
			}
			++del;
		}
	};
	int get_numenator() const { return numerator; }
	int get_denominator() const { return denominator; }
	double to_double() const { return double(numerator) / double(denominator); }

private:
	int numerator;
	int denominator;
};

ostream& operator << (ostream& os, Rational& ra) {
	os << "Rational(" << ra.get_numenator() << "/" << ra.get_denominator() << ")" << endl;
	return os;
}

Rational operator + (const Rational& ra, const Rational& ra2) {
	int den = ra.get_denominator() * ra2.get_denominator();
	int num = (ra.get_numenator() * ra2.get_denominator()) + (ra2.get_numenator() * ra.get_denominator());
	return Rational(num, den);
}

Rational operator - (const Rational& ra, const Rational& ra2) {
	int den = ra.get_denominator() * ra2.get_denominator();
	int num = (ra.get_numenator() * ra2.get_denominator()) - (ra2.get_numenator() * ra.get_denominator());
	return Rational(num, den);
}

Rational operator * (const Rational& ra, const Rational& ra2) {
	int den = ra.get_denominator() * ra2.get_denominator();
	int num = ra.get_numenator() * ra2.get_numenator();
	return Rational(num, den);
}

Rational operator / (const Rational& ra, const Rational& ra2) {
	int den = ra.get_denominator() * ra2.get_numenator();
	int num = ra.get_numenator() * ra2.get_denominator();
	return Rational(num, den);
}

bool operator == (const Rational& ra, const Rational& ra2) {
	return ra.get_numenator() == ra2.get_numenator() && ra.get_denominator() == ra2.get_denominator();
}


int main() {
	try {
		Rational ra = Rational(4, 6);
		Rational ra2 = Rational(1, 3);
		cout << ra << ra2;
		cout << ra.to_double();
	}
	catch (exception& e) {
		cerr << "Error: " << e.what() << endl;
	}
}