#include "Graph.h"
#include "Simple_window.h"
#include "std_lib_facilities.h"

/*

10. Define a class Pseudo_window that looks as much like a Window as you can make it without heroic efforts.
It should have rounded corners, a label, and control icons.
Maybe you could add some fake “contents,” such as an image. It need not actually do anything.
It is acceptable (and indeed recommended) to have it appear within a Simple_window.

*/

int main()
try {
    Point tl(2200,500);
    Point tl2(2200,900);
    Simple_window win(tl,2400,1200,"My window");
    Pseudo_window ps {tl, 2000, 500, "My pseudo window"};
    Pseudo_window ps1 {tl2, 600, 500, "My window"};
    win.attach(ps);
    win.attach(ps1);
    win.wait_for_button();

}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    keep_window_open();
}
catch (...) {
    cerr << "exception\n";
}