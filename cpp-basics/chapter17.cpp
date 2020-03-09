#include "lib/Link.h"

/*
    13.

    1 Modify the Link class from §17.10.1 to hold a value of a struct God.
    struct God should have members of type string: name, mythology, vehicle, and weapon.
    For example, God {"Zeus", "Greek", "", "lightning"} and God{"Odin", "Norse", "Eight-legged flying horse called Sleipner", "Spear called Gungnir"}.

    2 Write a print_all() function that lists gods with their attributes one per line.

    3 Add a member function add_ordered() that places its new element in its correct lexicographical position.

    4 Using the Links with the values of type God, make a list of gods from three mythologies;
    then move the elements (gods) from that list to three lexicographically ordered lists — one for each mythology.

*/

void const print_all (Link* p)
{
    cout << "------------\n";
    while(p->previous()) p = p->previous();
    while (p) {
        if (p->description.name != "~")
            cout << p -> description.name << ": "<< p -> description.weapon << "; "<< p -> description.vehicle << endl;
        p = p -> next();
    }

}

Link* gods(){
    Link*  gods = new Link {God {"Zeus", "Greek", "", "lightning"}};

    gods = gods->add_ordered (new Link {God{"Odin", "Norse", "Eight-legged flying horse called Sleipner", "Spear called Gungnir"}});
    gods = gods->add_ordered (new Link {God{"Thor", "Norse", "Chariot drawn by goats", "Mjöllnir"}});
    gods = gods->add_ordered (new Link {God{"Vídar", "Norse", "", "Unnamed sword"}});
    gods = gods->add_ordered (new Link {God{"Loki", "Norse", "", "Deception"}});
    gods = gods->add_ordered (new Link {God {"Poseidon", "Greek", "Chariot drawn by horses", "Trident"}});
    gods = gods->add_ordered (new Link {God {"Apollo", "Greek", "Chariot pulled by swans", "Bow and arrows"}});
    gods = gods->add_ordered (new Link {God {"Athena", "Greek", "", "Spear and aegis"}});
    gods = gods->add_ordered (new Link {God {"Huitzilopochtli", "Aztec", "", "Xiuhcoatl, turquoise snake"}});
    gods = gods->add_ordered (new Link {God {"Quetzalcoatl", "Aztec", "", "Lethal darts"}});
    gods = gods->add_ordered (new Link {God {"Tezcatlipoca", "Aztec", "", "Spear and shield"}});
    gods = gods->add_ordered(new Link {God {"Yogg Saron", "Old gods", "", "The Beast With a Thousand Maws"}});
    gods = gods->add_ordered(new Link {God {"C'Tun", "Old gods", "", "Madness and chaos"}});
    gods = gods->add_ordered(new Link {God {"N'Zoth", "Old gods", "", "Corruption and nightmares"}});
    return gods;
}



int main()
try
{
    Link* god_list = gods();
    //print_all(god_list);
    Link* aztec_gods = new Link {God {"~", "~", "", "~"}};
    Link* greek_gods = new Link {God {"~", "~", "", "~"}};
    Link* norse_gods = new Link {God {"~", "~", "", "~"}};
    Link* old_gods = new Link {God {"~", "~", "", "~"}};

    while(god_list->previous()) god_list = god_list->previous();
    while(god_list){
        Link* p = god_list;
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
catch (exception& e)
{
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}

