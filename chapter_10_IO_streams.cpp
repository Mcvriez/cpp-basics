#include "std_lib_facilities.h"

/*

 Print the data elements from both vectors.

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

ostream& operator << (ostream& ofs, Point& p) {
	ofs << "Point contains (" << p.x << ":" << p.y << ")" << endl;
	return ofs;
}


void dump_to_file(string out, vector <Point>& points) {
	ofstream ost{ out };
	if (!ost) error("can't open output file ", out);
	for (Point p : points)
		ost << p.x << ";" << p.y << "\n";
}


vector <Point> read_points_from_file(string file) {
	ifstream ist{ file };
	if (!ist) error("can't open input file ", file);
	vector <Point> result;
	for (Point p; ist >> p; ) {
		result.push_back(p);
	}
	return result;
}


vector <Point> write_points_to_file(string file) {
	cout << "Please enter " << max_points_size << " points:\n";
	vector<Point> original_points;
	for (Point p; cin >> p; ) {
		original_points.push_back(p);
		if (original_points.size() >= max_points_size) break;
	}
	dump_to_file(file, original_points);
	return original_points;
}

void print_points(vector<Point>& p) {
	cout << "Vector contains:" << endl;
	for (Point pp : p)
		cout << pp;
	cout << endl;
}

int main() {
	try {
		vector <Point> original_points = write_points_to_file(output);
		vector <Point> processed_points = read_points_from_file(output);
		print_points(original_points);
		print_points(processed_points);

	}
	catch (exception& e) {
		cerr << "Error: " << e.what() << endl;
	}
}