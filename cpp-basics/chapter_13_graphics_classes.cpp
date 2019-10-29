#include "Graph.h"
#include "Simple_window.h"

/*

For each “define a class” exercise, display a couple of objects of the class to demonstrate that they work.
4. Define functions n(), s(), e(), w(), center(), ne(), se(), sw(), and nw(). Each takes a Rectangle argument and returns
a Point. These functions define “connection points” on and in the rectangle. For example, nw(r) is the northwest (top
left) corner of a Rectangle called r.

*/

Point n(Graph_lib::Rectangle& rec) {
	return Point{ rec.start_point().x + rec.width() / 2, rec.start_point().y };
}
Point s(Graph_lib::Rectangle& rec) {
	return Point{ rec.start_point().x + rec.width() / 2, rec.start_point().y + rec.height() };
}
Point e(Graph_lib::Rectangle& rec) {
	return Point{ rec.start_point().x + rec.width() , rec.start_point().y + rec.height() / 2 };
}
Point w(Graph_lib::Rectangle& rec) {
	return Point{ rec.start_point().x , rec.start_point().y + rec.height() / 2 };
}
Point center(Graph_lib::Rectangle& rec) {
	return Point{ rec.start_point().x + rec.width() / 2 , rec.start_point().y + rec.height() / 2 };
}
Point ne(Graph_lib::Rectangle& rec) {
	return Point{ rec.start_point().x + rec.width(), rec.start_point().y};
}
Point se(Graph_lib::Rectangle& rec) {
	return Point{ rec.start_point().x + rec.width(), rec.start_point().y + rec.height() };
}
Point sw(Graph_lib::Rectangle& rec) {
	return Point{ rec.start_point().x, rec.start_point().y + rec.height() };
}
Point nw(Graph_lib::Rectangle& rec) { return rec.start_point(); }




int main()
try {
	Point start = { 0, 0 };
	Simple_window win{ Point { 100, 100 }, 800, 640, "Canvas" };
	Graph_lib::Rectangle rec{ start, 200, 120 };
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