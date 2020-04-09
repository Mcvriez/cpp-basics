#include <iostream>
#include <vector>
using namespace std;


//1. Write a template function f() that adds the elements of one vector<T> to the elements of another; for example, f(v1,v2)
//should do v1[i]+=v2[i] for each element of v1.

template <typename T>
vector<T>& f(vector<T>& v1, const vector<T>& v2) {
    for (int i = 0; i < v1.size() && i < v2.size(); ++i) {
        v1[i] += v2[i];
    }
    return v1;
}

int main()
try {
    vector <int> v1 {1, 2, 4, 4};
    v1 = {1, 3};
    // v1 = {};
    vector <int> v2 {1, 2, 4};
    // v2 = {};
    f(v1, v2);
    for (int x: v1) cout << x << '-';
}

catch (exception& e) { cerr << "exception: " << e.what() << endl;}
catch (...) {cerr << "exception\n";}

