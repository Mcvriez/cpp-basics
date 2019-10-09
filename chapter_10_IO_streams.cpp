#include "std_lib_facilities.h"

/*

Modify the store_temps.cpp program from exercise 2 to include a temperature suffix c for Celsius or f for Fahrenheit
temperatures. Then modify the temp_stats.cpp program to test each temperature, converting the Celsius readings to
Fahrenheit before putting them into the vector.

*/

const string raw_input = "C:\\Users\\arcady\\source\\repos\\cpp-basics\\raw_input.txt";
const string structured_temps = "C:\\Users\\arcady\\source\\repos\\cpp-basics\\structured_temps.txt";

struct Reading {
	Reading() : hour{ -1 }, temperature{ -1000000000 }, type{ 'C' }{};
	Reading(int h, double t, char cf) : hour{ h }, temperature{ t }, type{ cf } {};
	int hour;
	double temperature; 
	char type;
};

struct RawReading {
	RawReading() : hour{ -1 }, temperature{ -1000000000 }, type {'C'}{};
	RawReading(int h, double t, char cf) : hour{ h }, temperature{ t }, type{ cf } {
		if ((cf != 'C' && cf != 'F') || hour < 0 || hour > 23 || temperature < -500 || temperature > 1000) {
			hour = -1; // indicates corrupted reading
		}
	};
	int hour;
	double temperature; 
	char type;
};


ostream& operator << (ostream& ofs, Reading& r) {
	ofs << r.hour << " -> " << r.temperature << " -> '" << r.type << "'\n";
	return ofs;
}

ofstream& operator << (ofstream& ofs, RawReading& r) {
	// {6: 4.43: 'F'},
	ofs << "{" << r.hour << ": " << r.temperature << ": '" << r.type << "'}," << endl;
	return ofs;
}

ostream& operator << (ostream& ofs, RawReading& r) {
	// {6: 4.43: 'F'},
	ofs << "{" << r.hour << ": " << r.temperature << ": '" << r.type << "'},\n";
	return ofs;
}

ifstream& operator >> (ifstream& ifs, Reading& r){
	// {5: 3.26 : 'F'},   <- line example
	int i; double j; char cf;
	char ch1, ch2, ch3, ch4, ch5, ch6, ch7;
	ifs >> ch1 >> i >> ch2 >> j >> ch3 >> ch4 >> cf >> ch5 >> ch6 >> ch7;
	if (!ifs || ch1 != '{' || ch2 != ':' || ch3 != ':' || ch4 != '\'' || ch5 != '\'' || ch6 != '}' || ch7 != ',') {
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
	else { r.hour = i;  r.temperature = j; r.type = cf; }
	return ifs;
}

ifstream& operator >> (ifstream& ifs, RawReading& r) {
	int i; double j; char cf;
	ifs >> i >> j >> cf;
	if (!ifs) {
		if (ifs.eof()) return ifs;
		else {
			ifs.unget();
			ifs.clear();
			string bad;
			char ch;
			while (ifs.get(ch) && ch != '\n') { bad += ch; }
			cout << "Reading error: " << bad << endl;
			return ifs;
		}
	}
	else { r.hour = i;  r.temperature = j; r.type = cf; }
	return ifs;
}




void print_v(const vector<Reading>& v) {
	for (Reading r : v) {
		cout << '[' << r.hour << "->" << r.temperature << "], ";
	}
	cout << endl;
}

double mean(const vector<Reading>& v) {
	if (v.size() < 1) {
		cout << "Empty array" << endl;
		return 0;
	}
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

void store_temps(const string rawinput, const string output) {
	
	ifstream ist{ rawinput };
	if (!ist) error("can't open input file", rawinput);
	ist.exceptions(ist.exceptions() | ios_base::badbit);
	vector <RawReading> results;
	while (true) {
		RawReading r{};
		if (!(ist >> r)) break;
		if (r.hour != -1) results.push_back(r);
	}

	ofstream ost{ output };
	if (!ost) error("can't open output file ", output);
	for (RawReading r : results)
		ost << r;
	return;
}

void temp_stats(const string structured_input) {
	ifstream ist{ structured_input };
	if (!ist) error("can't open input file", structured_input);
	ist.exceptions(ist.exceptions() | ios_base::badbit);
	vector <Reading> results;
	while (true) {
		Reading r{};
		if (!(ist >> r)) break;
		if (r.type != 'F') {
			double t = r.temperature * 9 / 5 + 32;
			r.temperature = t;
			r.type = 'F';
		}
		// cout << r;
		results.push_back(r);
	}
	cout << "Fahrenheit temperature mean: " << mean(results) << endl;
	cout << "Fahrenheit temperature median: " << median(results) << endl;
	return;
}


int main() {
	try {
		store_temps(raw_input, structured_temps);
		temp_stats(structured_temps);
	}
	catch (exception& e) {
		cerr << "Error: " << e.what() << endl;
	}
}