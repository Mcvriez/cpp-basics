#include "std_lib_facilities.h"
/*

10. Write a function vector<string> split(const string& s) that returns a vector of whitespace-separated substrings
from the argument s.

*/

const string source = "C:\\Users \\arcady\\sou  rce\\repos\\cpp-ba  sics\\sourc e.lo g";
string outbin = "C:\\Users\\arcady\\source\\repos\\cpp-basics\\binary.txt";
string frombin = "C:\\Users\\arcady\\source\\repos\\cpp-basics\\frombinary.txt";

vector<string> split(const string& s){
	istringstream ss{ s };
	vector<string> v;
	string word;
	while (ss >> word) {
		v.push_back(word);
		cout << word << endl;
	}
	return v;
}

int main() {

	try {
		split(source);
	}
		
	catch (exception& e) {
		cerr << "exception: " << e.what() << endl;
		return 1;
	}

}