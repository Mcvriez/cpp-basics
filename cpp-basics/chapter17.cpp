#include "lib/std_lib_facilities.h"

/*
 1. What is the output format of pointer values on your implementation? Hint: Don’t read the documentation.
*/

int main()
try {
    string x {"10"};
    string* pi = &x;
    cout << pi << endl;
    cout << sizeof(pi) << endl;
    cout << sizeof(*pi) << endl;
}

catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    keep_window_open();
}
catch (...) {
    cerr << "exception\n";
}