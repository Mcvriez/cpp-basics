#include "std_lib_facilities.h"
/*

2. Write a program that given a file name and a word outputs each line that contains that word together with the line
number. Hint: getline().

*/


const string source = "C:\\Users\\arcady\\source\\repos\\cpp-basics\\source.log";
const string search_word = "'USDZAR'";

int main() {

	try {
		ifstream input { source };
		int line_counter = 0;
		int appearence_counter = 0;
		while (input) {
			string line;
			getline(input, line);
			++line_counter;
			stringstream ss{ line };
			for (string chunk; ss >> chunk;) {
				if (chunk == search_word) {
					cout << "Line number: " << setw(5) << line_counter << " > " << line << endl;
					++appearence_counter;
				}
			}
		}
		cout << "Total appearences of word " << search_word << " is " << appearence_counter << endl;

	}
	catch (exception& e) {
		cerr << "exception: " << e.what() << endl;
		return 1;
	}

}