#define _USE_MATH_DEFINES
#include "Graph.h"
#include "Simple_window.h"
#include<cmath>

/* 

11. Draw a series of regular polygons, one inside the other. 
The innermost should be an equilateral triangle, enclosed by a square, enclosed by a pentagon, etc.
For the mathematically adept only : let all the points of each N - polygon touch sides of the(N + 1) - polygon.
Hint : The trigonometric functions are found in <cmath>(§24.8, §B.9.2).

*/


int main()
{
	Simple_window win{ Point { 100, 100 }, 800, 640, "Canvas" };
	int n;
	int x = 400;
	int y = 320;
	int r;
	vector <Point> points;

	// -------------------- POLIGON -------------------- //

	r = 30;
	n = 3;
	for (int i = 0; i < n; i++) {
		points.push_back(Point{ int(x + r * cos(2 * M_PI * i / n)), int(y + r * sin(2 * M_PI * i / n) )});
		printf("%f %f\n", x + r * cos(2 * M_PI * i / n), y + r * sin(2 * M_PI * i / n));
	}
	Graph_lib::Polygon triangle;
	triangle.add(points[0]);
	triangle.add(points[1]);
	triangle.add(points[2]);
	points = {};
	win.attach(triangle);

	// -------------------- POLIGON -------------------- //

	r = 43;
	n = 4;
	for (int i = 0; i < n; i++) {
		points.push_back(Point{ int(x + r * cos(2 * M_PI * i / n)), int(y + r * sin(2 * M_PI * i / n)) });
		printf("%f %f\n", x + r * cos(2 * M_PI * i / n), y + r * sin(2 * M_PI * i / n));
	}
	Graph_lib::Polygon pol;
	pol.add(points[0]);
	pol.add(points[1]);
	pol.add(points[2]);
	pol.add(points[3]);
	points = {};
	win.attach(pol);

	// -------------------- POLIGON -------------------- //

	r = 60;
	n = 5;
	for (int i = 0; i < n; i++) {
		points.push_back(Point{ int(x + r * cos(2 * M_PI * i / n)), int(y + r * sin(2 * M_PI * i / n)) });
		printf("%f %f\n", x + r * cos(2 * M_PI * i / n), y + r * sin(2 * M_PI * i / n));
	}
	Graph_lib::Polygon pol1;
	pol1.add(points[0]);
	pol1.add(points[1]);
	pol1.add(points[2]);
	pol1.add(points[3]);
	pol1.add(points[4]);

	points = {};
	win.attach(pol1);


	// -------------------- POLIGON -------------------- //

	r = 70;
	n = 6;
	for (int i = 0; i < n; i++) {
		points.push_back(Point{ int(x + r * cos(2 * M_PI * i / n)), int(y + r * sin(2 * M_PI * i / n)) });
		printf("%f %f\n", x + r * cos(2 * M_PI * i / n), y + r * sin(2 * M_PI * i / n));
	}
	Graph_lib::Polygon pol2;
	pol2.add(points[0]);
	pol2.add(points[1]);
	pol2.add(points[2]);
	pol2.add(points[3]);
	pol2.add(points[4]);
	pol2.add(points[5]);

	points = {};
	win.attach(pol2);

	// -------------------- POLIGON -------------------- //

	r = 80;
	n = 7;
	for (int i = 0; i < n; i++) {
		points.push_back(Point{ int(x + r * cos(2 * M_PI * i / n)), int(y + r * sin(2 * M_PI * i / n)) });
		printf("%f %f\n", x + r * cos(2 * M_PI * i / n), y + r * sin(2 * M_PI * i / n));
	}
	Graph_lib::Polygon pol3;
	pol3.add(points[0]);
	pol3.add(points[1]);
	pol3.add(points[2]);
	pol3.add(points[3]);
	pol3.add(points[4]);
	pol3.add(points[5]);
	pol3.add(points[6]);

	points = {};
	win.attach(pol3);

	// -------------------- POLIGON -------------------- //

	r = 87;
	n = 8;
	for (int i = 0; i < n; i++) {
		points.push_back(Point{ int(x + r * cos(2 * M_PI * i / n)), int(y + r * sin(2 * M_PI * i / n)) });
		printf("%f %f\n", x + r * cos(2 * M_PI * i / n), y + r * sin(2 * M_PI * i / n));
	}
	Graph_lib::Polygon pol4;
	pol4.add(points[0]);
	pol4.add(points[1]);
	pol4.add(points[2]);
	pol4.add(points[3]);
	pol4.add(points[4]);
	pol4.add(points[5]);
	pol4.add(points[6]);
	pol4.add(points[7]);

	points = {};
	win.attach(pol4);

	// -------------------- POLIGON -------------------- //

	r = 95;
	n = 9;
	for (int i = 0; i < n; i++) {
		points.push_back(Point{ int(x + r * cos(2 * M_PI * i / n)), int(y + r * sin(2 * M_PI * i / n)) });
		printf("%f %f\n", x + r * cos(2 * M_PI * i / n), y + r * sin(2 * M_PI * i / n));
	}
	Graph_lib::Polygon pol5;
	pol5.add(points[0]);
	pol5.add(points[1]);
	pol5.add(points[2]);
	pol5.add(points[3]);
	pol5.add(points[4]);
	pol5.add(points[5]);
	pol5.add(points[6]);
	pol5.add(points[7]);
	pol5.add(points[8]);

	points = {};
	win.attach(pol5);

	// -------------------- POLIGON -------------------- //

	r = 100;
	n = 10;
	for (int i = 0; i < n; i++) {
		points.push_back(Point{ int(x + r * cos(2 * M_PI * i / n)), int(y + r * sin(2 * M_PI * i / n)) });
		printf("%f %f\n", x + r * cos(2 * M_PI * i / n), y + r * sin(2 * M_PI * i / n));
	}
	Graph_lib::Polygon pol6;
	pol6.add(points[0]);
	pol6.add(points[1]);
	pol6.add(points[2]);
	pol6.add(points[3]);
	pol6.add(points[4]);
	pol6.add(points[5]);
	pol6.add(points[6]);
	pol6.add(points[7]);
	pol6.add(points[8]);
	pol6.add(points[9]);

	points = {};
	win.attach(pol6);

	// -------------------- POLIGON -------------------- //

	r = 105;
	n = 11;
	for (int i = 0; i < n; i++) {
		points.push_back(Point{ int(x + r * cos(2 * M_PI * i / n)), int(y + r * sin(2 * M_PI * i / n)) });
		printf("%f %f\n", x + r * cos(2 * M_PI * i / n), y + r * sin(2 * M_PI * i / n));
	}
	Graph_lib::Polygon pol7;
	pol7.add(points[0]);
	pol7.add(points[1]);
	pol7.add(points[2]);
	pol7.add(points[3]);
	pol7.add(points[4]);
	pol7.add(points[5]);
	pol7.add(points[6]);
	pol7.add(points[7]);
	pol7.add(points[8]);
	pol7.add(points[9]);
	pol7.add(points[10]);

	points = {};
	win.attach(pol7);

	win.wait_for_button();
}