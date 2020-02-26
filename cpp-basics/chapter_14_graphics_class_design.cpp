#include "Graph.h"
#include "Simple_window.h"
#include "std_lib_facilities.h"

/*

7. Elaborate the bar graph class to allow labeling of the graph itself and its individual bars. Allow the use of color.

*/

constexpr int xmax = 1200; constexpr int ymax = 1200; constexpr int xoffset = 200; constexpr int yoffset = 200;
constexpr int xspace = 200; constexpr int yspace = 200; constexpr int xlength = xmax - xoffset - xspace;
constexpr int ylength = ymax - yoffset - yspace; constexpr int notches = 20;
constexpr int r_min = -5; constexpr int r_max = 5; constexpr int n_points = 400;
constexpr int x_scale = 80; constexpr int y_scale = 80;

struct Bar {
    explicit Bar (double v, const string& lab = "None", int col = 0) : value {v}, color {col}, label {lab} {}
    double value;
    int color;
    string label;
};

class Bars: public Shape {
    Point root;
    int scale;
    int width;
    int step;
    Vector_ref <Bar> bars;

public:
    void draw_lines() const override{
        if (fill_color().visibility()) {
            fl_color(fill_color().as_int());
            for (int i = 0; i < bars.size(); ++i) {
                int x = root.x + (i * (width + step) + step) * scale;
                int y = int(root.y - scale * bars[i].value);
                if (bars[i].color != 0) fl_color(bars[i].color);
                fl_rectf(x, y, width * scale, int(scale * bars[i].value));
            }
            fl_color(color().as_int());
        }
        if (color().visibility()) {
            fl_color(color().as_int());
            for (int i = 0; i < bars.size(); ++i) {
                int x = root.x + (i * (width + step) + step) * scale;
                int y = int(root.y - scale * bars[i].value);
                fl_rect(x, y, width * scale, int(scale * bars[i].value));
                if (bars[i].label != "None") {
                    fl_draw(bars[i].label.c_str(), x + width * scale / 2 - bars[i].label.size()*3, y - 25);
                }
            }
        }
    }
    explicit Bars (
            const Vector_ref <Bar>& vr,
            Point r = Point {0, 0},
            int sc = 10,
            int w = 10,
            int s = 5) : root {r}, width {w}, step {s}, scale {sc}, bars {vr} { }
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

    Vector_ref <Bar> some_bars;
    some_bars.push_back(new Bar{15, "Start", 38});
    some_bars.push_back(new Bar{23, "None", 123});
    some_bars.push_back(new Bar{55, "None", 228});
    some_bars.push_back(new Bar{43, "Very loong name", 67});
    some_bars.push_back(new Bar{9, "Finish", 87});

    Bars new_bar (some_bars, root, 15);
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