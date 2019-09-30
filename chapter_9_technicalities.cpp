#include "std_lib_facilities.h"

/*

 This exercise and the next few require you to design and implement a
Book class, such as you can imagine as part of software for a library.

Book should have members for the :

ISBN, 
title, 
author, 
copyright date. 

Also store data on whether or not the book is checked out. 
Create functions for returning those data values. 

Create functions for checking a book in and out. 
Do simple validation of data entered into a Book ; for example, 
accept ISBNs only of the form n-n-n-x where n is an integer and x is a digit or a letter.
Store an ISBN as a string

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
			cout << "creating ISBN" << endl;
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
	{cout << "creating book" << endl; };

	void list_book(Book& b) {
		cout << "is_checked: "<< b.is_checked() << endl;
		cout << "get_author: " << b.get_author() << endl;
		cout << "get_copyright: " << b.get_copyright() << endl;
		cout << "get_isbn: " << b.get_isbn() << endl;
		cout << "checking book.." << endl;
		b.check();
		cout << "is_checked: " << b.is_checked() << endl;
	}
}



int main() {
	try {
		Bookstore::ISBN book_id = Bookstore::ISBN(123, 4, 321, "kek");
		Bookstore::Book new_book = Bookstore::Book("Stephen King", "No License 2019", book_id, "The Stand");
		Bookstore::list_book(new_book);

	}
	catch (exception& e) {
		cerr << "Error: " << e.what() << endl;
		return 1;
	}
}