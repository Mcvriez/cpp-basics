
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

class Link {
public:
    string value;
    explicit Link(string  v, Link* p = nullptr, Link* s = nullptr) : value{std::move(v)}, succ{s} { }
    const Link* find(const string& s) const;
    Link* find(const string& s);

    Link* erase();
    Link* add(Link* n);
    Link* insert(Link* n) ;
    Link* advance(int n) const;
    Link* next() const { return succ; }
private:
    Link* succ;
};


#endif //CPP_BASICS_LINK_H