#include "std_lib_facilities.h"

/*

Improve print_until_s() from §8.5.2. Test it. What makes a good set of
test cases? Give reasons. Then, write a print_until_ss() that prints until it
sees a second occurrence of its quit argument.

*/

vector <string> words = { "shit", "piss", "fuck", "cunt", "cocksucker", "quit", "motherfucker",  "tits" };
vector <string> words2 = { "bob", "quit", "motherfucker", "quit", "tits" };
const string quit = "quit";

void print_until_s(const vector<string>& v, const string quit){
	cout << "\nvector contains:\n";
	int counter = 0;
	for (string s : v) {
		if (s == quit) counter++;
		if (counter > 1) return;
		cout << s << '\n';
	}
}

int main() {
	print_until_s(words, quit);
	print_until_s(words2, quit);
}

