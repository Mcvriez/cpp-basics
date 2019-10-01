#include "std_lib_facilities.h"

/*

Create a Patron class for the library. 
The class will have a:
- user’s name 
- library card number
- and library fees (if owed)

Have functions that access this data, as well as a function to set the fee of the user. 
Have a helper function that returns a Boolean (bool) depending on whether or not the user owes a fee

*/

namespace Library {

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
		const string get_username() const { return username; };
		const int get_number() const { return number; };
		const double get_fee() const { return fee; };
		void set_fee(double new_fee) { 
			if (new_fee >= 0) fee = new_fee;
			else cout << "Setting fee had failed. You can't have negative fee: " << new_fee << endl;
		}
	private:
		const string username;
		const int number;
		double fee;
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


	bool has_debt(Patron& user) {
		double fee = user.get_fee();
		if (fee) return true;
		return false;
	}
}

bool operator == (const Library::Book& b1, const Library::Book& b2) {
	return b1.get_isbn() == b2.get_isbn();
}
bool operator != (const Library::Book& b1, const Library::Book& b2) {
	return b1.get_isbn() != b2.get_isbn();
}

ostream& operator << (ostream& os, Library::Book& b) {
	cout << "Author: " << b.get_author() << endl;
	cout << "Title: " << b.get_title() << endl;
	cout << "Copyright: " << b.get_copyright() << endl;
	cout << "ISBN: " << b.get_isbn() << endl;
	cout << "Book is checked: " << b.is_checked() << endl;
	Library::Genre gen = b.get_genre();
	switch (gen){
		case Library::Genre::fiction:
			cout << "Genre: fiction" << endl; break;
		case Library::Genre::nonfiction:
			cout << "Genre: nonfiction" << endl;  break;
		case Library::Genre::periodical:  
			cout << "Genre: periodical" << endl;  break;
		case Library::Genre::biography:
			cout << "Genre: biography" << endl;  break;
		case Library::Genre::children:
			cout << "Genre: children" << endl;  break;
	}
	cout << "--------------" << endl;
	return os;
}



int main() {
	try {
		using namespace Library;
		ISBN book_id = ISBN(123, 4, 321, "kek");
		Book book = Book("Stephen King", "No License 2019", book_id, "The Stand", Genre::fiction);

		ISBN book_id1 = ISBN(1223, 4, 321, "kek");
		Book book1 = Book("Stephen King", "No License 2019", book_id1, "It", Genre::children);
		book1.check();

		Patron user = Patron("Anna", 4312);
		user.set_fee(-120);
		cout << user.get_username() + " has " <<  user.get_number() << " id." << endl;
		cout << user.get_username() + " has a debt: " << has_debt(user) <<  endl;
		cout << "Her debt is: " << user.get_fee() << endl << endl;


		cout << book;
		cout << book1;
	}
	catch (exception& e) {
		cerr << "Error: " << e.what() << endl;
		return 1;
	}
}