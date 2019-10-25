#include "Graph.h"
#include "Simple_window.h"

/*

1. Make an 800-by-1000 Simple_window.
2. Put an 8-by-8 grid on the leftmost 800-by-800 part of that window (so that each square is 100 by 100).
3. Make the eight squares on the diagonal starting from the top left corner red (use Rectangle).

4. Find a 200-by-200-pixel image (JPEG or GIF) and place three copies of it on the grid (each image covering four
squares). If you can’t find an image that is exactly 200 by 200, use set_mask() to pick a 200-by-200 section of a larger
image. Don’t obscure the red squares.

5. Add a 100-by-100 image. Have it move around from square to square when you click the “Next” button. Just put
wait_for_button() in a loop with some code that picks a new square for your image.

*/

const string pic = "C:\\Users\\arcady\\Pictures\\peps.jpg";
const string pic_s = "C:\\Users\\arcady\\Pictures\\Shark3y.jpg"; 

int main()
try {
	Simple_window win{ Point { 100, 100 }, 1000, 800, "Canvas" };
	Vector_ref <Graph_lib::Rectangle> vr;
	Lines grid;
	
	int size = 100;
	int max = 800;
	int count = 8;
	
	for (int i = 0; i <= count; ++i) {
		grid.add(Point {size * i, 0}, Point{ size * i, max});
		grid.add(Point{ 0, size * i }, Point{ max, size * i });
	}
	win.attach(grid);
		
	
	for (int i = 0; i < count; ++i){
		vr.push_back(new Graph_lib::Rectangle{ Point{i * size, i * size }, size, size });
		vr[(vr.size() - 1)].set_fill_color(Color::dark_red);
		win.attach(vr[(vr.size() - 1)]);
		}
	Graph_lib::Image pic1({ 300, 500 }, pic);
	Graph_lib::Image pic2({ 500, 300 }, pic);
	Graph_lib::Image pic3({ 100, 300 }, pic);
	
	pic1.set_mask(Point{ 400, 400 }, 200, 200);
	pic2.set_mask(Point{ 600, 200 }, 200, 200);
	pic3.set_mask(Point{ 100, 500 }, 200, 200);
	win.attach(pic1); win.attach(pic2); win.attach(pic3);
	   	  
	while (true) {
		int x = rand() % 8;
		int y = rand() % 8;
		cout << x << ' ' << y << endl;
		Graph_lib::Image pic4({ x * 100, y * 100 }, pic_s);
		pic4.set_mask(Point{ 100, 100 }, 100, 100);
		win.attach(pic4);
		win.wait_for_button();
		win.detach(pic4);
	}
}

catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
	keep_window_open();
}
catch (...) {
	cerr << "exception\n";
	keep_window_open();
}