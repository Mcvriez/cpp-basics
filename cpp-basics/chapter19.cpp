#include <iostream>

using namespace std;

//6. Repeat the previous exercise, but with a class Number<T> where T can be any numeric type. Try adding % to
//Number and see what happens when you try to use % for Number<double> and Number<int>.

template <typename T, typename std::enable_if<std::is_arithmetic<T>::value>::type* = nullptr>
struct Number {
    Number() : value {0} {std::cout << "default constructor called!\n";};
    explicit Number(T val): value {val} {std::cout << "constructor called!\n";};
    Number(const Number& n) {std::cout << "copy constructor called!\n"; value = n.value;}
    Number& operator= (const Number&n) {
        if (this == &n) return *this;
        std::cout << "copy assignment called!\n";
        value = n.value;
        return *this;}
    Number& operator+ (const Number&n) { value += n.value; return *this;}
    Number& operator- (const Number&n) { value -= n.value; return *this;}
    Number& operator* (const Number&n) { value *= n.value; return *this;}
    Number& operator/ (const Number&n) { value /= n.value; return *this;}
    Number& operator% (const Number&n) { value %= n.value; return *this;} // error: invalid operands of types ‘double’ and ‘double’ to binary ‘operator%’
    int val() const {return value;}
private:
    T value;
};

template <typename T>
ostream& operator << (ostream& os, const Number<T>& n) {os << n.val() << endl; return os;}

template <typename T>
istream& operator >> (istream& is, Number<T>& n) {T k; is >> k; if (is) n = Number<T> {k}; return is;}

int main()
try {
    const Number<int> k {11};
    Number<int> n;

    n = Number<int> {15};
    n = n % k;
    cout << n;

}
catch (exception& e) { cerr << "exception: " << e.what() << endl;}
catch (...) {cerr << "exception\n";}

