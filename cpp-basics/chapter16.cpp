#include "fltk_lib/Graph.h"
#include "fltk_lib/Simple_window.h"
#include "fltk_lib/std_lib_facilities.h"

// Drill chapter 16

struct Lines_window : Graph_lib::Window {
    Lines_window(Point p, int w, int h, const string& title);

private:
    Open_polyline lines;
    Button next_button;
    Button quit_button;
    In_box next_x;
    In_box next_y;
    Out_box xy_out;
    Menu color_menu;
    Menu style_menu;
    Button menu_button;
    Button style_menu_button;

    void hide_menu() { color_menu.hide(); menu_button.show(); }
    void red_pressed() { change(Color::red); hide_menu(); }
    void blue_pressed() { change(Color::blue); hide_menu(); }
    void black_pressed() { change(Color::black); hide_menu(); }
    void menu_pressed() { menu_button.hide(); color_menu.show(); }
    void change(Color c) { lines.set_color(c); }

    void hide_style_menu() { style_menu.hide(); style_menu_button.show(); }
    void solid_pressed() { change_style(Line_style(Line_style::solid, 5)); hide_style_menu(); }
    void dash_pressed() { change_style(Line_style(Line_style::dash, 5)); hide_style_menu(); }
    void dot_pressed() { change_style(Line_style(Line_style::dot, 5)); hide_style_menu(); }
    void style_menu_pressed() { style_menu_button.hide(); style_menu.show(); }
    void change_style(Line_style st) { lines.set_style(st); }


    void next();
    void quit();

    static void cb_red(Address, Address pw) {reference_to<Lines_window>(pw).red_pressed();};
    static void cb_blue(Address, Address pw) {reference_to<Lines_window>(pw).blue_pressed();};
    static void cb_black(Address, Address pw) {reference_to<Lines_window>(pw).black_pressed();};
    static void cb_menu(Address, Address pw) {reference_to<Lines_window>(pw).menu_pressed();};

    static void cb_solid(Address, Address pw) {reference_to<Lines_window>(pw).solid_pressed();};
    static void cb_dash(Address, Address pw) {reference_to<Lines_window>(pw).dash_pressed();};
    static void cb_dot(Address, Address pw) {reference_to<Lines_window>(pw).dot_pressed();};
    static void cb_smenu(Address, Address pw) {reference_to<Lines_window>(pw).style_menu_pressed();};

    static void cb_next(Address, Address pw) {reference_to<Lines_window>(pw).next();};
    static void cb_quit(Address, Address pw) {reference_to<Lines_window>(pw).quit();};
};

Lines_window::Lines_window (Point p, int w, int h, const string& title)
        :Window(p, w, h, title),
         next_button {Point{x_max() - 150, 0},
                      70,
                      20,
                      "Next point",
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
         color_menu {Point{x_max()-70,40},
                     70,
                     20,
                     Menu::vertical,
                     "color"},
         menu_button{Point{x_max() - 80,30},
                     80,
                     20,
                     "color menu",
                     cb_menu},
         style_menu_button {Point{x_max() - 170,30},
                     80,
                     20,
                     "style menu",
                     cb_smenu},
         style_menu {Point{x_max() - 160,40},
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
    color_menu.attach(new Button{Point{0,0},0,0,"red",cb_red});
    color_menu.attach(new Button{Point{0,0},0,0,"blue",cb_blue});
    color_menu.attach(new Button{Point{0,0},0,0,"black",cb_black});
    attach(color_menu);
    color_menu.hide();
    attach(menu_button);

    style_menu.attach(new Button{Point{0,0},0,0,"solid", cb_solid});
    style_menu.attach(new Button{Point{0,0},0,0,"dash", cb_dash});
    style_menu.attach(new Button{Point{0,0},0,0,"dot", cb_dot});
    attach(style_menu);
    style_menu.hide();
    attach(style_menu_button);

    attach(lines);
}

void Lines_window::quit()
{
    hide();
}

void Lines_window::next()
{
    int x = next_x.get_int();
    int y = next_y.get_int();
    lines.add(Point{x,y});
    ostringstream ss;
    ss << '(' << x << ',' << y << ')';
    xy_out.put(ss.str());
    redraw();
}


int main()
try {
    Point tl(500,500);

    Lines_window win {Point{100,100},600,400,"lines"};
    return gui_main();
    }

catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    keep_window_open();
}
catch (...) {
    cerr << "exception\n";
}