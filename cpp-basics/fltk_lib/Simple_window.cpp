
//
// This is a GUI support code to the chapters 12-16 of the book
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "Simple_window.h"

//------------------------------------------------------------------------------

Simple_window::Simple_window(Point xy, int w, int h, const string& title) :
        Window(xy,w,h,title),
        next_button(Point(x_max()-70,0), 70, 20, "Next", cb_next),
        button_pushed(false)
{
    attach(next_button);
}

//------------------------------------------------------------------------------

bool Simple_window::wait_for_button()
// modified event loop:
// handle all events (as per default), quit when button_pushed becomes true
// this allows graphics without control inversion
{
    show();
    button_pushed = false;
#if 1
    // Simpler handler
    while (!button_pushed) Fl::wait();
    Fl::redraw();
#else
    // To handle the case where the user presses the X button in the window frame
    // to kill the application, change the condition to 0 to enable this branch.
    Fl::run();
#endif
    return button_pushed;
}

//------------------------------------------------------------------------------

void Simple_window::cb_next(Address, Address pw)
// call Simple_window::next() for the window located at pw
{
    reference_to<Simple_window>(pw).next();
}

//------------------------------------------------------------------------------

void Simple_window::next()
{
    button_pushed = true;
    hide();
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

My_window::My_window (Point xy, int w, int h, const string& title) :
        Window(xy, w, h, title),
        bsize {128},
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
        moving_button(
                Point{(x_max() - bsize) / 2 ,(y_max() - bsize) / 2},
                bsize,
                bsize,
                "uncatchable Joe",
                cb_move),
        button_pushed(false)
{
    attach(next_button);
    attach(quit_button);
    attach(moving_button);
    attach(img);
}

//------------------------------------------------------------------------------

Checker_window::Checker_window (Point xy, int w, int h, const string& title) :
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
        check_nw(
                Point{x_max() / 2 - 150,y_max() / 2 - 150},
                145,
                145,
                "Iceland",
                cb_check_nw),
        check_ne(
                Point{x_max() / 2,y_max() / 2 - 150},
                145,
                145,
                "Norway",
                cb_check_ne),
        check_sw(
                Point{x_max() / 2 - 150,y_max() / 2},
                145,
                145,
                "Morocco",
                cb_check_sw),
        check_se(
                Point{x_max() / 2,y_max() / 2},
                145,
                145,
                "Yemen",
                cb_check_se),
        button_pushed(false)
{
    attach(next_button);
    attach(quit_button);
    attach(check_nw);
    attach(check_ne);
    attach(check_sw);
    attach(check_se);
}