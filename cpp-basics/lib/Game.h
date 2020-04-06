#ifndef CPP_BASICS_GAME_H
#define CPP_BASICS_GAME_H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Room {
    explicit Room (int n = 0) : number {n}, passages {3, nullptr}, pit {false}, bat {false} {};
    int number;
    bool pit;
    bool bat;
    std::vector <Room*> passages;
    bool connected (int i) {
        for (Room* x: passages) {
            if (x->number == i) return true;
        }
        return false;
    }
    Room* random_pass() {return passages[rand() % 3];}
};

struct Adventurer {
    Adventurer() : current_room {nullptr}, arrows {5}, alive {true} {};
    Room* current_room;
    int arrows;
    bool alive;
};

struct Wumpus {
    Wumpus() : current_room {nullptr}, awake {false}, alive {true} {};
    Room* current_room;
    bool alive;
    bool awake;
    void move();
};

class Game {
public:
    explicit Game (int sz = 20);
    void print_map();
    bool game_over() {return !(adventurer.alive && wumpus.alive);}
    static void instruction();
    void status_message();
    void action();
    void loop () {
        while(!game_over()) {
            action();
        }
    };
private:
    int tries = 1;
    void random_map();
    void shoot(const vector <int> &t);
    Adventurer adventurer;
    Wumpus wumpus;
    int map_size;
    std::vector <Room> cave;
};


#endif //CPP_BASICS_GAME_H
