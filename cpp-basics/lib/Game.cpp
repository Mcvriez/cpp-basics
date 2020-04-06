#include "Game.h"

bool is_number(const std::string& s)
{
    return !s.empty() && std::find_if(s.begin(), s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}

Map::Map(int sz) {
    map_size = sz; wumpus_awake = false;
    if (map_size < 12 || map_size > 200 || map_size % 2 != 0) throw std::runtime_error ("Map::Map invalid map_size");
    random_map();
    int bats = map_size / 10; int pits = map_size / 10;
    while (bats > 0) {
        int r = rand() % map_size;
        if (!cave[r].bat) {cave[r].bat = true; --bats;}
    }
    while (pits > 0) {
        int r = rand() % map_size;
        if (!cave[r].pit && !cave[r].bat) {cave[r].pit = true; --pits;}
    }
    while (true) {
        int r = rand() % map_size;
        if (!cave[r].pit && !cave[r].bat) {wumpus_room = cave[r].number; break;}
    }
    while (true) {
        int r = rand() % map_size;
        if (!cave[r].pit && !cave[r].bat && cave[r].number!= wumpus_room)
        {adventurer.current_room = cave[r].number; break;}
    }
    //print_map();
}

void Map::print_map() {
    if (tries > 1) cout << "Map was generated from " << to_string(tries) << " try\n";
    for (auto & i : cave)
    {
        cout << i.number << ":\t";
        if (i.bat) cout << "B";
        if (i.pit) cout << "P";
        if (i.number == wumpus_room) {cout << "W"; if (wumpus_awake) cout << '!';};
        if (i.number == adventurer.current_room) cout << "A";
        cout << "\t[";
        cout << i.passages[0]->number << "|";
        cout << i.passages[1]->number << "|";
        cout << i.passages[2]->number << "]";
        cout << endl;
    }
}

void Map::instruction() {
    const char * message = R"V0G0N(
WELCOME TO 'HUNT THE WUMPUS'

THE WUMPUS LIVES IN A CAVE OF 20 ROOMS: EACH ROOM HAS 3 TUNNELS LEADING TO OTHER
ROOMS. (LOOK AT A DODECAHEDRON TO SEE HOW THIS WORKS. IF YOU DON'T KNOW WHAT A
DODECAHEDRON IS, ASK SOMEONE)

***
HAZARDS:

BOTTOMLESS PITS - TWO ROOMS HAVE BOTTOMLESS PITS IN THEM
IF YOU GO THERE: YOU FALL INTO THE PIT (& LOSE!)

SUPER BATS  - TWO OTHER ROOMS HAVE SUPER BATS. IF YOU GO THERE, A BAT GRABS YOU
AND TAKES YOU TO SOME OTHER ROOM AT RANDOM. (WHICH MIGHT BE TROUBLESOME)

WUMPUS:

THE WUMPUS IS NOT BOTHERED BY THE HAZARDS (HE HAS SUCKER FEET AND IS TOO BIG FOR
A BAT TO LIFT). USUALLY HE IS ASLEEP. TWO THINGS WAKE HIM UP: YOUR ENTERING HIS
ROOM OR YOUR SHOOTING AN ARROW.

IF THE WUMPUS WAKES, HE MOVES (P=0.75) ONE ROOM OR STAYS STILL (P=0.25). AFTER
THAT, IF HE IS WHERE YOU ARE, HE EATS YOU UP (& YOU LOSE!)

YOU:

EACH TURN YOU MAY MOVE OR SHOOT A CROOKED ARROW
MOVING: YOU CAN GO ONE ROOM (THRU ONE TUNNEL)
ARROWS: YOU HAVE 5 ARROWS. YOU LOSE WHEN YOU RUN OUT.

EACH ARROW CAN GO FROM 1 TO 5 ROOMS: YOU AIM BY TELLING THE COMPUTER THE ROOMS
YOU WANT THE ARROW TO GO TO. IF THE ARROW CAN'T GO THAT WAY (IE NO TUNNEL) IT
MOVES AT RANDOM TO THE NEXT ROOM.

IF THE ARROW HITS THE WUMPUS: YOU WIN.

IF THE ARROW HITS YOU: YOU LOSE.

WARNINGS:

WHEN YOU ARE ONE ROOM AWAY FROM WUMPUS OP HAZARD, THE COMPUTER SAYS:

WUMPUS - 'I SMELL A WUMPUS'

BAT - 'BATS NEARBY'

PIT - 'I FEEL A DRAFT'

***
    )V0G0N";
    cout << message;
}

void Map::status_message() {
    system("clear");
    Room room = cave[adventurer.current_room - 1];
    cout << "\nYOU ARE IN ROOM " << room.number << endl;

    if (room.passages[0]->number == wumpus_room ||
        room.passages[1]->number == wumpus_room ||
        room.passages[2]->number == wumpus_room)
        cout << "I SMELL A WUMPUS\n";
    if (room.passages[0]->bat ||
        room.passages[1]->bat ||
        room.passages[2]->bat)
        cout << "BATS NEARBY!\n";
    if (room.passages[0]->pit ||
        room.passages[1]->pit ||
        room.passages[2]->pit)
        cout << "I FEEL A DRAFT\n";

    cout << "TUNNELS LEAD TO "
         << room.passages[0]->number << " "
         << room.passages[1]->number << " "
         << room.passages[2]->number << "\n";
}

