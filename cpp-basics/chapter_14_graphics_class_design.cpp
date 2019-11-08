#include "Graph.h"
#include "Simple_window.h"
#include "std_lib_facilities.h"

/*

5. Define a Striped_rectangle where instead of fill, the rectangle is “filled” by drawing one-pixel-wide horizontal lines
across the inside of the rectangle (say, draw every second line like that). 
You may have to play with the width of lines and the line spacing to get a pattern you like.

*/


class Striped_rectangle : public Rectangle {
public:
	using Rectangle::Rectangle;
	void draw_lines() const {
		if (fill_color().visibility()) {	
			fl_color(fill_color().as_int());
			fl_line_style(0, pixel_step);
			for (int i =0; i * pixel_step < w; ++i) {
				if (i % 2 != 0) {
					cout << i << point(0).y << i << point(0).y + h << endl;
					fl_line(point(0).x + i * pixel_step, point(0).y, point(0).x + i * pixel_step, point(0).y + h);
				}
			}
			fl_color(color().as_int());	
		}
		if (color().visibility()) {
			fl_line_style(color().as_int(), pixel_step);
			fl_color(color().as_int());
			fl_rect(point(0).x, point(0).y, w, h);
		}
	}
	void set_step(int x) {
		if (x < 1) error("Wrong step size");
		pixel_step = x;
	}
	int get_step() const {
		return pixel_step;
	}
private:
	int pixel_step = 7;
};

int main()
try {
	Point start{ 300, 300 };
	Simple_window win{ Point { 100, 100 }, 1000, 900, "Canvas" };

	Striped_rectangle rect { start , 300, 150 };
	
	rect.set_fill_color(Color::dark_cyan);
	win.attach(rect);
	win.wait_for_button();

	rect.set_fill_color(Color::dark_magenta);
	rect.move(100, 100);
	rect.set_step(15);
	win.wait_for_button();


}

catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
	keep_window_open();
}
catch (...) {
	cerr << "exception\n";
	
}