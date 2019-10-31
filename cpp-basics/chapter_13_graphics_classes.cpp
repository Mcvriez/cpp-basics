#include "Graph.h"
#include "Simple_window.h"

/*

For each “define a class” exercise, display a couple of objects of the class to demonstrate that they work.
13. Draw the color matrix from §13.10, but without lines around each color.

*/


int main()
try {

	Simple_window win{ Point { 100, 100 }, 1000, 900, "Canvas" };
	Point start{ 400, 300 };
	Vector_ref<Graph_lib::Rectangle> vr;
	for (int i = 0; i < 16; ++i)
		for (int j = 0; j < 16; ++j) {
			vr.push_back(new Graph_lib::Rectangle{ Point{i * 20,j * 20},20,20 });
			vr[vr.size()-1].set_fill_color(Color{ i * 16 + j });
			win.attach(vr[vr.size()-1]);
		}
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