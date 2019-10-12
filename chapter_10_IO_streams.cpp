#include "std_lib_facilities.h"

/*

11. Write a program that produces the sum of all the whitespace-separated integers in a text file. For example, bears: 17
elephants 9 end should output 26.

*/
const string file = "C:\\Users\\arcady\\source\\repos\\cpp-basics\\input.txt";

int read_file(const string fname) {

	ifstream ist{ fname };
	if (!ist) error("can't open input file", fname);
	ist.exceptions(ist.exceptions() | ios_base::badbit);

	vector <int> f{ 0 };
	int number;
	string buf;

	while (true) {
		ist >> number;
		if (!ist) {
			if (ist.eof()) break;
			ist.unget();
			ist.clear();
			ist >> buf;
		}
		else {
			cout << number << endl;
			f.push_back(number);
		}
	}
	int sum = 0;
	for (int x : f) sum += x;
	return sum;
}



int main() {

	try {
		cout << "sum of all integers in the file: " << read_file(file) << endl;

	}
	catch (exception& e) {
		cerr << "exception: " << e.what() << endl;
		return 1;
	}

}