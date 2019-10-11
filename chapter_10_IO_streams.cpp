#include "std_lib_facilities.h"

/*

Write a program that takes two files containing sorted whitespace-separated words and merges them, preserving order.

*/

const string file1 = "C:\\Users\\arcady\\source\\repos\\cpp-basics\\file1.txt";
const string file2 = "C:\\Users\\arcady\\source\\repos\\cpp-basics\\file2.txt";
const string out = "C:\\Users\\arcady\\source\\repos\\cpp-basics\\out.txt";


vector <string> read_file(const string fname) {
	
	ifstream ist{ fname };
	if (!ist) error("can't open input file", fname);
	ist.exceptions(ist.exceptions() | ios_base::badbit);
	
	vector <string> f;
	char ch;
	string buf;

	while (ist.get(ch)) {
		if (!ist) {
			if (ist.eof()) break;
		}
		buf += ch;
		if (ch == '\n' || ch == ' ') { f.push_back(buf); buf = ""; }
		cout << buf << ' ';
	}
	return f;
}

void output(const string ofname, const vector <string>& v) {
	ofstream ost{ ofname };
	if (!ost) error("can't open output file ", ofname);
	for (string word : v) {
		ost << word;
	}
}



int main() {

	try {
		vector <string> f2 = read_file(file1);
		vector <string> f1 = read_file(file2);
		f1.insert(f1.end(), f2.begin(), f2.end());
		sort(f1.begin(), f1.end());
		output(out, f1);
	}
	catch (exception& e) {
		cerr << "exception: " << e.what() << endl;
		return 1;
	}

}