#include "std_lib_facilities.h"

/*

Design and implement a Money class for calculations involving dollars and cents where arithmetic has to be accurate
to the last cent using the 4/5 rounding rule (.5 of a cent rounds up; anything less than .5 rounds down). Represent a
monetary amount as a number of cents in a long int, but input and output as dollars and cents, e.g., $123.45. Do not
worry about amounts that don’t fit into a long int

*/

class Money
{
public:
	Money(string amount);
	int amount() const { return cents; }
private:
	long int cents;
};

Money::Money(string amount)
{
	if (amount.front() != '$' ||  amount.size() < 2) error("wrong input format");
	string substr = amount.substr(1, amount.size() - 1);
	double dollars = stod(substr);
	long int c = dollars * 1000;
	if (c % 10 > 4) cents = c / 10 + 1;
	else if (c % 10 < -4) cents = c / 10 - 1;
	else cents = c / 10;
}

ostream& operator << (ostream& os, Money m) {
	string prefix = "$ ";
	string del = ".";
	long int am = m.amount();
	int cents = am % 100;
	if (cents < 0 || am < 0) {
		cents *= -1; am *= -1; prefix += "-";
	}
	if (cents < 10) del += "0";
	os << prefix << am / 100 << del << cents << endl;
	return os;
}

int main() {
	try {
		Money v = Money("$0");
		Money v1 = Money("$-0.01");
		Money v2 = Money("$-10");
		Money v3 = Money("$-0.03");
		cout << v << v1 << v2 << v3;
	}
	catch (exception& e) {
		cerr << "Error: " << e.what() << endl;
	}
}