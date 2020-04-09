#include <iostream>
#include <vector>
using namespace std;


//2. Write a template function that takes a vector<T> vt and a vector<U> vu as arguments and returns the sum of all
//vt[i]*vu[i]s.

template <typename T, typename U>
double f(const vector<T>& v1, const vector<U>& v2) {
    double k = 0;
    for (int i = 0; i < v1.size() && i < v2.size(); ++i) {
        k += v1[i] * v2[i];
    }
    return k;
}

template <typename T>
void print (const vector<T>& v){
    for (T x: v) { cout << x << ' ';}
    cout << endl;
}


int main()
try {
    vector <int> v1 {12, 342, 54, 12};
    vector <char> v12 = {'a', 'b', 'c'};
    vector <double> v2 {1.1, 2.1, 4.4, 12};
    double r = f(v1, v2); cout << r << endl;
    double r2 = f(v12, v2); cout << r2 << endl;
}

catch (exception& e) { cerr << "exception: " << e.what() << endl;}
catch (...) {cerr << "exception\n";}

