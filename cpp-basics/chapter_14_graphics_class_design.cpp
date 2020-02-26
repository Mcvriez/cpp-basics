#include "Graph.h"
#include "Simple_window.h"
#include "std_lib_facilities.h"

/*

9. Find another data set of heights (an inch is 2.54cm) and graph them with your program from the previous exercise. For
example, search the web for “height distribution” or “height of people in the United States” and ignore a lot of rubbish or
ask your friends for their heights. Ideally, you don’t have to change anything for the new data set. Calculating the scaling
from the data is a key idea. Reading in labels from input also helps minimize changes when you want to reuse code.

*/

constexpr int xmax = 1800; constexpr int ymax = 1200; constexpr int xoffset = 200; constexpr int yoffset = 200;
constexpr int xspace = 200; constexpr int yspace = 200; constexpr int xlength = xmax - xoffset - xspace;
constexpr int ylength = ymax - yoffset - yspace; constexpr int notches = 20;


struct Bubble {
    explicit Bubble (double pn, int h = 0, int col = 0) : number_of_people {pn}, color {col}, height {h} {}
    double number_of_people;
    int color;
    int height;
};

// 5'4" 3.7
istream& operator >> (istream& is, Bubble& bb)
{
    char c1, c2;
    int heigh_f;
    int heigh_d;
    double number_of_people;
    is >> heigh_f >> c1 >> heigh_d >> c2 >> number_of_people;
    if (!is || (c1!= '\'' && c1 != '.') || (c2 != '"')) return is;
    bb = Bubble(number_of_people, heigh_f * 12 + heigh_d, sqrt((number_of_people + 2) * 33));
    return is;
}

class Bubbles: public Shape {
    Point root;
    int scale;
    int width;
    int step;
    Vector_ref <Bubble> bars;

public:
    void draw_lines() const override{
        if (fill_color().visibility()) {
            fl_color(fill_color().as_int());
            int x_base = root.x + scale;
            for (int i = 0; i < bars.size(); ++i) {
                int y = int(root.y - scale * sqrt(bars[i].number_of_people) * 3 + 75);
                if (bars[i].color != 0) fl_color(bars[i].color);
                fl_pie(x_base, y, scale * sqrt(bars[i].number_of_people), scale * sqrt(bars[i].number_of_people), 0, 360);
                x_base += sqrt(bars[i].number_of_people) * scale + step * sqrt(scale);
            }
            fl_color(color().as_int());
        }
        if (color().visibility()) {
            fl_color(color().as_int());
            int x_base = root.x + scale;
            for (int i = 0; i < bars.size(); ++i) {
                int x = root.x + (i * (width + step) + step) * scale;
                int y = int(root.y - scale * sqrt(bars[i].number_of_people) * 3 + 75);
                fl_arc(x_base, y, scale * sqrt(bars[i].number_of_people), scale * sqrt(bars[i].number_of_people), 0, 360);
                if (bars[i].height != 0) {
                    fl_draw(to_string(bars[i].height).c_str(), x_base + sqrt(bars[i].number_of_people) * scale / 2 - 9, y - 25);
                    fl_draw(to_string(int(bars[i].number_of_people)).c_str(), root.x + 15, y + scale * sqrt(bars[i].number_of_people) / 2);
                }
                x_base += sqrt(bars[i].number_of_people) * scale + step * sqrt(scale);
            }
        }
    }
    void info() const {
        for (int i = 0; i < bars.size(); ++i) {
            cout << "-> " << bars[i].height << " ~ " << bars[i].number_of_people << endl;
        }

    }
    void add_bubble(Bubble *b){
        bars.push_back(b);
    }
    int size() {return bars.size();}
    explicit Bubbles (
            Point r = Point {0, 0},
            int sc = 10,
            int w = 10,
            int s = 5,
            const Vector_ref <Bubble>& vr = {})
            : root {r}, width {w}, step {s}, scale {sc}, bars {vr} { }
};

void fill_from_file (Bubbles& bubbles, const string& name)
{
    ifstream ist(name.c_str());
    if (!ist) error("can't open input file ",name);
    Bubble bb(0);
    double onp = bb.number_of_people;
    int oh = bb.height;
    while (ist >> bb) {
        double np = bb.number_of_people;
        int h = bb.height;
        if (!(oh == h && np == onp)) {
            bubbles.add_bubble(new Bubble {np, h, bb.color});}
        onp = np;
        oh = h;
    }
}

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

    Bubbles bubble_chart (root, 50);
    fill_from_file(bubble_chart,"/home/wq/CLionProjects/cpp-basics/cpp-basics/height_data.txt");
    bubble_chart.info();
    bubble_chart.set_fill_color(1);
    bubble_chart.set_style(Line_style(Line_style::dash, 2));
    win.attach(bubble_chart);
    win.wait_for_button();
}

catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    keep_window_open();
}
catch (...) {
    cerr << "exception\n";
}