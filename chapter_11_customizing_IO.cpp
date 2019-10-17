#include "std_lib_facilities.h"
/*

15. Write a program that reads a file of whitespace-separated numbers and outputs a file of numbers using 
scientific format
precision 8 
in four fields of 20 characters per line.

*/

const string source = "C:\\Users\\arcady\\source\\repos\\cpp-basics\\source.log";
const string target = "C:\\Users\\arcady\\source\\repos\\cpp-basics\\target.log";


ifstream input{ source };
ofstream output{ target };


int main() {

	try {
		if (!input || !output) cout << "Can't open file" << endl;

		double x;
		int count = 4;

		while (input >> x) {
			output << scientific << setprecision(8) << setw(20) << x;
			--count;
			if (!count) {
				count = 4;
				output << endl;
			}
		}
	}
		
	catch (exception& e) {
		cerr << "exception: " << e.what() << endl;
		return 1;
	}

}