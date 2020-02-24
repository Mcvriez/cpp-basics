//#include "Graph.h"
//#include "Simple_window.h"
//#include "std_lib_facilities.h"
#include<iostream>
#include<vector>
#include<list>
using namespace std;

/*

15. Most class hierarchies have nothing to do with graphics.
Define a class Iterator with a pure virtual function next() that returns a double* (see Chapter 17).

Now derive Vector_iterator and List_iterator from Iterator so that next()
 for a Vector_iterator yields a pointer to the next element of a vector<double> and
 List_iterator does the same for a list<double>.

You initialize a Vector_iterator with a vector<double> and the first call of next() yields a pointer
to its first element, if any. If there is no next element, return 0.
Test this by using a function void print(Iterator&) to print the elements of a vector<double> and a list<double>.

*/

// UNFINISHED - need to fix after chapter 17

std::vector<double> vd {12, 888, 43, 131, 4534.3, 777};
std::list<double> ld {11.101, 12, 13, 14, 2223, 16, 17.1717, 122.211};

class Iteratorx{ ;
public:
    virtual double* next() { double *x = nullptr; return x;}
};
void print(Iteratorx& it) {
    double* res = it.next();
    if (res != nullptr) cout << res << " ~~~~> " << *res << endl;
    else cout << "<nullptr>" << endl;
}
class Vector_iterator : public Iteratorx {
public:
    explicit Vector_iterator(std::vector<double>& va);
    double* next() override {
        cout << position << " ";
        if (position > size - 1 || size < 1) return nullptr;
        if (position > 0) pDouble += 1;
        ++position;
        cout << "???" << endl;
        return pDouble;
    }
private:
    double* pDouble;
    int position;
    int size;

};

Vector_iterator::Vector_iterator(std::vector<double> &va) : position {0} {
    size = va.size();
    cout  << size << endl;
    if (size > 0) {
        pDouble= &va[0];
    }
    cout << pDouble << " ----> " << *pDouble << endl;
    cout << "---------" << endl;
}

class List_iterator : public Iteratorx {
public:
    explicit List_iterator(std::list<double>& la) : position {0} {
        size = la.size();
        cout  << size << endl;
        if (size > 0) {
            pDouble= &la.front();
        }
    };

    double* next() override {
        if (position >= size || size < 1) return nullptr;
        if (position > 0) pDouble += 4;
        ++position;
        return pDouble;
    }
private:
    double* pDouble;
    int position;
    int size;
};



int main()
try {
    List_iterator test_v (ld);
    print(test_v);
    print(test_v);
    print(test_v);
    print(test_v);
    print(test_v);
    print(test_v);
    print(test_v);
    print(test_v);
    print(test_v);
    print(test_v);
    print(test_v);
    print(test_v);
    print(test_v);
    print(test_v);
    print(test_v);

}

catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
