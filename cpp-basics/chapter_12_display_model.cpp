#include "Graph.h"
#include "Simple_window.h"

/*

For each “define a class” exercise, display a couple of objects of the class to demonstrate that they work.
1. Define a class Arc, which draws a part of an ellipse. Hint: fl_arc().

*/



int main()
try {
	Simple_window win{ Point { 100, 100 }, 1000, 800, "Canvas" };

	Point p1{ 200, 200 };
	
	int aa{ 150 }; 
	int bb{ 75 };
	int start = -15;
	int end = 135;
	

	Graph_lib::Arc some_arc { p1, aa, bb, start, end };
	some_arc.set_color(Color::black);
	some_arc.set_style(Line_style(Line_style::solid, 4));
	some_arc.set_fill_color(Color::dark_cyan);
	win.attach(some_arc);

	p1 = { 440, 215 };

	aa =  90;
	bb = 156;
	start = 30;
	end = 90;


	Graph_lib::Arc some_arc1{ p1, aa, bb, start, end };
	some_arc1.set_color(Color::black);
	some_arc1.set_style(Line_style(Line_style::dashdot, 2));
	some_arc1.set_fill_color(Color::dark_yellow);
	win.attach(some_arc1);

	p1 = { 200, 515 };

	aa = 190;
	bb = 56;
	start = 120;
	end = 200;


	Graph_lib::Arc some_arc2{ p1, aa, bb, start, end };
	some_arc2.set_color(Color::dark_green);
	some_arc2.set_style(Line_style(Line_style::dash, 3));
	some_arc2.set_fill_color(Color::dark_blue);
	win.attach(some_arc2);
	
	
	
	win.wait_for_button();
}

catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
	keep_window_open();
}
catch (...) {
	cerr << "exception\n";
	keep_window_open();
}