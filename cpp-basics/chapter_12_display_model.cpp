#include "Graph.h"
#include "Simple_window.h"

void routine() {

	// 1. Draw a rectangle as a Rectangle and as a Polygon. Make the lines of the Polygon red and the lines of the Rectangle blue.
	Point tl{ 100, 100 }; // top left corner of our window
	Simple_window win{ tl, 390, 330, "Canvas" };
	/*win.set_label("Excercise 1");

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
	Graph_lib::Rectangle recth{ Point { 150, 150 }, 100, 30 }; // top left corner, width, height
	recth.set_color(Color::dark_cyan);
	recth.set_style(Line_style(Line_style::solid, 2));
	win.attach(recth);

	Text t{ Point{ 175, 170}, "Howdy!" };
	t.set_color(Color::dark_blue);
	// t.set_font(Font_type::helvetica);
	win.attach(t);

	win.wait_for_button();
	win.detach(recth);
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

	Graph_lib::Rectangle rect1{ Point { 230, 100 }, 50, 50 }; // top left corner, width, height
	rect1.set_fill_color(Color::red);
	Graph_lib::Rectangle rect2{ Point { 130, 100 }, 50, 50 }; // top left corner, width, height
	rect2.set_fill_color(Color::red);
	Graph_lib::Rectangle rect3{ Point { 180, 100 }, 50, 50 }; // top left corner, width, height
	rect3.set_fill_color(Color::white);

	Graph_lib::Rectangle rect4{ Point { 230, 150 }, 50, 50 }; // top left corner, width, height
	rect4.set_fill_color(Color::white);
	Graph_lib::Rectangle rect5{ Point { 130, 150 }, 50, 50 }; // top left corner, width, height
	rect5.set_fill_color(Color::white);
	Graph_lib::Rectangle rect6{ Point { 180, 150 }, 50, 50 }; // top left corner, width, height
	rect6.set_fill_color(Color::red);

	Graph_lib::Rectangle rect7{ Point { 230, 200 }, 50, 50 }; // top left corner, width, height
	rect7.set_fill_color(Color::red);
	Graph_lib::Rectangle rect8{ Point { 130, 200 }, 50, 50 }; // top left corner, width, height
	rect8.set_fill_color(Color::red);
	Graph_lib::Rectangle rect9{ Point { 180, 200 }, 50, 50 }; // top left corner, width, height
	rect9.set_fill_color(Color::white);

	win.attach(rect1); win.attach(rect2); win.attach(rect3);
	win.attach(rect4); win.attach(rect5); win.attach(rect6);
	win.attach(rect7); win.attach(rect8); win.attach(rect9);

	win.wait_for_button();

	win.detach(rect1); win.detach(rect2); win.detach(rect3);
	win.detach(rect4); win.detach(rect5); win.detach(rect6);
	win.detach(rect7); win.detach(rect8); win.detach(rect9);


	// 5. Draw a red ¼-inch frame around a rectangle that is three-quarters the height of your screen and two-thirds the width.
	win.resize(1500, 900);
	win.set_label("Excercise 5");

	//1280 x 768 || 24
	Graph_lib::Rectangle big_rect { Point { 100, 100 }, 1280, 768 };
	// big_rect.set_style(Line_style(Line_style::solid, 24));

	Graph_lib::Rectangle frame1{ Point { 76, 76 }, 1328, 24 };
	Graph_lib::Rectangle frame2{ Point { 76, 868 }, 1328, 24 };
	Graph_lib::Rectangle frame3{ Point { 76, 100 }, 24, 768 };
	Graph_lib::Rectangle frame4{ Point { 1380, 100 }, 24, 768 };

	frame1.set_fill_color(Color::dark_yellow);
	frame2.set_fill_color(Color::dark_yellow);
	frame3.set_fill_color(Color::dark_yellow);
	frame4.set_fill_color(Color::dark_yellow);


	win.attach(frame1); win.attach(frame2);
	win.attach(frame3); win.attach(frame4);
	win.attach(big_rect);
	win.wait_for_button();

	win.detach(big_rect); win.detach(frame1); win.detach(frame2);
	win.detach(frame3); win.detach(frame4);

	// 6. What happens when you draw a Shape that doesn’t fit inside its window? What happens when you draw a Window that doesn’t fit on your screen ? Write two programs that illustrate these two phenomena.

	win.resize(10000, 10000); // What happens when you draw a Window that doesn’t fit on your screen ?
	win.set_label("Excercise 6.1");
	win.wait_for_button();

	win.resize(400, 350);
	win.redraw();
	win.set_label("Excercise 6.2");
	Graph_lib::Polygon poly;
	poly.add(Point{ 500, 200 }); // What happens when you draw a Shape that doesn’t fit inside its window?
	poly.add(Point{ 50, 50 });
	poly.add(Point{ 75, 300 });
	poly.set_color(Color::black);
	poly.set_style(Line_style(Line_style::dashdot, 3));
	win.attach(poly);

	win.wait_for_button();
	win.detach(poly);


	// 7. Draw a two - dimensional house seen from the front, the way a child would : with a door, two windows, and a roof with a chimney.Feel free to add details; maybe have “smoke” come out of the chimney.

	win.resize(400, 350);
	win.redraw();

	win.set_label("Excercise 7");
	Graph_lib::Rectangle house{ Point {150, 200}, 100, 100 };
	house.set_style(Line_style(Line_style::solid, 2));
	house.set_fill_color(Color::dark_cyan);

	Graph_lib::Rectangle door{ Point {191, 260}, 16, 40 };
	door.set_fill_color(Color::dark_green);

	Graph_lib::Polygon roof;
	roof.add(Point{150, 200});
	roof.add(Point{250, 200});
	roof.add(Point{200, 150});
	roof.set_style(Line_style(Line_style::solid, 2));
	roof.set_fill_color(Color::black);

	Graph_lib::Polygon chimney;
	chimney.add(Point{ 225, 175 });
	chimney.add(Point{ 225, 155 });
	chimney.add(Point{ 230, 155 });
	chimney.add(Point{ 230, 180 });
	chimney.set_style(Line_style(Line_style::solid, 2));
	chimney.set_fill_color(Color::dark_yellow);

	Graph_lib::Rectangle window{ Point {160, 220}, 25, 25 };
	window.set_style(Line_style(Line_style::solid, 2));
	window.set_fill_color(Color::white);

	Graph_lib::Rectangle window2{ Point {216, 220}, 25, 25 };
	window2.set_style(Line_style(Line_style::solid, 2));
	window2.set_fill_color(Color::white);
	Graph_lib::Line window_plank{ Point {228, 220}, Point {228, 243} };
	Graph_lib::Line window_plank1{ Point {216, 232}, Point {240, 232} };

	Graph_lib::Line window_plank3{ Point {172, 220}, Point {172, 244} };
	Graph_lib::Line window_plank4{ Point {160, 232}, Point {184, 232} };

	win.attach(house); win.attach(door); win.attach(roof);
	win.attach(chimney);
	win.attach(window); win.attach(window2);
	win.attach(window_plank); win.attach(window_plank1);
	win.attach(window_plank3); win.attach(window_plank4);
	win.wait_for_button();*/

	// 8. Draw the Olympic five rings. If you can’t remember the colors, look them up.
	win.set_label("Excercise 8");

	Circle c{ Point{100, 150}, 45 };
	c.set_style(Line_style(Line_style::solid, 5));
	c.set_color(Color::blue);
	Circle c1{ Point{150, 200}, 45 };
	c1.set_style(Line_style(Line_style::solid, 5));
	c1.set_color(Color::yellow);
	Circle c2{ Point{200, 150}, 45 };
	c2.set_style(Line_style(Line_style::solid, 5));
	c2.set_color(Color::black);
	Circle c3{ Point{250, 200}, 45 };
	c3.set_style(Line_style(Line_style::solid, 5));
	c3.set_color(Color::dark_green);
	Circle c4{ Point{300, 150}, 45 };
	c4.set_style(Line_style(Line_style::solid, 5));
	c4.set_color(Color::red);

	win.attach(c); win.attach(c1); win.attach(c2);
	win.attach(c3); win.attach(c4);
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