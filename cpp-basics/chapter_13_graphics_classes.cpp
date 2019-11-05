#include "Graph.h"
#include "Simple_window.h"

/*

For each “define a class” exercise, display a couple of objects of the class to demonstrate that they work.

18. Define a class Poly that represents a polygon but checks that its points really do make a polygon in its constructor. Hint:
You’ll have to supply the points to the constructor.

*/



int main()
try {

	Simple_window win{ Point { 100, 100 }, 1000, 900, "Canvas" };
	Poly xpoly{ {100, 100}, {200, 100}, {100, 200 }, {200, 200} };

	win.attach(xpoly);
	win.wait_for_button();

}

catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
	keep_window_open();
}
catch (...) {
	cerr << "exception\n";
	
}