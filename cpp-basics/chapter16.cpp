#include "fltk_lib/Graph.h"
#include "fltk_lib/Simple_window.h"
#include "fltk_lib/std_lib_facilities.h"

/*

8. Provide a currency converter. Read the conversion rates from a file on startup. Enter an amount in an input window and
provide a way of selecting currencies to convert to and from (e.g., a pair of menus).

*/

istream& operator >> (istream& is, Currency& cc)
{
    string notion;
    char c1, c2, c3, c4;
    double gbp_rate;
    double eur_rate;
    double usd_rate;
    is >> notion >> c1 >> gbp_rate >> c2 >> eur_rate >> c3 >> usd_rate >> c4;
    if (!is || c1!= '{' || c2 != ',' || c3 != ',' || c4 != '}') return is;
    cc = Currency(notion, gbp_rate, eur_rate, usd_rate);
    return is;
}

void fill_from_file (Vector_ref <Currency>& rates, const string& path)
{
    ifstream ist(path.c_str());
    if (!ist) error("can't open input file ", path);
    Currency cc;
    while (ist >> cc) {
        if (cc.notion != "None")
            rates.push_back(new Currency {cc.notion, cc.gbp_rate, cc.eur_rate, cc.usd_rate});
    }
}

int main()
try {
    Point rootp(500,500);
    const string path = "/home/wq/CLionProjects/cpp-basics/cpp-basics/rates.txt";
    Vector_ref <Currency> rates;
    fill_from_file(rates, path);

    Currency_window win {rootp, 500, 200, "Custom Window", rates};
    return gui_main();

}

catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    keep_window_open();
}
catch (...) {
    cerr << "exception\n";
}