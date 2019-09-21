#include "std_lib_facilities.h"

// 1 To make the input stream an explicit parameter

// 2 Also give the Token_stream constructor (§7.8.2) an istream& parameter
// so that when we figure out how to make our own istream s (e.g., attached
// to files), we can use the calculator for those. Hint: Don’t try to copy an istream 

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
const char newline = '\n';


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
	istream& datastream;
	Token_stream() :full(false), buffer(0), datastream(std::cin){ }
	Token get();
	void unget(Token t) { buffer = t; full = true; }
	void ignore(char);
};

Token Token_stream::get()
{
	if (full) { full = false; return buffer; }
	char ch;
	datastream.get(ch);
	while (isspace(ch)) {
		if (ch == newline) return Token(print); // if newline detected, return print Token
		datastream.get(ch);
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
	case '.':	case '0':	case '1':	case '2':
	case '3':	case '4':	case '5':	case '6':
	case '7':	case '8':	case '9':
	{
		datastream.unget(); // put character back to stream, alternative to datastream.putback(ch)
		double val;
		datastream >> val;
		int val1 = narrow_cast<int>(val);
		return Token(number, val1);
	}
	case '#':
		return Token(let);
	default:
		if (isalpha(ch)) // isalpha checks whether ch is an alphabetic letter
		{
			string s;
			s += ch;
			while (datastream.get(ch) && (isalpha(ch) || isdigit(ch)) || ch == '_') s += ch; // (error was here)
			datastream.unget();
			if (s == "const") return Token(constant);
			if (s == "sqrt") return Token(square);
			if (s == "mod") return Token(mod);
			if (s == "pow") return Token(power);
			if (s == "quit" || s == "Quit" || s == "QUIT") return Token(quit); // (error was here)
			if (s == "help" || s == "Help" || s == "HELP") return Token(help);
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
	while (datastream.get(ch))
		if (ch == c || ch == newline) return;
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

Token_stream token_stream;
Symbol_table st;
double expression(Token_stream& ts); // we define it here because otherwise primary() won't compile

double primary(Token_stream& ts)
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':
	{
		double d = expression(ts);
		t = ts.get();
		if (t.kind != ')') {
			ts.unget(t); // to make cleaner work
			error("')' expected");
		}
		return d;    // error was here
	}
	case '-':
		return -primary(ts);
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
		double d = expression(ts);
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
		double d = expression(ts);
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
		double d = expression(ts);
		t = ts.get();
		if (t.kind != ',') {
			ts.unget(t);
			error("',' expected in the power statement");
		}
		double i = expression(ts);
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

double term(Token_stream& ts)
{
	double left = primary(ts);
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '*':
			left *= primary(ts);
			break;
		case '/':
		{	double d = primary(ts);
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

double expression(Token_stream& ts)
{
	double left = term(ts);
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '+':
			left += term(ts);
			break;
		case '-':
			left -= term(ts);
			break;
		default:
			ts.unget(t);
			return left;
		}
	}
}

double declaration(Token_stream& ts, bool cons)
{
	Token t = ts.get();
	if (t.kind != name) error("name expected in declaration");
	string name = t.name;
	if (st.is_declared(name)) error(name, " declared twice");
	Token t2 = ts.get();
	if (t2.kind != '=') { ts.unget(t2);  error("= midatastreamg in declaration of ", name); }
	double d = expression(ts);
	st.define_name(name, d, cons);
	return d;
}

double assignment(Token_stream& ts) {
	Token t = ts.get();
	string tname = t.name;
	double tvalue = t.value;

	if (!st.is_declared(tname)) error("undeclared variable: ", tname);

	Token t2 = ts.get();
	if (t2.kind == '=')
	{
		double d = expression(ts);
		st.set_value(tname, d);
		return d;
	}
	ts.datastream.unget();
	ts.unget(t);
	return expression(ts);
}

double statement(Token_stream& ts)
{
	Token t = ts.get();
	switch (t.kind) {
	case let:
		return declaration(ts, false);
	case constant:
		return declaration(ts, true);
	case name:
		ts.unget(t);
		return assignment(ts);
	default:
		ts.unget(t);
		return expression(ts);
	}
}

void clean_up_mess(Token_stream& ts)
{
	ts.ignore(print);
}

const string prompt = "> ";
const string result = "= ";

void calculate(Token_stream& ts)
{
	while (true)
		try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t = ts.get();
		if (t.kind == help) {
			cout << "\nCalculation application\n\nSupports all arithmetic operations including parenthesis, pow(x,y), mod(x) and sqrt(x) functions\nuse #x = y notation to define a variable\nuse x = y notation to redefine it\nuse const x = y to define a constant (can't be redefined)\n\nEnter 'help' to receive this this message\nEnter 'quit' for quit\n";
		}
		else {
			if (t.kind == quit) return;
			ts.unget(t);
			cout << result << statement(ts) << endl;
		}
	}
	catch (runtime_error& e) {
		cerr << e.what() << endl;
		clean_up_mess(ts);
	}
}

int main() {
	st.define_name("k", 1000, true);
	try {
		calculate(token_stream);
		return 0;
	}
	catch (exception& e) {
		cerr << "exception: " << e.what() << endl;
		char c;
		while (token_stream.datastream >> c && c != ';');
		return 1;
	}
	catch (...) {
		cerr << "exception\n";
		char c;
		while (token_stream.datastream >> c && c != ';');
		return 2;
	}
}