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
// Year(int x) : y{ x } { if (x < min || max <= x) throw Invalid{}; }

class Name_pairs
{
	public:
		Name_pairs(istream& input, ostream& output, int ms) : is{ input }, os{ output }, max_size { ms } {};
		void read_names();
		void read_ages();
		void print();
		void sort();
	private:
		istream& is; 
		ostream& os;
		int max_size;
		vector <string> names;
		vector <double> ages;
};

void Name_pairs::read_names() {
	string name;
	os << "Enter names separated by whitespace or newlines. Maximum " << max_size << " names.\nPress X to stop prematurely." << endl;
	while (names.size() < max_size && is >> name && name != "X") {
		names.push_back(name);
	}
};

void Name_pairs::read_ages() {
	double age;
	int s = names.size();
	if (s < 1) {
		os << "Names vector is empty." << endl; 
		return;
	}
	os << "Enter ages for the each name." << endl;
	for (int i = 0; i < s; ++i) {
		os << names[i] << ": "; 
		if (is >> age) {
			ages.push_back(age);
			if (ages.size() == s) return;
		}
		else  error("Invalid input - age");
	}
};

void Name_pairs::print() {
	os << endl << "names and ages:" << endl;
	if (!names.size() || !ages.size() || ages.size() != names.size()) {
		os << "Namepairs object is empty or corrupted." << endl;
		return;
	}
		for (int i = 0; i < names.size(); ++i) {
		os << names[i] << ": " << ages[i] << '\t';
	}
	os << endl;
}


void Name_pairs::sort() {
	os << "\nsorting names.." << endl;
	if (!names.size() || !ages.size() || ages.size() != names.size()) {
		os << "Namepairs object is empty or corrupted." << endl;
		return;
	}
	vector <string> copys;
	vector <double> copyd;

	for (string name : names) copys.push_back(name);
	for (double age : ages) copyd.push_back(age);
	
	std::sort(names.begin(), names.end());
	
	for (int i = 0; i < copys.size(); ++i) {
		for (int j = 0; j < copys.size(); ++j) {
			if (names[i] == copys[j]) ages[i] = copyd[j];
		}
	}
}


int routine (Name_pairs np) {
	np.read_names();
	np.read_ages();
	np.print();
	np.sort();
	np.print();
	return 0;
}

const int big_size = 2;

int main() {
	try {
		Name_pairs np(cin, cout, big_size);
		routine(np);
		Name_pairs np2(cin, cout, big_size);
		routine(np2);
	}
	catch (exception& e) {
		cerr << "Error: " << e.what() << endl;
		return 1;
	}
}