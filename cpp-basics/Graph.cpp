#include "Graph.h"
#include<map>
#include <utility>
#define PI 3.14159265


namespace Graph_lib {

	void Shape::draw_lines() const
	{
		if (color().visibility() && 1 < points.size())	// draw sole pixel?
			for (unsigned int i = 1; i < points.size(); ++i)
				fl_line(points[i - 1].x, points[i - 1].y, points[i].x, points[i].y);
		//cout << "Shape draw_lines()" << endl;
	}

	void Shape::draw() const
	{
		Fl_Color oldc = fl_color();
		// there is no good portable way of retrieving the current style
		fl_color(lcolor.as_int());
		fl_line_style(ls.style(), ls.width());
		draw_lines();
		fl_color(oldc);	// reset color (to pevious) and style (to default)
		fl_line_style(0);
	}


	// does two lines (p1,p2) and (p3,p4) intersect?
	// if se return the distance of the intersect point as distances from p1
	inline pair<double, double> line_intersect(Point p1, Point p2, Point p3, Point p4, bool& parallel)
	{
		double x1 = p1.x;
		double x2 = p2.x;
		double x3 = p3.x;
		double x4 = p4.x;
		double y1 = p1.y;
		double y2 = p2.y;
		double y3 = p3.y;
		double y4 = p4.y;

		double denom = ((y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1));
		if (denom == 0) {
			parallel = true;
			return pair<double, double>(0, 0);
		}
		parallel = false;
		return pair<double, double>(((x4 - x3) * (y1 - y3) - (y4 - y3) * (x1 - x3)) / denom,
			((x2 - x1) * (y1 - y3) - (y2 - y1) * (x1 - x3)) / denom);
	}


	//intersection between two line segments
	//Returns true if the two segments intersect,
	//in which case intersection is set to the point of intersection
	bool line_segment_intersect(Point p1, Point p2, Point p3, Point p4, Point& intersection) {
		bool parallel;
		pair<double, double> u = line_intersect(p1, p2, p3, p4, parallel);
		if (parallel || u.first < 0 || u.first > 1 || u.second < 0 || u.second > 1) return false;
		intersection.x = p1.x + u.first * (p2.x - p1.x);
		intersection.y = p1.y + u.first * (p2.y - p1.y);
		return true;
	}

	void Polygon::add(Point p)
	{
		int np = number_of_points();

		if (1 < np) {	// check that thenew line isn't parallel to the previous one
			if (p == point(np - 1)) error("polygon point equal to previous point");
			bool parallel;
			line_intersect(point(np - 1), p, point(np - 2), point(np - 1), parallel);
			if (parallel)
				error("two polygon points lie in a straight line");
		}

		for (int i = 1; i < np - 1; ++i) {	// check that new segment doesn't interset and old point
			Point ignore(0, 0);
			if (line_segment_intersect(point(np - 1), p, point(i - 1), point(i), ignore))
				error("intersect in polygon");
		}


		Closed_polyline::add(p);
	}

	void Polygon::draw_lines() const
	{
		if (number_of_points() < 3) error("less than 3 points in a Polygon");
		Closed_polyline::draw_lines();
	}

	void Open_polyline::draw_lines() const
	{
		if (fill_color().visibility()) {
			fl_color(fill_color().as_int());
			fl_begin_complex_polygon();
			for (int i = 0; i < number_of_points(); ++i) {
				fl_vertex(point(i).x, point(i).y);
			}
			fl_end_complex_polygon();
			fl_color(color().as_int());	// reset color
		}

		if (color().visibility())
			Shape::draw_lines();
	}

	void Closed_polyline::draw_lines() const
	{
		Open_polyline::draw_lines();

		if (color().visibility())	// draw closing line:
			fl_line(point(number_of_points() - 1).x, point(number_of_points() - 1).y, point(0).x, point(0).y);
	}

	void Shape::move(int dx, int dy)
	{
		for (unsigned int i = 0; i < points.size(); ++i) {
			points[i].x += dx;
			points[i].y += dy;
		}
	}

