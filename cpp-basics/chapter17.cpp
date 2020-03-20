#include <iostream>
#include <vector>
#include <random>
using namespace std;

/*

9. Consider the memory layout in §17.4. 
Write a program that tells the order in which static storage, the stack, and the free store are laid out in memory. 
In which direction does the stack grow: upward toward higher addresses or downward toward lower addresses? 
In an array on the free store, are elements with higher indices allocated at higher or lower addresses?

*/

static long a, b, c, d, e, g;

void stack_grow(){
	int a, b, c, d, e, g, f, h, i, k;
	a = 10; g = 11; k = 12;
	if (&a > &k) {
		cout << "stack grows down" << endl;
	}
	else 
		cout << "stack grows up" << endl;
			cout << "-------------" << endl;}

void free_mem_grow(int k){
	int d = k / 10;
	int* last_p;
	srand (time(NULL));
	while(k!=0){
		--k;
		int* x = new int {rand() % 100};
		if (k % d == 0) {
			if (last_p < x){cout << x << " ↑↑\n";}
			else {cout << x << " ↓↓\n";}
		}
		last_p = x;
	}}


int main()
{
	&a > &g? cout << "static storage grows down\n" : cout << "static storage grows up\n";
	stack_grow();
	free_mem_grow(1000000);
}



