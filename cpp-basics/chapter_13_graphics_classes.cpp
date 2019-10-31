#include "Graph.h"
#include "Simple_window.h"

/*

For each “define a class” exercise, display a couple of objects of the class to demonstrate that they work.
12. Draw a circle. Move a mark around on the circle (let it move a bit each time you hit the “Next” button).
*/


int main()
try {

	Simple_window win{ Point { 100, 100 }, 1000, 900, "Canvas" };
	Point start{ 100, 100 };
	int rad = 50;

	Circle c{ start, rad };
	c.set_fill_color(140);

	while (true) {
		int x = (rand() % 10);
		int y = (rand() % 10);
		cout << x << '|' << y << endl;
		c.move(x, y);
		c.set_fill_color(rand() % 255);
		win.attach(c);
		win.wait_for_button();
	}
}

catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
	keep_window_open();
}
catch (...) {
	cerr << "exception\n";
	keep_window_open();
}