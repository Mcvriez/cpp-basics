#include <iostream>
using namespace std;

/*

5. Write a function, string cat_dot(const string& s1, const string& s2), that concatenates two strings with a dot in
between. For example, cat_dot("Niels", "Bohr") will return a string containing Niels.Bohr.

6. Modify cat_dot() from the previous exercise to take a string to be used as the separator (rather than dot) as its third argument.

7. Write versions of the cat_dot()s from the previous exercises to take C-style strings as arguments
 and return a free-store-allocated C-style string as the result.
Do not use standard library functions or types in the implementation. Test these functions with several strings.
Be sure to free (using delete) all the memory you allocated from free store (using new).
Compare the effort involved in this exercise with the effort involved for exercises 5 and 6.
*/

string cat_dot(const string& s1, const string& s2, const string& sep) {
    return s1 + sep + s2;
}

char* cat_dot_c(const char* c1, const char* c2, const char* sep) {
    int count = 1;
    const char* c = c1; while(*c){ ++count; ++c;}
    c = c2; while(*c){ ++count; ++c;}
    c = sep; while(*c){ ++count; ++c;}
    char* res = new char[count];
    res[count] = 0;
    count = 0;
    while(*c1){res[count] = *c1; ++c1;++count;}
    while(*sep){res[count] = *sep; ++sep;++count;}
    while(*c2){res[count] = *c2; ++c2;++count;}
    return res;
}


int main()
{
    char s1[] = "Gogel"; char s2[] = "Barabek"; char sep[] = " Mogel ";
    char* res = cat_dot_c(s1, s2, sep);
    cout << res << endl;
    delete[] res;
}



