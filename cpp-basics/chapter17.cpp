#include "lib/std_lib_facilities.h"

/*
 3.
 Write a function, void to_lower(char* s), that replaces all uppercase characters in the C-style string s with their lowercase equivalents.
 For example, Hello, World! becomes hello, world!.
 Do not use any standard library functions.
 A C-style string is a zero-terminated array of characters, so if you find a char with the value 0 you are at the end.
*/

void to_lower(char* s) {
    int i = 0;
    while(s[i]){
        if (int(s[i]) > 64 && int(s[i]) < 91){
            int value = int(s[i]) + 32;
            s[i] = char(value);
        }
        ++i;
    }
}

int main()
try {
    char mys[]{ "Hello, World! AZ 0-~=``//" };
    to_lower(mys);
    cout << mys;
}

catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    keep_window_open();
}
catch (...) {
    cerr << "exception\n";
}