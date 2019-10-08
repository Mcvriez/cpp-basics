#include "std_lib_facilities.h"

/*

Write a program that produces the sum of all the numbers in a file of whitespace-separated integers.

*/


const string input = "C:\\Users\\arcady\\source\\repos\\cpp-basics\\input.txt";

ifstream& operator >> (ifstream& ifs, vector <int>& val){
	int i;
	ifs >> i;
	if (!ifs) {
		if (ifs.eof()) return ifs;
		else {
			ifs.clear();
			string t;
			ifs >> t;
			cout << "Format error occured with the string: "<< t << endl;
			return ifs;
		}
	}
	else val.push_back(i);
	return ifs;
}


void print_v(const vector<int>& v) {
	for (int x : v) {
		cout << x << "-";
	}
}

int sum(const vector<int>& v) {
	int sum = 0;
	for (int x : v) {
		sum += x;
	}
	return sum;
}

int main() {
	try {
		ifstream ist{ input };
		if (!ist) error("can't open input file", input);
		ist.exceptions(ist.exceptions() | ios_base::badbit);
		vector <int> results;
		while (true) {
			if (!(ist >> results)) break;
		}
		// print_v(results);
		cout << "Sum of the all elements: " <<sum(results);
	}
	catch (exception& e) {
		cerr << "Error: " << e.what() << endl;
	}
}