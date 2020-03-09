#ifndef CPP_BASICS_LINK_H
#define CPP_BASICS_LINK_H

#include <iostream>
#include <utility>
using namespace std;

//• insert: insert before an element
//• add: insert after an element
//• erase: remove an element
//• find: find a Link with a given value
//• advance: get the nth successor

//1 Modify the Link class from §17.10.1 to hold a value of a struct God.
//struct God should have members of type string: name, mythology, vehicle, and weapon.
//For example, God{"Zeus", "Greek", "", "lightning"} and God{"Odin", "Norse", "Eight-legged flying horse called Sleipner", "Spear called Gungnir"}.


struct God {
    God (const string& n, const string& m, const string& v, const string& w)
    : name {n}, mythology{m}, vehicle {v}, weapon{w} {};
    string name;
    string mythology;
    string vehicle;
    string weapon;
};

class Link {
public:
    const God description;

    explicit Link(God god, Link* p = nullptr, Link* s = nullptr) : description {god}, prev{p}, succ{s} { }

    Link* erase();
    const Link* find(const string& s) const;
    Link* insert(Link* n) ;
    Link* add(Link* n) ;
    Link* find(const string& s);
    Link* advance(int n) const;
    Link* add_ordered(Link* n);
    Link* next() const { return succ; }
    Link* previous() const { return prev; }
    Link* pop();
private:
    Link* prev;
    Link* succ;


};


#endif //CPP_BASICS_LINK_H