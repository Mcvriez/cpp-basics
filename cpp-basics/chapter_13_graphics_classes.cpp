#include "Graph.h"
#include "Simple_window.h"

/*

For each “define a class” exercise, display a couple of objects of the class to demonstrate that they work.
11. 
Draw a 300-by-200-pixel ellipse. 
Draw a 400-pixel-long x axis and a 300-pixel-long y axis through the center of the ellipse. 
Mark the foci. 
Mark a point on the ellipse that is not on one of the axes. 
Draw the two lines from the foci to the point.

*/


int main()
try {

	Simple_window win{ Point { 100, 100 }, 1000, 900, "Canvas" };
	Point start{ 500, 400 };
	int ww = 300;
	int hh = 200;
	//x 2 / a 2 + y2 / b 2 = 1,

	int ppx = 200;
	int ppy = sqrt((1 - pow(ppx, 2) / pow(ww, 2)) * pow(hh, 2)) - 1;
	Point ellp{ ppx + start.x, -ppy + start.y };
	
	Graph_lib::Ellipse ell (start, ww, hh);
	Graph_lib::Axis xax(Axis::Orientation::x, Point{ start.x - ww, start.y }, ww * 2, 6);
	Graph_lib::Axis yax(Axis::Orientation::y, Point{ start.x, start.y + hh }, hh * 2, 4);

	ell.set_style(Line_style(Line_style::solid, 2));

	Point foci1 = ell.focus1();
	Point foci2 = ell.focus2();

	Graph_lib::Mark m1 (foci1, 'X');
	Graph_lib::Mark m2 (foci2, 'X');
	Graph_lib::Mark m3(ellp, 'X');
	Line l1 (foci1, ellp);
	Line l2 (foci2, ellp);
	l1.set_style(Line_style(Line_style::dash, 2));
	l2.set_style(Line_style(Line_style::dash, 2));

	win.attach(ell);

	win.attach(xax);
	win.attach(yax);
	
	win.attach(m1);
	win.attach(m2);
	win.attach(m3);
	
	win.attach(l1);
	win.attach(l2);

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