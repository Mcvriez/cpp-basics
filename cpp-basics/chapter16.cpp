#include "fltk_lib/Graph.h"
#include "fltk_lib/Simple_window.h"
#include "fltk_lib/std_lib_facilities.h"


//1. Make a My_window that’s a bit like Simple_window except that it has two buttons, next and quit.

class My_window : Graph_lib::Window {
public:
    My_window (Point xy, int w, int h, const string& title);
    void wait_for_button() {
        while (!button_pushed) {Fl::wait();}
        button_pushed = false;
        Fl::redraw();}
private:
    Button next_button;     // the "next" button
    Button quit_button;     // the "next" button
    bool button_pushed;     // implementation detail

    static void cb_next(Address, Address pw) {reference_to<My_window>(pw).next();}
    static void cb_quit(Address, Address pw) {reference_to<My_window>(pw).quit();}
    void next() {button_pushed = true;}
    void quit() {button_pushed = true; hide();}

};

My_window::My_window (Point xy, int w, int h, const string& title) :
    Window(xy, w, h, title),
    next_button(
        Point{x_max()-70,0},
        70,
        20,
        "Next",
        cb_next),
    quit_button(
        Point{x_max()-70,25},
        70,
        20,
        "Quit",
        cb_quit),
    button_pushed(false)
{
    attach(next_button);
    attach(quit_button);
}


int main()
try {
    Point rootp(500,500);
    My_window win {rootp, 500, 500, "Custom Window"};
    win.wait_for_button();
    }

catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    keep_window_open();
}
catch (...) {
    cerr << "exception\n";
}