#include "Graph.h"
#include "Simple_window.h"
#include "std_lib_facilities.h"
#include <cstdlib>
#include <utility>

//#include<iostream>
//#include<vector>
//#include<list>
//using namespace std;


/*

Drill chapter 15

*/

constexpr int xmax = 1200;
constexpr int ymax = 1200;
constexpr int xoffset = 200; // distance from left-hand side of window to y axis
constexpr int yoffset = 200; // distance from bottom of window to x axis
constexpr int xspace = 200; // space beyond axis
constexpr int yspace = 200;
constexpr int xlength = xmax - xoffset - xspace;
constexpr int ylength = ymax - yoffset - yspace;
constexpr int notches = 20;

constexpr int r_min = -10;
constexpr int r_max = 10;
constexpr int n_points = 400; // number of points used in range
constexpr int x_scale = 40; // scaling factors
constexpr int y_scale = 40;


double one(double x) { return 1; }
double slope(double x) { return x/2; }
double square(double x) { return x*x; }
double sloping_cos(double x) {return slope(x) + cos(x);}

struct Person {
    explicit Person(const string& n = "John",const string& sn = "Doe", int a = 0) {
        if (a > 0 && a < 150) p_age = a;
        for (char c: restricted_symbols){
            if (n.find(c) != std::string::npos || sn.find(c) != std::string::npos) {
                string em = "symbol is not allowed for naming: " + string(1, c);
                error(em);}
        }
    }
    string name() const {return p_name + " " + p_sname;}
    void set_fist_name(const string& n) {
        for (char c: restricted_symbols){
            if (n.find(c) != std::string::npos) {
                string em = "symbol is not allowed: " + string(1, c);
                error(em);}
        }
        p_name = n;
    }
    void set_second_name(const string& n) {
        for (char c: restricted_symbols){
            if (n.find(c) != std::string::npos) {
                string em = "symbol is not allowed: " + string(1, c);
                error(em);}
        }
        p_sname = n;
    }
    void set_age (int a) {
        if (a > 0 && a < 150) p_age = a;
    }
    int age() const {return p_age;}
private:
    string p_name;
    string p_sname;
    int p_age;
    const vector <char> restricted_symbols {';', ':', '"', '\'', '[', ']', '*', '&', '^', '%', '$', '#', '@', '!'};
};

istream& operator >> (istream& is, Person& p) {
    cout << "Enter the person's full name and age: ";
    string name; string sname; int age;
    if (is >> name >> sname >> age) {
        p.set_fist_name(name);
        p.set_second_name(sname);
        p.set_age(age);
    }
    return is;
}
ostream& operator << (ostream& os, Person& p) {
    if (os)
        os << "Person name is " << p.name() <<" with age of " << p.age() << endl;
    return os;
}

vector <Person> persons;

int main()
try {
    Point tl(500,500);
    Point pmidle {xmax/2, ymax/2};

    Simple_window win(tl, xmax, ymax,"Function graphs.");
    Axis x_axis (Axis::x, Point{xoffset, ymax / 2}, xlength, notches, "1 = = 20 pixels");
    Axis y_axis (Axis::y, Point{xmax/2, ymax - yspace}, ylength, notches, "1 = = 20 pixels");
    x_axis.set_color(Color::dark_red);
    x_axis.set_style(Line_style(Line_style::solid, 2));
    y_axis.set_color(Color::dark_red);
    y_axis.set_style(Line_style(Line_style::solid, 2));

    Function one_f {one, r_min, r_max, pmidle, n_points, x_scale, y_scale};
    Function slope_f {slope, r_min, r_max, pmidle, n_points, x_scale, y_scale};
    Text slope_t {Point {xspace, 785}, "x/2"};
    Function square_f {square, -3, 3, pmidle, n_points, x_scale, y_scale};
    Function cos_f {cos, r_min, r_max, pmidle, n_points, x_scale, y_scale};
    cos_f.set_color(Color::dark_blue);
    Function scos_f {sloping_cos, r_min, r_max, pmidle, n_points, x_scale, y_scale};


    win.attach(x_axis);
    win.attach(y_axis);
    win.attach(one_f);
    win.attach(slope_f); win.attach(slope_t);
    win.attach(square_f);
    win.attach(cos_f);
    win.attach(scos_f);
    //win.wait_for_button();
    //Person p {"Larry", 77};
    //p.name = "Goofy";
    //p.age = 63;
    //cout << p.name << " " << p.age << endl;
    //cin >> p;
    //cout << p;

    for (Person p; cin >> p;)
        if (p.name() != "stop please")
        persons.push_back(p);
        else break;
    for (Person p: persons)
        cout << p;



}

catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    keep_window_open();
}
catch (...) {
    cerr << "exception\n";
}