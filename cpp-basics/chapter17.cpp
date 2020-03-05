#include "lib/std_lib_facilities.h"

/*

7. Write a program that reads characters from cin into an array that you allocate on the free store.
Read individual characters until an exclamation mark (!) is entered.
Do not use a std::string. Do not worry about memory exhaustion.

*/

vector<char*> expired;

char* temp (char* prev_arr_p, int size, char last){
    char* temp_arr = new char[size + 1];
    int i = 0;
    if (prev_arr_p) {
        while(prev_arr_p[i])
            {temp_arr[i] = prev_arr_p[i]; ++i;}

        temp_arr[i] = last;
        temp_arr[i + 1] = char(0);
        expired.push_back(prev_arr_p);
        delete[] prev_arr_p;
    }
    else temp_arr[0] = last;
    return temp_arr;
}


char* read_from(istream &is) {
    cout << "Enter characters, '!' to escape" << endl;
    char ch;
    int i = 0;
    char* pch = nullptr;
    while(is.get(ch) && ch != '!'){
        ++i;
        pch = temp(pch, i, ch);
    }
    return pch;
}


int main()
try
{
    char* ret = read_from(cin);
    int i = 0;
    while(ret[i]) {cout << ret[i] << "~"; ++i;}
    cout << endl << "-----------" << endl;

    // checking garbage
    for (char* x: expired){
        int j = 0;
        if (x) {
            while(x[j]) {
            cout << x[j];
            ++j;
            }
            cout << endl;
        }
    }
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    cout << expired.size();
}
catch (...) {
    cerr << "exception\n";
}

