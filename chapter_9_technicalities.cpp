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

// 3. The version from §9.7.1 p 324

enum class Month {
	jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};



class Date {
	int y, d;
	Month m;
public:
	Date(int y, Month m, int d); // check for valid date and initialize
	int month() const { return int(m); } // doesn't compile w\o const
	int day() const { return d; }
	int year() const { return y; }
	void add_day(int n); // increase the Date by n days
};


Date::Date(int yy, Month mm, int dd) {
	if (yy > 2200 || yy < 1800) error("Wrong date format - year", yy);
	if (dd > 31 || dd < 1) error("Wrong date format - day", dd);
	y = yy;
	m = mm;
	d = dd;
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
	if (n > 31 || n < 1) error("You can't add more than 31 day");
	d += n;
	if (d > 31) {
		++month;
		d = d - 31;
	}
	if (month > 12) {
		++y;
		m = Month::jan;
	}
}


int main() {
	try {
		Date today (1978, Month::jun, 25); // 1 C++98 style
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