#include "Graph.h"
#include "Simple_window.h"
#include "std_lib_facilities.h"

/*

3. Modify Fct from the previous exercise to take an extra argument to control precision or whatever. Make the type of that
argument a template parameter for extra flexibility.

*/

typedef double Fctn(double, int);

double cos_plus (double x, int i) {return cos(x) + x / 4;}
double cos_plus_plus (double x,  int i) {return cos(x) + x / 2 ;}

double fac(double n) { double r = 1; while (n>1) { r*=n; --n; }return r;}
double term(double x, int n) { return pow(x,n)/fac(n); }
double expe(double x, int n) {
    double sum = 0;
    for (int i=0; i<n; ++i) sum+=term(x,i);
    return sum;
}


struct Ffct : Shape {
    Ffct (Fctn f, double r1, double r2, Point orig, int c = 100, double xs = 25, double ys = 25, int pr= 1) :
    range_start(r1), range_end(r2), root {orig}, count {c}, xscale {xs}, yscale {ys}, funct{f}, precision {pr}
    {
        if (range_end - range_start <= 0) error("bad graphing range");
        if (count <= 0) error("non-positive graphing count");
        double dist = (range_end - range_start) / count;
        double r = range_start;
        for (int i = 0; i < count; ++i) {
            add(Point(root.x + int(r * xscale), root.y - int(funct(r, precision) * yscale)));
            r += dist;
        }
    }
    Fctn* funct;
    double range_start;
    int precision;
    double range_end;
    Point root;
    int count;
    double xscale;
    double yscale;
    void reset() {
        points.clear();
        if (range_end - range_start <= 0) error("bad graphing range");
        if (count <= 0) error("non-positive graphing count");
        double dist = (range_end - range_start) / count;
        double r = range_start;
        for (int i = 0; i < count; ++i) {
            add(Point(root.x + int(r * xscale), root.y - int(funct(r, precision) * yscale)));
            r += dist;
        }
    }
};


int main()
try {
    Point tl(500,500);
    Simple_window win(tl, 2400, 1200,"Function graphs.");
    Ffct my_function (cos_plus, 10, 35, Point {00, 1100}, 50, 50, 50);
    win.attach(my_function);
    win.wait_for_button();

    my_function.funct = expe;
    my_function.precision = 10;
    my_function.root = Point{300, 1000};
    my_function.reset();
    win.wait_for_button();

 }

catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    keep_window_open();
}
catch (...) {
    cerr << "exception\n";
}