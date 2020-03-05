#include "lib/std_lib_facilities.h"

/*

9. Which way does the stack grow: up (toward higher addresses) or down (toward lower addresses)?
Which way does the free store initially grow (that is, before you use delete)?
Write a program to determine the answers.

 compiler also sets aside some memory to be used when you call functions,
 and they need space for their arguments and local variables (that’s called stack storage or automatic storage)

calls from stack (grows down):

1~~0x 7ffee cb61e84
2~~0x 7ffee caecb84
3~~0x 7ffee ca77884
4~~0x 7ffee ca02584
5~~0x 7ffee c98d284
6~~0x 7ffee c917f84
7~~0x 7ffee c8a2c84
8~~0x 7ffee c82d984
9~~0x 7ffee c7b8684

calls to heap (also grows down):

1~~0x 7ff80 f114018
2~~0x 7ff80 f0c5018
3~~0x 7ff80 f076018
4~~0x 7ff80 f027018
5~~0x 7ff80 efd8018
6~~0x 7ff80 ef89018
7~~0x 7ff80 e1dd018
8~~0x 7ff80 e18e018
9~~0x 7ff80 e13f018


    1~~0x 7f 04670bb018
30000~~0x 7f 022398e018

1 -> 30000 = 9.7 GB
*/

void recursive_increment(int x){
    ++x;
    if (x % 10000 == 0) {int a = x / 10000; cout << a << "~~" << &a << endl;}
    if (x > 100000) return;
    recursive_increment(x);
}

void new_grows(int x){
    while (x < 30000) {
        ++x;
        string* k = new string[10000];
        if (x == 1) cout << x << "~~" << k << endl;
    }
    string* k = new string[10000];
    cout << x << "~~" << k << endl;
}

int main()
try
{
    // recursive_increment(0);
    new_grows(0);
}
catch (exception& e)
{
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}

