#include "std_lib_facilities.h"
/*

6. Write a program that replaces punctuation with whitespace. Consider . (dot), ; (semicolon), , (comma), ? (question
mark), - (dash), ' (single quote) punctuation characters. Don’t modify characters within a pair of double quotes ("). For
example, “- don't use the as-if rule.” becomes “ don t use the as if rule ”.

*/

string in = "C:\\Users\\arcady\\source\\repos\\cpp-basics\\source.log";
string out = "C:\\Users\\arcady\\source\\repos\\cpp-basics\\result.txt";

int main() {

	try {
		ifstream input { in };
		if (!input) cout << "Can't open file " << in << endl;
		ofstream output{ out };
		if (!output) cout << "Can't open file " << out << endl;

		char ch;
		string result;
		while (input.get(ch)) {
			if (ch == '"') {
				output << ch;
				while (input.get(ch) && ch != '"') // skipping
					output << ch;
				output << ch;
			}
			if (!ispunct(ch)) { output << ch; }
			else output << ' ';
		}
	}
		
	catch (exception& e) {
		cerr << "exception: " << e.what() << endl;
		return 1;
	}

}