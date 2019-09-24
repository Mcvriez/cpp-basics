#include "std_lib_facilities.h"

/*

Write a function that takes a vector<string> argument and returns a
vector<int> containing the number of characters in each string . Also
find the longest and the shortest string and the lexicographically first and
last string . How many separate functions would you use for these tasks?
Why?

*/

vector <string> words = { "shit", "piss", "fuck", "cunt", "cocksucker", "quit",  "tits" , "lol"};
vector <string> words2 = { "bob", "quit", "motherfucker", "quit", "tits", "bitch", "0", "00", "zed"};

void print_i(const vector<int>& v){
	cout << "vector contains:" << endl;
	for (int i : v) {
		cout << i << '\t';
	}
	cout << endl<<endl;
}

void print_s(const vector<string>& v) {
	cout << "vector contains:" << endl;
	for (string i : v) {
		cout << i << '\t';
	}
	cout << endl << endl;
}


void print_s_sized(const vector<string>& v, int size) {
	for (string s : v) {
		if (s.size() == size)
		cout << s << '\t';
	}
	cout << endl << endl;
}

vector <int> char_calc(const vector <string>& vs) {
	vector <int> v;
	for (string s : vs) {
		int x = s.size();
		v.push_back(x);
	}
	return v;
}

void sort_ints(vector <int>& vi) {
	sort(vi.begin(), vi.end());
}

void sort_strings(vector <string>& vs) {
	sort(vs.begin(), vs.end());
}

void compiled(vector <string> vs) {
	int size = vs.size();
	if (size == 0) { cout << "Vector is empty"; return; }
	
	print_s(vs);
	vector <int> lengths = char_calc(vs);
	print_i(lengths);
	
	sort_ints(lengths);
	int min = lengths[0];
	int max = lengths[size - 1];
	cout << "Smallest word(s):\n";
	print_s_sized(vs, min);
	cout << "Largest word(s):\n";
	print_s_sized(vs, max);
	
	sort_strings(vs);
	cout << "Sorted ";
	print_s(vs);
	cout << "Lexicographically first: " << vs[0] << endl;
	cout << "Lexicographically last: " << vs[size - 1] << endl;

}

int main() {
	compiled(words);
	compiled(words2);
}

