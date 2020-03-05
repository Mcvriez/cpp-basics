#include "lib/std_lib_facilities.h"

/*

8. Do exercise 7 again, but this time read into a std::string rather than to memory you put on the free store
(string knows how to use the free store for you).

*/


string read_from_s(istream &is) {
    cout << "Enter characters, '!' to escape" << endl;
    char ch;
    int i = 0;
    string arr;
    while(is.get(ch) && ch != '!'){
        ++i;
        arr.push_back(ch);
    }
    return arr;
}

int main()
try
{
    string ret = read_from_s(cin);
    int i = 0;
    while(ret[i]) {cout << ret[i] << "~"; ++i;}
    cout << endl << "-----------" << endl;

}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    }
catch (...) {
    cerr << "exception\n";
}

