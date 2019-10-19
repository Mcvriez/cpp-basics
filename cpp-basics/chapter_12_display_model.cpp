#include "Graph.h"
#include "Simple_window.h"

void routine() {

	// 1. Draw a rectangle as a Rectangle and as a Polygon. Make the lines of the Polygon red and the lines of the Rectangle blue.
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
	win.detach(poly_rect);
	win.detach(rect);

	// 2. Draw a 100-by-30 Rectangle and place the text “Howdy!” inside it.

	win.set_label("Excercise 2");
	Graph_lib::Rectangle rect2{ Point { 150, 150 }, 100, 30 }; // top left corner, width, height
	rect2.set_color(Color::dark_cyan);
	rect2.set_style(Line_style(Line_style::solid, 2));
	win.attach(rect2);

	Text t{ Point{ 175, 170}, "Howdy!" };
	t.set_color(Color::dark_blue);
	// t.set_font(Font_type::helvetica);
	win.attach(t);

	win.wait_for_button();
	win.detach(rect2);
	win.detach(t);

	// 3. Draw your initials 150 pixels high. Use a thick line. Draw each initial in a different color.
	win.set_label("Excercise 3");

	Text initial1{ Point{ 20, 220 }, "V" };
	initial1.set_font_size(150);
	initial1.set_color(Color::dark_blue);
	initial1.set_font(Font::helvetica_bold);
	win.attach(initial1);

	Text initial2{ Point{ 140, 220 }, "V" };
	initial2.set_font_size(150);
	initial2.set_color(Color::dark_magenta);
	initial2.set_font(Font::helvetica_bold);
	win.attach(initial2);

	Text initial3{ Point{ 260, 220 }, "V" };
	initial3.set_font_size(150);
	initial3.set_color(Color::dark_yellow);
	initial3.set_font(Font::helvetica_bold);
	win.attach(initial3);

	win.wait_for_button();
	win.detach(initial1);
	win.detach(initial2);
	win.detach(initial3);

	// 4. Draw a 3-by-3 tic-tac-toe board of alternating white and red squares.
	win.set_label("Excercise 4");


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