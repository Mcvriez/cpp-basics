#include "lib/std_lib_facilities.h"

/*
1. Allocate an array of ten ints on the free store using new.
2. Print the values of the ten ints to cout.
3. Deallocate the array (using delete[]).
4. Write a function print_array10(ostream& os, int* a) that prints out the values of a (assumed to have ten elements) to
os.
5. Allocate an array of ten ints on the free store; initialize it with the values 100, 101, 102, etc.; and print out its values.
6. Allocate an array of 11 ints on the free store; initialize it with the values 100, 101, 102, etc.; and print out its values.
7. Write a function print_array(ostream& os, int* a, int n) that prints out the values of a (assumed to have n elements)
to os.
8. Allocate an array of 20 ints on the free store; initialize it with the values 100, 101, 102, etc.; and print out its values.
9. Did you remember to delete the arrays? (If not, do it.)
10. Do 5, 6, and 8 using a vector instead of an array and a print_vector() instead of print_array().


1. Allocate an int, initialize it to 7, and assign its address to a variable p1.
2. Print out the value of p1 and of the int it points to.
3. Allocate an array of seven ints; initialize it to 1, 2, 4, 8, etc.; and assign its address to a variable p2.
4. Print out the value of p2 and of the array it points to.
5. Declare an int* called p3 and initialize it with p2.
6. Assign p1 to p2.
7. Assign p3 to p2.
8. Print out the values of p1 and p2 and of what they point to.
9. Deallocate all the memory you allocated from the free store.
10. Allocate an array of ten ints; initialize it to 1, 2, 4, 8, etc.; and assign its address to a variable p1.
11. Allocate an array of ten ints, and assign its address to a variable p2.
12. Copy the values from the array pointed to by p1 into the array pointed to by p2.
13. Repeat 10–12 using a vector rather than an array.
 */

void drill() {
    int* array_of_ten = new int[10];
    for(int i = 0; i < 10; ++i){
        cout << i << "~" << array_of_ten[i] << endl;
    }
    delete[] array_of_ten;
}
void print_array (ostream& os, int* a, int size) {
    for(int i = 0; i < size; ++i){
        os << i << " ~> " << a[i] << endl;
    }
}
void print_vector (ostream& os, const vector<int>& v) {
    for(int i = 0; i < v.size(); ++i){
        os << i << " ~> " << v[i] << endl;
    }
}
void drill2() {
    int x; x = 7; int* p1 = &x;
    cout << *p1 << " <~~ " << p1 << endl;
    int* p2 = new int[7] {1, 2, 4, 8, 16, 32, 64};
    cout << *p2 << " <~~ " << p2 << endl;
    int* p3 {p2};
    p2 = p1;
    p2 = p3;

    cout << *p1 << " <~~ " << p1 << endl;
    cout << *p2 << " <~~ " << p2 << endl;
    delete[] p2;
    p1 = new int[10] {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
    p2 = new int[10];
    //for (int i = 0; i < 10; ++i){if (p1[i]) p2[i] = p1[i];}
    //for (int i = 0; i < 10; ++i){cout << p2[i] << endl;}

    vector <int> v1 = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
    vector <int> v2(10);
    vector<int>* pv1 = &v1;
    vector<int>* pv2 = &v2;
    for (int i = 0; i < 10; ++i){
        (*pv2)[i] = (*pv1)[i];
    }
    for (int i = 0; i < 10; ++i){cout << v2[i] << endl;}


}

int main()
try {

    drill();
    int* a10 = new int[10] {100, 101, 102, 103, 104, 105, 106, 107, 108, 109};
    int* a11 = new int[11] {100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110};
    int* a20 = new int[20] {100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112,113, 114, 115, 116, 117, 118, 119};
    vector<int> v10 =  {100, 101, 102, 103, 104, 105, 106, 107, 108, 109};
    vector<int> v11 = {100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110};
    vector<int> v20 = {100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112,113, 114, 115, 116, 117, 118, 119};
    print_array(cout, a10, 10); //print_array(cout, a11, 11); print_array(cout, a20, 20);
    delete[] a10; delete[] a11; delete[] a20;
    print_vector(cout, v10); // print_vector(cout, v11); // print_vector(cout, v20);

    drill2();


}

catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    keep_window_open();
}
catch (...) {
    cerr << "exception\n";
}