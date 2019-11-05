
#ifndef GRAPH_GUARD
#define GRAPH_GUARD 1

#include "Point.h"
#include<vector>
#include "std_lib_facilities.h"
//#include<string>
//#include<cmath>
#include "fltk.h"
//#include "std_lib_facilities.h"
#define PI 3.14159265

namespace Graph_lib {
	// defense against ill-behaved Linux macros:
#undef major
#undef minor

	struct Color {
		enum Color_type {
			red = FL_RED, blue = FL_BLUE, green = FL_GREEN,
			yellow = FL_YELLOW, white = FL_WHITE, black = FL_BLACK,
			magenta = FL_MAGENTA, cyan = FL_CYAN, dark_red = FL_DARK_RED,
			dark_green = FL_DARK_GREEN, dark_yellow = FL_DARK_YELLOW, dark_blue = FL_DARK_BLUE,
			dark_magenta = FL_DARK_MAGENTA, dark_cyan = FL_DARK_CYAN
		};
		enum Transparency { invisible = 0, visible = 255 };

		Color(Color_type cc) :c(Fl_Color(cc)), v(visible) { }
		Color(Color_type cc, Transparency vv) :c(Fl_Color(cc)), v(vv) { }
		Color(int cc) :c(Fl_Color(cc)), v(visible) { }
		Color(Transparency vv) :c(Fl_Color()), v(vv) { }
		Color (uchar r, uchar g, uchar b) :c (fl_rgb_color(r, g, b)), v(visible) { }

		int as_int() const { return c; }
		char visibility() const { return v; }
		void set_visibility(Transparency vv) { v = vv; }
	private:
		unsigned char v;	// 0 or 1 for now
		Fl_Color c;
	};

	struct Line_style {
		enum Line_style_type {
			solid = FL_SOLID,				// -------
			dash = FL_DASH,				// - - - -
			dot = FL_DOT,					// ....... 
			dashdot = FL_DASHDOT,			// - . - . 
			dashdotdot = FL_DASHDOTDOT,	// -..-..
		};
		Line_style(Line_style_type ss) :s(ss), w(0) { }
		Line_style(Line_style_type lst, int ww) :s(lst), w(ww) { }
		Line_style(int ss) :s(ss), w(0) { }

		int width() const { return w; }
		int style() const { return s; }
	private:
		int s;
		int w;
	};

	class Font {
	public:
		enum Font_type {
			helvetica = FL_HELVETICA,
			helvetica_bold = FL_HELVETICA_BOLD,
			helvetica_italic = FL_HELVETICA_ITALIC,
			helvetica_bold_italic = FL_HELVETICA_BOLD_ITALIC,
			courier = FL_COURIER,
			courier_bold = FL_COURIER_BOLD,
			courier_italic = FL_COURIER_ITALIC,
			courier_bold_italic = FL_COURIER_BOLD_ITALIC,
			times = FL_TIMES,
			times_bold = FL_TIMES_BOLD,
			times_italic = FL_TIMES_ITALIC,
			times_bold_italic = FL_TIMES_BOLD_ITALIC,
			symbol = FL_SYMBOL,
			screen = FL_SCREEN,
			screen_bold = FL_SCREEN_BOLD,
			zapf_dingbats = FL_ZAPF_DINGBATS
		};

		Font(Font_type ff) :f(ff) { }
		Font(int ff) :f(ff) { }

		int as_int() const { return f; }
	private:
		int f;
	};

	template<class T> class Vector_ref {
		vector<T*> v;
		vector<T*> owned;
	public:
		Vector_ref() {}

		Vector_ref(T* a, T* b = 0, T * c = 0, T * d = 0)
		{
			if (a) push_back(a);
			if (b) push_back(b);
			if (c) push_back(c);
			if (d) push_back(d);
		}

		~Vector_ref() { for (int i = 0; i < owned.size(); ++i) delete owned[i]; }

		void push_back(T& s) { v.push_back(&s); }
		void push_back(T* p) { v.push_back(p); owned.push_back(p); }

		// ???void erase(???)

		T& operator[](int i) { return *v[i]; }
		const T& operator[](int i) const { return *v[i]; }
		int size() const { return v.size(); }
	};

	typedef double Fct(double);

	class Shape {	// deals with color and style, and holds sequence of lines
	protected:
		Shape() { }
		Shape(initializer_list<Point> lst);  // add() the Points to this Shape

	//	Shape() : lcolor(fl_color()),
	//		ls(0),
	//		fcolor(Color::invisible) { }

