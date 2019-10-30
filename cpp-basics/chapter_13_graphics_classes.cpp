#include "Graph.h"
#include "Simple_window.h"

/*

For each “define a class” exercise, display a couple of objects of the class to demonstrate that they work.
8. Define a class Regular_hexagon (a regular hexagon is a six-sided polygon with all sides of equal length). Use the
center and the distance from the center to a corner point as constructor arguments.

*/




int main()
try {
	
	Simple_window win{ Point { 100, 100 }, 800, 640, "Canvas" };
	Point start{ 200, 200 };
	int rad = 50;
	// Vector_ref<Graph_lib::Rectangle> vr;


	Regular_hexagon rex{ start, rad };
	win.attach(rex);

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