#include "Link.h"

const Link *Link::find(const string &s) const {
    const Link* p  = this;
    while(p){
        if (p->value == s) return p;
        p = p->next();
    }
    return nullptr;
}
Link* Link::find(const string &s) {
    Link* p  = this;
    while(p){
        if (p->value == s) return p;
        p = p->next();
    }
    return nullptr;
}

Link* Link::advance(int n) const {
    Link *p = nullptr;
    if (n > 0) {
        while (n--) {
            if (next() == nullptr) return nullptr;
            p = next();
        }
    }
    else if (n < 0) {
        while (n++) {
            if (previous() == nullptr) return nullptr;
            p = previous();
        }
    }
    return p;
}
Link* Link::insert(Link* n) {
    if (n == nullptr) return this;
    if (this == nullptr) {cout << "nullptr -> Link::insert\n"; return this;}
    n->succ = this;
    if (prev) prev->succ = n;
    n->prev = prev;
    prev = n;
    return n;
}
Link* Link::erase()
{
    Link* p = this;
    if (p == nullptr) {cout << "nullptr -> Link::erase\n"; return nullptr;}
    if (p->succ) p->succ->prev = p->prev;
    if (p->prev) p->prev->succ = p->succ;
    return p->succ;
}

Link* Link::add(Link *n) {
    if (n == nullptr) return this;
    if (this == nullptr) {cout << "nullptr -> Link::add\n"; return this;}
    n->prev = this;
    if (succ) {
        n->succ = succ;     // changing the adding link successor
        n->succ->prev = n;} // changing the predecessor of the next element after the inserted to the inserted
    this->succ = n;
    return n;
}

