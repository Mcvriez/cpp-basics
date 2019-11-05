#include "Graph.h"
#include "Simple_window.h"

/*

For each “define a class” exercise, display a couple of objects of the class to demonstrate that they work.

19. Define a class Star. One parameter should be the number of points. Draw a few stars with differing numbers of points,
differing line colors, and differing fill colors.

*/



int main()
try {

	Simple_window win{ Point { 100, 100 }, 1000, 900, "Canvas" };
	// Point centerp, int nsides, int rb, int rs
	Star xstar{ Point{500, 400 }, 5, 100, 50 };
	Star xstar1{ Point{150, 150 }, 6, 100, 50 };
	Star xstar2{ Point{500, 200 }, 7, 100, 25 };
	Star xstar3{ Point{700, 700 }, 8, 100, 70 };
	Star xstar4{ Point{100, 700 }, 9, 100, 20 };

	xstar.set_fill_color(rand() % 255);
	xstar1.set_fill_color(rand() % 255);
	xstar2.set_fill_color(rand() % 255);
	xstar3.set_fill_color(rand() % 255);
	xstar4.set_fill_color(rand() % 255);

	xstar.set_style(Line_style(Line_style::dash, 4));
	xstar1.set_style(Line_style(Line_style::dot, 3));
	xstar2.set_style(Line_style(Line_style::dashdot, 6));
	xstar3.set_style(Line_style(Line_style::dashdotdot, 4));
	xstar4.set_style(Line_style(Line_style::solid, 4));

	win.attach(xstar);
	win.attach(xstar1);
	win.attach(xstar2);
	win.attach(xstar3);
	win.attach(xstar4);

	win.wait_for_button();

}

catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
	keep_window_open();
}
catch (...) {
	cerr << "exception\n";
	
}