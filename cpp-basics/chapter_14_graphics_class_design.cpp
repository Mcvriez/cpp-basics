#include "Graph.h"
#include "Simple_window.h"
#include "std_lib_facilities.h"

/*

1. Here is another way of defining a factorial function:

int fac(int n) { return n>1 ? n * fac(n–1) : 1; } // factorial n!

It will do fac(4) by first deciding that since 4>1 it must be 4*fac(3), and that’s obviously 4*3*fac(2), which again is
4*3*2*fac(1), which is 4*3*2*1. Verify that the
recursive fac() works and gives the same results as the iterative fac() by calculating the factorial of 0, 1, 2, 3, 4, up until
and including 20.

*/
int fac_recursive(int n) { return n > 1 ? n * fac_recursive(n - 1) : 1; } // factorial n!
int fac(int n) { int r = 1; while (n > 1) {r *= n; --n;} return r; }

int main()
try {
    Point tl(500,500);
    Simple_window win(tl, 1200, 1200,"Function graphs.");
    for (int i = 1; i < 15; ++i){
        cout << fac(i) << "\t\t\t\t\t" << fac_recursive(i) << endl;
    }
 }

catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    keep_window_open();
}
catch (...) {
    cerr << "exception\n";
}