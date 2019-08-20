// Find mode (the number that appears most) in the array of strings
#include "std_lib_facilities.h"
#include <stdlib.h>
#include <time.h>

vector <string> strings = { "4BBXP6G381D3", "H05GEGTVZQ3M", "194RXOIBWZJN", "123", "LY4E8ITRM04S", "VHTI7KUBBVWH", "8RGX2VNC4UIY", "HZ4OPHZ3S5HG", "9Z39Q348AKK3", "JEASAMLBFLGJ", "3N5OOJB1369T", "123", "GHNXR6PLV9IZ", "5MFCE11U0G05", "123", "123", "abc", "abs", "asdfasdf", "asdfa", "sdf", "sadf", "asd", "fa", "sdf", "asd", "f", "asdf", "as", "df", "asd", "fw43", "wer", "s ", "werf", "sd", "f", "asdf", "asd", "f", "sadf", "sad", "fsa", "df", "sad", "f", "ag", "fg", "hj", "fgdh", "dfgs", "h", "sadfgs", "dfg", "g", "afdgdfg", "dfg", "sdf", "gh", "sgfhj", "ghd", "j", "gdhj", "gh", "j", "hk", "hn", "m", "vbm", "vbnm", "bvn", "m", "bvnm", "v", "nbm", "bvnm", "ytr", "rty", "sdfsh", };


string find_mode() {
	int max = 0;
	int current = 0;
	string mode = "";
	for (int index = 1; index < strings.size(); ++index) {
		if (strings[index] == strings[index - 1]) {
			++current;
		}
		else {
			current = 0;
		}
		if (current > max) {
			max = current;
			mode = strings[index];
		}
	}
	return mode;
}

int main() {
	sort(strings);
	cout << "test initialize:\n";
	for (string x : strings) {
		cout << x << ", ";
	}
	string mode = find_mode();
	cout << "\n\nMode string is: " << mode << " min is: " <<strings[0] << " max is: " << strings[strings.size() -1] <<".\n";
}       
