// Chapter 6 excercise 8 Bulls and cows redo with chars
#include "std_lib_facilities.h"

vector <char> game (4);

bool is_unique(char ch, int pos) {
	for (int i = 0; i < pos; ++i) {
		if (ch == game[i]) return false;
	}
	return true;
}

void initialize() {
	int seed = 0;
	cout << "Enter int number that will be used as a seed:\n";
	cin >> seed;
	if (!cin) { cout << ("Wrong input\n"); }
	cout << "calling srand(" << seed << ")\n";
	srand(seed); //doesn't work, I don't know why, each time same sequence
	for (int i = 0; i < 4; ++i) {
		char randchar = 97 + randint(25);
		game[i] = randchar;
		while (!is_unique(game[i], i)) {
			char randchar = 97 + randint(25);
			game[i] = randchar;
		}
	}
}

void print_game() {
	cout << "Game contains:\n";
	for (char x : game) cout << x;
	cout << "\n";
}

int play() {
	int bull = 0;
	int cow = 0;
	char c1; char c2; char c3; char c4;
	cout << "\nEnter your guess - four letters:\n";
	cin >> c1 >> c2 >> c3 >> c4;
	if (!cin) error("Wrong input\n");
	vector <char> vguess = { c1, c2, c3, c4 };
	cout << "Your guess is: " << c1 << c2 << c3 << c4 << "\n";
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
	//print_game();
	while (true) {
		if (play() == 0) {
			initialize();
			//print_game();
		}
	}
}