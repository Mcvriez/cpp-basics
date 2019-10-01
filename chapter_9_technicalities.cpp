#include "std_lib_facilities.h"

/*

Create a Library class. 
Include vectors of Books and Patrons. 

Include a struct called Transaction. 
Have it include a Book, a Patron, and a Date from the chapter. 
Make a vector of Transactions. 

Create functions to add books to the library, add patrons to the library, and check out books. 
Whenever a user checks out a book, have the library make sure that both the user and the book are in the library. 
If they aren’t, report an error. 
Then check to make sure that the user owes no fees. If the user does, report an error. 
If not, create a Transaction, and place it in the vector of Transactions.

Also write a function that will return a vector that contains the names of all Patrons who owe fees.

*/

namespace Chrono {
	enum class Month {
		jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
	};

	class Date {
	public:
		class Invalid { }; // to throw as exception
		Date(int y, Month m, int d); // check for valid date and initialize
		Date(); // default constructor
		// the default copy operations are fine
		// nonmodifying operations:
		int day() const { return d; }
		Month month() const { return m; }
		int year() const { return y; }
		// modifying operations:
		void add_day(int n);
		void add_month(int n);
		void add_year(int n);
	private:
		int y;
		Month m;
		int d;
	};
	bool is_date(int y, Month m, int d); // true for valid date
	bool leapyear(int y); // true if y is a leap year
	bool operator==(const Date& a, const Date& b);
	bool operator!=(const Date& a, const Date& b);
	ostream& operator<<(ostream& os, const Date& d);
	istream& operator>>(istream& is, Date& dd);
	// member function definitions:
	Date::Date(int yy, Month mm, int dd)
		: y{ yy }, m{ mm }, d{ dd }
	{
		if (!is_date(yy, mm, dd)) throw Invalid{};
	}
	const Date& default_date()
	{
		static Date dd{ 2001,Month::jan,1 }; // start of 21st century
		return dd;
	}
	Date::Date()
		:y{ default_date().year() },
		m{ default_date().month() },
		d{ default_date().day() }
	{
	}
	void Date::add_day(int n)
	{
		// . . .
	}
	void Date::add_month(int n)
	{
		// . . .
	}
	void Date::add_year(int n)
	{
		if (m == Month::feb && d == 29 && !leapyear(y + n)) { // beware of leap years!
			m = Month::mar; // use March 1 instead of February 29
			d = 1;
		}
		y += n;
	}
	// helper functions:
	bool is_date(int y, Month m, int d)
	{
		// assume that y is valid
		if (d <= 0) return false; // d must be positive
		if (m < Month::jan || Month::dec < m) return false;
		int days_in_month = 31; // most months have 31 days
		switch (m) {
		case Month::feb: // the length of February varies
			days_in_month = (leapyear(y)) ? 29 : 28;
			break;
		case Month::apr: case Month::jun: case Month::sep: case Month::nov:
			days_in_month = 30; // the rest have 30 days
			break;
		}
		if (days_in_month < d) return false;
		return true;
	}
	bool leapyear(int y)
	{
		return false;
	}
	bool operator==(const Date& a, const Date& b)
	{
		return a.year() == b.year()
			&& a.month() == b.month()
			&& a.day() == b.day();
	}
	bool operator!=(const Date& a, const Date& b)
	{
		return !(a == b);
	}
	ostream& operator<<(ostream& os, const Date& d)
	{
		return os << '(' << d.year()
			<< ',' << int(d.month())
			<< ',' << d.day() << ')';
	}
	istream& operator>>(istream& is, Date& dd)
	{
		int y, m, d;
		char ch1, ch2, ch3, ch4;
		is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;
		if (!is) return is;
		if (ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ')') { // oops: format error
			is.clear(ios_base::failbit); // set the fail bit
			return is;
		}
		dd = Date(y, Month(m), d); // update dd
		return is;
	}
	enum class Day {
		sunday, monday, tuesday, wednesday, thursday, friday, saturday
	};

} // Chrono


namespace TheLibrary {

	enum class Genre {
		fiction = 0, nonfiction, periodical, biography, children
	};


