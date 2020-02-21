#include "Graph.h"
#include "Simple_window.h"
#include "std_lib_facilities.h"

/*

13. Modify Binary_tree to take a parameter (or parameters) to indicate what kind of line to use to connect the nodes
(e.g., an arrow pointing down or a red arrow pointing up).
Note how this exercise and the last use two alternative ways of making a class hierarchy more flexible and useful.

*/

int main()
try {
    Point tl(500,500);
    Point tl2(1200,200);
    Simple_window win(tl,2400,1500,"My window");

    Binary_tree bt {tl2, 5, 50, "ua"};
    bt.set_fill_color(Color(135,206,250));
    win.attach(bt);
    win.wait_for_button();

    win.detach(bt);
    Binary_tree bt1 {tl2, 4, 70, "none"};
    bt1.set_fill_color(Color(230,230,250));
    win.attach(bt1);
    win.wait_for_button();

    win.detach(bt1);
    Binary_tree bt2 {tl2, 3, 140, "la"};
    bt2.set_fill_color(Color(220,20,60));
    bt2.set_arrow_color(Color::dark_cyan);
    win.attach(bt2);
    win.wait_for_button();

}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    keep_window_open();
}
catch (...) {
    cerr << "exception\n";
}