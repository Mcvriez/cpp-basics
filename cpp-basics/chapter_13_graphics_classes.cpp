#include "Graph.h"
#include "Simple_window.h"

/*

For each “define a class” exercise, display a couple of objects of the class to demonstrate that they work.
10. Define a class Regular_polygon. Use the center, the number of sides (>2), and the distance from the center to a corner
as constructor arguments.

*/


int main()
try {
	
	Simple_window win{ Point { 100, 100 }, 1000, 900, "Canvas" };
	int rad = 40;

	Vector_ref<Graph_lib::Regular_polygon> vr;
	
	int base_x = 100;
	int base_y = 100;
	for (int i = 0; i < 9; ++i) 
		for (int j = 0; j < 8; ++j){
			if (j % 2 > 0 || j == 1) { base_x = 143; }
		vr.push_back(new Regular_polygon(Point{ base_x + i * 87, base_y + 75 * j }, rand() % 10 + 3, rad));
		vr[vr.size() - 1].set_fill_color(rand() % 256);
		win.attach(vr[vr.size() - 1]);
		base_x = 100;

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