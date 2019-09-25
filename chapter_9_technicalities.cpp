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

// 1. The version from §9.4.1 page 309

struct Date {
	int y; // year
	int m; // month in year
	int d; // day of month
};

ostream& operator<<(ostream& os, const Date& d)
{
	return os << '(' << d.y
		<< ',' << d.m
		<< ',' << d.d << ')' << endl;
}

void init_day(Date& dd, int y, int m, int d)
{
	if (y > 2200 || y < 1800) error("Wrong date format - year", y);
	if (m > 12 || m < 1) error("Wrong date format - month", m);
	if (d > 31 || d < 1) error("Wrong date format - day", d);
	dd.y = y;
	dd.m = m;
	dd.d = d;
}

void add_day(Date& dd, int n)
{
	if (n > 31 || n < 1) error("You can't add more than 31 day");
	dd.d += n;
	if (dd.d > 31) {
		++dd.m;
		dd.d = dd.d - 31;
	}
	if (dd.m > 12) {
		++dd.y;
		dd.m = 1;
	}
}

void simple_print(const Date& today) {
	cout << today.y << "/" << today.m << "/" << today.d << endl;
}


int main() {
	try {
		Date today;
		init_day(today, 1978, 6, 25); // 1
		cout << today;
		Date tomorrow = today;
		add_day(tomorrow, 1);
		cout << tomorrow;
		Date inval;
		init_day(inval, 2004, 13, -5);
		cout << inval;
		return 0;
	}
	catch (exception& e) {
		cerr << "Error: " << e.what() << endl;
		return 1;
	}
}