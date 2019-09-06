#include "std_lib_facilities.h"
/*
Write a program that checks if a sentence is correct according to the “En-
glish” grammar in §6.4.1. Assume that every sentence is terminated by
a full stop (.) surrounded by whitespace. For example, birds fly but the
fish swim . is a sentence, but birds fly but the fish swim (terminating dot
missing) and birds fly but the fish swim. (no space before dot) are not. For
each sentence entered, the program should simply respond “OK” or “not
OK.” Hint: Don’t bother with tokens; just read into a string using >>
*/
vector <string> verbs = { "rules", "fly", "swim" };
vector <string> articles = { "the" };
vector <string> nouns = { "birds", "fish", "C++" };
vector <string> conjuctions = { "and", "or", "but" };

bool is_verb(string word){
	for (string x : verbs) {
		if (word == x) return true;
	}
	return false;
}

bool is_article(string word) {
	for (string x : articles) {
		if (word == x) return true;
	}
	return false;
}

bool is_noun(string word) {
	for (string x : nouns) {
		if (word == x) return true;
	}
	return false;
}

bool is_conjuction(string word) {
	for (string x : conjuctions) {
		if (word == x) return true;
	}
	return false;
}

int sentence() {
	string w1; string w2; string w3; string w4;
	cin >> w1;
	cout << w1 << " : first word\n";
	if (is_article(w1)) { cin >> w2; }
	else if (is_noun(w1)) { w2 = w1; }
	cout << w2 << " : second word\n";
	if (is_noun(w2)) {
		cin >> w3;
		cout << w3<< " : third word\n";
		if (is_verb(w3)) {
			cin >> w4;
			cout << w4 << " : forth word\n";
			if (w4 == ".") { return 0; }
			if (is_conjuction(w4)) { cout << "conjuction found: " << w4 << "\n"; return sentence(); }			
		}
	}
	while (w1 != ".") {
		cin >> w1;
	}
	return 1;
}

int main() {
	string word;
	while (true) {
		if (sentence() == 0) cout << "OK\n";
		else cout << "Not OK\n";
	}
}