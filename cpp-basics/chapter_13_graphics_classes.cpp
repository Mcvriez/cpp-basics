#include "Graph.h"
#include "Simple_window.h"

/*

For each “define a class” exercise, display a couple of objects of the class to demonstrate that they work.
7. Make an RGB color chart (e.g., search the web for “RGB color chart”)

*/




int main()
try {
	
	Simple_window win{ Point { 100, 100 }, 800, 640, "Canvas" };
	Vector_ref<Graph_lib::Rectangle> vr;
	for (int r = 0; r < 256; ++r)
		for (int g = 0; g < 256; ++g) {
			vr.push_back(new Graph_lib::Rectangle{ Point{r * 5, g *5 },5,5 });
			vr[vr.size()-1].set_fill_color(Color{ uchar(r),uchar(g),uchar(sqrt(10000 - g*r)) });
			win.attach(vr[vr.size() - 1]);
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