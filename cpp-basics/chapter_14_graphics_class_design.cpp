#include "Graph.h"
#include "Simple_window.h"
#include "std_lib_facilities.h"

/*

11. Define a Binary_tree class derived from Shape.
Give the number of levels as a parameter
 (levels==0 means no nodes,
 levels==1 means one node,
 levels==2 means one top node with two sub-nodes,
 levels==3 means one top node with two sub-nodes each with two sub-nodes, etc.).

Let a node be represented by a small circle.
Connect the nodes by lines (as is conventional).
P.S. In computer science, trees grow downward from a top node (amusingly, but logically, often called the root).

*/

int main()
try {
    Point tl(500,500);
    Point tl2(1200,200);
    Simple_window win(tl,2400,1200,"My window");
    Binary_tree bt {tl2, 3, 60};
    win.attach(bt);
    win.wait_for_button();
    win.detach(bt);

    Binary_tree bt1 {tl2, 7, 10};
    win.attach(bt1);
    win.wait_for_button();
    win.detach(bt1);

    Binary_tree bt2 {tl2, 10, 3};
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