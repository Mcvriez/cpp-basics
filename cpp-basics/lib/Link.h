#ifndef CPP_BASICS_LINK_H
#define CPP_BASICS_LINK_H

#include <iostream>
#include <utility>
using namespace std;


struct God {
    God (const string& n, const string& m, const string& v, const string& w)
            : name {n}, mythology{m}, vehicle {v}, weapon{w} {};
    string name;
    string mythology;
    string vehicle;
    string weapon;
};

template <typename T>
class Link {
public:
    const T description;
    explicit Link(T t, Link* p = nullptr, Link* s = nullptr) : description {t}, prev{p}, succ{s} { }
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