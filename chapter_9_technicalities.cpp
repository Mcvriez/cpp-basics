#include "std_lib_facilities.h"

/*

Add operators for the Book class. 
Have the == operator check whether the ISBN numbers are the same for two books.
Have != also compare the ISBN numbers. 
Have a << print out the title, author, and ISBN on separate lines.

*/

namespace Bookstore {
	
	struct ISBN {
		 string id;
		const int n0;
		const int n1;
		const int n2;
		const string s;
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
	};

	class Book
	{
	public:
		Book();
		Book(string author, string copyright, ISBN isbn, string title);
		const string get_author() const { return author; };
		const string get_copyright() const { return copyright; };
		const string get_isbn() const { return isbn; };
		const string get_title() const { return title; };
		const bool is_checked() const { return checked; };
		void check() { checked = true; return; };
		void uncheck() { checked = false; return; };
	private:
		const string author;
		const string copyright;
		const string isbn;
		const string title;
		bool checked;
	};

	Book::Book() :
		author{ "NoName" },
		copyright{ "Creative Commons Corporation" },
		isbn{ "000-0-000-xxx" },
		title{ "0 book" },
		checked{ false }
	{};

	Book::Book(string author, string copyright, ISBN isbn, string title) :
		author{ author },
		copyright{ copyright },
		isbn{ isbn.id },
		title{ title },
		checked{ false }
	{
		//cout << "creating book" << endl; 
	};


}

bool operator == (const Bookstore::Book& b1, const Bookstore::Book& b2) {
	return b1.get_isbn() == b2.get_isbn();
}
bool operator != (const Bookstore::Book& b1, const Bookstore::Book& b2) {
	return b1.get_isbn() != b2.get_isbn();
}

ostream& operator << (ostream& os, Bookstore::Book& b) {
	cout << "Author: " << b.get_author() << endl;
	cout << "Title: " << b.get_title() << endl;
	cout << "Copyright: " << b.get_copyright() << endl;
	cout << "ISBN: " << b.get_isbn() << endl;
	cout << "Book is checked: " << b.is_checked() << endl;
	return os;
}



int main() {
	try {
		Bookstore::ISBN book_id = Bookstore::ISBN(123, 4, 321, "kek");
		Bookstore::Book book = Bookstore::Book("Stephen King", "No License 2019", book_id, "The Stand");
		Bookstore::ISBN book_id1 = Bookstore::ISBN(1223, 4, 321, "kek");
		Bookstore::Book book1 = Bookstore::Book("Stephen King", "No License 2019", book_id1, "The Stand");
		cout << book;
		if (book1 == book) { cout << "Equal " << endl; }
		if (book1 != book) { cout << "Not equal " << endl; }
	}
	catch (exception& e) {
		cerr << "Error: " << e.what() << endl;
		return 1;
	}
}