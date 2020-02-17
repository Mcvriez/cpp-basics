#include "Graph.h"
#include "Simple_window.h"
#include "std_lib_facilities.h"



/*

7. Define a Striped_closed_polyline using the technique from Striped_rectangle (this requires some algorithmic
inventiveness)

*/

ostream& operator<<(ostream& out, Point& a) {
    out << "(" << a.x << "," << a.y << ")" << endl;
    return out;
}

void draw_mark(Point xy, int c)
{
    static const int dx = 15;
    static const int dy = 15;
    fl_font(1, 25);
    fl_draw(to_string(c).c_str(), xy.x - dx, xy.y - dy);
}

void draw_x(Point xy)
{
    fl_color(0);
    fl_font(0, 12);
    fl_draw(to_string(xy.y).c_str(), xy.x, xy.y);
}

class Striped_closed_polyline : public Closed_polyline {
public:
    explicit Striped_closed_polyline(int pstep) : pixel_step{ pstep } {  }
    void draw_lines() const override;
    void set_step(int x) {if (x < 1) error("Wrong step size"); pixel_step = x;}
    int get_step() const {return pixel_step;}
    void add(Point p) override;
    void complete() { Point last_p = Point(point(0)); add_dots(last_p);}

private:
    void add_dots(Point& p);
    int pixel_step;
    vector <Lpoint> dots;
};

void Striped_closed_polyline::add_dots(Point& p) {
    int n = number_of_points();
    float line_slope;
    double intercept;
    Lpoint dp;
    int inc = 1; // increment

    // y = line_slope * x + intercept

    if (n > 0) {
        Point pp = point(n - 1); // previous point
        if (p.x != pp.x) {
            line_slope = double(p.y - pp.y) / (p.x - pp.x);
            intercept = p.y - line_slope * p.x;
        }
        else {
            line_slope = 0;
            intercept = p.y;
        }

        if (std::abs(p.x - pp.x) >= std::abs(p.y - pp.y)){
            if (p.x < pp.x) inc = -1;
            for (int x = pp.x; x != p.x + inc; x += inc ) {
                double y;
                y = line_slope * x + intercept;
                dp = Lpoint(x, y + 0.5, n-1);
                dots.push_back(dp);
                // cout  << n-1 << "-" << n << " "<< dp;
            }
        }
        else {
            if (p.y < pp.y) inc = -1;
            for (int y = pp.y; y != p.y + inc; y += inc ) {
                double x;
                if (line_slope != 0) {
                    x = double(y - intercept) / line_slope;
                }
                else x = p.x;
                dp = Lpoint(x + 0.5, y, n-1);
                dots.push_back(dp);
                // cout  << n-1 << "-" << n << " "<< dp;
            }
        }

    }

}

void Striped_closed_polyline::add(Point p) {
    add_dots(p);
    Shape::add(p);
}

void Striped_closed_polyline::draw_lines() const {
    if (fill_color().visibility()) {

        fl_color(fill_color().as_int());
        // find y min and y max
        int min = dots[0].y;
        int max = dots[0].y;

        for (Lpoint p : dots) {
            if (p.y > max) max = p.y;
            if (p.y < min) min = p.y;
        }

        for (int y = min; y <= max; y++) {
            bool stripe = true;
            bool fill = true;
            vector <Lpoint> line_dots {};

            for (Lpoint pl: dots) {
                if (pl.y == y) line_dots.push_back(pl);

            }

            sort(line_dots.begin(), line_dots.end());

            if (line_dots.size() > 1) {
                Lpoint last_point = line_dots[0];

                for (Lpoint current_point : line_dots) {
                    if (current_point.y == point(2).y) {
                        cout << current_point.x << "-" << current_point.line << " ";
                    }
                    // precondition
                    if (current_point.x == last_point.x
                        && current_point.line != last_point.line) fill = false;
                    if (current_point.x == last_point.x
                        && current_point.line != last_point.line) fill = false;


                    if (last_point.line != current_point.line)
                    {
                        if (fill) {
                        fl_line(last_point.x, y, current_point.x, y);
                        }
                        fill = !fill;
                    }
                    last_point = current_point;
                }
            }
        }
        cout << endl << "----------------" << endl;
    }


    if (color().visibility()) {
        fl_color(color().as_int());
        Graph_lib::Shape::draw_lines();
        fl_line(point(number_of_points() - 1).x, point(number_of_points() - 1).y, point(0).x, point(0).y);
    }
    for (int i = 0; i < number_of_points(); ++i)
        draw_mark(point(i), i);

}



int main()
try {
    Point start{ 300, 300 };
    Simple_window win{ Point { 100, 100 }, 800, 700, "Canvas" };
    win.color(53);

    while (true) {
        Striped_closed_polyline rect{ 100 };
        srand(time(NULL));
        /*rect.add(Point{ 100, 200 }); // 0
        rect.add(Point{ 100, 400});  // 1
        rect.add(Point{ 350, 400});  // 2
        rect.add(Point{ 450, 150});  // 3
         */
        rect.add(Point {104, 580}); // 0
        rect.add(Point {137, 106});
        rect.add(Point {458, 199}); // 2
        rect.add(Point {234, 288}); // 3
        rect.add(Point {299, 299});
        rect.add(Point {196, 619});
        rect.add(Point {677, 628});
        rect.add(Point {275, 174}); // 7
        rect.add(Point {174, 362}); // 8
        rect.add(Point {735, 190});
        rect.add(Point {737, 115});
        rect.add(Point {134, 502});
        rect.add(Point {401, 591});
        rect.add(Point {541, 672});
        rect.add(Point {521, 500});



        rect.complete();

        rect.set_color(0);
        rect.set_style(Line_style(Line_style::solid, 1));

        rect.set_fill_color(220);

        win.attach(rect);
        win.wait_for_button();
    }

}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    keep_window_open();
}
catch (...) {
    cerr << "exception\n";

}