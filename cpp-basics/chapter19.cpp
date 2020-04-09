//#include "lib/vector.h"
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

template<typename T>
struct S {
    explicit S(T value = T()) : val {std::move(value)} {}
    T& get() const;
    T& get();
    void set(T v);
    void operator=(const T&);
    void read_val(T& v);
private:
    T val;
};

//Bonus: Define input and output operators (>> and <<) for vector<T>s.
//For both input and output use a { val, val, val }
//format. That will allow read_val() to also handle the S<vector<int>> variable.

template<typename T>
T& S<T>::get() const {return val;}

template<typename T>
T &S<T>::get() {return val;}

template<typename T>
void S<T>::set(const T v) {val = v;}

//Replace set() with an S<T>::operator=(const T&). Hint: Much simpler than §19.2.5.
template<typename T>
void S<T>::operator=(const T& t) {val = t;}

//Define a function template<typename T> read_val(T& v) that reads from cin into v.
template <typename T>
void S<T>::read_val(T &v) {
    T x;
    cin >> x;
    val = x;
}

template<typename T>
istream& operator >> (istream& is, S <vector<T>>& sv) {
    char ch; T t;
    is >> ch;
    if (ch!= '{') return is;
    vector<T> nv;
    while (is >> t) {
        is.get(ch);
        nv.push_back(t);
        if (ch == '}') {for (auto x: nv) sv.get().push_back(x);}
        if (ch != ',') break;
    }
    return is;
}

template<typename T>
ostream& operator << (ostream& os, S <vector<T>>& sv) {
    char ch; T t;
    os << '{';
    for (int x = 0; x < sv.get().size(); ++ x){
        os << sv.get().at(x);
        if (sv.get().size() - 1 != x) os << ", ";
    }
    os << '}' << endl;
    return os;
}

int main()
try {
    // S<int>, S<char>, S<double>, S<string>, and S<vector<int>>
    S <int> sint(5);
    S <char> schar{'k'};
    S <double> sdouble;
    S <string> sstring {"easylife"};
    vector <int> somev {1, 2, 3, 12};
    S <vector<int>> svector(somev);
    S<vector <string>> svectors;
    vector <string> somevs {"alpha", "beta", "gamma"};
    svectors = somevs;

    // cout << sint.val << endl; cout << schar.val << endl; cout << sdouble.val << endl; cout << sstring.val << endl;
    // for (int x: svector.val) cout << x << '~';
    sdouble.set(11.1111); sint = 15;
    // cout << sint.get() << endl; cout << schar.get() << endl; cout << sdouble.get() << endl; cout << sstring.get() << endl;
    // string p; int l; double b; char ch;
    // sstring.read_val(p); schar.read_val(ch); sint.read_val(l); sdouble.read_val(b);
    // cout << sint.get() << endl; cout << schar.get() << endl; cout << sdouble.get() << endl; cout << sstring.get() << endl;
    //cin >> svector;
    //for (int x: svector.get()) cout << x << '~'; cout << endl;
    //cout << svector;

    cin >> svector; cout << svector;

}

catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}