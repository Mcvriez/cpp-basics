#include "Graph.h"
#include "Simple_window.h"
/*

2. Draw a 100-by-30 Rectangle and place the text “Howdy!” inside it.

*/



void routine() {

	Point tl{ 100, 100 }; // top left corner of our window
	Simple_window win{ tl, 400, 330, "Canvas" };
	win.set_label("Excercise 1");

	Graph_lib::Rectangle rect{ Point { 150, 150 }, 100, 30 }; // top left corner, width, height
	rect.set_color(Color::dark_cyan);
	rect.set_style(Line_style(Line_style::solid, 2));
	win.attach(rect);

	Text t{ Point{ 175, 170}, "Howdy!" };
	t.set_color(Color::dark_blue);
	// t.set_font(Font_type::helvetica);
	win.attach(t);

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