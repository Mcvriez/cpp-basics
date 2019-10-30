#include "Graph.h"
#include "Simple_window.h"

/*

For each “define a class” exercise, display a couple of objects of the class to demonstrate that they work.
9. Tile a part of a window with Regular_hexagons (use at least eight hexagons)

*/




int main()
try {
	
	Simple_window win{ Point { 100, 100 }, 1000, 900, "Canvas" };
	int rad = 50;

	Vector_ref<Graph_lib::Regular_hexagon> vr;
	
	int base_x = 100;
	int base_y = 100;
	for (int i = 0; i < 9; ++i) 
		for (int j = 0; j < 8; ++j){
			if (j % 2 > 0 || j == 1) { base_x = 143; }
		vr.push_back(new Regular_hexagon(Point{ base_x + i * 87, base_y + 75 * j }, rad));
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