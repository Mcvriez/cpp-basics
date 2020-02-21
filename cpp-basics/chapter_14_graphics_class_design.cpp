#include "Graph.h"
#include "Simple_window.h"
#include "std_lib_facilities.h"

/*

12. Modify Binary_tree to draw its nodes using a virtual function.
Then, a new class from Binary_tree that overrides that virtual function to use a different representation for
a node (e.g., a triangle).

*/

int main()
try {
    Point tl(500,500);
    Point tl2(1200,200);
    Simple_window win(tl,2400,1200,"My window");
    Binary_tree_triangles bt {tl2, 3, 60};
    bt.set_fill_color(Color(255, 123, 20));
    win.attach(bt);
    win.wait_for_button();
    win.detach(bt);


}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    keep_window_open();
}
catch (...) {
    cerr << "exception\n";
}