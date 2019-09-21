#include "std_lib_facilities.h"

/*
Create a vector of Fibonacci number sand print them using the function from exercise 2. 
To create the vector, write a function, 

fibonacci(x, y, v, n),
where integers x and y are ints, 
v is an empty vector<int>, 
and n is the number of elements to put into v; 
v[0] will be x
and v[1] will be y.

A Fibonacci number is one that is part of a sequence where each element is the
sum of the two previous ones.
For example, starting with 1 and 2, we get 1, 2, 3, 5, 8, 13, 21, . . ..
Your fibonacci() function should make such a sequence starting with its x and y arguments.

*/

// exercise 4 http://prntscr.com/p90jkc

vector <int> numbers;
const string label = "Here comes the vector:\n";

void print(const string& s, const vector<int>& vv) {
	cout << s;
	for (int x : vv) cout << x << '\n';
}

void fibonacci(int x, int y, vector<int>& vect, int n) {
	for (int i = 0; i < n; ++i) {
		if (i == 0) vect.push_back(x);
		else if (i == 1) vect.push_back(y);
		else vect.push_back(vect[i - 1] + vect[i - 2]);
	}
}


int main() {
	fibonacci(1, 2, numbers, 50);
	print(label, numbers);
}