	void Lines::draw_lines() const
	{
		//	if (number_of_points()%2==1) error("odd number of points in set of lines");
		if (color().visibility())
			for (int i = 1; i < number_of_points(); i += 2)
				fl_line(point(i - 1).x, point(i - 1).y, point(i).x, point(i).y);
	}

	void Text::draw_lines() const
	{
		int ofnt = fl_font();
		int osz = fl_size();
		fl_font(fnt.as_int(), fnt_sz);
		fl_draw(lab.c_str(), point(0).x, point(0).y);
		fl_font(ofnt, osz);
	}

	Function::Function(Fct f, double r1, double r2, Point xy, int count, double xscale, double yscale)
		// graph f(x) for x in [r1:r2) using count line segments with (0,0) displayed at xy
		// x coordinates are scaled by xscale and y coordinates scaled by yscale
	{
		if (r2 - r1 <= 0) error("bad graphing range");
		if (count <= 0) error("non-positive graphing count");
		double dist = (r2 - r1) / count;
		double r = r1;
		for (int i = 0; i < count; ++i) {
			add(Point(xy.x + int(r * xscale), xy.y - int(f(r) * yscale)));
			r += dist;
		}
	}

	void Rectangle::draw_lines() const
	{
		if (fill_color().visibility()) {	// fill
			fl_color(fill_color().as_int());
			fl_rectf(point(0).x, point(0).y, w, h);
			fl_color(color().as_int());	// reset color
		}

		if (color().visibility()) {	// edge on top of fill
			fl_color(color().as_int());
			fl_rect(point(0).x, point(0).y, w, h);
		}
	}


	Axis::Axis(Orientation d, Point xy, int length, int n, const string& lab)
		:label(Point(0, 0), lab)
	{
		if (length < 0) error("bad axis length");
		switch (d) {
		case Axis::x:
		{	Shape::add(xy);	// axis line
		Shape::add(Point(xy.x + length, xy.y));	// axis line
		if (1 < n) {
			int dist = length / n;
			int x = xy.x + dist;
			for (int i = 0; i < n; ++i) {
				notches.add(Point(x, xy.y), Point(x, xy.y - 5));
				x += dist;
			}
		}
		// label under the line
		label.move(length / 3, xy.y + 20);
		break;
		}
		case Axis::y:
		{	Shape::add(xy);	// a y-axis goes up
		Shape::add(Point(xy.x, xy.y - length));
		if (1 < n) {
			int dist = length / n;
			int y = xy.y - dist;
			for (int i = 0; i < n; ++i) {
				notches.add(Point(xy.x, y), Point(xy.x + 5, y));
				y -= dist;
			}
		}
		// label at top
		label.move(xy.x - 10, xy.y - length - 10);
		break;
		}
		case Axis::z:
			error("z axis not implemented");
		}
	}

	void Axis::draw_lines() const
	{
		Shape::draw_lines();	// the line
		notches.draw();	// the notches may have a different color from the line
		label.draw();	// the label may have a different color from the line
	}

	void Axis::set_color(Color c)
	{
		Shape::set_color(c);
		notches.set_color(c);
		label.set_color(c);
	}

	void Axis::move(int dx, int dy)
	{
		Shape::move(dx, dy);
		notches.move(dx, dy);
		label.move(dx, dy);
	}

	void Circle::draw_lines() const
	{
		if (fill_color().visibility()) {	// fill
			fl_color(fill_color().as_int());
			fl_pie(point(0).x, point(0).y, r + r - 1, r + r - 1, 0, 360);
			fl_color(color().as_int());	// reset color
		}

		if (color().visibility()) {
			fl_color(color().as_int());
			fl_arc(point(0).x, point(0).y, r + r, r + r, 0, 360);
		}
	}

	void Ellipse::draw_lines() const
	{
		if (fill_color().visibility()) {	// fill
			fl_color(fill_color().as_int());
			fl_pie(point(0).x, point(0).y, w + w - 1, h + h - 1, 0, 360);
			fl_color(color().as_int());	// reset color
		}

		if (color().visibility()) {
			fl_color(color().as_int());
			fl_arc(point(0).x, point(0).y, w + w, h + h, 0, 360);
		}
	}

