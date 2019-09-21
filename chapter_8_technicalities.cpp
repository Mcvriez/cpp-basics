#include "std_lib_facilities.h"

//  Write a function print() that prints a vector of int s to cout. 
//  Give it two arguments: a string for “labeling” the outputand and a vector.

const vector <int> vect = { 1, 2, 3, 4, 123, 234 };
const string label = "Here comes the vector:\n";

void print(const string& s, const vector<int>& vv) {
	cout << s;
	for (int x : vv) cout << x << '\n';
}


int main() {
	print(label, vect);
}

