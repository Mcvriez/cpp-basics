#include "std_lib_facilities.h"

/*

Make a version of the calculator from Chapter 7 that accepts Roman numerals rather than the usual Arabic ones, for
example, XXI + CIV == CXXV.

*/


class Roman_int
{
public:
	Roman_int() :value{ 0 }, reprez{"N"}{};
	Roman_int(int x);
	int as_int() const { return value; }
	string repr() const { return reprez; }
private:
	int value;
	string reprez;
	static const int max = 5000;
};


Roman_int:: Roman_int(int x) :value{} {
	if (x < max && x > 0) {
		value = x;
	}
	else cout << "Roman int can't be less than zero or more than 5000";
	/*
	Symbol	I	V	X	L	C	D	M
	Value	1	5	10	50	100	500	1000
	*/
	int M = x / 1000;
	int h = M * 1000;
	int CM = (x - h) / 900;
	int D = (x - h) / 500;
	h += D * 500;
	int CD = (x - h) / 400;
	int C = (x - h) / 100;
	h += C * 100;
	int XC = (x - h) / 90;
	int L = (x - h) / 50;
	h += L * 50;
	int XL = (x - h) / 40;
	int X = (x - h) / 10;
	h += X * 10;
	int IX = (x - h) / 9;
	int V = (x - h) / 5;
	h += V * 5;
	int IV = (x - h) / 4;
	string rep;
	for (int i = 0; i < M; i++)
		rep += 'M';
	if (CM) rep += "CM";
	else {
		if (D) rep += 'D';
		if (CD) rep += "CD";
		else {
			for (int i = 0; i < C; i++)
				rep += 'C';
		}
	}
	if (XC) rep += "XC";
	else {
		if (L) rep += 'L';
		if (XL) rep += "XL";
		else {
			for (int i = 0; i < X; i++)
				rep += 'X';
		}
	}
	if (IX) rep += "IX";
	else {
		if (V) rep += 'V';
		if (IV) rep += "IV";
		else
			for (int i = 0; i < x - h; i++)
				rep += 'I';
	}
	reprez = rep;
};
ostream& operator << (ostream& os, const Roman_int& r) {
	os << r.repr();
	return os;
}

vector <string> roman_numerals = {"0"};

void fill_numerals() {
	for (int i = 1; i < 5000; ++i) {
		Roman_int r = Roman_int(i);
		roman_numerals.push_back(r.repr());
	}
}

/*
The grammar for input is:

Calculate:
	Statement ; Statement ;
	Statement:
		Expression
		Declaration
		Redeclaration
	Print:
		;
	Quit:
		quit || Quit || QUIT
	Help:
		help || Help || HELP
		Declaration:
			# Name = Expression

		Redeclaraton:
			existing Name = Expression
		Expression:
			Term
			Expression + Term
			Expression – Term

			Term:
				Primary
				Term * Primary
				Term / Primary
				Term % Primary

				Primary:
					Name
					Number
					(Expression)
					– Primary
					+ Primary
					sqrt(Expression)
					pow((Expression), (Expression))

						Name:
							string header: floating-point-literal
						Number:
							floating-point-literal

*/

#include "std_lib_facilities.h"

const char let = 'L';
const char quit = 'Q';
const char print = ';';
const char number = '8';
const char name = 'a';
const char square = 'S';
const char mod = 'M';
const char power = 'P';
const char constant = 'C';
const char help = 'H';


struct Token {
	char kind;        // type of the token - number, name, or some operation
	double value;     // value for digits 
	string name;      // and names
	// initialization:
	Token(char ch) :kind(ch), value(0) { }                       // with only char, operations 
	Token(char ch, double val) :kind(ch), value(val) { }         // numbers
	Token(char ch, string n) :kind(ch), name(n) { }              // names (error was here)
};

class Token_stream {
	bool full;
	Token buffer;
public:
	Token_stream() :full(false), buffer(0) { }
	Token get();
	void unget(Token t) { buffer = t; full = true; }
	void ignore(char);
};

Token Token_stream::get()
{
	if (full) { full = false; return buffer; }
	char ch;
	cin.get(ch);
	while (isspace(ch)) {
		if (ch == '\n') return Token(print); // if newline detected, return print Token
		cin.get(ch);
	}
	switch (ch)
	{
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case ';':
	case '=':
	case ',':
		return Token(ch);
		// I	V	X	L	C	D	M
	case 'I':	case 'V':	case 'X':
	case 'L':	case 'C':	case 'D':	case 'M':
	{
		cin.unget(); // put character back to stream, alternative to cin.putback(ch)
		string val;
		cin >> val;
		for (int i = 1; i < roman_numerals.size(); ++i) {
			if (val == roman_numerals[i]) {
				return Token(number, i);
			}
		}
		error("Unreadable Roman integer");
		
	}
	case '#':
		return Token(let);
	default:
		if (isalpha(ch)) // isalpha checks whether ch is an alphabetic letter
		{
			string s;
			s += ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch)) || ch == '_') s += ch; // (error was here)
			cin.unget();
			if (s == "const") return Token(constant);
			if (s == "sqrt") return Token(square);
			if (s == "mod") return Token(mod);
			if (s == "pow") return Token(power);
			if (s == "quit" || s == "Quit" || s == "QUIT") return Token(quit); // (error was here)
			if (s == "help" || s == "Help" || s == "HELP") return Token(help); // (error was here)
			return Token(name, s);
		}

		error("Bad token");
	}
}