	void Arc::draw_lines() const
	{
		if (fill_color().visibility()) {	// fill
			fl_color(fill_color().as_int());
			fl_pie(point(0).x, point(0).y, w + w - 1, h + h - 1, angle1, angle2);
			fl_color(color().as_int());	// reset color
		}

		if (color().visibility()) {
			fl_color(color().as_int());
			fl_arc(point(0).x, point(0).y, w + w, h + h, angle1, angle2);
			int x1, x2, y1, y2;
			
			x1 = w * cos(angle1 * PI / 180);
			y1 = -h * sin(angle1 * PI / 180);

			x2 = w * cos(angle2 * PI / 180);
			y2 = -h * sin(angle2 * PI / 180);

			fl_line(center().x , center().y, center().x + x1, center().y + y1);
			fl_line(center().x , center().y , center().x  + x2, center().y  + y2);

		}
	}

	void Box::draw_lines() const
	{
		int angle0 = 45;
		int angle1 = 135;
		int angle2 = 225;
		int angle3 = 315;

		if (fill_color().visibility() || label != "empty") {	// fill
			fl_color(fill_color().as_int());
			
			if (label != "empty") { fl_color(240, 240, 240); }

			fl_pie(point(0).x, point(0).y, w + w - 1, h + h - 1, angle0 - delta, angle0 + delta);
			fl_pie(point(0).x, point(0).y, w + w - 1, h + h - 1, angle1 - delta, angle1 + delta);
			fl_pie(point(0).x, point(0).y, w + w - 1, h + h - 1, angle2 - delta, angle2 + delta);
			fl_pie(point(0).x, point(0).y, w + w - 1, h + h - 1, angle3 - delta, angle3 + delta);
			fl_rectf(center().x + w * cos((angle1 + delta) * PI / 180), 
					 center().y - h * sin((angle1 + delta) * PI / 180), 
					 w * cos((angle0 - delta) * PI / 180) * 2, 
					 h * sin((angle0 - delta) * PI / 180) * 2
			);
			fl_rectf(center().x + w * cos((angle1 - delta) * PI / 180), 
					 center().y - h * sin((angle1 - delta) * PI / 180),
					 - w * cos((angle1 - delta) * PI / 180) * 2,
					 h * sin((angle1 - delta) * PI / 180) * 2
			);
			fl_color(color().as_int());	// reset color
		}

		if (color().visibility()) {
			//fl_color(color().as_int());
            fl_color(100,100,100);
			fl_line_style(0, 4);
			fl_arc(point(0).x, point(0).y, w + w, h + h, angle0 - delta , angle0 + delta);
			fl_arc(point(0).x, point(0).y, w + w, h + h, angle1 - delta, angle1 + delta);
			fl_arc(point(0).x, point(0).y, w + w, h + h, angle2 - delta, angle2 + delta);
			fl_arc(point(0).x, point(0).y, w + w, h + h, angle3 - delta, angle3 + delta);

			fl_line(center().x + w * cos((angle0 + delta) * PI / 180), center().y - h * sin((angle0 + delta) * PI / 180), center().x + w * cos((angle1 - delta) * PI / 180), center().y - h * sin((angle1 - delta) * PI / 180));
			fl_line(center().x + w * cos((angle1 + delta) * PI / 180), center().y - h * sin((angle1 + delta) * PI / 180), center().x + w * cos((angle2 - delta) * PI / 180), center().y - h * sin((angle2 - delta) * PI / 180));
			fl_line(center().x + w * cos((angle2 + delta) * PI / 180), center().y - h * sin((angle2 + delta) * PI / 180), center().x + w * cos((angle3 - delta) * PI / 180), center().y - h * sin((angle3 - delta) * PI / 180));
			fl_line(center().x + w * cos((angle3 + delta) * PI / 180), center().y - h * sin((angle3 + delta) * PI / 180), center().x + w * cos((angle0 - delta) * PI / 180), center().y - h * sin((angle0 - delta) * PI / 180));

		}

	}
	void draw_mark(Point xy, char c)
	{
		static const int dx = 4;
		static const int dy = 4;
		string m(1, c);
		fl_draw(m.c_str(), xy.x - dx, xy.y + dy);
	}

