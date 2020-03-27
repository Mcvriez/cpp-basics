#include <vector>

struct Node {
    explicit Node(int k = 0, int lev = 1, Node* pr = nullptr) : key {k}, next(lev), prev {pr} {};
    int key;
    Node* prev;
    std::vector <Node*> next;
};

class Skiplist {
public:
    explicit Skiplist(int pd = 2) :
    probability_divisor {pd},
    level {0}
    {
        header.key = INT_MIN;
        tail.key = INT_MAX;
        std::vector <Node*> header_initial (max_level, &tail);
        header.next = header_initial;
        tail.prev = &header;
    };
    void erase(int k);
    void add(int k);
    void print();
    int find_verbose(int k);
private:
    Node* find(int k, int _max_lev = 0);
    static int max_level;
    int level;
    int probability_divisor;
    Node tail;
    Node header;
    std::vector <Node> links;
    int random_level() const;
};

