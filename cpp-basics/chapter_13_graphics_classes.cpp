#include "Graph.h"
#include "Simple_window.h"

/*

For each “define a class” exercise, display a couple of objects of the class to demonstrate that they work.
6. Write a program that draws a class diagram like the one in §12.6. It will simplify matters if you start by defining a Box
class that is a rectangle with a text label.

*/




int main()
try {
	Point start = { 150, 600 };
	Point start2 = { 250, 300 };
	Point start3 = { 250, 50 };
	Point shape = { 375, 290 };

	Simple_window win{ Point { 100, 100 }, 800, 640, "Canvas" };

	Graph_lib::Box b1{ start, "Line" };
	Graph_lib::Box b2{ Point(start.x + 75, start.y), "Lines" };
	Graph_lib::Box b3{ Point(start.x + 160, start.y), "Polygon" };
	Graph_lib::Box b4{ Point(start.x + 240, start.y), "Axis" };
	Graph_lib::Box b5{ Point(start.x + 325, start.y), "Rectangle" };
	Graph_lib::Box b6{ Point(start.x + 425, start.y), "Text" };
	Graph_lib::Box b7{ Point(start.x + 500, start.y), "Image" };

	Graph_lib::Arrow a1(Point(start.x + 75, start.y-10), Point(shape.x + 8, shape.y), 8, 15);
	Graph_lib::Arrow a2(Point(start.x + 160, start.y - 10), Point(shape.x + 16, shape.y), 8, 15);
	Graph_lib::Arrow a3(Point(start.x + 240, start.y - 10), Point(shape.x + 24, shape.y), 8, 15);
	Graph_lib::Arrow a4(Point(start.x + 325, start.y - 10), Point(shape.x + 32, shape.y), 8, 15);
	Graph_lib::Arrow a5(Point(start.x + 425, start.y - 10), Point(shape.x + 40, shape.y), 8, 15);
	Graph_lib::Arrow a6(Point(start.x + 500, start.y - 10), Point(shape.x + 48, shape.y), 8, 15);
	Graph_lib::Arrow a7(Point(start.x, start.y - 10), Point(shape.x, shape.y), 8, 15);
	Graph_lib::Arrow a8(Point(start2.x, start2.y - 10), Point(start2.x, start2.y - 230), 8, 15);



	win.attach(b1);
	win.attach(b2);
	win.attach(b3);
	win.attach(b4);
	win.attach(b5);
	win.attach(b6);
	win.attach(b7);

	win.attach(a1);
	win.attach(a2);
	win.attach(a3);
	win.attach(a4);
	win.attach(a5);
	win.attach(a6);
	win.attach(a7);
	win.attach(a8);

	Graph_lib::Box b8{ Point(start2.x, start2.y), "Simple_window" };
	Graph_lib::Box b9{ Point(start2.x + 150, start2.y - 30), "Shape" };
	Graph_lib::Box b0{ Point(start2.x + 250, start2.y), "Point" };

	win.attach(b8);
	win.attach(b9);
	win.attach(b0);


	Graph_lib::Box b11{ Point(start3.x, start3.y), "Window" };
	Graph_lib::Box b12{ Point(start3.x + 150, start3.y), "Line_style" };
	Graph_lib::Box b13{ Point(start3.x + 250, start3.y), "Color" };

	win.attach(b11);
	win.attach(b12);
	win.attach(b13);


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