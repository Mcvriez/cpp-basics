//
// This is a GUI support code to the chapters 12-16 of the book
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#ifndef SIMPLE_WINDOW_GUARD
#define SIMPLE_WINDOW_GUARD 1

#include "GUI.h"    // for Simple_window only (doesn't really belong in Window.h)
#include "Graph.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------

struct Simple_window : Graph_lib::Window {
    Simple_window(Point xy, int w, int h, const string& title );

    void wait_for_button(); // simple event loop

private:
    Button next_button;     // the "next" button
    bool button_pushed;     // implementation detail

    static void cb_next(Address, Address); // callback for next_button
    void next();            // action to be done when next_button is pressed

};

//------------------------------------------------------------------------------

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

//------------------------------------------------------------------------------

class Checker_window : Graph_lib::Window {
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

//Window(xy, w, h, title),

#endif // SIMPLE_WINDOW_GUARD