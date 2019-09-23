#include "std_lib_facilities.h"

/*

1) Read five names into a vector<string> name, 
2) then prompt the user for the ages of the people named and store the ages in a vector<double> age.
3) Then print out the five ( name[i] , age[i] ) pairs.

4) Sort the names ( sort(name.begin(),name.end()) ) and print out the ( name[i] , age[i] ) pairs. 

The tricky part here is to get the age vector in the correct order to match the sorted
name vector. 
Hint: Before sorting name , take a copy and use that to make a copy of age in the right order after sorting name.

Then, do that exercise again but allowing an arbitrary number of names.

*/

vector <string> name;
vector <double> age;
const int sz = 5;

void print(const vector<string>& names, const vector <double>& ages) {
	cout << endl;
	for (int i = 0; i < names.size(); i++) {
		cout << names[i] << " is age of " << ages[i] << endl;
	}

}


void names_and_ages(vector<string>& names, vector <double>& ages, const int sz) {
	cout << "Enter names separated by whitespace or newline (you can enter x to stop at any time): \n";
	string input;
	// while (names.size() < sz && cin >> input && input != "x") {  <---- constant number of names
	while (cin >> input && input != "x" ) {
		names.push_back(input);
	}
	for (string name : names) {
		cout << "Enter age of " << name << ": ";
		double age;
		cin >> age;
		ages.push_back(age);
	}
}

void sort_names(vector<string>& names, vector <double>& ages) {
	cout << "\nSorting names..\n";
	// making copies:
	vector <string> copys;
	vector <double> copyd;
	for (string name : names) copys.push_back(name);
	for (double age : ages) copyd.push_back(age);
	
	sort(names.begin(), names.end());
	for (int i = 0; i < copys.size(); ++i) {
		for (int j = 0; j < copys.size(); ++j) {
			if (names[i] == copys[j]) {
				ages[i] = copyd[j];
			}
		}
	}
}


int main() {
	names_and_ages(name, age, sz);
	print(name, age);
	sort_names(name, age);
	print(name, age);
}

