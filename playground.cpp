// Find mode (the number that appears most) in the array
#include "std_lib_facilities.h"
#include <stdlib.h>
#include <time.h>

vector <int> numbers = {};

void initialize(int max, int step){
	for (int index = 0; index < max; ++index) {
		int randint = rand() % step + 1;
		numbers.push_back(randint);
	}
}

int find_mode() {
	int max = 0;
	int current = 0;
	int mode = 0;
	for (int index = 1; index < numbers.size(); ++index) {
		if (numbers[index] == numbers[index - 1]) {
			++current;
		}
		else {
			current = 0;
		}
		if (current > max) {
			max = current;
			mode = numbers[index];
		}
	}
	return mode;
}

int main() {
    int max_numbers = 200;
    int number_cap = 100;
	srand((int)time(0));
	initialize(max_numbers, number_cap);
	sort(numbers);
	cout << "test initialize:\n";
	for (int x : numbers) {
		cout << x << ", ";
	}
	int mode = find_mode();
	cout << "\n\nMode number is: " << mode << ".\n";
}       
