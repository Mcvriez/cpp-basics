#include "fltk_lib/Graph.h"
#include "fltk_lib/Simple_window.h"
#include "fltk_lib/std_lib_facilities.h"

/*

Place an Image on top of a Button; move both when the button is pushed.

*/


int main()
try {
    Point rootp(500,500);
    My_window win {rootp, 1500, 1500, "Custom Window"};


    win.wait_for_button();
    }

catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    keep_window_open();
}
catch (...) {
    cerr << "exception\n";
}