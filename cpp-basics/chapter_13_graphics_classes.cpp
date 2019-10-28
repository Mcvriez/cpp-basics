#include "Graph.h"
#include "Simple_window.h"

/*

For each “define a class” exercise, display a couple of objects of the class to demonstrate that they work.
3. Define a class Arrow, which draws a line with an arrowhead.	

*/



int main()
try {
	Point start = { 300, 300 };
	Simple_window win{ Point { 100, 100 }, 800, 640, "Canvas" };
	int size = 30;
	int delta = 10;


	Arrow arr{ start, Point {start.x + 200, start.y}, size, delta};
	arr.set_color(Color::black);
	arr.set_style(Line_style(Line_style::dash, 3));
	arr.set_color(Color::magenta);
	win.attach(arr);
	
	Arrow arr1{ start, Point {start.x, start.y + 200}, size, delta};
	arr1.set_color(Color::black);
	arr1.set_style(Line_style(Line_style::solid, 4));
	win.attach(arr1);

	Arrow arr2{ start, Point {start.x + 200, start.y + 200}, size, delta};
	arr2.set_color(Color::black);
	win.attach(arr2);

	Arrow arr3{ start, Point {start.x - 200, start.y}, size, delta};
	arr3.set_color(Color::black);
	win.attach(arr3);

	Arrow arr4{ start, Point {start.x, start.y - 200}, size, delta};
	arr4.set_color(Color::black);
	win.attach(arr4);

	Arrow arr5{ start, Point {start.x - 200, start.y + 200}, size, delta};
	arr5.set_color(Color::black);
	win.attach(arr5);

	Arrow arr6{ start, Point {start.x, start.y + 200}, size, delta};
	arr6.set_color(Color::black);
	win.attach(arr6);

	Arrow arr7{ start, Point {start.x - 200, start.y - 200}, size, delta};
	arr7.set_color(Color::black);
	win.attach(arr7);

	Arrow arr8{ start, Point {start.x + 400, start.y - 300}, size, delta};
	arr8.set_style(Line_style(Line_style::dot, 3));
	arr8.set_color(Color::black);
	win.attach(arr8);

	Arrow arr9{ start, Point {start.x + 400, start.y + 300}, size, delta};
	arr9.set_color(Color::black);
	win.attach(arr9);

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