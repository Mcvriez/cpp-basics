#include "Graph.h"
#include "Simple_window.h"

void routine() {

	Point tl{ 100,100 }; // top left corner of our window
	Simple_window win{ tl,600,400,"Canvas" };
	win.wait_for_button(); // display

	Axis xa{ Axis::x, Point{20,300}, 280, 10, "x axis" }; // make an Axis
	win.attach(xa); // attach xa to the window, win
	win.set_label("Canvas #2"); // relabel the window
	win.wait_for_button(); // display!

	Axis ya{ Axis::y, Point{20,300}, 280, 10, "y axis" };
	ya.set_color(Color::cyan); // choose a color
	ya.label.set_color(Color::dark_red); // choose a color for the text
	win.attach(ya);
	win.set_label("Canvas #3");
	win.wait_for_button(); // display!

	Function sine{ sin,0,100,Point{20,150},1000,50,50 }; // sine curve
	win.attach(sine);
	win.set_label("Canvas #4");
	win.wait_for_button();

	sine.set_color(Color::blue); // we changed our mind about sine’s color
	Graph_lib::Polygon poly; // a polygon; a Polygon is a kind of Shape
	poly.add(Point{ 300,200 }); // three points make a triangle
	poly.add(Point{ 350,100 });
	poly.add(Point{ 400,200 });
	poly.set_color(Color::red);
	poly.set_style(Line_style::dash);
	win.attach(poly);
	win.set_label("Canvas #5");
	win.wait_for_button();

	Graph_lib::Rectangle r{ Point{200,200}, 100, 50 }; // top left corner, width, height
	win.attach(r);
	win.set_label("Canvas #6");
	win.wait_for_button();

	Closed_polyline poly_rect;
	poly_rect.add(Point{ 100,50 });
	poly_rect.add(Point{ 200,50 });
	poly_rect.add(Point{ 200,100 });
	poly_rect.add(Point{ 100,100 });
	win.attach(poly_rect);
	r.set_fill_color(Color::yellow); // color the inside of the rectangle
	poly.set_style(Line_style(Line_style::dash, 4));
	poly_rect.set_style(Line_style(Line_style::dash, 2));
	poly_rect.set_fill_color(Color::green);
	win.set_label("Canvas #7");
	win.wait_for_button();

	Text t{ Point{150,150}, "Hello, graphical world!" };
	win.attach(t);
	win.set_label("Canvas #8");
	win.wait_for_button();

	t.set_font(Font::times_bold);
	t.set_font_size(20);
	win.set_label("Canvas #9");
	win.wait_for_button();

	Image ii{ Point{100,50},"C:\\Users\\arcady\\Pictures\\cut.jpg" }; // 400*212-pixel jpg
	win.attach(ii);
	win.set_label("Canvas #10");
	win.wait_for_button();

	ii.move(100, 200);
	win.set_label("Canvas #11");
	win.wait_for_button();

	Circle c{ Point{100,200},50 };
	Graph_lib::Ellipse e{ Point{100,200}, 75,25 };
	e.set_color(Color::dark_red);
	Mark m{ Point{100,200},'x' };
	ostringstream oss;
	oss << "screen size: " << x_max() << "*" << y_max()
	<< "; window size: " << win.x_max() << "*" << win.y_max();
	Text sizes {Point{100,20},oss.str()};
	win.attach(c);
	win.attach(m);
	win.attach(e);
	win.attach(sizes);
	win.set_label("Canvas #12");
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