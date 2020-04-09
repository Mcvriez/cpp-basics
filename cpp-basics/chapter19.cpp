#include "lib/Link.h"
#include "lib/Link.cpp"

//4. Modify class Link from §17.9.3 to be a template with the type of value as the template argument.
// Then redo exercise 13 from Chapter 17 with Link<God>.

void const print_all (Link<God>* p)
{
    cout << "------------\n";
    while(p->previous()) p = p->previous();
    while (p) {
        if (p->description.name != "~")
            cout << p -> description.name << ": "<< p -> description.weapon << "; "<< p -> description.vehicle << endl;
        p = p -> next();
    }

}

Link<God>* gods(){
    Link<God>*  gods = new Link<God> {God {"Zeus", "Greek", "", "lightning"}};

    gods = gods->add_ordered (new Link<God> {God{"Odin", "Norse", "Eight-legged flying horse called Sleipner", "Spear called Gungnir"}});
    gods = gods->add_ordered (new Link<God> {God{"Thor", "Norse", "Chariot drawn by goats", "Mjöllnir"}});
    gods = gods->add_ordered (new Link<God> {God{"Vídar", "Norse", "", "Unnamed sword"}});
    gods = gods->add_ordered (new Link<God> {God{"Loki", "Norse", "", "Deception"}});
    gods = gods->add_ordered (new Link<God> {God {"Poseidon", "Greek", "Chariot drawn by horses", "Trident"}});
    gods = gods->add_ordered (new Link<God> {God {"Apollo", "Greek", "Chariot pulled by swans", "Bow and arrows"}});
    gods = gods->add_ordered (new Link<God> {God {"Athena", "Greek", "", "Spear and aegis"}});
    gods = gods->add_ordered (new Link<God> {God {"Huitzilopochtli", "Aztec", "", "Xiuhcoatl, turquoise snake"}});
    gods = gods->add_ordered (new Link<God> {God {"Quetzalcoatl", "Aztec", "", "Lethal darts"}});
    gods = gods->add_ordered (new Link<God> {God {"Tezcatlipoca", "Aztec", "", "Spear and shield"}});
    gods = gods->add_ordered (new Link<God> {God {"Yogg Saron", "Old gods", "", "The Beast With a Thousand Maws"}});
    gods = gods->add_ordered (new Link<God> {God {"C'Tun", "Old gods", "", "Madness and chaos"}});
    gods = gods->add_ordered (new Link<God> {God {"N'Zoth", "Old gods", "", "Corruption and nightmares"}});
    return gods;
}


int main()
try {
    Link<God>* god_list = gods();
    Link<God>* aztec_gods = new Link<God> {God {"~", "~", "", "~"}};
    Link<God>* greek_gods = new Link<God> {God {"~", "~", "", "~"}};
    Link<God>* norse_gods = new Link<God> {God {"~", "~", "", "~"}};
    Link<God>* old_gods = new Link<God> {God {"~", "~", "", "~"}};

    while(god_list->previous()) god_list = god_list->previous();
    while(god_list){
        Link<God>* p = god_list;
        god_list = god_list->erase();
        cout << p->description.name << " " << p << endl;
        if (p && p->description.mythology == "Greek") greek_gods->add_ordered(p);
        if (p && p->description.mythology == "Aztec") aztec_gods->add_ordered(p);
        if (p && p->description.mythology == "Norse") norse_gods->add_ordered(p);
        if (p && p->description.mythology == "Old gods") old_gods->add_ordered(p);
    }

    print_all(old_gods);
    print_all(norse_gods);
    print_all(greek_gods);
    print_all(aztec_gods);
}
catch (exception& e) { cerr << "exception: " << e.what() << endl;}
catch (...) {cerr << "exception\n";}

