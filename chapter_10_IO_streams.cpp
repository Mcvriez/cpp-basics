#include "std_lib_facilities.h"


int main() {
	try {
		cout << "hello" << endl;
	}
	catch (exception& e) {
		cerr << "Error: " << e.what() << endl;
	}
}