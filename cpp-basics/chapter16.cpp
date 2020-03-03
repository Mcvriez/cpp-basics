#include "fltk_lib/Graph.h"
#include "fltk_lib/Simple_window.h"
#include "fltk_lib/std_lib_facilities.h"
#include "calc.h"

/*

9. Modify the calculator from Chapter 7 to get its input from an input box and return its results in an output box.

*/

struct Calc: public Graph_lib::Window {
    Calc(Point p, int w, int h, const string& title);
private:
    Button result_button;
    Button quit_button;

    In_box amount_input;
    Out_box result_output;

    void quit() { hide();}
    void calculate();

    static void cb_result(Address, Address pw) { reference_to<Calc>(pw).calculate();};
    static void cb_quit(Address, Address pw) {reference_to<Calc>(pw).quit();};
};

Calc::Calc(Point p, int w, int h, const string &title)
    : Window(p, w, h, title),
      result_button {Point{x_max()-150,0},70,20,"Calculate", cb_result},
      quit_button   {Point(x_max()-70,0),70,20,"Quit", cb_quit},
      amount_input  {Point{70, 0}, 150, 20, "Expression"},
      result_output {Point{70, 25}, 50, 20, "Result:"}
{
    attach(quit_button);
    attach(result_button);
    attach(amount_input);
    attach(result_output);
    result_output.put("");

}

void Calc::calculate() {
    string expression = amount_input.get_string();
    Calc_lib::Calculator cc;
    string result;
    result = cc.calculate(expression);
    result_output.put(result);
}


int main()
try {
    Point rootp(500,500);
    Calc win {rootp, 500, 200, "Custom Window"};
    return gui_main();


}

catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    keep_window_open();
}
catch (...) {
    cerr << "exception\n";
}