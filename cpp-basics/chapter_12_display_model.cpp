#define _USE_MATH_DEFINES
#include "Graph.h"
#include "Simple_window.h"
#include<cmath>

/* 

12. A superellipse is a two-dimensional shape defined by the equation
Look up superellipse on the web to get a better idea of what such shapes look like. 

Write a program that draws “starlike” patterns by connecting points on a superellipse. 

- Take a, b, m, n, and N as arguments. Select N points on the superellipse defined by a, b, m, and n. 

- Make the points equally spaced for some definition of “equal.” 

- Connect each of those N points to one or more other points (if you like you can make the number of points to which to connect a point another
argument or just use N–1, i.e., all the other points).

13. Find a way to add color to the lines from the previous exercise. Make some lines one color and other lines another color
or other colors.

*/


int main()
{
	Simple_window win{ Point { 100, 100 }, 800, 640, "Canvas" };
	int x0 = 400;
	int y0 = 320;

	double a;
	double b;
	double m;
	double n;
	int N;
	int y2, y1, x;

	vector <Point> points;
	vector <int> xvector{ -125, -100, -75, -50, 0 , 50, 75, 100, 125 };

	// -------------------- POLIGON -------------------- //

	a = b = 150;
	n = m = 0.5;
	for (int x : xvector) {
		y1 = b * pow(abs(1 - pow(abs((x / a)), n)), 1.0 / m);
		y2 = y1 * -1;
		points.push_back(Point{ x + x0, y1 + y0 });
		points.push_back(Point{ x + x0, y2 + y0 });
				
	}

	
	Graph_lib::Polygon poly;
	poly.add(points[0]);
	poly.add(points[1]);
	poly.add(points[2]);
	poly.add(points[3]);
	poly.set_color(Color::dark_green);
	poly.set_style(Line_style(Line_style::dash, 3));

	Graph_lib::Polygon poly1;
	poly1.add(points[4]);
	poly1.add(points[5]);
	poly1.add(points[6]);
	poly1.add(points[7]);
	poly1.set_color(Color::dark_red);
	poly1.set_style(Line_style(Line_style::dot, 4));
	
	Graph_lib::Polygon poly2;
	poly2.add(points[8]);
	poly2.add(points[9]);
	poly2.add(points[10]);
	poly2.add(points[11]);
	poly2.set_color(Color::dark_cyan);
	poly2.set_style(Line_style(Line_style::dash, 3));
	
	Graph_lib::Polygon poly3;
	poly3.add(points[12]);
	poly3.add(points[13]);
	poly3.add(points[14]);
	poly3.add(points[15]);
	poly3.set_style(Line_style(Line_style::dashdot, 2));

	win.attach(poly);
	win.attach(poly1);
	win.attach(poly2);
	win.attach(poly3);
	win.wait_for_button();
}