	void Marked_polyline::draw_lines() const
	{
		Open_polyline::draw_lines();
		for (int i = 0; i < number_of_points(); ++i)
			draw_mark(point(i), mark[i % mark.size()]);
	}

	std::map<string, Suffix::Encoding> suffix_map;

	int init_suffix_map()
	{
		suffix_map["jpg"] = Suffix::jpg;
		suffix_map["JPG"] = Suffix::jpg;
		suffix_map["jpeg"] = Suffix::jpg;
		suffix_map["JPEG"] = Suffix::jpg;
		suffix_map["gif"] = Suffix::gif;
		suffix_map["GIF"] = Suffix::gif;
		suffix_map["bmp"] = Suffix::bmp;
		suffix_map["BMP"] = Suffix::bmp;
		return 0;
	}

	Suffix::Encoding get_encoding(const string& s)
		// try to deduce type from file name using a lookup table
	{
		static int x = init_suffix_map();

		string::const_iterator p = find(s.begin(), s.end(), '.');
		if (p == s.end()) return Suffix::none;	// no suffix

		string suf(p + 1, s.end());
		return suffix_map[suf];
	}

	bool can_open(const string& s)
		// check if a file named s exists and can be opened for reading
	{
		ifstream ff(s.c_str());
		return bool(ff);
	}
	// somewhat overelaborate constructor
	// because errors related to image files can be such a pain to debug
	/*Image::Image(Point xy, string s, Suffix::Encoding e)
		:w(0), h(0), fn(xy, "")
	{
		add(xy);

		if (!can_open(s)) {
			fn.set_label("cannot open \"" + s + '\"');
			p = new Bad_image(30, 20);	// the "error image"
			return;
		}

		if (e == Suffix::none) e = get_encoding(s);

		switch (e) {
		case Suffix::jpg:
			p = new Fl_JPEG_Image(s.c_str());
			break;
		case Suffix::gif:
			p = new Fl_GIF_Image(s.c_str());
			break;
			//	case Suffix::bmp:
			//		p = new Fl_BMP_Image(s.c_str());
			//		break;
		default:	// Unsupported image encoding
			fn.set_label("unsupported file type \"" + s + '\"');
			p = new Bad_image(30, 20);	// the "error image"
		}
	}

	void Image::draw_lines() const
	{
		if (fn.label() != "") fn.draw_lines();

		if (w && h)
			p->draw(point(0).x, point(0).y, w, h, cx, cy);
		else
			p->draw(point(0).x, point(0).y);
	}
	*/
	void Arrow::draw_lines() const
	{
		fl_color(color().as_int());
		fl_line(p0.x, p0.y, point(0).x, point(0).y);
		fl_color(color().as_int());

		fl_line_style(0);
		Closed_polyline::draw_lines();
		fl_begin_complex_polygon();
		for (int i = 0; i < number_of_points(); ++i) {
			fl_vertex(point(i).x, point(i).y);
		}
		fl_end_complex_polygon();
		fl_color(color().as_int());	// reset color
	}

    void Regular_octagon::draw_lines() const
    {
        if (fill_color().visibility()) {
            fl_color(fill_color().as_int());
            fl_begin_complex_polygon();
            for (int i = 0; i < number_of_points(); ++i) {
                fl_vertex(point(i).x, point(i).y);
            }
            fl_end_complex_polygon();
            fl_color(color().as_int());	// reset color
        }

        if (color().visibility())
            Shape::draw_lines();

        if (color().visibility())	// draw closing line:
            fl_line(point(number_of_points() - 1).x, point(number_of_points() - 1).y, point(0).x, point(0).y);
    }

