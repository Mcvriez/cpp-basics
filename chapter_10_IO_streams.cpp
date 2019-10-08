#include "std_lib_facilities.h"

/*

Write a program that creates a file of data in the form of the temperature Reading type defined in §10.5. For testing, fill
the file with at least 50 “temperature readings.” Call this program store_temps.cpp and the file it creates
raw_temps.txt

*/

const string input = "C:\\Users\\arcady\\source\\repos\\cpp-basics\\input.txt";
const string output = "C:\\Users\\arcady\\source\\repos\\cpp-basics\\raw_temps.txt";

struct Reading {
	Reading() : hour{ -1 }, temperature{ -1000000000 } {};
	Reading(int h, double t) : hour{ h }, temperature{ t } {};
	int hour;
	double temperature; // in Fahrenheit
};


ifstream& operator >> (ifstream& ifs, Reading& r){
	int i; double j;
	ifs >> i >> j;
	if (!ifs) {
		if (ifs.eof()) return ifs;
		else {
			ifs.clear();
			string bad;
			char ch;
			while (ifs.get(ch) && ch != '\n') { bad += ch; }
			cout << "Reading error: " << bad << endl;
			return ifs;
		}
	}
	else { r.hour = i;  r.temperature = j; }
	return ifs;
}

ofstream& operator << (ofstream& ofs, Reading& r) {
	ofs << "\t{'" << r.hour << "': '" << r.temperature << "'},\n";
	return ofs;
}

void print_v(const vector<Reading>& v) {
	for (Reading r : v) {
		cout << '[' << r.hour << "->" << r.temperature << "], ";
	}
}


int main() {
	try {
		ifstream ist{ input };
		if (!ist) error("can't open input file", input);
		ist.exceptions(ist.exceptions() | ios_base::badbit);
		vector <Reading> results;
		while (true) {
			Reading r{};
			if (!(ist >> r)) break;
			if (r.hour != -1) results.push_back(r);
		}
		print_v(results);
		ofstream ost{ output }; 
		if (!ost) error("can't open output file ", output);
		ost << "'temperatures': {\n";
		for (Reading r : results)
			ost << r;
		ost << "};";
	}
	catch (exception& e) {
		cerr << "Error: " << e.what() << endl;
	}
}