// Chapter 6 excercise 9
#include "std_lib_facilities.h"
#include <math.h> 

/*Write a program that reads digits and composes them into integers. For
example, 123 is read as the characters 1, 2, and 3. 

The program should
output 123 is 1 hundred and 2 tens and 3 ones . 

The number should be output as an int value. Handle numbers with one, two, three, or four
digits. Hint: To get the integer value 5 from the character '5' subtract '0' ,
that is, '5' � '0'==5 */

vector <char> chars;

void read() {
	cout << "Enter 1-4 digits ending with ;\n";
	int counter = 0;
	while (counter <= 4) {
		char ch;
		cin >> ch;
		if (!cin) error("reading error\n");
		if (ch == ';') break;
		if (counter == 4 && ch != ';') error("invalid input");
		chars.push_back(ch);
		++counter;
	}
}

void int_char() {
	int  number = 0;
	for (int i = 0; i < chars.size(); ++i){
		number += (chars[i] - '0') *  pow(10, chars.size() - i - 1);
	}
	cout << number << " is ";
	if (number > 999) cout << chars[0] << " thouthand " << chars[1] << " hundred " << chars[2] << " tens " << chars[3] << " ones.\n";
	else if (number > 99) cout << chars[0] << " hundred " << chars[1] << " tens " << chars[2] << " ones.\n";
	else if (number > 9) cout << chars[0] << " tens " << chars[1] << " ones.\n";
	else if (number > 0) cout << chars[0] << " ones.\n";
	cout << "\n\n";
	chars = {};
}

int main() {
	while (true){
		read();
		int_char();
	}
}