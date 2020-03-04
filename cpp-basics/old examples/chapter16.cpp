#include "fltk_lib/std_lib_facilities.h"

/*

10. Provide a program where you can choose among a set of functions (e.g., sin() and log()), provide parameters for those
functions, and then graph them.

*/



int main()
try {
    Point rootp(500,500);
    Math_window win {rootp, 1500, 1000, "Custom Window"};
    return gui_main();
}

catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    keep_window_open();
}
catch (...) {
    cerr << "exception\n";
}