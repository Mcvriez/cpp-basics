#include "Graph.h"
#include "Simple_window.h"
#include "std_lib_facilities.h"

/*

6. Design and implement a bar graph class.
Its basic data is a vector<double> holding N values,
and each value should be represented by a “bar” that is a rectangle where the height represents the value.

*/

constexpr int xmax = 1200; constexpr int ymax = 1200; constexpr int xoffset = 200; constexpr int yoffset = 200;
constexpr int xspace = 200; constexpr int yspace = 200; constexpr int xlength = xmax - xoffset - xspace;
constexpr int ylength = ymax - yoffset - yspace; constexpr int notches = 20;
constexpr int r_min = -5; constexpr int r_max = 5; constexpr int n_points = 400;
constexpr int x_scale = 80; constexpr int y_scale = 80;

class Bar: public Shape {
    Point root;
    int scale;
    int width;
    int step;
    vector<double> values;
public:
    void draw_lines() const override{
        if (fill_color().visibility()) {
            fl_color(fill_color().as_int());
            for (int i = 0; i < values.size(); ++i) {
                int x = root.x + (i * (width + step) + step) * scale;
                int y = int(root.y - scale * values[i]);
                fl_rectf(x, y, width * scale, int(scale * values[i]));
            }
            fl_color(color().as_int());
        }
        if (color().visibility()) {
            fl_color(color().as_int());
            for (int i = 0; i < values.size(); ++i) {
                int x = root.x + (i * (width + step) + step) * scale;
                int y = int(root.y - scale * values[i]);
                fl_rect(x, y, width * scale, int(scale * values[i]));
            }
        }
    }

    explicit Bar (Point r = Point {0,0}, const vector <double>& d = {}, int sc = 10, int w = 10, int s = 5):
    root {r}, width {w}, step {s}, scale {sc} {
        if (!d.empty()) {
            for (int i = 0; i < d.size(); i++)
                values.push_back(d[i]);
        }
    }
};

int main()
try {
    Point tl(500,500);
    Point root {200, ymax - 200};
    Simple_window win(tl, xmax, ymax,"Function graphs.");
    Axis x_axis (Axis::x, root, xlength, notches, "1 = = 40 pixels");
    Axis y_axis (Axis::y, root, ylength, notches, "1 = = 40 pixels");
    x_axis.set_color(Color::dark_red);
    x_axis.set_style(Line_style(Line_style::solid, 2));
    y_axis.set_color(Color::dark_red);
    y_axis.set_style(Line_style(Line_style::solid, 2));
    win.attach(x_axis);
    win.attach(y_axis);

    vector <double> values {12, 52, 11, 4, 23};
    Bar new_bar (root, values, 10);
    new_bar.set_fill_color(Color::dark_green);
    new_bar.set_style(Line_style(Line_style::dash, 3));
    win.attach(new_bar);

    win.wait_for_button();

}

catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    keep_window_open();
}
catch (...) {
    cerr << "exception\n";
}