#include "std_lib_facilities.h"

/*

Write the function print_year() mentioned in §10.11.2

*/


const int not_a_reading = -7777;    // less than absolute zero
const int not_a_month = -1;


struct Day {
	vector<double> hour{ vector<double>(24,not_a_reading) };
};


struct Month {        // a month of temperature readings
	int month;        // [0:11] January is 0
	vector<Day> day;  // [1:31] one vector of readings per day
	Month()           // at most 31 days in a month (day[0] wasted)
		:month(not_a_month), day(32) { }
};


struct Year {             // a year of temperature readings, organized by month
	int year;             // positive == A.D.
	vector<Month> month;  // [0:11] January is 0
	Year() :month(12) { } // 12 months in a year
};


void print_day(ostream& ost, const Day& day) {
	for (int i = 0; i < day.hour.size(); ++i) {
		if (day.hour[i] != not_a_reading)
			ost << "\t\t " << "day "<< i <<": " << day.hour[i] << endl;
	}
}


void print_month(ostream& ost, const Month& month) {
	if (month.month != not_a_month) {
		ost << "\tmonth: " << month.month << endl;
		for (Day day : month.day)
			print_day(ost, day);
	}
}

void print_year(ostream& ost, const Year& y)
{
	ost << y.year << " contains following data:" << endl;
	for (Month m : y.month) {
		print_month(ost, m);
	}
}


int main()
	try
	{
	Year y2000;
	Month feb; Month dec;
	Day feb_d1; Day feb_d2; Day dec_d15; Day dec_d14;
	feb_d1.hour[1] = 68;
	feb_d1.hour[0] = 67.2;
	feb_d2.hour[3] = 66.66;
	dec_d15.hour[15] = -9.2;
	dec_d15.hour[14] = -8.8;
	dec_d14.hour[0] = -2;
	feb.month = 1;
	dec.month = 11;
	feb.day[1] = feb_d1;
	feb.day[2] = feb_d2;
	dec.day[14] = dec_d14;
	dec.day[15] = dec_d15;
	y2000.year = 2000;
	y2000.month[1] = feb;
	y2000.month[11] = dec;

	print_year(cout, y2000);
	}
	catch (exception& e) {
		cerr << "error: " << e.what() << '\n';
		return 1;
	}
	catch (...) {
		cerr << "Oops: unknown exception!\n";
		return 2;
	}
