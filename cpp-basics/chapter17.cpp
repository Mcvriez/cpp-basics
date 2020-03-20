#include <iostream>
#include "lib/std_lib_facilities.h"
using namespace std;

/*
10. Look at the “array solution” to the palindrome problem in §18.7.2. 

Fix it to deal with long strings by 
- (a) reporting if an input string was too long and 
- (b) allowing an arbitrarily long string. 

Comment on the complexity of the two versions.
*/

bool is_palindrome(const char s[], int n)
{
	int first = 0;
	int last = n-1;
	while (first < last) {
		if (s[first]!=s[last]) return false;
		++first;
		--last;
	}
	return true;
}


istream& read_word(istream& is, char* buffer, int max)
{
	is.width(max);
	is >> buffer;
	return is;
}

void a10(int max) {
	for (char s[max]; read_word(cin, s, max); ) 
	{
		char buff = 0;
		cout << s << " is";
		if (!is_palindrome(s, strlen(s))) cout << " not";
		cout << " a palindrome\n";
		buff = cin.get();
		if (buff != 0 && buff != '\n' && buff != ' ') cout << "input string is longer than " << max << " characters!\n";
		cin.unget();
	}
}

istream& read_word_unlim(istream& is, char* &buffer)
{
	char read;
	int count = 0;
	char* a = new char[1];
	while(cin.get(read))
	{
		if (read == ' ' || read == '\n') break;
		a[count] = read;
		++count;
		char* backup = new char[count + 1];
		for (int i = 0; i < count; ++i) {backup[i] = a[i];}
		delete[] a;
		a = backup;
	}
	buffer = a; 
	return is;
}

void b10() {
	for (char* s; read_word_unlim(cin, s);) 
	{
		cout << s << " is";
		if (!is_palindrome(s, strlen(s))) cout << " not";
		cout << " a palindrome\n";
	}
}

int main()
{
	//a10(5);
	b10();
}



