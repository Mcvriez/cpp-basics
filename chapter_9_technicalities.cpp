#include "std_lib_facilities.h"

/*
1 Design and implement a Name_pairs class holding (name,age) pairs where
name is a string and age is a double . 

2 Represent that as a vector<string> (called name) and a vector<double> (called age) member. 

3 Provide an input operation read_names() that reads a series of names. 

4 Provide a read_ages() operation that prompts the user for an age for each name. 

5 Provide a print() operation that prints out the ( name[i] , age[i] ) pairs (one per line)
in the order determined by the name vector. 

6 Provide a sort() operation that sorts the name vector in alphabetical order and reorganizes the age
vector to match. 

Implement all “operations” as member functions. Test the class (of course: test early and often).

*/


class Name_pairs
{
	public:
		Name_pairs();
	private:
		string name;
		double age;
};

Name_pairs::Name_pairs()
{
}



int main() {
	try {

		return 0;
	}
	catch (exception& e) {
		cerr << "Error: " << e.what() << endl;
		return 1;
	}
}