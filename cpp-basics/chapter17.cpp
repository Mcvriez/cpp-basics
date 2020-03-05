#include "lib/std_lib_facilities.h"

/*

5. Write a function, char* findx(const char* s, const char* x), that finds the first occurrence of the C-style string x in s.

*/

const char* findx_const(const char* s, const char* x) {
    if (!s || !x) return nullptr;
    int i = 0;
    while(s[i]){
        if (s[i] == x[0]){
            int j = 0;
            const char* pr = &(s[i]);
            while(x[j]) {
                if (x[j] != s[i]) break;
                ++j; ++i;
            }
            if (!x[j]) return pr;
        }
        ++i;
    }
    return nullptr;
}

char* findx(const char* s, const char* x) {
    if (!s || !x) return nullptr;
    int i = 0;
    while(s[i]){
        if (s[i] == x[0]){
            int j = 0;
            char* pr = const_cast<char *>(&(s[i])); // ???
            while(x[j]) {
                if (x[j] != s[i]) break;
                ++j; ++i;
            }
            if (!x[j]) return pr;
        }
        ++i;
    }
    return nullptr;
}

int main()
try {
    string s = "123abd456aBc789abc0123";
    const char* pch = s.c_str();
    const char x[] {"abc"};
    const char* res = findx(pch, x);
    res ? cout << *res << res[1] << res[2] << res[3] : cout << "Nullptr";


}

catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    keep_window_open();
}
catch (...) {
    cerr << "exception\n";
}