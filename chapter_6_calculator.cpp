// Chapter 6 excercise 9
#include "std_lib_facilities.h"
#include <math.h> 

/*Write a program that reads digits and composes them into integers. For
example, 123 is read as the characters 1, 2, and 3. The program should
output 123 is 1 hundred and 2 tens and 3 ones . The number should be
output as an int value. Handle numbers with one, two, three, or four
digits. Hint: To get the integer value 5 from the character '5' subtract '0' ,
that is, '5' – '0'==5 */

vector <char> chars;

void read() {
	cout << "Enter 1-4 digits ending with ;\n";
	int counter = 4;
	while (counter >= 0) {
		char ch;
		cin >> ch;
		if (!cin) error("reading error\n");
		if (ch == ';') break;
		chars.push_back(ch);
		if (counter == 0 && ch != ';') error("invalid input");
		--counter;
	}
}

void int_char() {
	int number = 0;
	for (int i = chars.size() - 1; i >= 0; --i) {
		int value = (chars[i] - '0') * pow(10, 3 - i);
		number += value;
	}
	cout << number 
}

int main() {}