	struct ISBN {
	private:
		string id;
		const int n0;
		const int n1;
		const int n2;
		const string s;
	public:
		ISBN(int nn0, int nn1, int nn2, string ss) :
			n0{ nn0 },
			n1{ nn1 },
			n2{ nn2 },
			s{ ss },
			id{ "" }
		{
			// cout << "creating ISBN" << endl;
			id = to_string(n0) + "-" + to_string(n1) + "-" + to_string(n2) + s;
		};
		const string get_id()const { return id; }
	};


	class Patron
	{
	public:
		Patron(string name, int numb) : username{ name }, number{ numb }, fee{0} {};
		string get_username() const { return username; };
		int get_number() const { return number; };
		double get_fee() const { return fee; };
		void set_fee(double new_fee) { 
			if (new_fee >= 0) fee = new_fee;
			else cout << "Setting fee had failed. You can't have negative fee: " << new_fee << endl;
		}
	private:
		string username;
		int number;
		double fee;
	};



	class Book
	{
	public:
		Book();
		Book(string author, string copyright, ISBN isbn, string title, Genre ge);
		string get_author() const { return author; };
		string get_copyright() const { return copyright; };
		string get_isbn() const { return isbn; };
		string get_title() const { return title; };
		Genre get_genre() const { return genre; };
		bool is_checked() const { return checked; };
		void check() { checked = true; return; };
		void uncheck() { checked = false; return; };
	private:
		string author;
		string copyright;
		string isbn;
		string title;
		Genre genre;
		bool checked;
	};

	Book::Book() :
		author{ "NoName" },
		copyright{ "Creative Commons Corporation" },
		isbn{ "000-0-000-xxx" },
		title{ "0 book" },
		genre {Genre::fiction},
		checked{ true }
	{};

	Book::Book(string author, string copyright, ISBN isbn, string title, Genre gen) :
		author{ author },
		copyright{ copyright },
		isbn{ isbn.get_id() },
		title{ title },
		genre{ gen },
		checked{ true }
	{
		//cout << "creating book" << endl; 
	};

	bool has_debt(const Patron& user) {
		double fee = user.get_fee();
		if (fee) return true;
		return false;
	}
	bool operator == (const Book& b1, const Book& b2) {
		return 
			b1.get_isbn() == b2.get_isbn() && 
			b1.get_title() == b2.get_title() && 
			b1.get_author() == b2.get_author();
	}
	bool operator != (const Book& b1, const Book& b2) {
		return !(b1 == b2);
	}
	bool operator == (const Patron& b1, const Patron& b2) {
		return
			b1.get_number() == b2.get_number() &&
			b1.get_username() == b2.get_username() &&
			b1.get_fee() == b2.get_fee();
	}
	bool operator != (const Patron& b1, const Patron& b2) {
		return !(b1 == b2);
	}
	ostream& operator << (ostream& os, Book& b) {
		cout << "Author: " << b.get_author() << endl;
		cout << "Title: " << b.get_title() << endl;
		cout << "Copyright: " << b.get_copyright() << endl;
		cout << "ISBN: " << b.get_isbn() << endl;
		cout << "Book is checked: " << b.is_checked() << endl;
		Genre gen = b.get_genre();
		switch (gen) {
		case Genre::fiction:
			cout << "Genre: fiction" << endl; break;
		case Genre::nonfiction:
			cout << "Genre: nonfiction" << endl;  break;
		case Genre::periodical:
			cout << "Genre: periodical" << endl;  break;
		case Genre::biography:
			cout << "Genre: biography" << endl;  break;
		case Genre::children:
			cout << "Genre: children" << endl;  break;
		}
		cout << "--------------" << endl;
		return os;
	}
	ostream& operator << (ostream& os, Patron& user) {
		cout << user.get_username() + " has " << user.get_number() << " id." << endl;
		cout << user.get_username() + " has a debt: " << has_debt(user) << endl;
		cout << "His debt is: " << user.get_fee() << endl << endl;
		cout << "--------------" << endl;
		return os;
	}
	
	/*


	and check out books.
	Whenever a user checks out a book, have the library make sure that both the user and the book are in the library.
	If they aren’t, report an error.
	
	Then check to make sure that the user owes no fees. If the user does, report an error.

	If not, create a Transaction, and place it in the vector of Transactions.

	Also write a function that will return a vector that contains the names of all Patrons who owe fees.

	*/
	 
	class Library
	{
	public:
		Library() : books{}, users{}, transactions{} {};
		class Invalid { };
		
