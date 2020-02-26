#include "Graph.h"
#include "Simple_window.h"
#include "std_lib_facilities.h"

/*

5. “Animate” (as in §15.5) the series 1 – 1/3 + 1/5 – 1/7 + 1/9 – 1/11 + . . . .
It is known as Leibniz’s series and converges to pi/4.

*/

constexpr int xmax = 1200; constexpr int ymax = 1200; constexpr int xoffset = 200; constexpr int yoffset = 200;
constexpr int xspace = 200; constexpr int yspace = 200; constexpr int xlength = xmax - xoffset - xspace;
constexpr int ylength = ymax - yoffset - yspace; constexpr int notches = 20;

constexpr int r_min = -5; constexpr int r_max = 5; constexpr int n_points = 400;
constexpr int x_scale = 80; constexpr int y_scale = 80;

double precision = 0;
double leibniz_f(double x) {
    double f = 1;
    int del = 3;
    int sign = -1;
    for (int i = 0; i < precision; ++i) {
        f += (double(1) / del) * sign;
        del += 2;
        sign *= -1;
    }
    return f;
}


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

    while (precision < 100 ){
        Function cos_f {leibniz_f, r_min, r_max, pmidle, n_points, x_scale, y_scale};
        cout << leibniz_f(100) * 4 << " " << precision <<  endl;
        cos_f.set_color(Color::dark_blue);
        cos_f.set_style(Line_style(Line_style::solid, 2));
        win.attach(cos_f);

        win.wait_for_button();
        win.detach(cos_f);
        ++precision;
    }
}

catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    keep_window_open();
}
catch (...) {
    cerr << "exception\n";
}