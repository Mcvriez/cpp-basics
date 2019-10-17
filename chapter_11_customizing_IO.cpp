#include "std_lib_facilities.h"
/*

12. Reverse the order of characters in a text file. For example, asdfghjkl becomes lkjhgfdsa. Warning: There is no really
good, portable, and efficient way of reading a file backward.

*/

const string source = "C:\\Users\\arcady\\source\\repos\\cpp-basics\\source.log";
const string reversed = "C:\\Users\\arcady\\source\\repos\\cpp-basics\\reversed.log";


int main() {

	try {
		ifstream ist{ source };
		if (!ist) cout << "Can't open file";

		ofstream ost{ reversed };
		if (!ost) cout << "Can't open file";

		char c;
		vector <char> v;

		while (ist.get(c)) {
			v.push_back(c);
		}
		for (int x = v.size(); x > 0; --x) {
			ost << v[x - 1];
		}
	}
		
	catch (exception& e) {
		cerr << "exception: " << e.what() << endl;
		return 1;
	}

}