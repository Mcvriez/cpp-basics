#include "std_lib_facilities.h"

/*

Define a Roman_int class for holding Roman numerals (as ints) with a << and >>. 
Provide Roman_int with an as_int() member that returns the int value, so that if r is a Roman_int, we can write cout << "Roman" << r << "
equals " << r.as_int() << '\n';.

*/


class Roman_int
{
public:
	Roman_int() :value{ 0 }, reprez{"N"}{};
	Roman_int(int x) :value{} {
		if (x < max && x > 0) {
			value = x;
		}
		else cout << "Roman int can't be less than zero or more than 5000";
		/*
		Symbol	I	V	X	L	C	D	M
		Value	1	5	10	50	100	500	1000
		*/
		int M = x / 1000;
		int h = M * 1000;
		int CM = (x - h) / 900;
		int D = (x - h) / 500;
		h += D * 500;
		int CD = (x - h) / 400;
		int C = (x - h) / 100;
		h += C * 100;
		int XC = (x - h) / 90;
		int L = (x - h) / 50;
		h += L * 50;
		int XL = (x - h) / 40;
		int X = (x - h) / 10;
		h += X * 10;
		int IX = (x - h) / 9;
		int V = (x - h) / 5;
		h += V * 5;
		int IV = (x - h) / 4;
		string rep;
		for (int i = 0; i < M; i++)
			rep += 'M';
		if (CM) rep += "CM";
		else {
			if (D) rep += 'D';
			if (CD) rep += "CD";
			else {
				for (int i = 0; i < C; i++)
					rep += 'C';
			}
		}
		
		if (XC) rep += "XC";
		else {
			if (L) rep += 'L';
			if (XL) rep += "XL";
			else {
				for (int i = 0; i < X; i++)
					rep += 'X';
			}
		}
		if (IX) rep += "IX";
		else {
			if (V) rep += 'V';
			if (IV) rep += "IV";
			else
				for (int i = 0; i < x - h; i++)
					rep += 'I';
		}
		reprez = rep;
	};
	int as_int() const { return value; }
	string repr() const { return reprez; }
private:
	int value;
	string reprez;
	static const int max = 5000;
};

ostream& operator << (ostream& os, const Roman_int& r) {
	os << r.repr();
	return os;
}


int main()
	try
	{
	for (int i = 50; i < 1100; i += 49) {
		Roman_int r = Roman_int(i);
		cout << r.as_int() << " -> " << r << ",\t";
	}
	}
	catch (exception& e) {
		cerr << "error: " << e.what() << '\n';
		return 1;
	}
	catch (...) {
		cerr << "Oops: unknown exception!\n";
		return 2;
	}
