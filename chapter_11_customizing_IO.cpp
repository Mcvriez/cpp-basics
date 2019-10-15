#include "std_lib_facilities.h"
/*

Write a program that reads a text file and converts its input to all lower case, producing a new file.

*/


const string source = "C:\\Users\\arcady\\source\\repos\\cpp-basics\\source.log";
const string target = "C:\\Users\\arcady\\source\\repos\\cpp-basics\\target.log";

int main() {

	try {
		ifstream input { source };
		ofstream output{ target };
		char ch;
		while (input.get(ch)) {
			ch = tolower(ch);
			output << ch;
		}

	}
	catch (exception& e) {
		cerr << "exception: " << e.what() << endl;
		return 1;
	}

}