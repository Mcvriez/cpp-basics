#include <iostream>
using namespace std;

/*

1. Write a function, char* strdup(const char*), that copies a C-style string into memory it allocates on the free store. Do not use any standard library functions. 
Do not use subscripting; use the dereference operator * instead.

*/

char* strdup(const char* cp) {
    const char* ccp = cp; int counter = 1;
    while (*ccp) {cout << *ccp << "-" << counter << endl; ++counter; ++ccp;}
    char* r = new char[counter]; char* result = r;
    while (*cp) {
        *r = *cp;
        ++r; ++cp; 
    }
    *r = 0;
    return result;
}


int main()
{
    const char* cp {"test"};
    char* r = strdup(cp);
    cout << cp << ":\t" << &cp << endl;
    cout << r << ":\t" << &r << endl;
    delete[] r;

}


