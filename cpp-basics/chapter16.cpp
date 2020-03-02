#include "fltk_lib/Graph.h"
#include "fltk_lib/Simple_window.h"
#include "fltk_lib/std_lib_facilities.h"

/*

4. Make a menu with items that make a circle, a square, an equilateral triangle, and a hexagon, respectively. Make an input
box (or two) for giving a coordinate pair, and place the shape made by pressing a menu item at that coordinate. Sorry, no
drag and drop.

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