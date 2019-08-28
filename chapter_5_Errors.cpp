// Chapter 5 excercise 12/13 Bulls and cows
#include "std_lib_facilities.h"

vector <int> game(4);

bool is_unique(int test, int pos) {
	for (int i = 0; i < pos; ++i) {
		if (test == game[i]) return false;
	}
	return true;
}

void initialize() {
	int seed = 0;
	cout << "Enter int number that will be used as a seed:\n";
	cin >> seed;
	if (!cin) { error("Wrong input\n"); }
	cout << "calling srand(" << seed << ")\n";
	srand(seed); //doesn't work, I don't know why, each time same sequence
	for (int i = 0; i < 4; ++i) {
		game[i] = randint(9);
		while(!is_unique(game[i], i))
			game[i] = randint(9);
	}
}

void print_game() {
	cout << "Game contains:\n";
	for (int x : game) cout << x;
	cout << "\n";
}

int play() {
	int guess = 0;
	int bull = 0;
	int cow = 0;

	cout << "\nEnter your guess. (Four numbers from 0 to 9):\n";
	cin >> guess;
	if (!cin) error("Wrong input\n");
	int x0 = guess / 1000; 
	guess -= x0 * 1000;
	int x1 = guess / 100;
	guess -= x1 * 100;
	int x2 = guess / 10;
	int x3 = guess -= x2 * 10;
	vector <int> vguess = { x0, x1, x2, x3 };
	cout << "Your guess is: " << x0 << x1 << x2 << x3 << "\n";
	for (int i = 0; i < 4; ++i) {
		if (vguess[i] == game[i]) ++bull;
		for (int j = 0; j < 4; ++j) {
			if (vguess[j] == game[i] && i != j) {
				++cow;
			}
		}
	}
	if (bull == 4) {
		cout << "You won!\n";
		return 0;
	}
	cout << "You have " << bull << " bulls and " << cow << " cows\n";
}

int main() {
	initialize();
	print_game();
	while (true) {
		if (play() == 0) {
			initialize();
			print_game();
		}
	}
}