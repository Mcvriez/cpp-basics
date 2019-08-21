#include "std_lib_facilities.h"

int area(int length, int width) {
	return length * width;
}

int main()
{
	while (true) {
		int x = 0;
		cin >> x;
		if (x > 0) {
			cout << "all is ok\n";
		}
		else {
			cerr << "Bad bad\n";
			error("LOL");
		}
	}
}