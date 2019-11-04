#include "Graph.h"
#include "Simple_window.h"

/*

For each “define a class” exercise, display a couple of objects of the class to demonstrate that they work.
15. “Tile” a window with small right triangles.

*/



int main()
try {

	Point tl(200, 50);
	Point pzero(30, 50);
	int winx = 1200;
	int winy = 800;

	Simple_window win(tl, winx, winy, "My window");
	Vector_ref<Graph_lib::Right_triangle> vrt;

	int size = 35;
	int step = size * sqrt(2);

	for (int i = 0; i < winy / (step + 1); ++i)
		for (int j = 0; j < winx / (step + 1); ++j)
		{
			vrt.push_back(new Graph_lib::Right_triangle(Point(pzero.x + j * step, pzero.y + i * step), size, size, 45));
			vrt[vrt.size() - 1].set_fill_color(rand() % 255);
			vrt[vrt.size() - 1].set_color(Color::invisible);
			win.attach(vrt[vrt.size() - 1]);
			vrt.push_back(new Graph_lib::Right_triangle(Point(pzero.x + j * step, pzero.y + i * step), size, size, 135));
			vrt[vrt.size() - 1].set_fill_color(rand() % 255);
			vrt[vrt.size() - 1].set_color(Color::invisible);
			win.attach(vrt[vrt.size() - 1]);
			vrt.push_back(new Graph_lib::Right_triangle(Point(pzero.x + j * step, pzero.y + i * step), size, size, -45));
			vrt[vrt.size() - 1].set_fill_color(rand() % 255);
			vrt[vrt.size() - 1].set_color(Color::invisible);
			win.attach(vrt[vrt.size() - 1]);
			vrt.push_back(new Graph_lib::Right_triangle(Point(pzero.x + j * step, pzero.y + i * step), size, size, -135));
			vrt[vrt.size() - 1].set_fill_color(rand() % 255);
			vrt[vrt.size() - 1].set_color(Color::invisible);
			win.attach(vrt[vrt.size() - 1]);
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