		void add(Point p) { points.push_back(p); }
		void set_point(int i, Point p) { points[i] = p; }
	public:
		void draw() const;					// deal with color and draw_lines
	protected:
		virtual void draw_lines() const;	// simply draw the appropriate lines
	public:
		virtual void move(int dx, int dy);	// move the shape +=dx and +=dy

		void set_color(Color col) { lcolor = col; }
		Color color() const { return lcolor; }

		void set_style(Line_style sty) { ls = sty; }
		Line_style style() const { return ls; }

		void set_fill_color(Color col) { fcolor = col; }
		Color fill_color() const { return fcolor; }

		Point point(int i) const { return points[i]; }
		int number_of_points() const { return int(points.size()); }

		virtual ~Shape() { }
		/*
		struct Window* attached;
		Shape(const Shape& a)
			:attached(a.attached), points(a.points), line_color(a.line_color), ls(a.ls)
		{
			if (a.attached)error("attempt to copy attached shape");
		}
		*/
		Shape(const Shape&) = delete;
		Shape& operator=(const Shape&) = delete;
	private:
		vector<Point> points;	// not used by all shapes
		Color lcolor{ fl_color() };
		Line_style ls{ 0 };
		Color fcolor{ Color::invisible };

		//	Shape(const Shape&);
		//	Shape& operator=(const Shape&);
	};

	struct Function : Shape {
		// the function parameters are not stored
		Function(Fct f, double r1, double r2, Point orig, int count = 100, double xscale = 25, double yscale = 25);
		//Function(Point orig, Fct f, double r1, double r2, int count, double xscale = 1, double yscale = 1);	
	};

	struct Fill {
		Fill() :no_fill(true), fcolor(0) { }
		Fill(Color c) :no_fill(false), fcolor(c) { }

		void set_fill_color(Color col) { fcolor = col; }
		Color fill_color() { return fcolor; }
	protected:
		bool no_fill;
		Color fcolor;
	};

	struct Line : Shape {
		Line(Point p1, Point p2) { add(p1); add(p2); }
	};

	struct Rectangle : Shape {

		Rectangle(Point xy, int ww, int hh) :w{ ww }, h{ hh }, sp{ xy }
		{
			if (h <= 0 || w <= 0) error("Bad rectangle: non-positive side");
			add(xy);
		}
		Rectangle(Point x, Point y) :w{ y.x - x.x }, h{ y.y - x.y }
		{
			if (h <= 0 || w <= 0) error("Bad rectangle: first point is not top left");
			add(x);
		}
		void draw_lines() const;

		//	void set_fill_color(Color col) { fcolor = col; }
		//	Color fill_color() { return fcolor; }

		int height() const { return h; }
		int width() const { return w; }
		Point start_point() const { return sp; }
	private:
		int h;			// height
		int w;			// width
		Point sp;
		Color lcolor{ Color::invisible };
	};



	bool intersect(Point p1, Point p2, Point p3, Point p4);


	struct Open_polyline : Shape {	// open sequence of lines
		using Shape::Shape;
		void add(Point p) { Shape::add(p); }
		void draw_lines() const;
	};

	struct Closed_polyline : Open_polyline {	// closed sequence of lines
		using Open_polyline::Open_polyline;
		void draw_lines() const;

		//	void add(Point p) { Shape::add(p); }
	};


	struct Polygon : Closed_polyline {	// closed sequence of non-intersecting lines
		using Closed_polyline::Closed_polyline;
		void add(Point p);
		void draw_lines() const;
	};

	struct Poly : Polygon {	// closed sequence of non-intersecting lines
		Poly(initializer_list<Point> lst)  {
			if(lst.size() < 3) error("Polygon should contain at least 3 points");
			for (Point p : lst) {
				cout << p.x << '|' << p.y << endl;
				add(p);
			}
		}

	};

	struct Lines : Shape {	// indepentdent lines
		Lines() {}
		Lines(initializer_list<Point> lst) : Shape{ lst } { if (lst.size() % 2) error("odd number of points for Lines"); }
		void draw_lines() const;
		void add(Point p1, Point p2) { Shape::add(p1); Shape::add(p2); }
	};

	struct Right_triangle : Closed_polyline {
		Right_triangle(Point xy, int ww, int hh, int angle) :w{ ww }, h{ hh }, sp{ xy }
		{
			if (h <= 0 || w <= 0) error("Bad rectangle: non-positive side");
			add(xy);
			int x1 = w * cos(angle * PI / 180) + sp.x;
			int y1 = -h * sin(angle * PI / 180) + sp.y;
			int x2 = w * cos((angle + 90) * PI / 180) + sp.x;
			int y2 = -h * sin((angle + 90) * PI / 180) + sp.y;
			add(Point(x1, y1));
			add(Point(x2, y2));
		}
		Point start_point() const { return sp; }
		// void draw_lines() const;
	private:
		int h;			// height
		int w;			// width
		Point sp;
	};

