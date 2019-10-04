#include "std_lib_facilities.h"

/*

Refine the Money class by adding a currency (given as a constructor argument). 
Accept a floating-point initializer as long as it can be exactly represented as a long int. 

Don’t accept illegal operations. For example, Money*Money
doesn’t make sense, and USD 1.23 + DKK 5.00 makes sense only if you provide a conversion table defining the
conversion factor between U.S. dollars (USD) and Danish kroner (DKK).

*/

class Money
{
public:
	Money(string curr, double amount);
	Money(string curr, double amount, double ratio);
	long int amount() const { return cents; }
	string currency() const { return cur; }
	double ratio() const { return usratio; }
private:
	long int cents;
	string cur;
	double usratio;
};

Money::Money(string curr, double amount){
	cur = curr;
	long int c = amount * 1000;
	if (c % 10 > 4) cents = c / 10 + 1;
	else if (c % 10 < -4) cents = c / 10 - 1;
	else cents = c / 10;
	if (curr == "$" || curr == "USD" || curr == "usd") usratio = 1;
	else error("can't initialize non us dollar currency without provided ratio");
}

Money::Money(string curr, double amount, double ratio) {
	cur = curr;
	long int c = amount * 1000;
	if (c % 10 > 4) cents = c / 10 + 1;
	else if (c % 10 < -4) cents = c / 10 - 1;
	else cents = c / 10;
	if (ratio <= 0) error("wrong ratio");
	usratio = ratio;
}

ostream& operator << (ostream& os, Money m) {
	string prefix = m.currency() + " ";
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

bool operator == (const Money& m1, const Money& m2) {
	return m1.currency() == m2.currency() && m1.amount() == m2.amount();
}

bool operator != (const Money& m1, const Money& m2) {
	return !(m1 == m2);
}

bool same_currency(const Money& m1, const Money& m2) {
	return m1.currency() == m2.currency();
}

Money operator + (const Money& m1, const Money& m2) {
	if (same_currency(m1, m2)) {
		return Money(m1.currency(), double(m1.amount() + m2.amount()) / 100, m1.ratio());
	}
	else return Money("$", double(m1.amount() * m1.ratio() + m2.amount() * m2.ratio())/100);
}

Money operator - (const Money& m1, const Money& m2) {
	if (same_currency(m1, m2)) {
		return Money(m1.currency(), double(m1.amount() - m2.amount()) / 100, m1.ratio());
	}
	else return Money("$", double(m1.amount() * m1.ratio() - m2.amount() * m2.ratio()) / 100);
}


int main() {
	try {
		Money v = Money("$", 0);
		Money v1 = Money("$", 12.01);
		Money v2 = Money("$", -10);
		Money v3 = Money("DKK", -23.03, 0.15);
		cout << v1 - v3 << v1 << double(v3.amount() * v3.ratio()) / 100;
		
	}
	catch (exception& e) {
		cerr << "Error: " << e.what() << endl;
	}
}