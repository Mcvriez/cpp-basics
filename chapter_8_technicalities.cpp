#include "std_lib_facilities.h"

/*

Write a function maxv() that returns the largest element of a vector
argument.

*/

vector <double> ints = { 12, 32, 54, 324, 6556, 12 };
vector <double> price = {2.13, 4.31, 324.24, 54.64, 566.55, 1235.6};
vector <double> weight = {0.88, 123.123, 0.5, 3.5, 5.0, 12.34, 20.1};
vector <string> words = { "shit", "piss", "fuck", "cunt", "cocksucker", "motherfucker",  "tits" };

void sortd(vector<double> to_sort) {
	sort(to_sort.begin(), to_sort.end());
	cout << "Largest element is: " << to_sort[to_sort.size() - 1] << endl;
}

void sorts(vector<string> to_sort) {
	sort(to_sort.begin(), to_sort.end());
	cout << "Largest element is: " << to_sort[to_sort.size() - 1] << endl;
}



int main() {
	sortd(ints);
	sortd(price);
	sortd(weight);
	sorts(words);

}

