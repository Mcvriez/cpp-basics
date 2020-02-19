#include "Graph.h"
#include "Simple_window.h"
#include "std_lib_facilities.h"

/*

8. Define a class Octagon to be a regular octagon.
Write a test that exercises all of its functions (as defined by you or inherited from Shape).

*/

ostream& operator<<(ostream& out, Point& a) {
    out << "(" << a.x << "," << a.y << ")" << endl;
    return out;
}

int main()
try {
    Point start{ 300, 300 };
    Simple_window win{ Point { 100, 100 }, 1200, 1000, "Canvas" };
    win.color(53);

    Regular_octagon rect{ start, 100 };
    rect.set_fill_color(220);
    rect.set_style(Line_style(Line_style::Line_style_type(3), 4));
    rect.set_color(200);

    win.attach(rect);
    win.wait_for_button();

    rect.move(100, 100);
    win.wait_for_button();

    Point m = rect.center();
    cout << m;

    int c = rect.color().as_int();
    cout << c << endl;

    int r = rect.radius();
    cout << r << endl;

    int fc = rect.fill_color().as_int();
    cout << fc << endl;

    int np = rect.number_of_points();
    cout << np << endl;

    int ls = rect.style().style();
    cout << ls << endl;

    Point p0 = rect.point(0);
    cout << p0 << endl;

    win.wait_for_button();

}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    keep_window_open();
}
catch (...) {
    cerr << "exception\n";
}