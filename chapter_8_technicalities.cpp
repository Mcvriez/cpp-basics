#include "std_lib_facilities.h"

/*

Write a function that given two vector<double>s price and weight com-
putes a value (an “index”) that is the sum of all price[i]*weight[i]. 
Make sure to have weight.size()==price.size()

*/

vector <double> price = {2.13, 4.31, 324.24, 54.64, 566.55, 1235.6};
vector <double> weight = {0.88, 0.5, 3.5, 5.0, 12.34, 20.1};


double compute(const vector<double>& prices, const vector <double>& weights) {
	if (weights.size() != prices.size()) {
		cout << "Prices and weights don't match\n";
		return 0;
	}
	double sum = 0;
	for (int i = 0; i < prices.size(); i++) {
		sum += prices[i] * weights[i];
	}
	return sum;

}



int main() {
	double result = compute(price, weight);
	if (result) cout << "Index is: " << result << endl;
}