void Map::random_map() {
    if (tries == 1000) {throw std::runtime_error("can't generate random map after " + to_string(tries) + " attempts;\n" );}
    cave.clear();
    int counter = 100;
    for (int i = 1; i <= map_size; ++i) {cave.emplace_back(i);}
    vector <int> invar (map_size);

    for (int i = 0; i < invar.size(); ++i) {invar[i] = i;}
    for (auto & i : cave) {
        while (i.passages[0] == nullptr) {
            int randint = invar[rand() % invar.size()];
            if (i.number != randint + 1) {
                i.passages[0] = &cave[randint]; cave[randint].passages[0] = &i;
                invar.erase(invar.begin());
                invar.erase(std::remove(invar.begin(), invar.end(), randint), invar.end());
                break;}}}

    for (int i = 0; i < map_size; ++i) {invar.push_back(i);}
    for (auto & i : cave) {
        while (i.passages[1] == nullptr) {
            if (counter == 0) {++tries; random_map(); };
            --counter;
            int randint = invar[rand() % invar.size()];
            if (i.number != randint + 1 && i.passages[0]->number != randint + 1 &&
                (i.passages[0]->passages[1] == nullptr ||
                 i.passages[0]->passages[1] != cave[randint].passages[0]) // eliminate squares
            ) {
                i.passages[1] = &cave[randint]; cave[randint].passages[1] = &i;
                invar.erase(invar.begin());
                invar.erase(std::remove(invar.begin(), invar.end(), randint), invar.end());
                break;}}}

    for (int i = 0; i < map_size; ++i) {invar.push_back(i);}
    for (auto & i : cave) {
        while (i.passages[2] == nullptr) {
            if (counter == 0) {++tries; random_map(); };
            --counter;
            bool flag = true;
            int randint = invar[rand() % invar.size()];
            for (auto r : i.passages) {  // eliminate triangles
                if (r != nullptr) {
                    for (auto cr : r->passages){
                        if (cr != nullptr && cr == &cave[randint]) flag = false; }
                }
                if
                (cave[randint].passages[0] == i.passages[0]->passages[0] ||
                cave[randint].passages[0] == i.passages[0]->passages[1] ||
                cave[randint].passages[1] == i.passages[0]->passages[0] ||
                cave[randint].passages[1] == i.passages[0]->passages[1] ||
                cave[randint].passages[0] == i.passages[1]->passages[0] ||
                cave[randint].passages[0] == i.passages[1]->passages[1] ||
                cave[randint].passages[1] == i.passages[1]->passages[0] ||
                cave[randint].passages[1] == i.passages[1]->passages[1] ||
                (i.passages[0]->passages[2] != nullptr && cave[randint].passages[0] == i.passages[0]->passages[2]) ||
                (i.passages[0]->passages[2] != nullptr && cave[randint].passages[1] == i.passages[0]->passages[2]) ||
                (i.passages[1]->passages[2] != nullptr && cave[randint].passages[0] == i.passages[1]->passages[2]) ||
                (i.passages[1]->passages[2] != nullptr && cave[randint].passages[1] == i.passages[1]->passages[2]))
                    flag = false;       // eliminate squares
            }
            if (flag &&
                i.number != randint + 1 &&
                i.passages[0] != &cave[randint] &&
                i.passages[1] != &cave[randint])
            {
                i.passages[2] = &cave[randint]; cave[randint].passages[2] = &i;
                invar.erase(invar.begin());
                invar.erase(std::remove(invar.begin(), invar.end(), randint), invar.end());
                break;}}}

}

void Map::action() {
    char ch;
    cout << "SHOOT OR MOVE (S-M)?\n";
    string answ;
    getline(cin, answ);
    if (answ == "S" || answ == "s") {
        cout << "Rooms?\n";
        int x; vector <int> shooting;

        while (cin.get(ch) && ch != '\n') {
            cin.unget();
            if ((isdigit(ch) || ch == ' ') && adventurer.arrows > 0) {
                cin >> x;
                shooting.push_back(x);
                --adventurer.arrows;
            }
            else {
                while (cin.get(ch) && ch != '\n') {}
            }
        }

        for (int i : shooting) cout << i << " ";
        cout << endl;
    }
    else if (answ == "M" || answ == "m") {
        string an;
        while (true) {
            cout << "WHERE TO?\n";
            getline(cin, an);
            if (is_number(an) && an.size() < 8) {
                if
                (stoi(an) == cave[adventurer.current_room - 1].passages[0]->number ||
                stoi(an) == cave[adventurer.current_room - 1].passages[1]->number ||
                stoi(an) == cave[adventurer.current_room - 1].passages[2]->number)
                    {
                        adventurer.current_room = stoi(an);
                        break;
                    }
                else {cout << "THERE IS NO PASSAGE TO ROOM " << an << endl; }
            }
            else {cout << "PATH IS UNCLEAR\n"; }
        }
    }
    else {cout << "HUH?";}
}