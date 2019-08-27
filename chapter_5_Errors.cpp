// Chapter 5 excercise 10 sum of doubles
#include "std_lib_facilities.h"
const int max_int = 2147483647;

int main() {
	cout << "Sum of first N integers\n";
	int number = 0;
	double read = 0;
	double sum = 0;
	vector <double> values = {};
	vector <double> diff = {};

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
				sum += values[index];
			}
			cout << "The sum of first " << number << " elements is: " << sum << "\nDiff is:\n";
			for (int index = 1; index < values.size(); ++index) {
				diff.push_back(values[index] - values[index - 1]);
				cout << values[index] - values[index - 1] << " ";
			}
			cout << "\n";
		}
	}
}