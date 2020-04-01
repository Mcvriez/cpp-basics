#ifndef CPP_BASICS_GAME_H
#define CPP_BASICS_GAME_H

#include <iostream>
#include <vector>
using namespace std;

struct Room {
    explicit Room (int n) : number {n}, connected_rooms {3, nullptr}, pit {false}, bat {false} {};
    int number;
    bool pit;
    bool bat;
    std::vector <Room*> connected_rooms;
    ~Room() {for (auto r : connected_rooms) delete r;}
};
struct Adventurer {
    Adventurer() : current_room {0}, arrows {5}, dead {false} {};
    int current_room;
    int arrows;
    bool dead;
};

class Map {
public:
    explicit Map (int sz);
    void print_map();
    bool game_over() {return adventurer.dead;}
    static void instruction();
    void status_message();
private:
    Adventurer adventurer;
    bool wumpus_awake;
    int wumpus_room;
    int map_size;
    std::vector <Room> cave;
};


#endif //CPP_BASICS_GAME_H
