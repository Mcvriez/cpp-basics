#include <iostream>

using namespace std;

//5. Define a class Int having a single member of class int. Define constructors, assignment, and operators +, –, *, / for it.
//Test it, and improve its design as needed (e.g., define operators << and >> for convenient I/O).

struct Int {
    Int() : value(0) { };
    explicit Int(int val = 0): value {val} {std::cout << "constructor called!\n";};
    Int(const Int& n) {std::cout << "copy constructor called!\n"; value = n.value;}
    Int& operator= (const Int&n) {if (this == &n) return *this;
        std::cout << "copy assignment called!\n"; value = n.value; return *this;}
    Int& operator+ (const Int&n) {value += n.value; return *this;}
    Int& operator- (const Int&n) {value -= n.value; return *this;}
    Int& operator* (const Int&n) {value *= n.value; return *this;}
    Int& operator/ (const Int&n) {value /= n.value; return *this;}
    int val() const {return value;}
private:
    int value;
};

ostream& operator << (ostream& os, const Int& n) {os << n.val() << endl; return os;}
istream& operator >> (istream& is, Int& n) {int k; is >> k; if (is) n = Int {k}; return is;}

int main()
try {
    const Int k {11};
    Int n = k;
    n = Int {15};
    n = n - k;
    cout << n;
    cin >> n;
    cout << n;

}
catch (exception& e) { cerr << "exception: " << e.what() << endl;}
catch (...) {cerr << "exception\n";}

