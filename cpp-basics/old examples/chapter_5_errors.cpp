// Chapter 5 excercise 14

#include "std_lib_facilities.h"
vector <int> monday;
vector <int> tuesday;
vector <int> wednesday;
vector <int> thursday;
vector <int> friday;
vector <int> saturday;
vector <int> sunday;
int rejected = 0;


void app_exit() {
	cout << "Program statistics:\n";
	int sum = 0; cout << "monday:\n";
	for (int x : monday) { sum += x; cout << x << ","; }
	cout << "\nSum: "<< sum << "\n"; sum = 0; cout << "tuesday:\n";
	for (int x : tuesday) { sum += x; cout << x << ","; }
	cout << "\nSum: " << sum << "\n"; sum = 0; cout << "wednesday:\n";
	for (int x : wednesday) { sum += x; cout << x << ","; }
	cout << "\nSum: " << sum << "\n"; sum = 0; cout << "thursday:\n";
	for (int x : thursday) { sum += x; cout << x << ","; }
	cout << "\nSum: " << sum << "\n"; sum = 0; cout << "friday:\n";
	for (int x : friday) { sum += x; cout << x << ","; }
	cout << "\nSum: " << sum << "\n"; sum = 0; cout << "saturday:\n";
	for (int x : saturday) { sum += x; cout << x << ","; }
	cout << "\nSum: " << sum << "\n"; sum = 0; cout << "sunday:\n";
	for (int x : sunday) { sum += x; cout << x << ","; }
	cout << "\nSum: " << sum << "\n";
	cout << "\nTotal rejects is: " << rejected << "\n";

}

int user_input(){
	string weekday = "";
	int value = 0;
	cout << "Enter day of the week and number or stop 0 to stop and see the stats\n";
	cin >> weekday >> value;
	if (!cin) error("Invalid input!\n");
	if (weekday == "stop" && value == 0) return 0;
	else if (weekday == "Monday" || weekday == "monday" || weekday == "mon" || weekday == "Mon") monday.push_back(value);
	else if (weekday == "Tuesday" || weekday == "tuesday" || weekday == "tue" || weekday == "Tue") tuesday.push_back(value);
	else if (weekday == "Wednesday" || weekday == "wednesday" || weekday == "wed" || weekday == "Wed") wednesday.push_back(value);
	else if (weekday == "Thursday" || weekday == "thursday" || weekday == "thu" || weekday == "Thu") thursday.push_back(value);
	else if (weekday == "Friday" || weekday == "friday" || weekday == "fri" || weekday == "Fri") friday.push_back(value);
	else if (weekday == "Saturday" || weekday == "saturday" || weekday == "sat" || weekday == "Sat") saturday.push_back(value);
	else if (weekday == "Sunday" || weekday == "sunday" || weekday == "sun" || weekday == "Sun") sunday.push_back(value);
	else {
		cout << weekday << " " << value << " was rejected\n";
		++rejected;
	}
	return 1;
}

int main() {
	while (true) {
		if (user_input() == 0) {
			app_exit(); break;
		}
	}
	return 0;
}