#include "Game.h"

Map::Map(int sz) {
    map_size = sz; wumpus_awake = false;
    if (map_size < 4 || map_size > 200) throw std::runtime_error ("Map::Map invalid map_size");
    if (map_size % 2 != 0) ++map_size;
    try
    {
        for (int i = 1; i <= map_size; ++i) {cave.emplace_back(i);}
        vector <int> invar (map_size * 3);
        for (int i = 0; i < invar.size(); ++i) { invar[i] = 1 + i / 3;}
        for (int i = 0; i < cave.size(); ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if (cave[i].connected_rooms[j] == nullptr) {
                    int randint = rand() % invar.size();
                    int counter = 0;
                    while (
                            invar[randint] == cave[i].number ||
                            (cave[i].connected_rooms[0] != nullptr && cave[i].connected_rooms[0]->number
                                                                      == invar[randint]) ||
                            (cave[i].connected_rooms[1] != nullptr && cave[i].connected_rooms[1]->number
                                                                      == invar[randint]) ||
                            (cave[i].connected_rooms[2] != nullptr && cave[i].connected_rooms[2]->number
                                                                      == invar[randint])
                            ) // can't link to itself, cant have duplicated channels connecting same two rooms
                    {
                        randint = rand() % invar.size();
                        ++ counter;
                        if (counter > 1000) throw std::runtime_error ("\nMap:Map infinite loop during the map generation\n");
                    }
                    int connected_room_loc = invar[randint] - 1;
                    Room* random_room_link = &(cave[connected_room_loc]);
                    cave[i].connected_rooms[j] = random_room_link; // link current room with random room

                    for (int k = 0; k < 3; ++k) {
                        if (cave[connected_room_loc].connected_rooms[k] == nullptr) {
                            cave[connected_room_loc].connected_rooms[k] = &cave[i]; // link random room with current
                            break;
                        }
                    }
                    invar.erase(invar.begin() + randint);
                }
            }
            invar.erase(std::remove(invar.begin(), invar.end(), i + 1), invar.end()); // remove current room from available invar
        }
    }
    catch (const std::runtime_error& error)
    {
        cave.clear();
        cout << "<infinite loop, re-creating random map>\n";
        Map {map_size};
    }

    int bats = 2; int pits = 2;
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
    print_map();
}

void Map::print_map() {
    for (auto & i : cave)
    {
        cout << i.number << ":\t";
        if (i.bat) cout << "B";
        if (i.pit) cout << "P";
        if (i.number == wumpus_room) {cout << "W"; if (wumpus_awake) cout << '!';};
        if (i.number == adventurer.current_room) cout << "A";
        cout << "\t[";
        cout << i.connected_rooms[0]->number << "|";
        cout << i.connected_rooms[1]->number << "|";
        cout << i.connected_rooms[2]->number << "]";
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
    Room room = cave[adventurer.current_room - 1];
    cout << "YOU ARE IN ROOM " << room.number << endl;

    if (room.connected_rooms[0]->number == wumpus_room ||
        room.connected_rooms[1]->number == wumpus_room ||
        room.connected_rooms[2]->number == wumpus_room)
        cout << "I SMELL A WUMPUS\n";
    if (room.connected_rooms[0]->bat ||
        room.connected_rooms[1]->bat ||
        room.connected_rooms[2]->bat)
        cout << "BATS NEARBY!\n";
    if (room.connected_rooms[0]->pit ||
        room.connected_rooms[1]->pit ||
        room.connected_rooms[2]->pit)
        cout << "I FEEL A DRAFT\n";

    cout << "TUNNELS LEAD TO "
    << room.connected_rooms[0]->number << " "
    << room.connected_rooms[1]->number << " "
    << room.connected_rooms[2]->number << "\n";
}

