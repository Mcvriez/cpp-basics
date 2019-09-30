#include "std_lib_facilities.h"

/*

Create an enumerated type for the Book class called Genre. Have the types be fiction, nonfiction, periodical,
biography, and children. Give each book a Genre and make appropriate changes to the Book constructor and member
functions.

*/

namespace Bookstore {

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

	class Book
	{
	public:
		Book();
		Book(string author, string copyright, ISBN isbn, string title, Genre ge);
		const string get_author() const { return author; };
		const string get_copyright() const { return copyright; };
		const string get_isbn() const { return isbn; };
		const string get_title() const { return title; };
		const Genre get_genre() const { return genre; };
		const bool is_checked() const { return checked; };
		void check() { checked = true; return; };
		void uncheck() { checked = false; return; };
	private:
		const string author;
		const string copyright;
		const string isbn;
		const string title;
		const Genre genre;
		bool checked;
	};

	Book::Book() :
		author{ "NoName" },
		copyright{ "Creative Commons Corporation" },
		isbn{ "000-0-000-xxx" },
		title{ "0 book" },
		genre {Genre::fiction},
		checked{ false }
	{};

	Book::Book(string author, string copyright, ISBN isbn, string title, Genre gen) :
		author{ author },
		copyright{ copyright },
		isbn{ isbn.get_id() },
		title{ title },
		genre{ gen },
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
	Bookstore::Genre gen = b.get_genre();
	switch (gen){
		// nonfiction, periodical, biography, children
		case Bookstore::Genre::fiction:
			cout << "Genre: fiction" << endl; break;
		case Bookstore::Genre::nonfiction:
			cout << "Genre: nonfiction" << endl;  break;
		case Bookstore::Genre::periodical:  break;
			cout << "Genre: periodical" << endl;  break;
		case Bookstore::Genre::biography:
			cout << "Genre: biography" << endl;  break;
		case Bookstore::Genre::children:
			cout << "Genre: children" << endl;  break;
	}
	cout << "--------------" << endl;
	return os;
}



int main() {
	try {
		Bookstore::ISBN book_id = Bookstore::ISBN(123, 4, 321, "kek");
		Bookstore::Book book = Bookstore::Book("Stephen King", "No License 2019", book_id, "The Stand", Bookstore::Genre::fiction);

		Bookstore::ISBN book_id1 = Bookstore::ISBN(1223, 4, 321, "kek");
		Bookstore::Book book1 = Bookstore::Book("Stephen King", "No License 2019", book_id1, "It", Bookstore::Genre::children);
		book1.check();

		cout << book;
		cout << book1;
	}
	catch (exception& e) {
		cerr << "Error: " << e.what() << endl;
		return 1;
	}
}