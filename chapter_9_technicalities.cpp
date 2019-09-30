#include "std_lib_facilities.h"

/*
Look at the headache-inducing last example of §8.4. Indent it properly
and explain the meaning of each construct. Note that the example doesn’t
do anything meaningful; it is pure obfuscation.

*/


struct X {                                                                // structure X

	void f(int x) {                                                         // function f taking one argument x
		struct Y {                                                            // function f declares struct Y
			int f() { return 1; }                                               // function Y.f definition 
			int m;                                                              // int m declaration inside struct Y
		};
		int m;                                                                // int m declaration inside function f
		m = x;                                                                // argument of the function x is assigned to m, initialization
		Y m2;                                                                 // initialization of the variable m2 with type struct Y
		return f( m2.f() );                                                     // function f calls itself with return of m2.f(), which is 1
	}

	int m;                                                                  // int m declaration inside struct X
	void g(int m) {                                                         // function f declaration, taking argument int m inside struct X
		if (m) {
			f(m + 2);
		}
		else {
			g(m + 2);
		}
	}
	
	X()	{ }                                                                 // initializer of structure X
	
	void m3() {}

	void main() {
		X a; 
		a.f(2);
	}
};



int main() {
	try {

	}
	catch (exception& e) {
		cerr << "Error: " << e.what() << endl;
		return 1;
	}
}