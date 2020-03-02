#include "fltk_lib/Graph.h"
#include "fltk_lib/Simple_window.h"
#include "fltk_lib/std_lib_facilities.h"

/*

5. Write a program that draws a shape of your choice and moves it to a new point each time you click “Next.” The new
point should be determined by a coordinate pair read from an input stream.

*/


int main()
try {
    Point rootp(500,500);
    Shapes_window win {rootp, 1500, 1500, "Custom Window"};
    return gui_main();
    }

catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    keep_window_open();
}
catch (...) {
    cerr << "exception\n";
}