#include "Graph.h"
#include "Simple_window.h"
#include "std_lib_facilities.h"

/*

4. Define a class Immobile_Circle, which is just like Circle but can’t be moved.

*/

class Immobile_Circle: public Circle {
	using Circle::Circle;
public:
	void move(int dx, int dy) {
		cout << "This is immobile circle. What exactly did you expect?" << endl;
	}

};


int main()
try {
	Point start{ 300, 300 };
	Simple_window win{ Point { 100, 100 }, 1000, 900, "Canvas" };
	Immobile_Circle c { start , 100 };
	win.attach(c);
	win.wait_for_button();
	
	c.move(200, 200);
	win.wait_for_button();


}

catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
	keep_window_open();
}
catch (...) {
	cerr << "exception\n";
	
}