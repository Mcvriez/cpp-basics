#include "std_lib_facilities.h"
/*

14. Write a program that reads a text file and writes out how many characters of each character classification (§11.6) are in
the file.

*/

const string source = "C:\\Users\\arcady\\source\\repos\\cpp-basics\\source.log";
const string reversed = "C:\\Users\\arcady\\source\\repos\\cpp-basics\\reversed.log";

ifstream input{ source };


int main() {

	try {
		if (!input) cout << "Can't open file " << source << endl;

		string word;
		int isspacex = 0;
		int isalphax = 0;
		int isdigitx = 0;
		int isxdigitx = 0;
		int isupperx = 0;
		int islowerx = 0;
		int isalnumx = 0;
		int iscntrlx = 0;
		int ispunctx = 0;
		int isprintx = 0;
		int isgraphx = 0;

		while (getline(input, word)) {
			for (char ch : word) {
				if (isspace(ch))  isspacex += 1;
				if (isalpha(ch))  isalphax += 1;
				if (isdigit(ch))  isdigitx += 1;
				if (isxdigit(ch)) isxdigitx += 1;
				if (isupper(ch))  isupperx += 1;
				if (islower(ch))  islowerx += 1;
				if (isalnum(ch))  isalnumx += 1;
				if (iscntrl(ch))  iscntrlx += 1;
				if (ispunct(ch))  ispunctx += 1;
				if (isprint(ch))  isprintx += 1;
				if (isgraph(ch))  isgraphx += 1;
			}
		}
		cout << isspacex << " occurencies of isspace" << endl;
		cout << isalphax << " occurencies of isalpha" << endl;
		cout << isdigitx << " occurencies of isdigit" << endl;
		cout << isxdigitx << " occurencies of isxdigit" << endl;
		cout << isupperx << " occurencies of isupper" << endl;
		cout << islowerx << " occurencies of islower" << endl;
		cout << isalnumx << " occurencies of isalnum" << endl;
		cout << iscntrlx << " occurencies of iscntrl" << endl;
		cout << ispunctx << " occurencies of ispunct" << endl;
		cout << isprintx << " occurencies of isprint" << endl;
		cout << isgraphx << " occurencies of isgraph" << endl;
	}
		
	catch (exception& e) {
		cerr << "exception: " << e.what() << endl;
		return 1;
	}

}