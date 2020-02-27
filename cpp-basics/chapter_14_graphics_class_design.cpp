#include "Graph.h"
#include "Simple_window.h"
#include "std_lib_facilities.h"

/*

10. What kind of data is unsuitable for a line graph or a bar graph? Find an example and find a way of displaying it (e.g., as
a collection of labeled points).

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
    bb = Bubble(number_of_people, heigh_f * 12 + heigh_d, sqrt((number_of_people + 2) * 10));
    return is;
}

class PieChart: public Shape {
    Point root;
    int scale;
    int width;
    int step;
    Vector_ref <Bubble> bars;

public:
    void draw_lines() const override{
        double total = 0;
        for (int i = 0; i < bars.size(); ++i) {
            total += bars[i].number_of_people;
        }
        double size = scale * (sqrt(total));

        if (fill_color().visibility()) {
            fl_color(fill_color().as_int());
            int x_base = int(root.x + size) / 3;
            int y_base = int(root.y - scale * (sqrt(total) + step) / 1.5 ) ;
            int start_angle = 0;
            int current_angle = 0;

            for (int i = 0; i < bars.size(); ++i) {
                if (bars[i].color != 0) fl_color(bars[i].color);
                current_angle += bars[i].number_of_people / total * 360;
                if (i + 1 ==  bars.size()) current_angle = 360;
                int spec_size = size * sqrt(sqrt(bars[i].number_of_people / total));
                fl_pie(x_base + (size - spec_size) / 2 , y_base + (size - spec_size) / 2, spec_size, spec_size, start_angle, current_angle);
                start_angle = current_angle;
            }
            fl_color(color().as_int());
        }

        if (color().visibility()) {
            fl_color(color().as_int());
            int x_base = int(root.x + size) / 3;
            int y_base = int(root.y - scale * (sqrt(total) + step) / 1.5 ) ;
            int x_center = x_base + size / 2;
            int y_center = y_base + size / 2 ;
            int start_angle = 0;
            int current_angle = 0;



            for (int i = 0; i < bars.size(); ++i) {

                current_angle += bars[i].number_of_people / total * 360;
                if (i + 1 ==  bars.size()) current_angle = 360;
                int spec_size = size * sqrt(sqrt(bars[i].number_of_people / total));
                int x1 = spec_size / 2 * cos(start_angle * PI / 180);
                int y1 = -spec_size / 2 * sin(start_angle * PI / 180);

                int x2 = spec_size / 2 * cos(current_angle * PI / 180);
                int y2 = -spec_size / 2 * sin(current_angle * PI / 180);

                int x3 = spec_size / 1.7 * cos((current_angle +  start_angle )* PI / 360);
                int y3 = -spec_size / 1.7 * sin((current_angle +  start_angle )* PI / 360);

                fl_arc(x_base + (size - spec_size) / 2 , y_base + (size - spec_size) / 2, spec_size, spec_size, start_angle, current_angle);
                fl_line(x_center , y_center, x_center + x1, y_center + y1);
                fl_line(x_center , y_center , x_center  + x2, y_center  + y2);
                start_angle = current_angle;

                if (bars[i].height != 0) {
                    string height = to_string(bars[i].height) + " inches";
                    fl_draw(height.c_str(), x_center + x3, y_center + y3);
                    height = to_string((bars[i].number_of_people) / total * 100) + " %";
                    fl_draw(height.c_str(), x_center + x3, y_center + y3 + 15);
                }
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
    explicit PieChart (
            Point r = Point {0, 0},
            int sc = 10,
            int w = 10,
            int s = 5,
            const Vector_ref <Bubble>& vr = {})
            : root {r}, width {w}, step {s}, scale {sc}, bars {vr} { }
};

void fill_from_file (PieChart& bubbles, const string& name)
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

    PieChart bubble_chart (root, 100);
    fill_from_file(bubble_chart,"/home/wq/CLionProjects/cpp-basics/cpp-basics/height_data.txt");
    //bubble_chart.info();
    bubble_chart.set_fill_color(1);
    bubble_chart.set_style(Line_style(Line_style::solid, 2));
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