#include "Graph.h"
#include "Simple_window.h"

/*

For each “define a class” exercise, display a couple of objects of the class to demonstrate that they work.
2. Draw a box with rounded corners. Define a class Box, consisting of four lines and four arcs.

*/



int main()
try {
	Simple_window win{ Point { 100, 100 }, 800, 640, "Canvas" };

	Point p1{ 500, 300 };
	
	int aa{ 330 }; 
	int bb{ 200 };
	int angle = 20;
	
	Box box{ p1, aa, bb, angle };
	box.set_style(Line_style(Line_style::dash, 3));
	box.set_color(Color::dark_red);
	box.set_fill_color(Color::dark_cyan);
	win.attach(box);
	
	Point p2{ 600, 500 };

	aa = { 140 };
	bb = { 200 };
	angle = 15;

	Box box1{ p2, aa, bb, angle };
	box1.set_style(Line_style(Line_style::dot, 2));
	box1.set_color(Color::black);
	win.attach(box1);
	
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