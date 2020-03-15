#include <iostream>
#include <vector>
using namespace std;

/*
Array drill:
1. Define a global int array ga of ten ints initialized to 1, 2, 4, 8, 16, etc.
2. Define a function f() taking an int array argument and an int argument indicating the number of elements in the array.
3. In f():
    a. Define a local int array la of ten ints.
    b. Copy the values from ga into la.
    c. Print out the elements of la.
    d. Define a pointer p to int and initialize it with an array allocated on the free store with the same number of
    elements as the argument array.
    e. Copy the values from the argument array into the free-store array.
    f. Print out the elements of the free-store array.
    g. Deallocate the free-store array.
4. In main():
a. Call f() with ga as its argument.
b. Define an array aa with ten elements, and initialize it with the first ten factorial values (1, 2*1, 3*2*1, 4*3*2*1,etc.).
c. Call f() with aa as its argument.
*/

int ga[10] {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
void f(int a[], int size) {
    long la[size];
    for (int i = 0; i < size; ++i) {la[i] = a[i];}
    for (int i = 0; i < size; ++i) {cout << la[i] << endl;}
    long* p = new long[size];
    cout << "---------------\n";
    for (int i = 0; i < size; ++i) {p[i] = a[i];}
    int z = 0; while(z < size) {cout << p[z] << endl; ++z;}
    cout << "===============\n";
    delete[] p;
}
void drill_array(){
    f(ga, 10);
    int size = 15;
    int fa[size]; int fact = 1;
    for (int i = 0; i < size; ++i) {
        fact *= (i + 1);
        fa[i] = fact;
    }
    f(fa, size);
}
/*
 Standard library vector drill:
1. Define a global vector<int> gv; initialize it with ten ints, 1, 2, 4, 8, 16, etc.
2. Define a function f() taking a vector<int> argument.
3. In f():
a. Define a local vector<int> lv with the same number of elements as the argument vector.
b. Copy the values from gv into lv.
c. Print out the elements of lv.
d. Define a local vector<int> lv2; initialize it to be a copy of the argument vector.
e. Print out the elements of lv2.
4. In main():
a. Call f() with gv as its argument.
b. Define a vector<int> vv, and initialize it with the first ten factorial values (1, 2*1, 3*2*1, 4*3*2*1, etc.).
c. Call f() with vv as its argument.
 */

vector <int> gv {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
void f2(vector<int> vi){
    vector<int> lv (vi.size());
    for (int x = 0; x < vi.size(); ++x) {
        lv[x] = vi[x];
        cout << lv[x] << endl;
    }
    vector<int> lv2 = vi;
    for (int x: lv2) {cout << x << endl;}

}
void drill_vector(){
    f2(gv);
    int size = 11;
    vector<int> vv(size);
    int fact = 1;
    for (int i = 0; i < size; ++i) {fact *= (i + 1); vv[i] = fact;}
    f2(vv);
}

int main()
{
    drill_vector();
}


