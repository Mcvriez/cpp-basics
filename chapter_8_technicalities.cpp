#include "std_lib_facilities.h"

/*
Write two functions that reverse the order of elements in a vector<int>.

For example:
1, 3, 5, 7, 9 becomes 9, 7, 5, 3, 1. 

The first reverse function should produce a new vector with the reversed sequence, 
leaving its original vector unchanged. 

The other reverse function should reverse the
elements of its vector without using any other vectors (hint: swap).

*/

vector <string> words = { "shit", "piss", "fuck", "cunt", "cocksucker", "motherfucker",  "tits" };
vector <string> reversed;

const string label = "Here comes the vector:\n";
const string label_r = "Here comes the reversed vector:\n";

void print(const string& s, const vector<string>& vv) {
	cout << s;
	for (string x : vv) cout << x << '\t';
	cout << "\n\n";
}

void fibonacci(int x, int y, vector<int>& vect, int n) {
	for (int i = 0; i < n; ++i) {
		if (i == 0) vect.push_back(x);
		else if (i == 1) vect.push_back(y);
		else vect.push_back(vect[i - 1] + vect[i - 2]);
	}
}

void reverse_1(const vector<string>& source, vector<string>& result) {
	for (int i = source.size() - 1; i >= 0; --i) { 
		result.push_back(source[i]); 
	}
}

void reverse_2(vector<string>& source) {
	int ss = source.size() - 1;
	for (int i = 0; i < ss ; ++i) {
		swap(source[i], source[ss]);
		--ss;
	}
}

int main() {
	print(label, words);
	reverse_1(words, reversed);
	print(label_r, reversed);

	reverse_2(reversed);
	print(label, reversed);
}

