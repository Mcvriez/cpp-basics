#include "std_lib_facilities.h"
/*
Write a program where you first enter a set of name-and-value pairs, such
as Joe 17 and Barbara 22 . For each pair, add the name to a vector called
names and the number to a vector called scores (in corresponding po-
sitions, so that if names[7]=="Joe" then scores[7]==17 ). Terminate input
with NoName 0 . Check that each name is unique and terminate with an
error message if a name is entered twice. Write out all the (name,score)
pairs, one per line.
Define a class Name_value that holds a string and a value. Rework exer-
cise 19 in Chapter 4 to use a vector<Name_value> instead of two vectors.
*/


class Name_value {
	public:
		string name;        
		double value;     
		Name_value()     
			:name(), value(0) { } 
		Name_value(string name, double val)     
			:name(name), value(val) { }
		bool is_unique(string testname);
};

vector <Name_value> names;

bool Name_value::is_unique(string testname){
			for (Name_value nv: names) {
				if (nv.name == testname) return false;
			}
		return true;
		}

void terminate(){
	cout << "Vector contains  following names:\n";
	for (Name_value nv: names){
		cout << nv.name << " " << nv.value << "\n";
	}
}

int main() {
	try
	{	
		cout << "Enter pairs of names and values. Each name should be unique. Enter NoName 0 to exit.\n";
		while (true)
		{
			Name_value nv;
			cin >> nv.name >> nv.value;
			if (nv.name == "NoName" && nv.value == 0){
				terminate();
				return 0;
			}
			if (nv.is_unique(nv.name)) {
				names.push_back(nv);
			}
			else {error("Name is not unique");}
		}
	}
	catch (exception& e) {
		cerr << "error: " << e.what() << '\n';
		keep_window_open();
		return 1;
	}
	catch (...) {
		cerr << "Oops: unknown exception!\n";
		keep_window_open();
		return 2;
	}
}

