#include "std_lib_facilities.h"

/*

Using the code and discussion in §10.4, prompt the user to input seven (x,y) pairs. As the data is entered, store it in a
vector of Points called original_points.

*/

const int max_points_size = 7;

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
		ifs.clear(ios_base::failbit); // set the fail bit
		return ifs;
	}
	p = Point(x, y); // update dd
	return ifs;
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
	for (Point p : original_points)
		cout << '(' << p.x << ", " << p.y << ")\n";
}

int main() {
	try {
		original_points();
	}
	catch (exception& e) {
		cerr << "Error: " << e.what() << endl;
	}
}