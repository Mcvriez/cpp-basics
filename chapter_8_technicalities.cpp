#include "std_lib_facilities.h"

int x = 7;
int y = 9;

const int cx = 7;
const int cy = 9;

double dx = 7.7;
double dy = 9.9;


/*

void swap_v(int a, int b) {
	int temp;
	temp = a, a = b;
	b = temp;
	cout << '\n' << a << " " << b << "\n\n";
	cout << '\n' << x << " " << y << "\n\n";

}

void swap_r(int& a, int& b) {
	int temp;
	temp = a; a = b;
	b = temp;
	cout << '\n' << a << " " << b << "\n\n";
	cout << '\n' << x << " " << y << "\n\n";
}


*/

void swap_cr(const int& a, const int& b) {
	int temp; temp = a, a = b;
	b = temp;
}

int main (){
	swap_cr(dx, dy);
	
}