#include "Graph.h"
#include "Simple_window.h"
#include "std_lib_facilities.h"

/*
11. Find the average maximum temperatures for each month of the year for two or more locations (e.g., Cambridge, England,
and Cambridge, Massachusetts; there are lots of towns called “Cambridge”) and graph them together. As ever, be careful
with axes, labels, use of color, etc.
*/

constexpr int xmax = 1800; constexpr int ymax = 1200; constexpr int xoffset = 200; constexpr int yoffset = 200;
constexpr int xspace = 200; constexpr int yspace = 200; constexpr int xlength = xmax - xoffset - xspace;
constexpr int ylength = ymax - yoffset - yspace; constexpr int notches = 12;

constexpr int scale = 10;

struct Temp_max {
    int month;
    double cay, zur, crb;   // Grand Cayman, Zurich, Cranbrook
};

istream& operator >> (istream& is, Temp_max& ttm) {
    char c1, c2, c3;
    Temp_max tm{};

    if (is >> c1 >> tm.month >> c2 >> tm.cay >> tm.zur >> tm.crb >> c3) {
        if (!is || c1!= '(' || c2 != ':' || c3 != ')')  {
            is.clear(ios_base::failbit);
            return is;
        }
    }
    else
        return is;

    ttm = tm;
    return is;
}

int main()
try {
    Point tl(500,500);
    Point root {200, ymax - 200};
    Point rootx {200, int(ymax / 1.5)};

    Simple_window win(tl, xmax, ymax,"Function graphs.");
    Axis x_axis (Axis::x, rootx, xlength, notches, "1 = = 40 pixels");
    Axis y_axis (Axis::y, root, ylength, 40, "1 = = 40 pixels");
    x_axis.set_color(Color::dark_red); x_axis.set_style(Line_style(Line_style::solid, 2));
    y_axis.set_color(Color::dark_red); y_axis.set_style(Line_style(Line_style::solid, 2));
    win.attach(x_axis); win.attach(y_axis);

    const string path = "/home/wq/CLionProjects/cpp-basics/cpp-basics/temps.txt";
    ifstream ist(path.c_str());
    if (!ist) error("can't open input file ",path);
    Temp_max t;
    Open_polyline cay, zur, crb;
    cay.set_color(Color::dark_yellow); cay.set_style(Line_style(Line_style::solid, 4));
    zur.set_color(Color::dark_cyan); zur.set_style(Line_style(Line_style::solid, 4));
    crb.set_color(Color::dark_blue); crb.set_style(Line_style(Line_style::solid, 4));

    int step = xlength / notches;
    int x_start = rootx.x + step / 2;
    int y_start = rootx.y;
    while(ist >> t) {
        cout << t.month << endl;
        cay.add(Point {x_start, int(y_start - scale * t.cay)});
        zur.add(Point {x_start, int(y_start - scale * t.zur)});
        crb.add(Point {x_start, int(y_start - scale * t.crb)});
        x_start += step;
    }
    win.attach(cay);win.attach(zur);win.attach(crb);




    win.wait_for_button();
}

catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    keep_window_open();
}
catch (...) {
    cerr << "exception\n";
}