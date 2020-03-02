
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

//------------------------------------------------------------------------------

Shapes_window::Shapes_window (Point p, int w, int h, const string& title)
        : Window(p, w, h, title),
          next_button {Point{x_max() - 150, 0},
                       70,
                       20,
                       "Move",
                       cb_next},

          quit_button {Point(x_max() - 70,0),
                       70,20,
                       "Quit",
                       cb_quit},

          next_x {Point{x_max() - 310,0},
                  50,
                  20,
                  "next x:"},
          next_y {Point{x_max() - 210,0},
                  50,
                  20,
                  "next y:"},
          xy_out {Point{100,0},
                  100,
                  20,
                  "current (x,y):"},
          color_menu {Point{x_max() - 70, 40},
                      70,
                      20,
                      Menu::vertical,
                      "color"},
          menu_button{Point{x_max() - 80,30},
                      80,
                      20,
                      "color menu",
                      cb_menu},

          item_menu {Point{x_max() - 160, 40},
                     70,
                     20,
                     Menu::vertical,
                     "style"}

{

    attach(next_button);
    attach(quit_button);
    attach(next_x);
    attach(next_y);
    attach(xy_out);
    xy_out.put("no point");
    color_menu.attach(new Button{Point{0, 0}, 0, 0, "red", cb_red});
    color_menu.attach(new Button{Point{0, 0}, 0, 0, "blue", cb_blue});
    color_menu.attach(new Button{Point{0, 0}, 0, 0, "black", cb_black});
    attach(color_menu);
    color_menu.hide();
    attach(menu_button);

    item_menu.attach(new Button{Point{0, 0}, 0, 0, "circle", cb_circle});
    item_menu.attach(new Button{Point{0, 0}, 0, 0, "square", cb_square});
    item_menu.attach(new Button{Point{0, 0}, 0, 0, "triangle", cb_triangle});
    item_menu.attach(new Button{Point{0, 0}, 0, 0, "hexagon", cb_hexagon});
    attach(item_menu);

}

void Shapes_window::quit()
{
    hide();
}

void Shapes_window::next()
{
    int x = next_x.get_int();
    int y = next_y.get_int();
    ostringstream ss;
    ss << '(' << x << ',' << y << ')';
    xy_out.put(ss.str());
    if (x > 0 && y > 0) {
        shapes[shapes.size()-1].move(Point{x, y});
    }
    redraw();
}

void Shapes_window::circle_pressed()
{
    int x = next_x.get_int();
    int y = next_y.get_int();
    if (x > 0 && y > 0) {
        shapes.push_back(new Circle{Point{x, y}, 100});
        shapes[shapes.size() - 1].set_color(col);
        shapes[shapes.size() - 1].set_style(Line_style(Line_style::Line_style::dash, 5));

    }
    ostringstream ss;
    ss << '(' << x << ',' << y << ')';
    xy_out.put(ss.str());
    reattach();
    redraw();
}

void Shapes_window::triangle_pressed()
{

    int x = next_x.get_int();
    int y = next_y.get_int();
    double angle = PI / 180 * 30;
    if (x > 0 && y > 0) {
        shapes.push_back(new Polygon{
                {x, y - 100},

                {x - int(100 * cos(angle)), y + int(100 * sin(angle))},
                {x + int(100 * cos(angle)), y + int(100 * sin(angle))}
        });
        shapes[shapes.size() - 1].set_color(col);
        shapes[shapes.size() - 1].set_style(Line_style(Line_style::Line_style::dash, 5));
    }
    ostringstream ss;
    ss << '(' << x << ',' << y << ')';
    xy_out.put(ss.str());
    reattach();
    redraw();
}

void Shapes_window::square_pressed()
{
    int x = next_x.get_int();
    int y = next_y.get_int();
    if (x > 0 && y > 0) {
        shapes.push_back(new Rectangle{Point {x - 100, y - 100}, 200, 200});
        shapes[shapes.size() - 1].set_color(col);
        shapes[shapes.size() - 1].set_style(Line_style(Line_style::Line_style::dash, 5));
    }
    ostringstream ss;
    ss << '(' << x << ',' << y << ')';
    xy_out.put(ss.str());
    reattach();
    redraw();
}

void Shapes_window::hexagon_pressed()
{
    int x = next_x.get_int();
    int y = next_y.get_int();
    if (x > 0 && y > 0) {
        shapes.push_back(new Regular_hexagon {Point {x, y}, 100});
        shapes[shapes.size() - 1].set_color(col);
        shapes[shapes.size() - 1].set_style(Line_style(Line_style::Line_style::dash, 5));
    }
    ostringstream ss;
    ss << '(' << x << ',' << y << ')';
    xy_out.put(ss.str());
    reattach();
    redraw();
}