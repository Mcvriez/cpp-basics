
#ifndef POINT_GUARD
#define POINT_GUARD

typedef void (*Callback)(void*,void*);

namespace Graph_lib {

	struct Point {
		int x, y;
		Point(int xx, int yy) : x(xx), y(yy) { }
		Point() :x(0), y(0) { }

		Point& operator+=(Point d) { x+=d.x; y+=d.y; return *this; }
	};

	inline bool operator==(Point a, Point b) { return a.x == b.x && a.y == b.y; }

	inline bool operator!=(Point a, Point b) { return !(a == b); }

    struct Lpoint {
        int x, y, line;
        Lpoint(int xx, int yy, int ll) : x(xx), y(yy), line(ll) { }
        Lpoint() :x(0), y(0), line(0) {}
        Lpoint& operator+=(Lpoint d) { x+=d.x; y+=d.y; return *this; }
        bool operator < (const Lpoint& str) const
        {
            return (x < str.x);
        }
    };

    inline bool operator==(Lpoint a, Lpoint b) { return a.x == b.x && a.y == b.y && a.line == b.line; }

    inline bool operator!=(Lpoint a, Lpoint b) { return !(a == b); }


}
#endif