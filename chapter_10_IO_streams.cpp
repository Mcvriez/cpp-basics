#include "std_lib_facilities.h"

/*

Write a program that reads the data from raw_temps.txt created in exercise 2 into a vector and then calculates the
mean and median temperatures in your data set. Call this program temp_stats.cpp

*/

// const string input = "C:\\Users\\arcady\\source\\repos\\cpp-basics\\input.txt";
const string input = "C:\\Users\\arcady\\source\\repos\\cpp-basics\\raw_temps.txt";

struct Reading {
	Reading() : hour{ -1 }, temperature{ -1000000000 } {};
	Reading(int h, double t) : hour{ h }, temperature{ t } {};
	int hour;
	double temperature; // in Fahrenheit
};

// \t{'6': '4.43'},\n

ifstream& operator >> (ifstream& ifs, Reading& r){
	int i; double j;
	char ch1, ch2, ch3, ch4, ch5, ch6, ch7, ch8;
	ifs >> ch1 >> ch2 >> i >> ch3 >> ch4 >> ch5 >> j >> ch6 >> ch7 >> ch8;
	if (!ifs || ch1 != '{' || ch2 != '\'' || ch3 != '\'' || ch4 != ':' || ch5 != '\'' || ch6 != '\'' || ch7 != '}' || ch8 != ',') {
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
	cout << endl;
}

double mean(const vector<Reading>& v) {
	int sum = 0;
	for (Reading r : v) {
		sum += r.temperature;
	}
	return sum / v.size();
}

double median(const vector<Reading>& v) {
	vector <double> temps;
	for (Reading r : v) {
		temps.push_back(r.temperature);
	}
	sort(temps);
	if (temps.size() < 1) {
		cout << "Empty array" << endl; 
		return 0;
	}
	if (temps.size() == 1) {
		return temps[0];
	}
	if (temps.size() % 2) return temps[temps.size() / 2];
	double res = (temps[temps.size() / 2] + temps[temps.size() / 2 - 1]) / 2;
	return res;
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
		cout << "temperature mean: " << mean(results) << endl;
		cout << "temperature median: " << median(results) << endl;
	}
	catch (exception& e) {
		cerr << "Error: " << e.what() << endl;
	}
}