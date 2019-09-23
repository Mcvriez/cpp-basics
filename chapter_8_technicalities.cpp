#include "std_lib_facilities.h"

/*

Write a function that finds the smallest and the largest element of a vector
argument and also computes the mean and the median. Do not use global
variables. Either return a struct containing the results or pass them back
through reference arguments. Which of the two ways of returning several
results values do you prefer and why?

*/

struct vector_stats
{
	double smallest;
	double largest;
	double mean;
	double median;
};

vector <double> ints = { 12, 32, 54, 324, 6556, 11 };
vector <double> price = {2.13, 4.31, 324.24, 54.64, 566.55, 1235.6};
vector <double> weight = {0.88, 123.123, 0.5, 3.5, 5.0, 12.34, 20.1};
vector <double> emptys;


void print_vs(vector_stats vs) {
	cout << endl << "struct contains: \n";
	cout << "smallest: " << vs.smallest << endl;
	cout << "largest: " << vs.largest << endl;
	cout << "mean: " << vs.mean << endl;
	cout << "median: " << vs.median << endl;
}

vector_stats sortd(vector<double> to_sort) {
	int size = to_sort.size();
	vector_stats result;
	if (size == 0) { 
		cout << "Empty vector\n"; 
		result = { 0, 0, 0, 0 }; 
		return result; }

	sort(to_sort.begin(), to_sort.end());
	double smallest = to_sort[0];
	double largest = to_sort[size - 1];
	double mean = 0;
	double median;
	for (double x : to_sort) mean += x;
	mean /= size;
	if (size == 1) median = to_sort[0];
	else if (size % 2) median = to_sort[size / 2];
	else median = { (to_sort[size / 2] + to_sort[size / 2 - 1]) / 2 };
	result.smallest = smallest;
	result.largest = largest;
	result.mean = mean;
	result.median = median;
	return result;
}



int main() {
	print_vs(sortd(ints));
	print_vs(sortd(price));
	print_vs(sortd(weight));
	print_vs(sortd(emptys));

}

