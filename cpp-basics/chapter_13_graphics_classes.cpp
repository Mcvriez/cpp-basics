#include "Graph.h"
#include "Simple_window.h"

/*

For each “define a class” exercise, display a couple of objects of the class to demonstrate that they work.
14. 
Define a right triangle class. 
Make an octagonal shape out of eight right triangles of different colors.

*/



int main()
try {

	Point tl(200, 50);
	Point pzero(500, 300);
	Simple_window win(tl, 1200, 800, "My window");
	Vector_ref<Graph_lib::Right_triangle> vrt;
	
	for (int i = 0; i < 4; ++i) {
		vrt.push_back(new Graph_lib::Right_triangle(pzero, 200, 100 + 100 * (i % 2), i * 90));
		vrt[vrt.size() - 1].set_fill_color(rand() % 255);
		win.attach(vrt[vrt.size() - 1]);
		int x = -200 * (i * (3-i) - 1);
		int y = x + 300 * (i - 1) * (1 - (i % 2));
		int angle = 180 + i * 90;
		vrt.push_back(new Graph_lib::Right_triangle(Point(pzero.x + x, pzero.y + y), 200, 100 + 100 * (i % 2), angle));
		vrt[vrt.size() - 1].set_fill_color(rand() % 255);
		win.attach(vrt[vrt.size() - 1]);
		cout << i << '|' << i % 2 << '|' << x << '|' << y << '|' << angle << endl;
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