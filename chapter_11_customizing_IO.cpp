#include "std_lib_facilities.h"
/*

13. Reverse the order of words (defined as whitespace-separated strings) in a file. For example, Norwegian Blue parrot
becomes parrot Blue Norwegian. You are allowed to assume that all the strings from the file will fit into memory at
once.

*/

const string source = "C:\\Users\\arcady\\source\\repos\\cpp-basics\\source.log";
const string reversed = "C:\\Users\\arcady\\source\\repos\\cpp-basics\\reversed.log";


int main() {

	try {
		ifstream ist{ source };
		if (!ist) cout << "Can't open file";

		ofstream ost{ reversed };
		if (!ost) cout << "Can't open file";

		string word;
		vector <string> v;

		while (ist >> word) {
			v.push_back(word);
		}
		for (int x = v.size(); x > 0; --x) {
			ost << v[x - 1] << ' ';
		}
	}
		
	catch (exception& e) {
		cerr << "exception: " << e.what() << endl;
		return 1;
	}

}