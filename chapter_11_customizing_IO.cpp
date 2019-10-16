#include "std_lib_facilities.h"
/*

8. Use the program from the previous exercise to make a dictionary (as an alternative to the approach in §11.7). Run the
result on a multi-page text file, look at the result, and see if you can improve the program to make a better dictionary.

*/

string in = "C:\\Users\\arcady\\source\\repos\\cpp-basics\\source.log";
string out = "C:\\Users\\arcady\\source\\repos\\cpp-basics\\result.txt";
string outdict = "C:\\Users\\arcady\\source\\repos\\cpp-basics\\dictionary.txt";

void raw_input() {
	ifstream input{ in };
	if (!input) cout << "Can't open file " << in << endl;
	ofstream output{ out };
	if (!output) cout << "Can't open file " << out << endl;

	bool mode = true;
	char ch, ch1, ch2, last_char;
	char single = '\'';

	while (input.get(ch)) {
		ch = tolower(ch);
		// cout << ch;
		if (ch == '-') {
			input.get(ch);
			if (isalpha(last_char) && isalpha(ch)) {
				output << '-';
			}
			else output << ' ';
		}

		if (ch == 'n') {
			input.get(ch1);
			input.get(ch2);
			if (ch1 == single && ch2 == 't') {
				if (last_char != 'a') output << " not";
				else output << "nnot";
				input.get(ch);
			}
			else { input.putback(ch2); input.putback(ch1); }
		}

		if (!ispunct(ch)) { output << (ch); }
		else output << ' ';
		last_char = ch;
	}
}

void dictionary() {
	ifstream newinput{ out };
	if (!newinput) cout << "Can't open file " << out << endl;
	ofstream doutput{ outdict };
	if (!doutput) cout << "Can't open file " << outdict << endl;
	vector <string> dict;
	string word;
	string last_word;

	while (newinput >> word) {
		dict.push_back(word);
	}
	sort(dict);
	for (string w : dict) {
		if (w != last_word) doutput << w << endl;
		last_word = w;
	}
}

int main() {

	try {
		raw_input();
		dictionary();		
	}
		
	catch (exception& e) {
		cerr << "exception: " << e.what() << endl;
		return 1;
	}

}