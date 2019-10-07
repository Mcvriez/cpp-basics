#include "std_lib_facilities.h"

/*

Close the ofstream and then open an ifstream for mydata.txt. Read the data from mydata.txt and store it in a new
vector called processed_points.

*/

const int max_points_size = 2;
const string output = "C:\\Users\\arcady\\source\\repos\\cpp-basics\\mydata.txt";

class Point
{
public:
	Point() : x{ 0 }, y{ 0 } {};
	Point(double xx, double yy) : x{ xx }, y{ yy } {};
	double y;
	double x;
};


istream& operator >> (istream& ifs, Point& p) {
	double x, y;
	char ch;
	ifs >> x >> ch >> y;
	if (!ifs) return ifs;
	if (ch != ';') { // oops: format error
		cout << "Incorrect file format" << endl;
		ifs.clear(ios_base::failbit); // set the fail bit
		return ifs;
	}
	p = Point(x, y); // update dd
	return ifs;
}


void dump_to_file(string output, vector <Point>& points) {
	ofstream ost{ output };
	if (!ost) error("can't open output file ", output);
	for (Point p : points)
		ost << p.x << ";" << p.y << "\n";
}

vector <Point> read_file (string input) {
	ifstream ist{ input };
	if (!ist) error("can't open input file ", input);
	vector <Point> result;
	for (Point p; ist >> p; ) {
		result.push_back(p);
	}
	return result;
}

ostream& operator << (ostream& ofs, Point& p) {
	ofs << "Point contains (" << p.x << ":" << p.y <<  ")" << endl;
	return ofs;
}

void original_points() {
	cout << "Please enter " << max_points_size << " points:\n";
	vector<Point> original_points;
	for (Point p; cin >> p; ) {
		original_points.push_back(p);
		if (original_points.size() >= max_points_size) break;
	}
	dump_to_file(output, original_points);
}

int main() {
	try {
		// original_points();
		vector <Point> processed_points = read_file(output);
		for (Point pp : processed_points)
			cout << pp;
	}
	catch (exception& e) {
		cerr << "Error: " << e.what() << endl;
	}
}