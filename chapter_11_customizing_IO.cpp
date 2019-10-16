#include "std_lib_facilities.h"
/*

5. Write a program that reads strings and for each string outputs the character classification of each character, as defined by
the character classification functions presented in §11.6. Note that a character can have several classifications (e.g., x is
both a letter and an alphanumeric).

*/

string path = "C:\\Users\\arcady\\source\\repos\\cpp-basics\\source.log";

int main() {

	try {
		ifstream input { path };
		if (!input) cout << "Can't open file " << path << endl;
		string word;
		while (getline(input, word)) {
			for (char ch : word) {
				cout << "Character " << ch << " classification:" << endl;
				if (isspace(ch)) cout << "isspace" << '\t';
				if (isalpha(ch)) cout << "isalpha" << '\t';
				if (isdigit(ch)) cout << "isdigit" << '\t';
				if (isxdigit(ch)) cout << "isxdigit" << '\t';
				if (isupper(ch)) cout << "isupper" << '\t';
				if (islower(ch)) cout << "islower" << '\t';
				if (isalnum(ch)) cout << "isalnum" << '\t';
				if (iscntrl(ch)) cout << "iscntrl" << '\t';
				if (ispunct(ch)) cout << "ispunct" << '\t';
				if (isprint(ch)) cout << "isprint" << '\t';
				if (isgraph(ch)) cout << "isgraph" << '\t';
				cout << endl;
			}
		}
	}
		
	catch (exception& e) {
		cerr << "exception: " << e.what() << endl;
		return 1;
	}

}