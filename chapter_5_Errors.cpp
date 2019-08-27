// Chapter 5 excercise 11 Fibonacci
#include "std_lib_facilities.h"
const int max_int = 2147483647;

int main() {
	int max = 0;
	cout << "Enter max Fibonacci numbers you want to see:\n";
	cin >> max;
	if (!cin) error("Wrong input\n");
	int first = 1;
	int second = 1;
	int sum = 0;
	cout << first << "\t";
	while (max_int - second > first && max > 0) {
		cout << second << "\t";
		sum = first + second;
		first = second;
		second = sum;
		--max;
	}
}