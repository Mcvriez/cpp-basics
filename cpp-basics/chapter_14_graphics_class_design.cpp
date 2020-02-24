#include "Graph.h"
#include "Simple_window.h"
#include "std_lib_facilities.h"
#include <cstdlib>

//#include<iostream>
//#include<vector>
//#include<list>
//using namespace std;


/*

16. Define a class Controller with four virtual functions on(), off(), set_level(int), and show().
Derive at least two classes from Controller.

One should be a simple test class where show() prints out whether the class is set to on or off and what is the current level.

The second derived class should somehow control the line color of a Shape;
the exact meaning of “level” is up to you.

Try to find a third “thing” to control with such a Controller class.

*/

class Controller {
    virtual void on() = 0;
    virtual void off() = 0;
    virtual void set_level(int x) = 0;
    virtual void show() = 0;
};
class Test : Controller {
public:
    Test(int lev, bool st): level {lev}, turned_on {st} {if (lev < 0) level = 0;};
    explicit Test(int lev): level {lev}, turned_on {false} {if (lev < 0) level = 0;};
    Test(): level {0}, turned_on {false} {};
    void set_level(int x) override { if (x >= 0) level = x; else cout << "Attempt to assign negative level: " << x << endl;}
    void on() override {turned_on = true;}
    void off() override {turned_on = false;}
    void show() override {
        cout << "Test class object is turned ";
        turned_on ? cout << "on" << endl : cout << "off" << endl;
        cout << "Test class object level is: " << level << endl;
    }
private:
    int level;
    bool turned_on;
};
class ShapeController : Controller {
public:
    explicit ShapeController(Shape& sh): shape {sh}, color {sh.color()}, old_color {sh.color()}, turned_on {false} {};
    void set_level(int x) override {
        if (x >= 0) color = x;
        else cout << "Attempt to assign negative level: " << x << endl;
    }
    void on() override {turned_on = true;}
    void off() override {turned_on = false;}
    void show() override {
        if (turned_on) {shape.set_color(color);} else shape.set_color(old_color);;
    }
private:
    Shape& shape;
    Graph_lib::Color color;
    Graph_lib::Color old_color;
    bool turned_on;
};
class SoundController : Controller {
public:
    SoundController (): turned_on {false}, level{15}, new_level {0} {};
    void set_level(int x) override { if (x < 100 && x > -100) new_level =x;}
    void on() override {turned_on = true;}
    void off() override {turned_on = false; show();}
    void show() override {
        if (turned_on) {
            string scom = "pactl set-sink-volume 1 " + to_string(new_level) + "%";
            const char* com = scom.c_str();
            cout << com << endl;
            system(com);}
        else {
            string scom = "pactl set-sink-volume 1 " + to_string(level) + "%";
            const char* com = scom.c_str();
            cout << com << endl;
            system(com);
        }
    }
private:
    int level;
    int new_level;
    bool turned_on;
};

int main()
try {

    Point tl(500,500);
    Point tl2(300,300);
    Simple_window win(tl,2400,1500,"My window");


    Rectangle rec {tl2, 700, 700};
    rec.set_style(Line_style(Line_style::dash, 10)); win.attach(rec);
    win.wait_for_button();

    ShapeController cont (rec); cont.on(); cont.set_level(199); cont.show();
    win.wait_for_button();

    cont.set_level(99); cont.off(); cont.show();
    win.wait_for_button();

    Test t1 {};
    t1.show(); t1.set_level(15); t1.on(); t1.set_level(-14); t1.show();

    SoundController sc;
    win.wait_for_button();

    sc.on();sc.set_level(10);sc.show();
    win.wait_for_button();

    sc.on();sc.set_level(20);sc.show();
    win.wait_for_button();

    sc.on();sc.set_level(-20);sc.show();
    win.wait_for_button();

    sc.on();sc.off();
    win.wait_for_button();




}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
