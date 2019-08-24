// Chapter 5 excercise 2 3 4 5 6
// ubuntu home cmake conf 
#include "std_lib_facilities.h"

const double kelvin = -273.15;
const double fahrenheit = -459.67;
const string error_message = "Invalid input\n";

double ctok(double c)
{	
	double k = c - kelvin;
	return k;
}

double ktoc (double k)
{
	double c = k + kelvin;
	return c;
}

double ftoc(double f)
{
	double c = (f - 32) * 5 / 9;
	return c;
}

double ctof(double c)
{
	double f = c * 9 / 5 + 32;
	return f;
}

int main(){
	cout << "Please enter degree and scale system (c for Celcius, k for Kelvin, f for Fahrenheit\n";
	while (true) {
		double degree = 0;
		char system = 'c';
		cin >> degree >> system;
		if (system != 'c' && system != 'k' && system != 'f') {
			cout << error_message;
			//error(error_message);
		}
		else if (system == 'c' && degree >= kelvin) {
			double k = ctok(degree);
			double f = ctof(degree);
			cout << degree << " degrees in Celcius are equal to " << k << " Kelvin and " << f << " Fahrenheit\n";
		}
		else if (system == 'k' && degree >= 0) {
			double c = ktoc(degree);
			double f = ctof(c);
			cout << degree << " degrees in Kelvin are equal to " << c << " Celcius and " << f << " Fahrenheit\n";
		}
		else if (system == 'f' && degree >= fahrenheit) {
			double c = ftoc(degree);
			double k = ctok(c);
			cout << degree << " degrees in Fahrenheit are equal to " << c << " Celcius and " << k << " Kelvin\n";
		}
		else {
			cout << error_message;
			//error(error_message);
		}
	}
}