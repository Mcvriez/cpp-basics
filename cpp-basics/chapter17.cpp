#include <iostream>
using namespace std;

/*

2. Write a function, char* findx(const char* s, const char* x), that finds the first occurrence of the C-style string x in s. 
Do not use any standard library functions. 
Do not use subscripting; use the dereference operator * instead.

*/

char* findx(const char* s, const char* x) {
    while (*s) {
        char* p = const_cast<char*>(s);
        const char* xp = x; 
        while (*xp==*s) {
            ++xp;++s;
            if (!*xp) return p;
            if(*xp!=*s) --s;
        }
        ++s;
    }
    return nullptr;
}


int main()
{
    const char* fp {"test b2 3d1kfsfs dfjs12121223lkjnk  111233  askd"};
    const char* subs {"123"};
    char* f = findx(fp, subs);
    if (f) cout << f << endl;
    else cout << "No result" << endl;

}



