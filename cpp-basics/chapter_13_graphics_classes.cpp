#include "Graph.h"
#include "Simple_window.h"

/*

For each “define a class” exercise, display a couple of objects of the class to demonstrate that they work.
5. Define the functions from exercise 4 for a Circle and an Ellipse. Place the connection points on or outside the shape but
not outside the bounding rectangle.

*/

Point n(Graph_lib::Circle& rec) {
	return Point{ rec.center().x , rec.center().y - rec.radius() };
}
Point s(Graph_lib::Circle& rec) {
	return Point{ rec.center().x , rec.center().y + rec.radius() };
}
Point e(Graph_lib::Circle& rec) {
	return Point{ rec.center().x + rec.radius() , rec.center().y };
}
Point w(Graph_lib::Circle& rec) {
	return Point{ rec.center().x - rec.radius() , rec.center().y };
}
Point center(Graph_lib::Circle& rec) {
	return rec.center();
}
Point ne(Graph_lib::Circle& rec) {
	return Point{ rec.center().x + rec.radius(), rec.center().y - rec.radius() };
}
Point se(Graph_lib::Circle& rec) {
	return Point{ rec.center().x + rec.radius(), rec.center().y + rec.radius() };
}
Point sw(Graph_lib::Circle& rec) {
	return Point{ rec.center().x - rec.radius(), rec.center().y + rec.radius() };
}
Point nw(Graph_lib::Circle& rec) {
	return Point{ rec.center().x - rec.radius(), rec.center().y - rec.radius() };
}


Point n(Graph_lib::Ellipse& rec) {
	return Point{ rec.center().x , rec.center().y - rec.minor() };
}
Point s(Graph_lib::Ellipse& rec) {
	return Point{ rec.center().x , rec.center().y + rec.minor() };
}
Point e(Graph_lib::Ellipse& rec) {
	return Point{ rec.center().x + rec.major() , rec.center().y };
}
Point w(Graph_lib::Ellipse& rec) {
	return Point{ rec.center().x - rec.major() , rec.center().y };
}
Point center(Graph_lib::Ellipse& rec) {
	return rec.center();
}
Point ne(Graph_lib::Ellipse& rec) {
	return Point{ rec.center().x + rec.major(), rec.center().y - rec.minor() };
}
Point se(Graph_lib::Ellipse& rec) {
	return Point{ rec.center().x + rec.major(), rec.center().y + rec.minor() };
}
Point sw(Graph_lib::Ellipse& rec) {
	return Point{ rec.center().x - rec.major(), rec.center().y + rec.minor() };
}
Point nw(Graph_lib::Ellipse& rec) {return Point { rec.center().x - rec.major(), rec.center().y - rec.minor() }; 
}




int main()
try {
	Point start = { 300, 300 };
	Simple_window win{ Point { 100, 100 }, 800, 640, "Canvas" };
	Graph_lib::Circle rec{ start,  120 };
	
	rec.set_style(Line_style(Line_style::dash, 3));
	rec.set_color(Color::black);
	win.attach(rec);
	cout << n(rec).x << ':' << n(rec).y << endl;
	cout << s(rec).x << ':' << s(rec).y << endl;
	cout << e(rec).x << ':' << e(rec).y << endl;
	cout << w(rec).x << ':' << w(rec).y << endl;
	cout << center(rec).x << ':' << center(rec).y << endl;
	cout << ne(rec).x << ':' << ne(rec).y << endl;
	cout << se(rec).x << ':' << se(rec).y << endl;
	cout << sw(rec).x << ':' << sw(rec).y << endl;
	cout << nw(rec).x << ':' << nw(rec).y << endl;

	Graph_lib::Ellipse ell{ start,  200, 100 };
	ell.set_style(Line_style(Line_style::dash, 3));
	ell.set_color(Color::black);
	win.attach(ell);
	cout << n(ell).x << ':' << n(ell).y << endl;
	cout << s(ell).x << ':' << s(ell).y << endl;
	cout << e(ell).x << ':' << e(ell).y << endl;
	cout << w(ell).x << ':' << w(ell).y << endl;
	cout << center(ell).x << ':' << center(ell).y << endl;
	cout << ne(ell).x << ':' << ne(ell).y << endl;
	cout << se(ell).x << ':' << se(ell).y << endl;
	cout << sw(ell).x << ':' << sw(ell).y << endl;
	cout << nw(ell).x << ':' << nw(ell).y << endl;

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