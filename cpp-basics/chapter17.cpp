#include <iostream>
using namespace std;

/*

4. Consider what happens if you give strdup(), findx(), and strcmp() an argument that is not a C-style string.
Try it!

First figure out how to get a char* that doesn’t point to a zero-terminated array of characters and then use it
(never do this in real — non-experimental — code; it can create havoc).

Try it with free-store-allocated and stack-allocated “fake C-style strings.”

If the results still look reasonable, turn off debug mode.

Redesign and re-implement those three functions so that they take another argument giving the maximum number of elements allowed in argument strings.
Then, test that with correct C-style strings and “bad” strings.

*/

char* strdup(const char* cp, int count) {
    const char* ccp = cp; int counter = 1;
    while (*ccp ) {++counter; ++ccp;}
    char* r = new char[counter]; char* result = r;
    while (*cp && count > 0) {
        *r = *cp;
        ++r; ++cp; --count;
    }
    *r = 0;
    return result;
}

char* findx(const char* s, const char* x, int count) {
    while (*s && count >=0) {
        char* p = const_cast<char*>(s);
        const char* xp = x;
        while (*xp==*s) {
            ++xp;++s;
            if (!*xp) return p;
            if(*xp!=*s) {--s; ++count;}
        }
        ++s;--count;
    }
    return nullptr;
}

int strcmp(const char* s1, const char* s2, int count) {
    while (*s1 && *s2 && count >= 0) {
        if (*s1 > *s2) return 1;
        if (*s2 > *s1) return -1;
        s1++; s2++; --count;
    }
    if (*s1&&count) return 1;
    if (*s2&&count) return -1;
    return 0;
}


void corrupted_chars() {
    char okay[] = "test_correct_strdup";
    char fokay[] = "test_correct_findx";
    char cokay[] = "test_correct_strcmp";
    char corrupted {'a'}; char ch2 {'b'};
    //char ch3 {0};

    cout << strdup(&corrupted, 2) << endl;
    cout <<  strdup(okay, 100) << endl;
    cout <<  findx(&corrupted, new char {'b'}, 2) << endl;
    cout <<  findx(fokay, new char[3] {'c', 'o', 'r'}, 5) << endl;
    cout <<  strcmp(&corrupted, new char[2] {'a', 'b'}, 2) << endl;
    cout <<  strcmp(cokay, new char[2] {'a', 'b'}, 2) << endl;

    cout << "-----------" << endl;

}
void corrupted_new_chars(){

    char* corrupted = new char {'q'};
    for (int x = 100; x > 0; --x) { corrupted[x] = 'q';} corrupted[5] = '!';
    char* okay = new char[8] {'t', 'e', 's', 't', 'd','u', 'p', 0};
    char* fokay = new char[8] {'t', 'e', 's', 't', 'f','n', 'x', 0};
    char* cokay = new char[4] {'t', 'e', 's', 0};

    cout << strdup(corrupted, 10) << endl;
    cout << strdup(okay, 15) << endl;
    cout << findx(corrupted, new char('!'), 10) << endl;
    cout << findx(fokay, new char('s'), 6) << endl;
    cout << strcmp(corrupted, new char[4] {'t', 'e', 's', 0}, 3) << endl;
    cout << strcmp(cokay, new char[4] {'t', 'e', 's', 0}, 6) << endl;
    cout << "-----------" << endl;
}


int main()
{
    corrupted_chars();
    corrupted_new_chars();
}



