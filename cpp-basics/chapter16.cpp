#include "fltk_lib/Graph.h"
#include "fltk_lib/Simple_window.h"
#include "fltk_lib/std_lib_facilities.h"

/*

2. Make a window (based on My_window) with a 4-by-4 checkerboard of square buttons. When pressed, a button
performs a simple action, such as printing its coordinates in an output box, or turns a slightly different color (until another
button is pressed).

*/


int main()
try {
    Point rootp(500,500);
    Checker_window win {rootp, 500, 500, "Custom Window"};
    win.wait_for_button();
    }

catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    keep_window_open();
}
catch (...) {
    cerr << "exception\n";
}