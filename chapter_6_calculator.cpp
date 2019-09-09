// Chapter 6 excercise 10
#include "std_lib_facilities.h"

/*A permutation is an ordered subset of a set. For example, say you wanted
to pick a combination to a vault. There are 60 possible numbers, and
you need three different numbers for the combination. There are P(60,3)
permutations for the combination, where P is defined by the formula:

P (a, b) = a! / (a − b)!

where ! is used as a suffix factorial operator. For example, 4! is 4*3*2*1.
Combinations are similar to permutations, except that the order of the
objects doesn’t matter. For example, if you were making a “banana split”
sundae and wished to use three different flavors of ice cream out of five
that you had, you wouldn’t care if you used a scoop of vanilla at the
beginning or the end; you would still have used vanilla. The formula for
combinations is:

C (a, b) = P (a,b) / b!


Design a program that asks users for two numbers, asks them whether
they want to calculate permutations or combinations, and prints out the
result. This will have several parts. Do an analysis of the above require-
ments. Write exactly what the program will have to do. Then, go into
the design phase. Write pseudo code for the program, and break it into
sub-components. This program should have error checking. Make sure
that all erroneous inputs will generate good error messages.*/

// ask for two numbers
// read them to two integers
// ask what to calculate P or C

int factorial(int x){
	for (int i = x - 1; i > 0; --i){
		x *= i;
	}
	return x;
}

int permutation(int x, int y) {return factorial(x) / factorial(x-y);} // P(a, b) = a!/(a−b)!
int combination(int x, int y) {return permutation(x, y) / factorial(y);} // C(a, b) = P(a,b)/b!


void user_input(){
	cout << "Enter two positive integers separated by white space. First number should be bigger than second:\nFirst number: ";
	int x;
	int y;
	string input;
	cin >> x;
	cout << "Second number: ";
	cin >> y;
	if (!cin) error ("Invalid input - integers\n");
	if (x < 0 || y < 0) cout << "Numbers should be positive\n";
	else if (x < y) {
		cout << "Number of the permutations is zero.\n\n";
	}
	else {
		cout << "Enter what you want to calculate - number of permutations (P) or number of combinations (C):\n";
		cin >> input;
		if (!cin) error ("Invalid input - result\n");
		if (input == "C" || input == "c") {
			int result = combination(x, y);
			cout << "Number of combinations is: " << result << "\n\n";
		}
		else if (input == "P" || input == "p") {
			int result = permutation(x,y);
			cout << "Number of permutations is: " << result << "\n\n";
		}
		else cout << "Invalid input - type of operation. Try again\n";
	}
}

int main() {
	while (true){
		try {
			user_input();
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
}