#include <iostream>
using namespace std;

/*

8. Rewrite all the functions in §18.7 to use the approach of making a backward copy of the string and then comparing; for example, take "home", generate "emoh", and compare those two strings to see that they are different, so home isn’t a palindrome.

*/

bool is_palindrome(const string& s) {
    string ss;
    for (const char x : s ) {ss.insert(0, 1, x);}
    return ss == s;
}

bool is_palindrome_a(const char s[], int n) {
    char backward[n];
    const char* k = s;
    while(n){
        backward[n-1] = *k;
        ++k; --n;
    }
    int i = 0;
    while(backward[i]){
        if (backward[i] != *s) {return false;}
        ++i; ++s;
    }
    return true;
}

bool is_palindrome_s(const char* first, const char* last) {
    const char* k = first;
    int count = 1;
    int scount;
    while(k != last){++count; ++k;}
    scount = count;
    k = first;
    char arr[count];
    while(count) {arr[count - 1] = *k; --count; ++k;}
    while(scount){
        if (*first != arr[count]) return false;
        ++count;
        ++first;
        --scount;
    }
    return true;
}

int main()
{
    cout<< is_palindrome("kappa") << endl;
    cout<< is_palindrome("kappak") << endl;

    char sss[]{ "string" }; char ss[]{ "AaA" };
    cout<< is_palindrome_a(sss, 6) << endl;
    cout<< is_palindrome_a(ss, 3) << endl;

    char* p1 = sss; char* p2 = &sss[5];
    char* ps1 = ss; char* ps2 = &ss[2];
    cout<< is_palindrome_s(p1, p2) << endl;
    cout<< is_palindrome_s(ps1, ps2) << endl;
}



