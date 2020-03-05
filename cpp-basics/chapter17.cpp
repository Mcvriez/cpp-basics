#include "lib/std_lib_facilities.h"

/*

4. Write a function, char* strdup(const char*), that copies a C-style string into memory it allocates on the free store.
Do not use any standard library functions.

*/

char* strdup(const char* pcc) {
    int i = 0;
    while(pcc[i]){++i;}
    char* res = new char[i]; i = 0;
    while (pcc[i]){ res[i] = pcc[i]; ++i; }
    res[i] = char(0); // 0 terminator
    return res;
}

int main()
try {
    string s = "12345";
    char* pcn = strdup(s.c_str());
    cout << pcn << "~" << pcn[0] << pcn[4] << pcn[5]<<s.c_str()[5] << endl;
    cout << pcn << "~" << s.c_str()[0] << s.c_str()[4] << s.c_str()[5] << s.c_str()[6];
}

catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    keep_window_open();
}
catch (...) {
    cerr << "exception\n";
}