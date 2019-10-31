#include "Graph.h"
#include "Simple_window.h"

/*

For each “define a class” exercise, display a couple of objects of the class to demonstrate that they work.
12. Draw a circle. Move a mark around on the circle (let it move a bit each time you hit the “Next” button).
*/


int main()
try {

	Simple_window win{ Point { 100, 100 }, 1000, 900, "Canvas" };
	Point start{ 400, 300 };
	int rad = 150;
	Point M;
	Circle c{ start, rad };
	//x2 + y2 = r2

	while (true) {
		int sign = rand() % 2 - 1;
		if (sign == 0) sign = 1;
		int sign2 = rand() % 2 - 1;
		if (sign2 == 0) sign2 = 1;
		int x = sign * (rand() % rad);
		int y = sign2 * sqrt(pow(rad, 2) - pow(x, 2));
		M = { x + start.x, y + start.y };
		Mark mm (M, 'X');

		win.attach(c);
		win.attach(mm);
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