	struct Text : Shape {
		// the point is the bottom left of the first letter
		Text(Point x, const string& s) : lab{ s } { add(x); }

		void draw_lines() const;

		void set_label(const string& s) { lab = s; }
		string label() const { return lab; }

		void set_font(Font f) { fnt = f; }
		Font font() const { return Font(fnt); }

		void set_font_size(int s) { fnt_sz = s; }
		int font_size() const { return fnt_sz; }
	private:
		string lab;	// label
		Font fnt{ fl_font() };
		int fnt_sz{ (14 < fl_size()) ? fl_size() : 14 };	// at least 14 point
	};


	struct Axis : Shape {
		// representation left public
		enum Orientation { x, y, z };
		Axis(Orientation d, Point xy, int length, int nummber_of_notches = 0, string label = "");

		void draw_lines() const;
		void move(int dx, int dy);

		void set_color(Color c);

		Text label;
		Lines notches;
		//	Orientation orin;
		//	int notches;
	};

	struct Circle : Shape {
		Circle(Point p, int rr)	// center and radius
			:r{ rr } {
			add(Point{ p.x - r, p.y - r });
		}

		void draw_lines() const;

		Point center() const { return { point(0).x + r, point(0).y + r }; }

		void set_radius(int rr) { r = rr; }
		int radius() const { return r; }
	private:
		int r;
	};


	struct Ellipse : Shape {
		Ellipse(Point p, int ww, int hh)	// center, min, and max distance from center
			:w{ ww }, h{ hh } {
			add(Point{ p.x - ww, p.y - hh });
		}

		void draw_lines() const;

		Point center() const { return{ point(0).x + w, point(0).y + h }; }
		Point focus1() const { return{ center().x + int(sqrt(double(w * w - h * h))), center().y }; }
		Point focus2() const { return{ center().x - int(sqrt(double(w * w - h * h))), center().y }; }
		
		void set_major(int ww) { w = ww; }
		int major() const { return w; }
		void set_minor(int hh) { h = hh; }
		int minor() const { return h; }
	private:
		int w;
		int h;
	};
	/*
	struct Mark : Text {
		static const int dw = 4;
		static const int dh = 4;
		Mark(Point xy, char c) : Text(Point(xy.x-dw, xy.y+dh),string(1,c)) {}
	};
	*/

	struct Marked_polyline : Open_polyline {
		Marked_polyline(const string& m) :mark(m) { }
		void draw_lines() const;
	private:
		string mark;
	};

	struct Marks : Marked_polyline {
		Marks(const string& m) :Marked_polyline(m)
		{
			set_color(Color(Color::invisible));
		}
	};

	struct Mark : Marks {
		Mark(Point xy, char c) : Marks(string(1, c)) { add(xy); }
	};

	/*

	struct Marks : Shape {
		Marks(char m) : mark(string(1,m)) { }
		void add(Point p) { Shape::add(p); }
		void draw_lines() const;
	private:
		string mark;
	};
	*/

	struct Bad_image : Fl_Image {
		Bad_image(int h, int w) : Fl_Image(h, w, 0) { }
		void draw(int x, int y, int, int, int, int) { draw_empty(x, y); }
	};

	struct Suffix {
		enum Encoding { none, jpg, gif, bmp };
	};

	Suffix::Encoding get_encoding(const string& s);

	struct Image : Shape {
		Image(Point xy, string s, Suffix::Encoding e = Suffix::none);
		~Image() { delete p; }
		void draw_lines() const;
		void set_mask(Point xy, int ww, int hh) { w = ww; h = hh; cx = xy.x; cy = xy.y; }
		void move(int dx, int dy) { Shape::move(dx, dy); p->draw(point(0).x, point(0).y); }
	private:
		int w, h, cx, cy; // define "masking box" within image relative to position (cx,cy)
		Fl_Image* p;
		Text fn;
	};
	struct Arc : Shape {
		Arc(Point p, int ww, int hh, int start_angle, int end_angle)	// center, min, and max distance from center
			:w{ ww }, h{ hh }, angle1{ start_angle }, angle2{ end_angle }{
			add(Point{ p.x - ww, p.y - hh });
		}
		Point center() const { return{ point(0).x + w, point(0).y + h }; }
		Point focus2() const { return{ center().x - int(sqrt(double(w * w - h * h))), center().y }; }
		
