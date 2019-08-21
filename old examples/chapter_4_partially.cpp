// Vectors and names
#include "std_lib_facilities.h"

vector <int> scores = {};
vector <string> names = {};

bool is_unique(string input) {
	for (string name : names) {
		if (name == input) {
			return false;
		}
	}
	return true;
}

void list_score(string input) {
	bool found = false;
	for (int index = 0; index < names.size(); ++index) {
		if (names[index] == input) {
			cout << names[index] << " has score of " << scores[index] << "\n";
			found = true;
			break;
		}
	}
	if (found == false) {
		cout << "Name not found.\n";
	}
}

void list_names(int input) {
	bool found = false;
	for (int index= 0; index< scores.size(); ++index) {
		if (scores[index] == input) {
			cout << names[index] << " has the same score of " << scores[index] << "\n";
			found = true;
		}
	}
	if (found == false) {
		cout << "Score not found.\n";
	}
}

void list_all() {
	for (int index = 0; index < scores.size(); ++index) {
		cout << names[index] << " had scored " << scores[index] << " points.\n";
	}
}

int main() {
	int score = 0;
	string name = "";
	cout << "Hello. Please enter set of name and score pairs (like <Joe 17>)\n";
	cout << "To terminate, enter <NoName 0>\n";
	cout << "To show scores assosciated with name, enter <Name -1>\n";
	cout << "To list all names having the same score n, enter <List n>\n";
	while (true) {
		cin >> name >> score;
		if (name == "NoName" && score == 0) {
			list_all();
			break;
		}
		else if (score == -1)
			list_score(name);
		else if (name == "List")
			list_names(score);
		else if (is_unique(name) == false)
			cout << "Name is already present\n";
		else {
			names.push_back(name);
			scores.push_back(score);
		}
	}
}       
