#include "std_lib_facilities.h"
/*

11. Write a function vector<string> split(const string& s, const string& w) that returns a vector of whitespace-
separated substrings from the argument s, where whitespace is defined as “ordinary whitespace” plus the characters in
w.

*/

const string source = "first !second second seco!nd !thirdth !__!irdthird        still third";
const string del = "!__!";
const string del2 = "!";
const string del3 = "";

vector<string> split(const string& s, const string& w){
	istringstream ss{ s };
	vector<string> v;
	string word;
	string buff;
	char ch;

	while (ss.get(ch)) {
		if (!isspace(ch))
			word += ch;
		else {
			bool check = true;
			buff += ch;
			for (char n : w) {
				ss.get(ch);
				buff += ch;
				if (ch != n) {
					word += buff;
					check = false;
					break;
				}
			}
			buff = "";
			if (check && word != "") {
				v.push_back(word); 
				word = "";
			}
		}	
	}
	if (word.size()) v.push_back(word);
	for (string word : v) {
		cout << word << endl;
	}
	cout << v.size() << endl;;
	return v;
}

int main() {

	try {
		split(source, del);
		split(source, del2);
		split(source, del3);
	}
		
	catch (exception& e) {
		cerr << "exception: " << e.what() << endl;
		return 1;
	}

}