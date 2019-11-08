#include "Graph.h"
#include "Simple_window.h"
#include "std_lib_facilities.h"

/*

1. Define two classes Smiley and Frowny, which are both derived from class Circle and have two eyes and a mouth.
	Next, derive classes from Smiley and Frowny which add an appropriate hat to each.

*/

struct Smiley : Graph_lib::Circle {
	using Circle::Circle;
	void draw_lines() const {
		fl_line_style(0, r/40 + 1);
		Circle::draw_lines();
		fl_color(0);
		Point left_eye{ point(0).x + r / 2 , point(0).y + r / 2 };
		Point right_eye{ point(0).x + r + r / 6, point(0).y + r / 2 };
		
		fl_arc(left_eye.x, left_eye.y, r/3, r/3, 0, 360);
		fl_arc(right_eye.x, right_eye.y, r/3, r/3, 0, 360);
		
		fl_line_style(0, r / 20 + 1);
		fl_arc(point(0).x + r/2, point(0).y + r/2 + r / 6, r, r, 190, 350);
		
		fl_pie(left_eye.x, left_eye.y, r / 3, r / 3, 0, 360);
		fl_pie(right_eye.x, right_eye.y, r / 3, r / 3, 0, 360);
	}
};

struct Frowny : Graph_lib::Circle {
	using Circle::Circle;
	void draw_lines() const {
		fl_line_style(0, r / 40 + 1);
		Circle::draw_lines();
		fl_color(0);
		Point left_eye{ point(0).x + r / 2 , point(0).y + r / 2 };
		Point right_eye{ point(0).x + r + r / 6, point(0).y + r / 2 };

		fl_arc(left_eye.x, left_eye.y, r / 3, r / 3, 0, 360);
		fl_arc(right_eye.x, right_eye.y, r / 3, r / 3, 0, 360);

		fl_line_style(0, r / 20 + 1);
		fl_arc(point(0).x + r / 2, point(0).y  + r + r/6, r, r, 10, 170);

		fl_pie(left_eye.x, left_eye.y, r / 3, r / 3, 0, 360);
		fl_pie(right_eye.x, right_eye.y, r / 3, r / 3, 0, 360);
	}
};


struct Smiley_hat : Smiley {
	using Smiley::Smiley;
	void draw_lines() const {
		Smiley::draw_lines();
		fl_color(255, 51, 153);
		fl_line_style(0, r / 3 + 1);
		fl_arc(point(0).x, point(0).y, r + r, r + r, 65, 115);
	}
};

struct Frowny_hat : Frowny {
	using Frowny::Frowny;
	void draw_lines() const {
		Frowny::draw_lines();
		fl_rectf(point(0).x, point(0).y + r / 6, 2 * r, r/3);
		fl_rectf(point(0).x + r/3, point(0).y - 1.5 * r + r / 6, r * 4 / 3, r * 1.5);
	}
};

int main()
try {

	Simple_window win{ Point { 100, 100 }, 1000, 900, "Canvas" };

	Frowny_hat sm { Point {300, 300}, 150 };
	sm.set_fill_color(Color::cyan);

	Smiley_hat sf{ Point {700, 300}, 100 };
	sf.set_fill_color(Color::yellow);
	win.attach(sf);
	win.attach(sm);

	win.wait_for_button();
	sm.move(100, 100);
	win.wait_for_button();

}

catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
	keep_window_open();
}
catch (...) {
	cerr << "exception\n";
	
}