void Token_stream::ignore(char c)       // reads till the specified character, needed to clear incorrect input statement
{
	if (full && c == buffer.kind) {
		full = false;
		return;
	}
	full = false;

	char ch;
	while (cin >> ch)
		if (ch == c) return;
}

struct Variable {
	string name;
	double value;
	bool constant;
	Variable(string n, double v, bool c) :name(n), value(v), constant(c) { }
};

class Symbol_table {
	vector <Variable> names;
public:
	Symbol_table() :names() {}
	double get_value(string s);
	void set_value(string s, double d);
	double define_name(string var, double val, bool cons);
	bool is_declared(string s);
};


double Symbol_table::get_value(string s)
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return names[i].value;
	error("get: undefined name ", s);
}

void Symbol_table::set_value(string s, double d)
{
	for (int i = 0; i <= names.size(); ++i) {
		if (names[i].name == s) {
			if (names[i].constant == true) error("can't redefine constant: ", names[i].name);
			names[i].value = d;
			names[i].constant = false;
			return;
		}
	}
	error("set: undefined name ", s);
}

double Symbol_table::define_name(string var, double val, bool cons)
{
	if (is_declared(var)) error(var, " declared twice");
	names.push_back(Variable(var, val, cons));
	return val;
}

bool Symbol_table::is_declared(string s)
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return true;
	return false;
}

Token_stream ts;
Symbol_table st;
double expression(); // we define it here because otherwise primary() won't compile

double primary()
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':
	{
		double d = expression();
		t = ts.get();
		if (t.kind != ')') {
			ts.unget(t); // to make cleaner work
			error("')' expected");
		}
		return d;    // error was here
	}
	case '-':
		return -primary();
	case number:
		return t.value;
	case name: {
		return st.get_value(t.name);
	}
	case square:
	{
		t = ts.get();
		if (t.kind != '(') error("'(' expected");
		ts.unget(t);
		double d = expression();
		if (d < 0) {
			error("You can't get square root of the negative number");
		}
		return sqrt(d);
	}
	case mod:
	{
		t = ts.get();
		if (t.kind != '(') error("'(' expected");
		ts.unget(t);
		double d = expression();
		if (d < 0) {
			return d *= -1;
		}
		return d;
	}
	case power: {
		t = ts.get();
		if (t.kind != '(') {
			ts.unget(t);
			error("'(' expected");
		}
		double d = expression();
		t = ts.get();
		if (t.kind != ',') {
			ts.unget(t);
			error("',' expected in the power statement");
		}
		double i = expression();
		t = ts.get();
		if (t.kind != ')') {
			ts.unget(t);
			error("')' expected");
		}
		return(powf(d, i));
	}
	default:
		error("primary expected");
	}
}

double term()
{
	double left = primary();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '*':
			left *= primary();
			break;
		case '/':
		{	double d = primary();
		if (d == 0) error("divide by zero");
		left /= d;
		break;
		}
		default:
			ts.unget(t);
			return left;
		}
	}
}

double expression()
{
	double left = term();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '+':
			left += term();
			break;
		case '-':
			left -= term();
			break;
		default:
			ts.unget(t);
			return left;
		}
	}
}

double declaration(bool cons)
{
	Token t = ts.get();
	if (t.kind != name) error("name expected in declaration");
	string name = t.name;
	if (st.is_declared(name)) error(name, " declared twice");
	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of ", name);
	double d = expression();
	st.define_name(name, d, cons);
	return d;
}

double assignment() {
	Token t = ts.get();
	string tname = t.name;
	double tvalue = t.value;

	if (!st.is_declared(tname)) error("undeclared variable: ", tname);

	Token t2 = ts.get();
	if (t2.kind == '=')
	{
		double d = expression();
		st.set_value(tname, d);
		return d;
	}
	cin.unget();
	ts.unget(t);
	return expression();
}

double statement()
{
	Token t = ts.get();
	switch (t.kind) {
	case let:
		return declaration(false);
	case constant:
		return declaration(true);
	case name:
		ts.unget(t);
		return assignment();
	default:
		ts.unget(t);
		return expression();
	}
}

void clean_up_mess()
{
	ts.ignore(print);
}

const string prompt = "> ";
const string result = "= ";

void calculate()
{
	while (true) try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t = ts.get();
		if (t.kind == help) {
			cout << "\nCalculation application\n\nSupports all arithmetic operations including parenthesis, pow(x,y), mod(x) and sqrt(x) functions\nuse #x = y notation to define a variable\nuse x = y notation to redefine it\nuse const x = y to define a constant (can't be redefined)\n\nEnter 'help' to receive this this message\nEnter 'quit' for quit\n";
		}
		else {
			if (t.kind == quit) return;
			ts.unget(t);
			Roman_int res = Roman_int(statement());
			cout << result << res.repr() << endl;
		}
	}
	catch (runtime_error& e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

int main() {
	fill_numerals();
	st.define_name("k", 1000, true);
	try {
		calculate();
		return 0;
	}
	catch (exception& e) {
		cerr << "exception: " << e.what() << endl;
		char c;
		while (cin >> c && c != ';');
		return 1;
	}
	catch (...) {
		cerr << "exception\n";
		char c;
		while (cin >> c && c != ';');
		return 2;
	}
}