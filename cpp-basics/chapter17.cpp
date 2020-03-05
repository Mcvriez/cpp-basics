#include "lib/std_lib_facilities.h"

/*

6. This chapter does not say what happens when you run out of memory using new. That’s called memory exhaustion. Find
out what happens. You have two obvious alternatives: look for documentation, or write a program with an infinite loop
that allocates but never deallocates. Try both. Approximately how much memory did you manage to allocate before
failing?

*/

/*

Mar  5 15:39:49 wq-null kernel: [13363.189684] Out of memory: Killed process 24086 (a.out)

 total-vm: 12 889 580kB,
 anon-rss: 12 873 860kB,
 file-rss:0kB, shmem-rss:0kB

 */

void danger(){
    new vector<string> [100000];
}
int main()
try {
    while (1) danger();
}

catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    keep_window_open();
}
catch (...) {
    cerr << "exception\n";
}

