#include "std_lib_facilities.h"

/*
This drill simply involves getting the sequence of versions of Date to work. 
For each version:

1 define a Date called today initialized to June 25, 1978. 
2 then, define a Date called tomorrow and give it a value by copying today into it and increasingits day by one using add_day(). 
3 finally, output today and tomorrow using a << defined as in §9.8.

Your check for a valid date may be very simple. Feel free to ignore leap years.
However, don’t accept: 

- a month that is not in the [1,12] range 
- day of the month that is not in the [1,31] range. 

Test each version with at least one invalid date (e.g., 2004, 13, –5).

*/

// 5. The version from §9.7.4 same as previous because I have to use const member functions to make ostream& operator << work

enum class Month {
	jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

class Year { // year in [min:max) range
	static const int min = 1800;
	static const int max = 2200;
	static const int default = 1970;
public:
	class Invalid { };
	Year(int x) : y{ x } { if (x < min || max <= x) throw Invalid{}; }
	int year() const { return y; }
	Year() : y{ default } {}
private:
	int y;
};

class Date {
	int d;
	Month m;
	Year y;
public:
	Date(Year y, Month m, int d); // check for valid date and initialize
	int month() const { return int(m); } // doesn't compile w\o const
	int day() const { return d; }
	int year() const { return y.year(); }
	void add_day(int n); // increase the Date by n days

};


Date::Date(Year yy, Month mm, int dd) {
	y = yy;
	m = mm;
	d = dd;
	if (m<Month::jan || m>Month::dec || d < 1 || d>31) error("invalid date");
}

ostream& operator << (ostream& os, const Date& d) // 
{
	return os << '(' << d.year()
		<< ',' << d.month()
		<< ',' << d.day() << ')' << endl;
}

void Date::add_day(int n)
{
	int month = int(m);
	int year = y.year();
	if (n > 31 || n < 1) error("You can't add more than 31 day");
	d += n;
	if (d > 31) {
		++month;
		d = d - 31;
		m = Month(month);
	}
	if (month > 12) {
		y = Year{ year + 1 };
		m = Month::jan;
	}
}


int main() {
	try {
		Year my_year;
		cout << my_year.year() << endl;
		Date today(1969, Month::jun, 31); // 1 C++98 style
		cout << today;
		Date tomorrow = today;
		tomorrow.add_day(1);      // 2
		cout << tomorrow;
		
		Date inval{ 2004, Month::dec, -5 };
		cout << inval;

		return 0;
	}
	catch (exception& e) {
		cerr << "Error: " << e.what() << endl;
		return 1;
	}
}