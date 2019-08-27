// Chapter 5 excercise 9 sum of ints with int check
#include "std_lib_facilities.h"
const int max_int = 2147483647;

int main() {
	cout << "Sum of first N integers\n";
	int number = 0;
	int read = 0;
	int sum = 0;
	vector <int> values = {};

	cout << "Please enter number (positive and integer) of values you want to sum:\n";
	cin >> number;
	if (number < 1 && cin) {
		cout << "Number should be positive.\n";
	}
	else {
		cout << "Please enter some integers (press any character to stop):\n";
		while (cin >> read) {
			if (cin) {
				cout << read << " was added.\n";
				values.push_back(read);
			}
			else {
				cout << "Read error.\n";
			}
		}
		if (values.size() < number) {
			cout << "Number of values should be less than array of values.\n";
		}
		else {
			for (int index = 0; index < number; ++index) {
				if (max_int - sum < values[index] && sum > 0 || max_int - sum > values[index] && sum < 0) {
					cerr << "Result cannot be represented as an int\n";
					return 0;
				}
				sum += values[index];
			}
			cout << "The sum of first " << number << " elements is: " << sum << "\n";
		}
	}

}