    void Pseudo_window::draw_lines() const {
        Box::draw_lines();
        const int header = 50;
        if (color().visibility()) {
            int angle0 = 45;
            int angle1 = 135;
            int angle2 = 225;
            int angle3 = 315;
            { fl_color(240, 240, 240); }

            fl_pie(point(0).x, point(0).y, w + w - 1, h + h - 1, angle0 - delta, angle0 + delta);
            fl_pie(point(0).x, point(0).y, w + w - 1, h + h - 1, angle1 - delta, angle1 + delta);

            fl_color(210, 210, 210);

            fl_pie(point(0).x, point(0).y, w + w - 1, h + h - 1, angle2 - delta, angle2 + delta);
            fl_pie(point(0).x, point(0).y, w + w - 1, h + h - 1, angle3 - delta, angle3 + delta);
            fl_rectf(center().x + w * cos((angle1 + delta) * PI / 180),
                     center().y - h * sin((angle1 + delta) * PI / 180) + header,
                     w * cos((angle0 - delta) * PI / 180) * 2,
                     h * sin((angle0 - delta) * PI / 180) * 2 - header
            );
            fl_rectf(center().x + w * cos((angle1 - delta) * PI / 180),
                     center().y - h * sin((angle1 - delta) * PI / 180) + header * 2,
                     - w * cos((angle1 - delta) * PI / 180) * 2,
                     h * sin((angle1 - delta) * PI / 180) * 2 - header * 2
            );

            fl_color(100,100,100);
            fl_line_style(0, 5);

            fl_arc(point(0).x, point(0).y, w + w, h + h, angle0 - delta , angle0 + delta);
            fl_arc(point(0).x, point(0).y, w + w, h + h, angle1 - delta, angle1 + delta);
            fl_arc(point(0).x, point(0).y, w + w, h + h, angle2 - delta, angle2 + delta);
            fl_arc(point(0).x, point(0).y, w + w, h + h, angle3 - delta, angle3 + delta);

            fl_line(center().x + w * cos((angle0 + delta) * PI / 180), center().y - h * sin((angle0 + delta) * PI / 180), center().x + w * cos((angle1 - delta) * PI / 180), center().y - h * sin((angle1 - delta) * PI / 180));
            fl_line(center().x + w * cos((angle1 + delta) * PI / 180), center().y - h * sin((angle1 + delta) * PI / 180), center().x + w * cos((angle2 - delta) * PI / 180), center().y - h * sin((angle2 - delta) * PI / 180));
            fl_line(center().x + w * cos((angle2 + delta) * PI / 180), center().y - h * sin((angle2 + delta) * PI / 180), center().x + w * cos((angle3 - delta) * PI / 180), center().y - h * sin((angle3 - delta) * PI / 180));
            fl_line(center().x + w * cos((angle3 + delta) * PI / 180), center().y - h * sin((angle3 + delta) * PI / 180), center().x + w * cos((angle0 - delta) * PI / 180), center().y - h * sin((angle0 - delta) * PI / 180));

        }

        int x = center().x + w * cos((225 + delta) * PI / 180) + 10;
        int y = center().y - h / 2 - header / 1.4;
        int r = 10;
        fl_color(255,99,71);
        fl_pie(x, y, r + r - 1, r + r - 1, 0, 360);

        fl_color(255,215,0);
        fl_pie(x + header / 1.5, y, r + r - 1, r + r - 1, 0, 360);

        fl_color(100,225,100);
        fl_pie(x + 2 *(header / 1.5), y, r + r - 1, r + r - 1, 0, 360);

        if (label != "empty") {
            fl_color(Color::black);
            fl_font(1, 120);
            fl_draw(label.c_str(), center().x - label.size() * 5, y + 15);
            fl_font(fl_font(), fl_size());
        }
	}

