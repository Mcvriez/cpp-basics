/*
The grammar for input is:
	
Calculate:
	Statement:
		Expression
		Declaration	
		Redeclaration

	Print:
		;	
	Quit:
		q
	
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
						
Tests:

(123+----12)/(34/17 -2); - divide by zero
1237812382163872168372163 * 12312;
sdfjsadkjfksadjfkjas0981239'''a3 32 00923u	2302	309u092	3;;;;;;;;23423 23; ;23 ;234;23; 
let let = 5;
let quit = 5;
let 123 = 124;

*/

#include "std_lib_facilities.h"

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

const char let = 'L';
const char quit = 'Q';
const char print = ';';
const char number = '8';
const char name = 'a';
const char square = 'S';
const char power = 'P';


Token Token_stream::get()
{
	if (full) { full = false; return buffer; }
	char ch;
	cin >> ch;
	switch (ch) {
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
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	{	
	cin.unget(); // put character back to stream, alternative to cin.putback(ch)
	double val;
	cin >> val;
	return Token(number, val);
	}
	case '#':
		return Token(let);
	default:
		if (isalpha(ch) ) { // isalpha checks whether ch is an alphabetic letter
			string s;
			s += ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch)) || ch == '_') s += ch; // (error was here)
			cin.unget();
			if (s == "sqrt") return Token(square);
			if (s == "pow") return Token(power);
			if (s == "exit") return Token(quit); // (error was here)
			
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
	Variable(string n, double v) :name(n), value(v) { }
};

vector <Variable> names;

const Variable k ("k", 1000);

double get_value(string s)
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return names[i].value;
	error("get: undefined name ", s);
}

void set_value(string s, double d)
{
	for (int i = 0; i <= names.size(); ++i)
		if (names[i].name == s) {
			names[i].value = d;
			return;
		}
	error("set: undefined name ", s);
}

bool is_declared(string s)
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return true;
	return false;
}

Token_stream ts;

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
			return get_value(t.name); 
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

double declaration()
{
	Token t = ts.get();
	
	if (t.kind != name) error("name expected in declaration");
	
	string name = t.name;

	if (is_declared(name)) error(name, " declared twice");
	
	Token t2 = ts.get();
	
	if (t2.kind != '=') error("= missing in declaration of ", name);
	double d = expression();
	names.push_back(Variable(name, d));
	return d;
}

double assignment() {
	Token t = ts.get();
	string tname = t.name;
	double tvalue = t.value;

	if (!is_declared(tname)) error("undeclared variable: ", tname);

	Token t2 = ts.get();
	if (t2.kind == '=') 
	{
		double d = expression();
		set_value(tname, d);
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
		return declaration();
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
		if (t.kind == quit) return;
		ts.unget(t);
		cout << result << statement() << endl;
	}
	catch (runtime_error& e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

int main() {
names.push_back(k);
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