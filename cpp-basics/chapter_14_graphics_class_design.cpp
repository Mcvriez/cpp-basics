#include "Graph.h"
#include "Simple_window.h"
#include "std_lib_facilities.h"

/*

Graph
 a sine (sin()),
 a cosine (cos()),
 the sum of those (sin(x) + cos(x)),
 and the sum of the squares of those (sin(x)*sin(x)+cos(x)*cos(x)) on a single graph.

Do provide axes and labels.

*/

constexpr int xmax = 1200; constexpr int ymax = 1200; constexpr int xoffset = 200; constexpr int yoffset = 200;
constexpr int xspace = 200; constexpr int yspace = 200; constexpr int xlength = xmax - xoffset - xspace;
constexpr int ylength = ymax - yoffset - yspace; constexpr int notches = 20;

constexpr int r_min = -5; constexpr int r_max = 5; constexpr int n_points = 400;
constexpr int x_scale = 80; constexpr int y_scale = 80;

int main()
try {
    Point tl(500,500);
    Point pmidle {xmax/2, ymax/2};

    Simple_window win(tl, xmax, ymax,"Function graphs.");
    Axis x_axis (Axis::x, Point{xoffset, ymax / 2}, xlength, notches, "1 = = 40 pixels");
    Axis y_axis (Axis::y, Point{xmax/2, ymax - yspace}, ylength, notches, "1 = = 40 pixels");
    x_axis.set_color(Color::dark_red);
    x_axis.set_style(Line_style(Line_style::solid, 2));
    y_axis.set_color(Color::dark_red);
    y_axis.set_style(Line_style(Line_style::solid, 2));
    win.attach(x_axis);
    win.attach(y_axis);


    Function cos_f {cos, r_min, r_max, pmidle, n_points, x_scale, y_scale};
    cos_f.set_color(Color::dark_blue);

    Function sin_f {sin, r_min, r_max, pmidle, n_points, x_scale, y_scale};
    sin_f.set_color(Color::dark_green);

    Function sum_f {[](double x) {return cos(x) + sin(x);}, r_min, r_max, pmidle, n_points, x_scale, y_scale};
    sum_f.set_color(Color::dark_yellow);

    Function sum_sq_f {[](double x) {return cos(x) * cos(x) + sin(x) * sin(x);}, r_min, r_max, pmidle, n_points, x_scale, y_scale};
    sum_sq_f.set_color(Color::dark_magenta);

    win.attach(cos_f);
    win.attach(sin_f);
    win.attach(sum_f);
    win.attach(sum_sq_f);

    sum_f.set_style(Line_style(Line_style::solid, 4));
    sum_sq_f.set_style(Line_style(Line_style::solid, 2));
    sin_f.set_style(Line_style(Line_style::solid, 2));
    cos_f.set_style(Line_style(Line_style::solid, 2));


    win.wait_for_button();
}

catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    keep_window_open();
}
catch (...) {
    cerr << "exception\n";
}