#include "lib/Link.h"

/*
    11. Complete the “list of gods” example from §17.10.1 and run it.
*/

void null_test(){
    Link a {"Master"};
    Link* pa = &a;
    pa = nullptr;

    pa->find("abc");
    pa->insert(new Link {"abc"});
}

void print_all(Link* p)
{
    cout << "{ ";
    while (p) {
        cout << p -> value;
        p = p -> next();
        if (p) cout << ", ";
    }
    cout << " }\n";
}

void gods(){
    Link* norse_gods = new Link{"Thor"};
    norse_gods = norse_gods->insert(new Link{"Odin"});
    norse_gods = norse_gods->insert(new Link{"Zeus"});
    norse_gods = norse_gods->insert(new Link{"Freia"});

    Link* greek_gods = new Link{"Hera"};
    greek_gods = greek_gods->insert(new Link{"Athena"});
    greek_gods = greek_gods->insert(new Link{"Mars"});
    greek_gods->add(new Link{"Hermes"});
    greek_gods = greek_gods->insert(new Link{"Poseidon"});

    Link* p2 = norse_gods->find("Zeus");
    if (p2) {
        if (p2==norse_gods) norse_gods = p2->next(); // re-binding norse_gods to the first element if Zeus was first
        p2->erase();
        greek_gods = greek_gods->insert(p2);
    }

    Link* p = greek_gods->find("Mars");
    if (p) p->value = "Ares";



    print_all(norse_gods);
    print_all(greek_gods);
}

int main()
try
{


    gods();


}
catch (exception& e)
{
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}

