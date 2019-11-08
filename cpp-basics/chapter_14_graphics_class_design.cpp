#include "Graph.h"
#include "Simple_window.h"
#include "std_lib_facilities.h"

/*

2. Try to copy a Shape. What happens?

Error	C2280	 'Graph_lib::Circle::Circle(const Graph_lib::Circle &)': attempting to reference a deleted function


3. Define an abstract class and try to define an object of that type. What happens?

Error	C2259	 'Abstract': cannot instantiate abstract class

*/

class Abstract {
public:
	virtual void f() = 0;
};


int main()
try {
	Point start{ 300, 300 };
	Simple_window win{ Point { 100, 100 }, 1000, 900, "Canvas" };
	Circle c { start , 100 };
	win.attach(c);
	win.wait_for_button();

	//Circle d = c;
	//Abstract aa;

}

catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
	keep_window_open();
}
catch (...) {
	cerr << "exception\n";
	
}