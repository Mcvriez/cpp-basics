#include "std_lib_facilities.h"

/*

Define an input operator (>>) that reads monetary amounts with currency denominations, such as USD1.23 and
DKK5.00, into a Money variable. Also define a corresponding output operator (>>).

*/

class Money
{
public:
	Money() : cents{ 0 }, cur{ "$" }, usratio{ 1 } {};
	Money(string curr, double amount);
	Money(string curr, double amount, double ratio);
	long int amount() const { return cents; }
	string currency() const { return cur; }
	double ratio() const { return usratio; }
	void set_ratio(double r) { if (r > 0) usratio = r; else error("Invalid ratio"); }
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
	if (!(curr == "$" || curr == "USD" || curr == "usd")) {
		cout << "Warning. Initializing non us dollar currency without provided ratio" << endl;
		usratio = 0;
	}
	else usratio = 1;
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

ostream& operator << (ostream& os, Money& m) {
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

istream& operator >> (istream& is, Money& m) {
	cout << "Enter the currency and amount:" << endl;
	char ch;
	string currency;
	while (is.get(ch)) {
		if (!isdigit(ch) && !isspace(ch))
			currency += ch;
		else {
			is.unget();
			break;
		}
	}
	if (currency == "") {
		is.clear(ios_base::failbit);
		error("non-defined currency");
	}
	if (!is) return is;
	double value;
	is >> value;
	
	m = Money(currency, value);
	cout << "object Money updated with following parameters: " << m << endl;
	return is;
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
	else if (m1.ratio() && m2.ratio())
		return Money("$", double(m1.amount() * m1.ratio() + m2.amount() * m2.ratio()) / 100);
	else error("Ratio is not defined for at least one of the sums. Use set_ratio() function.");
}
Money operator - (const Money& m1, const Money& m2) {
	if (same_currency(m1, m2)) {
		return Money(m1.currency(), double(m1.amount() - m2.amount()) / 100, m1.ratio());
	}
	else if (m1.ratio() && m2.ratio()) 
		return Money("$", double(m1.amount() * m1.ratio() - m2.amount() * m2.ratio()) / 100);
	else error("Ratio is not defined for at least one of the sums. Use set_ratio() function.");
	
}


int main() {
	try {
		Money v = Money("$", 0);
		Money v1 = Money("$", 12.01);
		Money v2 = Money("$", -10);
		Money v3 = Money("DKK", -23.03, 0.15);
		Money x;
		cin >> x; 
		
	}
	catch (exception& e) {
		cerr << "Error: " << e.what() << endl;
	}
}