#include <iostream>
#include <unistd.h>
#include <algorithm>
//#include <vector>
//#include "lib/std_lib_facilities.h"
using namespace std;

void sleep() {
    constexpr int sleeptime = 2000000;
    cout << "----------------------\n";
    usleep(sleeptime);
}
struct X {
    int val;
    void out(const string& s, int nv) { cerr << "v: " << val << "->"<< nv << " " << s << "\t<- " << this << endl; }
    X(){ out("\tX()\tconstructor",0); val=0; }
    explicit X(int v) { val=v; out( "\tX(int)\tconstructor", v); }
    X(const X& x){ val=x.val; out("\tX(X&)\tcopy constr",x.val); }
    X& operator = (const X& a) { out("\tX::operator = ()",a.val); val=a.val; return *this; }
    ~X() { out("\t~X()\tdestructor",0); }
};
X copy(X a) { return a; }
X copy2(X a) { X aa = a; return aa; }
X& ref_to(X& a) { return a; }
X* make(int i) { X a(i); return new X(a); }
struct XX { X a; X b; };

void try_this1() {
    //X glob(9108);
    //X loc{4};
    // X loc2  = loc; loc2.val = 10;
    //loc.val = 7;
    // loc = X{5};
    // loc2 = copy(loc);
    // loc2 = copy2(loc);
    // X loc3 {6};
    // X& r = ref_to(loc);
    // X* m = make(7); delete m;
    // vector <X> v (2);
    // XX loc4;
    // X* p = new X{9};
    X* pp = new X[2];
    sleep();
    // delete p;
    delete[] pp;
}
void try_this2(){
    class vector {
        int sz;
        double* elem;
    public:
        explicit vector(int s) : sz(s),elem(new double[s])
        {
            for (int i = 0; i<s; ++i) elem[i] = 0;
        }
        double operator[](int i) { return elem[i]; }
    };

    vector v(10);
    double x = v[2];
    cout << x;
    //v[3] = x;
}



int main()
{


    gods();


