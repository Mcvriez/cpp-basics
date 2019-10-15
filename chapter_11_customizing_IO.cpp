#include "std_lib_facilities.h"
/*

3. Write a program that removes all vowels from a file (“disemvowels”). For example, Once upon a time! becomes nc
pn tm!. Surprisingly often, the result is still readable; try it on your friends

*/


const string source = "C:\\Users\\arcady\\source\\repos\\cpp-basics\\source.log";
const string target = "C:\\Users\\arcady\\source\\repos\\cpp-basics\\target.log";
const vector <char> vowels = { 'a', 'e', 'i', 'o', 'u', 'y' };

int main() {

	try {
		ifstream input { source };
		if (!input) error("can't open input file", source);
		ofstream output{ target };
		if (!output) error("can't open output file", target);

		char ch;
		while (input.get(ch)) {
			bool vowel = false;
			for (char c : vowels) {
				if (tolower(ch) == c) {
					vowel = true; 
					break;
				}
			}
			if (!vowel) output << ch;
		}
		

	}
	catch (exception& e) {
		cerr << "exception: " << e.what() << endl;
		return 1;
	}

}