    Binary_tree::Binary_tree(Point s, int l, int r, string  at): root{s}, level {l}, radius{r}, arrow_type {std::move(at)}{

	    int delta_y = radius * 4;
	    int delta_x = radius / 2;
	    int max = int(pow(2, level)) * radius + delta_x * int(pow(2, level));
	    int x0 = root.x - max / 2;
         for (int i = level; i > 0; --i) {
             for (int j = 0; j < pow(2, i)/2; j++){
                 int x = int(x0 + (j + 0.5) * max / (pow(2, i - 1)));
                 int y = root.y + delta_y * (i - 1);
                 add(Point{x, y});
             }
         }
        // add shapes to "shapes" (circle), based on points
        int size = number_of_points();
        for (int i = 0; i < size; ++i) {
            //circles - default
            circles.push_back(new Circle(point(i), radius));

            //triangles
            int xmod = int(sqrt(3)/2 * radius);
            Point ftop = {point(i).x, point(i).y - radius};
            Point fleft = {point(i).x + xmod, point(i).y + radius / 2};
            Point fright = {point(i).x - xmod, point(i).y + radius / 2};
            triangles.push_back(new Poly{ftop, fleft, fright});
        }

        size -= 1;
        // add arrows + lines to "arrows"
        for (int j = 0; j < size; ++j) {
            Point start = {point(j).x, point(j).y};
            Point finish = {point((size + j) / 2 + 1).x, point((size + j) / 2 + 1).y};
            Point s1; Point f1;
            double alpha = atan(double((start.x - finish.x)) / (start.y - finish.y)) * 180 / PI;
            s1.x = int(start.x - sin((alpha) * PI / 180) * radius);
            s1.y = int(start.y - cos((alpha) * PI / 180) * radius);
            f1.x = int(finish.x + sin((alpha) * PI / 180) * radius);
            f1.y = int(finish.y + cos((alpha) * PI / 180) * radius);

            if (arrow_type == "ua")
                arrows.push_back(new Arrow(s1, f1, radius/2, 25));
            else if (arrow_type == "la")
                arrows.push_back(new Arrow(f1, s1, radius/2, 25));
            else
                arrows.push_back(new Line(s1, f1));
        }
	}
    void Binary_tree::set_fill_color(Color col) {
        for (int i = 0; i < number_of_points(); ++i) {
            circles[i].set_fill_color(col);
            circles[i].set_style(Line_style(Line_style::Line_style::solid, radius / 15));
            triangles[i].set_fill_color(col);
            triangles[i].set_style(Line_style(Line_style::Line_style::solid, radius / 15));
            if (i < number_of_points() - 1)
                arrows[i].set_style(Line_style(Line_style::Line_style::solid, radius / 15));
        }
    }
    void Binary_tree::set_arrow_color(Color col) {
        for (int i = 0; i < number_of_points() - 1; ++i) {
            arrows[i].set_color(col);
            arrows[i].set_style(Line_style(Line_style::Line_style::dash, radius / 15));
        }
    }
    void Binary_tree::draw_lines() const {
        for (int i = 0; i < circles.size(); ++i){
            circles[i].draw();
        }
        for (int i = 0; i < arrows.size(); ++i){
            arrows[i].draw();
        }
        fl_font(0, 300);
        for (int i = 0; i < marks.size(); ++i){
            marks[i].draw();
        }
	}

    void Binary_tree::mark_node(const string& path) {
	    if (path.size() == 1)
        marks.push_back(new Text(Point{root.x - 40, root.y + int(radius * 1.2)}, "Marked element"));
	    if (path.size() > 1){
	        int l = 0;
	        int pos = 1;
	        for (int i = 1; i < path.size(); ++i) {
	            switch(path[i]) {
                    case 'l':
                        pos = pos * 2 + 1;
                        break;
                    case 'r':
                        pos = pos * 2;
                        break;
	                default:
	                    cout << "Unknown symbol " << path[i] << " - skipping." << endl;
                }
	        }
            int pointx = (int(pow(2, level)) - 1) - pos;
            if (pointx >=0){
                Point n = point(pointx);
                n.x -= 40;
                n.y += int(radius * 1.4);
                marks.push_back(new Text(n, "Marked element"));
	        }
        }
	}

    void Binary_tree_triangle::draw_lines() const {
        for (int i = 0; i < triangles.size(); ++i){
            triangles[i].draw();
        }
        for (int i = 0; i < arrows.size(); ++i){
            arrows[i].draw();
        }
        for (int i = 0; i < marks.size(); ++i){
            marks[i].draw();
        }
	}
}
// Graph