		void draw_lines() const;
		void set_major(int ww) { w = ww; }
		int major() const { return w; }
		void set_minor(int hh) { h = hh; }
		int minor() const { return h; }
		void set_start_angle(int start_angle) { angle1 = start_angle; }
		int start_angle() const { return angle1;}
		void end_angle(int end_angle) { angle2 = end_angle; }
		int end_angle() const { return angle2; }

	private:
		int w;
		int h;
		int angle1;
		int angle2;
	};

	struct Box : Shape {
		Box(Point p, int ww, int hh, int delta_angle)	// center, min, and max distance from center
			:w{ ww / 2 }, h{ hh / 2 }, delta{ delta_angle }, label{ "empty" }{
			add(Point{ p.x - ww, p.y - hh });
		}
		Box(Point p, int ww, int hh)	// center, min, and max distance from center
			:w{ ww / 2 }, h{ hh / 2 }, delta{ 5 }, label{ "empty" }{
			add(Point{ p.x - ww, p.y - hh });
		}
		Box(Point p, string lab)	// center, min, and max distance from center
			:w{ int(lab.size() * 7) }, h{ 20 }, delta{ 7 }, label{ lab }{
			add(Point{ p.x - int(lab.size() * 7), p.y - 15 });
		}

		Point center() const { return{ point(0).x + w, point(0).y + h }; }

		void draw_lines() const;
		void set_major(int ww) { w = ww; }
		int major() const { return w; }
		void set_minor(int hh) { h = hh; }
		int minor() const { return h; }

	private:
		int w;
		int h;
		int delta;
		const string label;
	};

	struct Arrow : Closed_polyline {	// open sequence of lines
		Arrow(Point ending, Point pointer, int arrow_size, int delta_angle):
			p1{ pointer }, p0{ ending }, size{ arrow_size }, delta{ delta_angle }{
			Point pa1; Point pa2; Point pa0;
			
			double tan_alpha;
			double x = p1.x - p0.x;
			double y = p0.y - p1.y;
			
			tan_alpha =  x / y;
			double alpha = atan(tan_alpha) * 180 / PI;

			int theta = 90;
			if (y < 0) theta = 270;

			pa0.x = p1.x - cos((alpha - theta) * PI / 180) * size * coef + 0.5;
			pa0.y = p1.y - sin((alpha - theta) * PI / 180) * size * coef + 0.5;

			pa1.x = p1.x - cos((alpha - delta - theta) * PI / 180) * size;
			pa2.x = p1.x - cos((alpha + delta - theta) * PI / 180) * size;
			pa1.y = p1.y - sin((alpha - delta - theta) * PI / 180) * size;
			pa2.y = p1.y - sin((alpha + delta - theta) * PI / 180) * size;
			add(pa0);  add(pa1); add(p1); add(pa2);
		}
		void draw_lines() const;
		void set_ending(Point p) { p0 = p; }
		Point ending() const { return p0; }
		void set_pointer(Point p) { p1 = p; }
		Point pointer() const { return p1; }
	private:
		void add(Point p) { Shape::add(p); }
		Point p0;   // start
		Point p1;   // end
		Point pa0;  // arrow middle bottom
		Point pa1;  // arrow left
		Point pa2;  // arrow right
		int size;
		int delta;
		const double coef = 0.7;
	};

	struct Regular_hexagon : Polygon {

		Regular_hexagon(Point centerp, int ra) :centr{ centerp }, rad{ ra }
		{
			if (rad <= 0) error("Bad polygon: non-positive radius");
			for (int i = 0; i < 6; ++i) {
				double angle = PI / 180 * (60 * i - 30);
				add(Point{ int(centr.x + rad * cos(angle)), int(centr.y + rad * sin(angle)) });
			}

		}
		int radius() const { return rad; }
		Point center() const { return centr; }
	private:
		int rad;
		Point centr;

	};

	struct Regular_polygon : Polygon {

		Regular_polygon(Point centerp, int nsides, int ra) :centr{ centerp }, rad{ ra }, sides {nsides}
		{
			if (rad <= 0 || sides < 3) error("Bad polygon");
			for (int i = 0; i < sides; ++i) {
				double angle = PI / 180 * (360 / sides * i);
				add(Point{ int(centr.x + rad * cos(angle)), int(centr.y + rad * sin(angle)) });
			}

		}
		int radius() const { return rad; }
		Point center() const { return centr; }
	private:
		int rad;
		int sides;
		Point centr;

	};


}
#endif