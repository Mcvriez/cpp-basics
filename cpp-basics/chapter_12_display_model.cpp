#include "Graph.h"
#include "Simple_window.h"

void routine() {

	// 9. Display an image on the screen, e.g., a photo of a friend. Label the image both with a title on the window and with a caption in the window

	Point tl{ 100, 100 };
	Simple_window win{ tl, 440, 390, "Canvas" };

	string image = "C:\\Users\\arcady\\Pictures\\Shark3y.jpg";
	Image ii{ Point{20,70}, image }; 
	win.attach(ii);
	win.set_label("Excercise 9 - my friend");
	
	Text title{ Point{140,50}, "My frien Sharky" };
	title.set_font(Font::helvetica_bold);
	title.set_font_size(20);
	win.attach(title);

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