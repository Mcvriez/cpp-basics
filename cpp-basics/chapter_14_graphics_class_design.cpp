#include "Graph.h"
#include "Simple_window.h"
#include "std_lib_facilities.h"

/*

9. Define a Group to be a container of Shapes with suitable operations applied to the various members of the Group.
Hint: Vector_ref.
Use a Group to define a checkers (draughts) board where pieces can be moved under program control.

*/

ostream& operator<<(ostream& out, Point& a) {
    out << "(" << a.x << "," << a.y << ")" << endl;
    return out;
}

int main()
try {
    Point tl(200,50);
    Simple_window win(tl,2400,1200,"My window");

    bool color = false;

    Group checkers;
    for (int i = 0; i<8; ++i)
        for (int j = 0; j<8; ++j) {
            checkers.add_shape(new Rectangle {Point{i*20,j*20},20,20});
            if (color) x.set_fill_color(Color::white);
            else x.set_color(Color::black);
            color = !color;
            win.attach(x);

            ;
        }
    //checkers.move(1,0);
    win.wait_for_button();

    win.wait_for_button();
    /*
    Group grp;
    Regular_octagon oct(Point(600,400),150);
    win.attach(oct);

    grp.add_shape(oct);
    win.wait_for_button();

    oct.set_style(Line_style(Line_style::dash, 10));
    oct.set_fill_color(100);

    Circle hs(Point(150,150),100);
    win.attach(hs);
    grp.add_shape(hs);
    win.wait_for_button();

    grp.move(100,100);
    win.wait_for_button();

    grp.set_fill_color(Color::dark_cyan);
    win.wait_for_button();

    grp.set_style(Line_style(Line_style::dashdot, 5));
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