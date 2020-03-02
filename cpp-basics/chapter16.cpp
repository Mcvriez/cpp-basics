#include "fltk_lib/Graph.h"
#include "fltk_lib/Simple_window.h"
#include "fltk_lib/std_lib_facilities.h"
#include <chrono>
#include <thread>

/*

6. Make an “analog clock,” that is, a clock with hands that move. You get the time of day from the operating system through
a library call. A major part of this exercise is to find the functions that give you the time of day and a way of waiting for a
short period of time (e.g., a second for a clock tick) and to learn to use them based on the documentation you found.

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