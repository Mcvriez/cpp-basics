#include "std_lib_facilities.h"
/*

16. Write a program to read a file of whitespace-separated numbers and output them in order (lowest value first), one value
per line. Write a value only once, and if it occurs more than once write the count of its occurrences on its line. For
example, 7 5 5 7 3 117 5 should give
3
5 3
7 2
117

*/

const string source = "C:\\Users\\arcady\\source\\repos\\cpp-basics\\source.log";
const string target = "C:\\Users\\arcady\\source\\repos\\cpp-basics\\target.log";


ifstream input{ source };
ofstream output{ target };


int main() {

	try {
		if (!input || !output) cout << "Can't open file" << endl;

		int x; 
		vector <int> v;
		
		while (input >> x) {
			v.push_back(x);
		}
		sort(v.begin(), v.end());
		v.push_back(0);

		if (!v.size()) error("Empty file");

		int last = v[0];
		int counter = 0;
		
		for (int x: v){
			if (x == last) ++counter;
			else {
				if (counter > 1 ) output << last << ' ' << counter << endl;
				else output << last << endl;
				counter = 1;
			}
			last = x;
		}

	}
		
	catch (exception& e) {
		cerr << "exception: " << e.what() << endl;
		return 1;
	}

}