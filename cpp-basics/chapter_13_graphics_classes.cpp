// #include "Graph.h"
// #include "Simple_window.h"
#include "std_lib_facilities.h"
/*

drill ch 14 

1. Define a class B1 with a virtual function vf() and a non-virtual function f(). 
	Define both of these functions within class B1. 
	Implement each function to output its name (e.g., B1::vf()). 
	Make the functions public. 
	Make a B1 object and call each function.

2. Derive a class D1 from B1 and override vf(). 
	Make a D1 object and call vf() and f() for it.

3. Define a reference to B1 (a B1&) and initialize that to the D1 object you just defined. 
	Call vf() and f() for that reference.

4. Now define a function called f() for D1 and repeat 1–3. 
	Explain the results.

5. Add a pure virtual function called pvf() to B1 and try to repeat 1–4. 
	Explain the result.

6. Define a class D2 derived from D1 and override pvf() in D2. 
	Make an object of class D2 and invoke f(), vf(), and pvf() for it.

7. Define a class B2 with a pure virtual function pvf(). 
	Define a class D21 with a string data member and a member function that overrides pvf(); 
	D21::pvf() should output the value of the string. 
	Define a class D22 that is just like D21 except that its data member is an int. 
	Define a function f() that takes a B2& argument and calls pvf() for its argument.
	Call f() with a D21 and a D22

*/

// 1
class B1 {
public:
	virtual void vf() const { cout << "B1::vf()" << endl; }
	void f() const { cout << "B1::f()" << endl; }
	// virtual void pvf() const = 0; // 5
};

// 2
class D1 : public B1 {
public:
	void vf() const override { cout << "D1::vf()" << endl; }
	void const f() { cout << "D1::f()" << endl; }
};

class D2 : public D1 {
public:
	void pvf() const { cout << "D2::pvf()" << endl; }
};



class B2 {
public:
	virtual void pvf() const = 0; // 5
};


class D21 : public B2 {
public:
	void pvf() const override { cout << name << endl; };
	string name{"subclass D21 from superclass B2"};
};

class D22 : public B2 {
public:
	void pvf() const override { cout << name << endl; };
	int name{ 1337 };
};

void f(B2& b) {
	b.pvf();
}


int main()
try {
	//comment virtual void const pvf() = 0; // 5 to work

	
	B1 bobj;
	bobj.vf();
	bobj.f();
	cout << endl;

	D1 dobj;
	dobj.vf();
	dobj.f();
	cout << endl;
	
	B1& ref = dobj; // 3
	ref.vf();
	ref.f();
	cout << endl;
	

	D2 d2obj;
	d2obj.pvf();
	d2obj.vf();
	d2obj.f();
	cout << endl;


	D21 d210bj;
	D22 d220bj;

	f(d210bj);
	f(d220bj);

	keep_window_open();
}

catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
	keep_window_open();
}
catch (...) {
	cerr << "exception\n";
	
}