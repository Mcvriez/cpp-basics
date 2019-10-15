#include "std_lib_facilities.h"
/*

4. Write a program called multi_input.cpp that prompts the user to enter several integers in any combination of octal,
decimal, or hexadecimal, using the 0 and 0x base suffixes; interprets the numbers correctly; and converts them to decimal
form. Then your program should output the values in properly spaced columns like this:

0x43 hexadecimal converts to 67 decimal
0123 octal converts to 83 decimal
65 decimal converts to 65 decima

*/

int counter = 3;
vector <int> vault;
vector <int> type_vault;

int main() {

	try {
		cin.unsetf(ios::dec); // don’t assume decimal (so that 0x can mean hex)
		cin.unsetf(ios::oct); // don’t assume octal (so that 12 can mean twelve)
		cin.unsetf(ios::hex); // don’t assume hexadecimal (so that 12 can mean twelve)
		cout << "Enter " << counter << " numbers. You should use correct prefixes for hexadecimal ('0x') and hex ('0') numbers" << endl;
		while (counter) {
			--counter;
			int number;
			char ch;
			char ch1;
			int base = 10;

			cin.get(ch);
				if (ch == '0') {
					cin.get(ch1);
					cin.putback(ch1);
					if (ch1 == 'x') { base = 16; }
					else { base = 8; }	
				}
			cin.putback(ch);
			
			cin >> number;
			cin.get(ch); // to clear the newline or whitespace
			if (cin){
				vault.push_back(number);
				type_vault.push_back(base);
			}
		}
		for (int i = 0; i < vault.size(); ++i) {
			switch (type_vault[i]) {
			case 16: {
				cout << showbase << hex << vault[i] << " hexadecimal ";
				break; }
			case 8: {
				cout << showbase << oct << vault[i] << " octal ";
				break; }
			case 10: {
				cout << showbase << dec << vault[i] << " decimal ";
				break; }
			}		
			cout << "converts to " << dec << vault[i] << " decimal" << endl;
		}	
	}
		
	catch (exception& e) {
		cerr << "exception: " << e.what() << endl;
		return 1;
	}

}