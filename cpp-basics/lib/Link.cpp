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
    else if (n < 0)  p = const_cast<Link *>(this);
    return p;
}
Link* Link::insert(Link* n) {
    if (n == nullptr) return this;
    if (this == nullptr) {cout << "nullptr -> Link::insert\n"; return this;}
    n->succ = this;
    return n;
}
Link* Link::erase()
{
    Link* p = this;
    if (p == nullptr) {cout << "nullptr -> Link::erase\n"; return nullptr;}
    return p->succ;
}

Link *Link::add(Link* n) {
    Link* p = this;
    while(p->next()){
        p = p->next();
    }
    p->succ = n;
    return this;
}

