#include "lib/std_lib_facilities.h"

/*
 2. How many bytes are there in an int? In a double? In a bool? Do not use sizeof except to verify your answer.
*/

int main()
try {
    int* pia = new int[2];
    double* pda = new double[2];
    bool* pba = new bool[2];
    float* pfa = new float[2];
    string* pca = new string[2];

    cout << &pia[0] << "~~" << &pia[1] << "|" << endl;
    cout << &pda[0] << "~~" << &pda[1] << "|" << endl;
    cout << &pba[0] << "~~" << &pba[1] << "|" << endl;
    cout << &pfa[0] << "~~" << &pfa[1] << "|" << endl;
    cout << &pca[0] << "~~" << &pca[1] << "|" << endl;


    // 0x|562a87916e70~~0x|562a87916e74  ~~> 6e70 -> 6e74 = 4 bits  int
    // 0x|562a87916e90~~0x|562a87916e98  ~~> 6e90 -> 6e98 = 8 bits  double
    // 0x|562a87916eb0~~0x|562a87916eb1  ~~> 6eb0 -> 6eb1 = 1 bit   bool
    // 0x|55ea74d5aed0~~0x|55ea74d5aed4  ~~> aed0 -> aed4 = 4 bits  float
    // 0x|557ad1791ef8~~0x|557ad1791f18  ~~> 1ef8 -> 1f18 = 32 bits string

    cout << sizeof(int)<<endl;
    cout << sizeof(double)<<endl;
    cout << sizeof(bool)<<endl;
    cout << sizeof(float)<<endl;
    cout << sizeof(string)<<endl;
}

catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    keep_window_open();
}
catch (...) {
    cerr << "exception\n";
}