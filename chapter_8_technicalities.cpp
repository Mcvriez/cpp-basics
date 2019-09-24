#include "std_lib_facilities.h"

/*
Can we declare a non-reference function argument const e.g., 

void f(const int); ? 

What might that mean? Why might we want to do that?
Why don’t people do that often? Try it; write a couple of small programs
to see what works.

Answer:
Only reason I can think of is when people want to use some constant in the function without risk of occasional overwriting it.
Like Pi.

*/

vector <string> words = { "shit", "piss", "fuck", "cunt", "cocksucker", "quit",  "tits" , "lol"};
vector <string> words2 = { "bob", "quit", "motherfucker", "quit", "tits", "bitch", "0", "00", "zed"};


void f(const int ci) {
	cout << ci << endl;
}

int main() {
	
}

