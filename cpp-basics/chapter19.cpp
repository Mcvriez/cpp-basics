#include <iostream>
#include <vector>
using namespace std;


//3. Write a template class Pair that can hold a pair of values of any type.
// Use this to implement a simple symbol table like the one we used in the calculator (§7.8).

template <typename T, typename U>
struct Pair {
    T key;
    U value;
    explicit Pair(T p1 = T(), U p2 = U()) : key {p1}, value {p2} {};
};

template <typename T, typename U>
ostream& operator << (ostream& os, Pair<T,U>& p) {
    os << p.key << ":\t" << p.value << endl;
}

template <typename T>
void print (const vector<T>& v){
    for (T x: v) { cout << x;}
    cout << endl;
}


int main()
try {
    vector <Pair<string, char>> symbol_table;
    symbol_table.emplace_back("let", 'L');
    symbol_table.emplace_back("quit", 'Q');
    symbol_table.emplace_back("print", ';');
    symbol_table.emplace_back("number", '8');
    symbol_table.emplace_back("name", 'a');
    symbol_table.emplace_back("square", 'S');
    symbol_table.emplace_back("mod", 'M');
    symbol_table.emplace_back("power", 'P');
    symbol_table.emplace_back("const", 'C');
    symbol_table.emplace_back("help", 'H');
    print(symbol_table);


}

catch (exception& e) { cerr << "exception: " << e.what() << endl;}
catch (...) {cerr << "exception\n";}

