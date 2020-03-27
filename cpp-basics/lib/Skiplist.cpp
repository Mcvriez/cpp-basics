#include <iostream>
#include "Skiplist.h"
using namespace std;

int Skiplist::max_level = 32;

int Skiplist::random_level() const{
    int n = 0;
    while (true) {
        if (n == max_level) return n;
        if (rand() % probability_divisor > 0)
            ++n;
        else
            return n;}}

int Skiplist::find_verbose(int key) {
    int steps = 0;
    int lev = level;
    Node* node = &header;
    Node* backup = node;
    while(true){
        if (key > node->key) {
            backup = node;
            node = node->next[lev];
            cout << "→";
        }
        else {
            node = backup;
            if (lev <= 0) break;
            --lev;
            cout << "⃖↓";
        }
        ++steps;
    }
    cout << endl;
    return steps;
}

Node* Skiplist::find(int key, int max_lev) {
    int lev = level;
    Node* node = &header;
    Node* backup = node;
    while(true){
        if (key > node->key) {
            backup = node;
            node = node->next[lev];
        }
        else {
            node = backup;
            if (lev <= max_lev) break;
            --lev;
        }
    }
    return node;
}

void Skiplist::add(int key) {
    Node* prev = find(key);
    if (prev->next[0]->key == key) {
        //std::cerr << "Skiplist::add duplicate\n";
        return;
    }
    int node_level = random_level();
    if (node_level > level) level = node_level;
    std::vector <Node*> v_initial (node_level + 1);
    Node* current = new Node {key, node_level, prev};
    current->next = v_initial;
    for (int i = node_level; i >= 0; --i) {
        prev = find(key, i);
        current->next[i] = prev->next[i];
        prev->next[i] = current;
    }
    current->next[0]->prev = current;
}

void Skiplist::print() {
    Node* start = header.next[0];
    cout << "H\t" << level + 1 << " [";
    for (int i = 0; i <= level; ++i) { cout << header.next[i]->key << " ";}
    cout << "]\n";
    while (start->key < tail.key){
        std::cout << start->key << "\t" << start->next.size() << "|"<< start->prev->key << " [ ";
        for (Node* x : start->next) {cout << x->key << " ";}
        cout << "]\n";
        start = start->next[0];
    }
    cout << "T\t" << level + 1 << '|' << tail.prev->key << endl;
}

void Skiplist::erase(int key) {
    Node* current = find(key)->next[0];
    if (current->key != key) {cout << "Skiplist::erase - key not found\n"; return;}
    for (int i = (int)current->next.size() - 1; i >= 0; --i) {
        Node* prev = find(key, i);
        prev->next[i] = current->next[i];
    }
    current->next[0]->prev = find(key);
    delete current;
}




