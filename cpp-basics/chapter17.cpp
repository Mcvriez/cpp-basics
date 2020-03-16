#include <iostream>
#include <string>
using namespace std;

/*

3. Write a function, int strcmp(const char* s1, const char* s2), that compares C-style strings.
Let it return
    a negative number if s1 is lexicographically before s2,
    zero if s1 equals s2,
    and a positive number if s1 is lexicographically after s2.
Do not use any standard library functions. Do not use subscripting; use the dereference operator * instead.

*/

int strcmp(const char* s1, const char* s2) {
    while (*s1 && s2) {
        if (*s1 > *s2) return 1;
        if (*s2 > *s1) return -1;
        s1++; s2++;
    }
    if (*s1) return 1;
    if (*s2) return -1;
    return 0;
}


int main()
{
    const char* fp {"1"};
    const char* subs {"2"};

    int f = strcmp(fp, subs);
    cout << f << endl;

}



