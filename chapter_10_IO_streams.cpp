#include "std_lib_facilities.h"

/*

 Start a program to work with points, discussed in §10.4. Begin by defining the data type Point that has two coordinate

*/

class Point
{
public:
	Point() : x{ 0 }, y{ 0 } {};
	Point(double xx, double yy) : x{ xx }, y{ yy } {};
	double y;
	double x;
};


ifstream& operator >> (ifstream& ifs, Point& p) {
	double x, y;
	char ch;
	ifs >> x >> ch >> y;
	if (!ifs) return ifs;
	if (ch != ';') { // oops: format error
		ifs.clear(ios_base::failbit); // set the fail bit
		return ifs;
	}
	p = Point(x, y); // update dd
	return ifs;
}


ofstream& operator << (ofstream& ofs, Point& p) {
	ofs << "Point contains (" << p.x << " : " << p.y <<  ")" << endl;
	return ofs;
}

void points() {
	cout << "Please enter input file name: ";
	string iname;
	cin >> iname;

	ifstream ist{ iname }; // ist is an input stream for the file named name
	
	if (!ist) error("can't open input file ", iname);
	vector<Point> points;
	for (Point p; ist >> p; )
		points.push_back(p);
	cout << "Please enter name of output file: ";
	string oname;
	cin >> oname;
	ofstream ost{ oname }; // ost is an output stream for a file named oname
	if (!ost) error("can't open output file ", oname);
	for (Point p : points)
		ost << '(' << p.x << ',' << p.y << ")\n";
}

int main() {
	try {
		points();
	}
	catch (exception& e) {
		cerr << "Error: " << e.what() << endl;
	}
}