#include "Link.h"
template <typename T>
const Link<T> *Link<T>::find(const string &s) const {
    const Link* p  = this;
    while(p){
        if (p->description.name == s) return p;
        p = p->next();
    }
    return nullptr;
}

template <typename T>
Link<T>* Link<T>::find(const string &s) {
    Link* p  = this;
    while(p){
        if (p->description.name == s) return p;
        p = p->next();
    }
    return nullptr;
}

template <typename T>
Link<T>* Link<T>::advance(int n) const {
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

template <typename T>
Link<T>* Link<T>::insert(Link* n) {
    if (n == nullptr) return this;
    if (this == nullptr) {cout << "nullptr -> Link::insert\n"; return this;}
    n->succ = this;
    if (prev) prev->succ = n;
    n->prev = prev;
    prev = n;
    //cout << this->description.name << " inserts " << n->description.name << endl;
    return n;
}

template <typename T>
Link<T>* Link<T>::erase()
{
    Link* p = this;
    if (p == nullptr) {cout << "nullptr -> Link::erase\n"; return nullptr;}
    if (p->succ) p->succ->prev = p->prev;
    if (p->prev) p->prev->succ = p->succ;
    return p->succ;
}

template <typename T>
Link<T>* Link<T>::pop()
{
    Link* p = this;
    if (p == nullptr) {cout << "nullptr -> Link::erase\n"; return nullptr;}
    if (p->succ) p->succ->prev = p->prev;
    if (p->prev) p->prev->succ = p->succ;

    p->prev = nullptr; p->succ = nullptr;
    return p->succ;
}

template <typename T>
Link<T>* Link<T>::add(Link *n) {
    if (n == nullptr) return this;
    if (this == nullptr) {cout << "nullptr -> Link::add\n"; return this;}
    n->prev = this;
    if (succ) {
        n->succ = succ;     // changing the adding link successor
        n->succ->prev = n;} // changing the predecessor of the next element after the inserted to the inserted
    this->succ = n;
    //cout << this->description.name << " adds " << n->description.name << endl;
    return n;
}

template <typename T>
Link<T>* Link<T>::add_ordered(Link *n) {
    if (n == nullptr) return this;
    if (this == nullptr) {
        cout << "nullptr -> Link::add\n";
        return this;}
    Link * p;
    p = this;

    while(p) {
        if (!p->prev && !p->succ) break;
        if (n->description.name < p->description.name) {
            if (p->prev && n->description.name < p->prev->description.name) { p = p->prev;}
            else return p->insert(n);
        }
        else if (n->description.name > p->description.name) {
            if (p->succ  && n->description.name > p->succ->description.name) { p = p->succ; }
            else return p->add(n);
        }
        else break;
    }

    if (n->description.name > p->description.name) {return p->add(n);}
    return p->insert(n);
}