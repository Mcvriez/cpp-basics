
#include "GUI.h"	// for Simple_window only (doesn't really belong in Window.h)
#include <thread>

using namespace Graph_lib;

// Simple_window is basic scaffolding for ultra-simple interaction with graphics
// it provides one window with one "next" button for ultra-simple animation

struct Simple_window : Graph_lib::Window {
    Simple_window(Point xy, int w, int h, const string& title );
    bool wait_for_button();
    Button next_button;
private:
    bool button_pushed;
    static void cb_next(Address, Address addr);
    void next();

};
//------------------------------------------------------------------------------

class My_window : public Graph_lib::Window {
public:
    My_window(Point xy, int w, int h, const string &title);

    void wait_for_button() {
        Fl::wait();
        Fl::redraw();
        if (!button_pushed) {
            Fl::wait();
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            next();
            draw_plain();
            Fl::redraw();
            wait_for_button();
        };
    }
private:
    Circle plane {root , 30};
    int ascension = -1;
    int radius = 500;
    double delta = 0;

    Vector_ref<Line> shapes;
    Image img {Point{250,  250}, "/home/wq/Documents/png-3.jpg", Suffix::Encoding::jpg};
    Point root {750, 750};

    Button next_button;     // the "next" button
    Button quit_button;
    Button pause_button;

    bool button_pushed;     // implementation detail
    bool pause_flag;

    static void cb_start(Address, Address pw) { reference_to<My_window>(pw).start(); }
    static void cb_quit(Address, Address pw) { reference_to<My_window>(pw).quit(); }
    static void cb_pause(Address, Address pw) { reference_to<My_window>(pw).pause(); }

    void draw_hands();
    void draw_plain();

    void quit() { button_pushed = true; hide(); }
    void reattach() {for (int i = 0; i < shapes.size(); ++i) {attach(shapes[i]);}}
    void next() { draw_hands(); reattach();}
    void start() { pause_flag = false; }
    void pause() { pause_flag = true; }
};

//------------------------------------------------------------------------------

class Checker_window : public Graph_lib::Window {
public:
    Checker_window (Point xy, int w, int h, const string& title);
    void wait_for_button() {
        while (!button_pushed) {Fl::wait();}
        button_pushed = false;
        Fl::redraw();}
private:
    Button next_button;
    Button quit_button;
    Button check_nw;
    Button check_ne;
    Button check_sw;
    Button check_se;
    bool button_pushed;
    const int default_color = 49;

    static void cb_next(Address, Address pw) {reference_to<Checker_window>(pw).next();}
    static void cb_quit(Address, Address pw) {reference_to<Checker_window>(pw).quit();}

    static void cb_check_nw(Address, Address pw) {reference_to<Checker_window>(pw).nw();}
    static void cb_check_ne(Address, Address pw) {reference_to<Checker_window>(pw).ne();}
    static void cb_check_sw(Address, Address pw) {reference_to<Checker_window>(pw).sw();}
    static void cb_check_se(Address, Address pw) {reference_to<Checker_window>(pw).se();}

    void reset_color () {check_nw.set_color(default_color); check_ne.set_color(default_color); check_sw.set_color(default_color); check_se.set_color(default_color); redraw();}
    void nw () {reset_color(); check_nw.set_color(12); };
    void ne () {reset_color(); check_ne.set_color(69); };
    void sw () {reset_color(); check_sw.set_color(121); };
    void se () {reset_color(); check_se.set_color(134); };

    void next() {button_pushed = true;}
    void quit() {button_pushed = true; hide();}

};

//------------------------------------------------------------------------------

struct Shapes_window: public Graph_lib::Window {
    Shapes_window(Point p, int w, int h, const string& title);

private:
    Vector_ref<Shape> shapes;
    Button next_button;
    Button quit_button;
    In_box next_x;
    In_box next_y;
    Out_box xy_out;
    Menu color_menu;
    Button menu_button;

    Menu item_menu;

    Color col {38};

    void reattach() {
        for (int i = 0; i < shapes.size(); ++i){
            attach(shapes[i]);
        }
    }

    void hide_menu() { color_menu.hide(); menu_button.show(); }
    void red_pressed() { change(121); hide_menu(); }
    void blue_pressed() { change(180); hide_menu(); }
    void black_pressed() { change(38); hide_menu(); }
    void menu_pressed() { menu_button.hide(); color_menu.show(); }
    void change(Color c) { col = c; }

    void circle_pressed();
    void square_pressed();
    void triangle_pressed();
    void hexagon_pressed();

    void next();
    void quit();

    static void cb_red(Address, Address pw) {reference_to<Shapes_window>(pw).red_pressed();};
    static void cb_blue(Address, Address pw) {reference_to<Shapes_window>(pw).blue_pressed();};
    static void cb_black(Address, Address pw) {reference_to<Shapes_window>(pw).black_pressed();};
    static void cb_menu(Address, Address pw) {reference_to<Shapes_window>(pw).menu_pressed();};

    static void cb_circle(Address, Address pw) {reference_to<Shapes_window>(pw).circle_pressed();};
    static void cb_square(Address, Address pw) {reference_to<Shapes_window>(pw).square_pressed();};
    static void cb_triangle(Address, Address pw) {reference_to<Shapes_window>(pw).triangle_pressed();};
    static void cb_hexagon(Address, Address pw) {reference_to<Shapes_window>(pw).hexagon_pressed();};

    static void cb_next(Address, Address pw) {reference_to<Shapes_window>(pw).next();};
    static void cb_quit(Address, Address pw) {reference_to<Shapes_window>(pw).quit();};
};

//------------------------------------------------------------------------------

class Math_window : public Graph_lib::Window {
public:
    Math_window(Point xy, int w, int h, const string &title);
private:
    Button draw_button;
    Button quit_button;
    Button save_button;
    Menu func_menu;
    In_box mult_input;
    In_box x0_input;
    In_box y0_input;
    Out_box func_output;

    bool button_pushed;
    int function_id;

    Vector_ref <Shape> shapes;
    Function* current;

    static void cb_next(Address, Address pw) {reference_to<Math_window>(pw).next();}
    static void cb_quit(Address, Address pw) {reference_to<Math_window>(pw).quit();}
    static void cb_save(Address, Address pw) {reference_to<Math_window>(pw).save();}
    static void cb_log(Address, Address pw)  {reference_to<Math_window>(pw).log();}
    static void cb_sin(Address, Address pw)  {reference_to<Math_window>(pw).sin();}
    static void cb_cos(Address, Address pw)  {reference_to<Math_window>(pw).cos();}

    void next();
    void quit() {button_pushed = true; hide();}
    void save() {shapes.push_back(*current);}
    void log()  {function_id = 0; update_funct_output(); next();}
    void sin()  {function_id = 1; update_funct_output(); next();}
    void cos()  {function_id = 2; update_funct_output(); next();}

    void update_funct_output();
    void draw_shapes() {
        for (int x = 0; x < shapes.size(); ++x ){
            attach(shapes[x]);
        }
    }

    static double f_log(double x) { return std::log(x); }
    static double f_sin(double x) { return std::sin(x); }
    static double f_cos(double x) { return std::cos(x); }
};