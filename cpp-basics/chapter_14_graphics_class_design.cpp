#include "Graph.h"
#include "Simple_window.h"
#include "std_lib_facilities.h"

/*

14. Add an operation to Binary_tree that adds text to a node.
You may have to modify the design of Binary_tree to implement this elegantly.
Choose a way to identify a node; for example, you might give a string "lrrlr" for navigating left,
right, right, left, and right down a binary tree (the root node would match both an initial l and an initial r).

*/

int main()
try {
    Point tl(500,500);
    Point tl2(900,200);
    Simple_window win(tl,1800,1500,"My window");

    Binary_tree_triangle bt {tl2, 5, 30, "ua"};
    bt.set_fill_color(Color(135,206,250));
    bt.mark_node("_rlrl"); // 17
    win.attach(bt);
    win.wait_for_button();

   /*
    win.detach(bt);
    Binary_tree bt1 {tl2, 4, 70, "none"};
    bt1.set_fill_color(Color(230,230,250));
    win.attach(bt1);
    win.wait_for_button();

    win.detach(bt1);
    Binary_tree bt2 {tl2, 3, 140, "la"};
    bt2.mark_node("ABCDEG");
    bt2.set_fill_color(Color(220,20,60));
    bt2.set_arrow_color(Color::dark_red);
    win.attach(bt2);
    win.wait_for_button();
    */
}

catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    keep_window_open();
}
catch (...) {
    cerr << "exception\n";
}