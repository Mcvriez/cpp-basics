// Chapter 5 excercise 8 sum of ints
#include "std_lib_facilities.h"

int main() {
	cout << "Sum of first N integers\n";
	try {
		int number = 0;
		int read = 0;
		int sum = 0;
		vector <int> values = {};

		cout << "Please enter number (positive and integer) of values you want to sum:\n";
		cin >> number;
		if (number < 1) {
			cout << "Number should be positive.\n";
			return 0;
		}
		else {
			cout << "Please enter some integers (press any character to stop):\n";
			while (cin >> read) {
				values.push_back(read);
			}
			if (values.size() < number) {
				cout << "Number of values should be less than array of values.\n";
				return 0;
			}
			else {
				for (int index = 0; index < number; ++index) {
					sum += values[index];
				}
				cout << "The sum of first " << number << " elements is: " << sum << "\n";
				return 0;
			}
		}
	}
	catch (exception& e) {
		cerr << "Error: " << e.what() << endl;
		keep_window_open();
		return 1;
	}
	catch (...) {
		cerr << "Unknown exception!\n";
		keep_window_open();
		return 2;
	}

}