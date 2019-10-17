#include "std_lib_facilities.h"
/*

9. Split the binary I/O program from §11.3.2 into two: one program that converts an ordinary text file into binary and one
program that reads binary and converts it to text. Test these programs by comparing a text file with what you get by
converting it to binary and back.

*/

string source = "C:\\Users\\arcady\\source\\repos\\cpp-basics\\source.log";
string outbin = "C:\\Users\\arcady\\source\\repos\\cpp-basics\\binary.txt";
string frombin = "C:\\Users\\arcady\\source\\repos\\cpp-basics\\frombinary.txt";

void to_binary() {
	ifstream input{ source, ios_base::binary };
	if (!input) cout << "Can't open file " << source << endl;
	ofstream output{ outbin, ios_base::binary };
	if (!output) cout << "Can't open file " << outbin << endl;

	for (char x; input.read(as_bytes(x), sizeof(char)); ) {// note: reading bytes
		output.write(as_bytes(y), sizeof(char));
	}
}


void from_binary() {

	ifstream input{ outbin };
	if (!input) cout << "Can't open file " << outbin << endl;

	ofstream from_bin{ frombin, ios_base::binary };
	if (!from_bin) cout << "Can't open file " << frombin << endl;

	for (char x; input.read(as_bytes(x), sizeof(char));) {
		from_bin.write(as_bytes(x), sizeof(char));
	} 
}

int main() {

	try {
		to_binary();
		from_binary();
	}
		
	catch (exception& e) {
		cerr << "exception: " << e.what() << endl;
		return 1;
	}

}