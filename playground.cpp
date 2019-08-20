// Find mode (the number that appears most) in the array
#include "std_lib_facilities.h"
#include <stdlib.h>

vector <int> numbers = {};

void initialize(int max, int step){
	for (int index = 0; index < max; ++index) {
		int randint = rand() % step + 1;
		numbers.push_back(randint);
	}
}

int main() {
    int max_numbers = 100;
    int number_cap = 10;
	initialize(max_numbers, number_cap);
	cout << "test initialize:\n";
	for (int x : numbers) {
		cout << x << "\t";
	}

}       
