// Chapter 5 excercise 7 quadratic equation p2 (this time it works)
// back to office
#include "std_lib_facilities.h"

int main() {
	cout << "Quadratic equation is equation with the form ax2 + bx + c = 0, and a is not zero.\n";
	while (true) {
		cout << "\nPlease write a, b and c separated with whitespace.\n";
		double a = 1;
		double b = 0;
		double c = 0;
		cin >> a >> b >> c;
		double discriminant = b * b - 4 * a * c;
		cout << "discriminant of the equation is " << discriminant << "\n";
		if (a == 0) {
			cout << "a can't be equal to zero!\n";
		}
		else if (discriminant > 0) {
			double x1 = (b * -1 + sqrt(discriminant)) / (2 * a);
			double x2 = (b * -1 - sqrt(discriminant)) / (2 * a);
			cout << "Equation has two roots: " << x1 << " and " << x2 << "\n";
		}
		else if (discriminant == 0) {
			double x = (b * -1) / 2 * a;
			cout << "Equation has one root: " << x << "\n";
		}
	}
}