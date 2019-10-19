#include "Graph.h"
#include "Simple_window.h"
/*

1. Draw a rectangle as a Rectangle and as a Polygon. 
Make the lines of the Polygon red and the lines of the Rectangle blue.

*/



void routine() {

	Point tl{ 100, 100 }; // top left corner of our window
	Simple_window win{ tl, 390, 330, "Canvas" };
	win.set_label("Excercise 1");

	Graph_lib::Rectangle rect{ Point { 150, 130 }, 100, 100 }; // top left corner, width, height
	
	rect.set_color(Color::dark_cyan);
	rect.set_style(Line_style(Line_style::solid, 2));
	
	Graph_lib::Polygon poly_rect;
	
	poly_rect.add(Point{ 100, 50 });	poly_rect.add(Point{ 200, 50 });	
	poly_rect.add(Point{ 200, 150 }); poly_rect.add(Point{ 100, 150 });
	poly_rect.set_color(Color::dark_red);
	poly_rect.set_style(Line_style(Line_style::dashdot, 2));

	win.attach(poly_rect);
	win.attach(rect);
	win.wait_for_button();


}


int main()
{

	try
	{
		routine();
	}
	catch (exception& e) {
		// some error reporting
		return 1;
	}
	catch (...) {
		// some more error reporting
		return 2;
	}
}