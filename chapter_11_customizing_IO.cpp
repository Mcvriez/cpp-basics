#include "std_lib_facilities.h"
/*

7. Modify the program from the previous exercise so that it 
 - replaces don't with do not, can't with cannot, etc.; 
 - leaves hyphens within words intact (so that we get “ do not use the as-if rule ”); 
 - and converts all characters to lower case.

*/

string in = "C:\\Users\\arcady\\source\\repos\\cpp-basics\\source.log";
string out = "C:\\Users\\arcady\\source\\repos\\cpp-basics\\result.txt";

int main() {

	try {
		ifstream input { in };
		if (!input) cout << "Can't open file " << in << endl;
		ofstream output{ out };
		if (!output) cout << "Can't open file " << out << endl;

		bool mode = true;
		char ch, ch1, ch2, last_char;
		char single = '\'';

		while (input.get(ch)) {
			ch = tolower(ch);
			cout << ch;
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
			
			if (!ispunct(ch) || ch =='"') { output << (ch); }
			else if (mode) output << ' ';
			else output << (ch);
			if (ch == '"') mode = !mode;
			last_char = ch;
		}
	}
		
	catch (exception& e) {
		cerr << "exception: " << e.what() << endl;
		return 1;
	}

}