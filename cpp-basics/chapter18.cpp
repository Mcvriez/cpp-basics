#include <iostream>
#include <ctime>
#include "lib/Skiplist.h"
using namespace std;

/*
11. Look up (e.g., on the web) skip list and implement that kind of list. This is not an easy exercise.
*/


int main()
try
{
    srand (time(nullptr));
    Skiplist sl;

    //sl.add(10); sl.add(99999); sl.add(55555); sl.add(-15);
    int n = 10000000; n = 20;
    while(--n > 0) {sl.add(rand() % n * 10);}
    //cout << sl.find_verbose(99999) << endl << sl.find_verbose(55555) << endl << sl.find_verbose(-15) << endl;

    sl.print(); cout << endl; sl.erase(50); cout << endl;
    sl.print();
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}