		const Book& add_book(const Book book) {
			books.push_back(book);
			cout << "Book " + book.get_title() + " was added to the library" << endl;
			return books[books.size() - 1];
		};   // need to check this one
		
		const Patron& add_patron(const Patron p) {
			users.push_back(p);
			cout << "User " + p.get_username() + " was added to the library" << endl;
			return users[users.size() - 1];
		};   // need to check this one
		
		const bool book_exists(string b) const {
			for (Book book : books)
				if (book.get_isbn() == b) return true;
			return false;
		}
	
		const bool user_exists(int id) const {
			for (Patron user : users)
				if (user.get_number() == id) return true;
			return false;
		}

		vector <Patron> get_debitors() const;
		
		void check_out(const string isbn, const int user_id, const Chrono::Date& d);


	private:
		vector <Book> books;
		vector <Patron> users;
		struct Transaction;
		vector <Transaction> transactions;
	
		Book& find_book_link(const string isbn) {
			for (int i = 0; i < books.size(); ++i)
				if (isbn == books[i].get_isbn()) return books[i];
		}
		
		Patron& find_user_link(int id) {
			for (int i = 0; i < users.size(); ++i)
				if (id == users[i].get_number())
					return users[i];
		}
	};

	struct Library::Transaction {
			Transaction(const Book& b, const Patron& p, Chrono::Date d) : book{ b }, user{ p }, date{ d }{};
			Book book;
			Patron user;
			Chrono::Date date;
	};

	vector <Patron> Library::get_debitors() const {
		vector <Patron> debitors;
		for (Patron u : users) {
			if (u.get_fee()) {
				debitors.push_back(u);
				cout << "Username " + u.get_username() + " is in debitors list" << endl;
			}
		}
		return debitors;
	}

	void Library::check_out(const string isbn, const int user_id, const Chrono::Date& d)
	{
		if (!book_exists(isbn)) {
			cout << "Check-out of book " << isbn << " had failed. Book is not found." << endl;
			throw Invalid{};
		}
		if (!user_exists(user_id)) {
			cout << "Check-out of user " << isbn << " had failed. User is not found." << endl;
			throw Invalid{};
		}
		Book b = find_book_link(isbn);
		Patron u = find_user_link(user_id);
		if (!(b.is_checked())) cout << "Warning. Book was unchecked for some reason." << endl;
		if (u.get_fee()) {
			cout << "User can't be checked - he owes money: " << u.get_fee() << endl;
			throw Invalid{};
		}
		Transaction tran = Transaction(b, u, d);
		transactions.push_back(tran);
		cout << "Transaction was added." << endl;
	}
}


int main() {
	try {
		using namespace TheLibrary;

		Library lib = Library();

		ISBN book_id = ISBN(123, 4, 321, "kek");
		ISBN book_id1 = ISBN(1223, 4, 321, "kek");
		ISBN book_id2 = ISBN(21, 12, 21312, "zxc");
		ISBN book_id3 = ISBN(1433, 55, 3687, "kfs");
		ISBN book_id4 = ISBN(4312, 767, 8777, "wer");
		
		Book book = Book("Stephen King", "No License 2019", book_id, "The Stand", Genre::fiction);
		Book book1 = Book("Stephen King", "No License 2019", book_id1, "It", Genre::children);
		Book book2 = Book("Henry Kissiniger", "License 2019", book_id2, "World order", Genre::biography);
		Book book3 = Book("Stephen J. Dubner", "License 2019", book_id3, "Freakonomics", Genre::nonfiction);
		Book book4 = Book("Daniel Kahneman", "License 2019", book_id4, "Thinking, fast and slow", Genre::nonfiction);

		Patron user = Patron("Anna", 4312);
		Patron user1 = Patron("Bob", 12345);
		Patron user2 = Patron("Bill", 122);
		Patron user3 = Patron("Frank", 312);
		Patron user4 = Patron("Pisikak", 1312);
		
		user.set_fee(30);
		user4.set_fee(320);
		
		lib.add_book(book); lib.add_book(book1); lib.add_book(book2); lib.add_book(book3); lib.add_book(book4);
		lib.add_patron(user); lib.add_patron(user1); lib.add_patron(user2); lib.add_patron(user3); lib.add_patron(user4);

		vector <Patron> elpartons = lib.get_debitors();
		
	}
	catch (exception& e) {
		cerr << "Error: " << e.what() << endl;
	}
}