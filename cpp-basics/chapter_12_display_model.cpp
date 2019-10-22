#include "Graph.h"
#include "Simple_window.h"
#include<cmath>

// 10. Draw the file diagram from §12.8.

int main()
{
	Simple_window win{ Point { 100, 100 }, 800, 640, "Canvas" };
	
	// --------------- BLOCK --------------- //

	Point pointH = { 100, 70 };
	string comment = "some comment";
	string code = "struct Point { ... };";
	string code1 = "...";

	int px = pointH.x;
	int py = pointH.y;
	

	Graph_lib::Rectangle block{ pointH, 135, 30};
	block.set_style(Line_style(Line_style::solid, 1));
	block.set_fill_color(Color::white);
	win.attach(block);

	Point ph{ px, py - 7 };
	Text theader{ ph, "Point.h" };
	theader.set_font(Font::helvetica_bold);
	theader.set_font_size(15);
	win.attach(theader);
	
	px += 10;

	Point pi = { px , py + 1 * 20 };
	Text bold_line{ pi, code };
	bold_line.set_font(Font::times_bold);
	bold_line.set_font_size(15);
	win.attach(bold_line);
	

	// --------------- BLOCK --------------- //

	pointH = { 100, 200 };
	string header = "Graph.h";
	string code2 = "int main() { ... }";
	comment = "// graphing interface:";
	code = "struct Shape { ... };";
	code1 = "...";

	px = pointH.x;
	py = pointH.y;

	Graph_lib::Rectangle block1{ pointH, 150, 70 };
	block1.set_style(Line_style(Line_style::solid, 1));
	block1.set_fill_color(Color::white);
	win.attach(block1);

	ph = { px, py - 7 };
	Text theader1{ ph, "Graph.h" };
	theader1.set_font(Font::helvetica_bold);
	theader1.set_font_size(15);
	win.attach(theader1);

	px += 10; py += 20;
	
	// comment
	Point pc{ px, py };
	Text com1{ pc, comment };
	win.attach(com1);

	pi = { px , py + 1 * 20 };
	Text bold_line1{ pi, code };
	bold_line1.set_font(Font::times_bold);
	bold_line1.set_font_size(15);
	win.attach(bold_line1);

	pi = { px , py + 2 * 20 };
	Text bold_line11{ pi, code1 };
	bold_line11.set_font(Font::times_bold);
	bold_line11.set_font_size(15);
	win.attach(bold_line11);

	// --------------- BLOCK --------------- //

	pointH = { 50, 400 };
	header = "Graph.cpp";
	comment = "// graphing interface:";
	code = "Graph code";
	
	
	px = pointH.x;
	py = pointH.y;

	Graph_lib::Rectangle block2{ pointH, 100, 30 };
	block2.set_style(Line_style(Line_style::solid, 1));
	block2.set_fill_color(Color::white);
	win.attach(block2);

	ph = { px, py - 7 };
	Text theader2{ ph,  header };
	theader2.set_font(Font::helvetica_bold);
	theader2.set_font_size(15);
	win.attach(theader2);

	px += 10; 

	pi = { px , py + 1 * 20 };
	Text bold_line2{ pi, code };
	bold_line2.set_font(Font::times_bold);
	bold_line2.set_font_size(15);
	win.attach(bold_line2);

	// --------------- BLOCK --------------- //

	pointH = { 110, 530 };

	header = "chapter12.cpp";
	comment = "// graphing interface:";
	code = "#include \"Graph.h\"";
	code1 = "#include \"Simple_window.h\"";
	code2 = "int main() { ... }";

	px = pointH.x;
	py = pointH.y;

	Graph_lib::Rectangle block3{ pointH, 210, 70 };
	block3.set_style(Line_style(Line_style::solid, 1));
	block3.set_fill_color(Color::white);
	win.attach(block3);

	ph = { px, py - 7 };
	Text theader3{ ph, header };
	theader3.set_font(Font::helvetica_bold);
	theader3.set_font_size(15);
	win.attach(theader3);

	px += 10; 
	// comment
    pc = { px, py };
	// Text com1 = { pc, comment };
	// win.attach(com1);

	pi = { px , py + 1 * 20 };
	Text bold_line3{ pi, code };
	bold_line3.set_font(Font::times_bold);
	bold_line3.set_font_size(15);
	win.attach(bold_line3);

	pi = { px , py + 2 * 20 };
	Text bold_line31{ pi, code1 };
	bold_line31.set_font(Font::times_bold);
	bold_line31.set_font_size(15);
	win.attach(bold_line31);

	pi = { px , py + 3 * 20 };
	Text bold_line32{ pi, code2 };
	bold_line32.set_font(Font::times_bold);
	bold_line32.set_font_size(15);
	win.attach(bold_line32);

	// --------------- BLOCK --------------- //

	pointH = { 220, 320 };

	header = "window.cpp";
	comment = "// graphing interface:";
	code = "Window code";
	code1 = "#include \"Simple_window.h\"";
	code2 = "int main() { ... }";

	px = pointH.x;
	py = pointH.y;

	Graph_lib::Rectangle block4{ pointH, 130, 30 };
	block4.set_style(Line_style(Line_style::solid, 1));
	block4.set_fill_color(Color::white);
	win.attach(block4);

	ph = { px, py - 7 };
	Text theader4{ ph, header };
	theader4.set_font(Font::helvetica_bold);
	theader4.set_font_size(15);
	win.attach(theader4);

	px += 10;
	// comment
	pc = { px, py };
	// Text com1 = { pc, comment };
	// win.attach(com1);

	pi = { px , py + 1 * 20 };
	Text bold_line4{ pi, code };
	bold_line4.set_font(Font::times_bold);
	bold_line4.set_font_size(15);
	win.attach(bold_line4);



	// --------------- BLOCK --------------- //

	pointH = { 250, 410 };

	header = "Simple_window.h:";
	comment = "// window interface:";
	code = "class Simple_window { ... };";
	code1 = "...";
	code2 = "int main() { ... }";

	px = pointH.x;
	py = pointH.y;

	Graph_lib::Rectangle block5{ pointH, 200, 70 };
	block5.set_style(Line_style(Line_style::solid, 1));
	block5.set_fill_color(Color::white);
	win.attach(block5);

	ph = { px, py - 7 };
	Text theader5{ ph, header };
	theader5.set_font(Font::helvetica_bold);
	theader5.set_font_size(15);
	win.attach(theader5);

	px += 10;
	// comment
	py += 20;
	pc = { px, py };
	Text com5 = { pc, comment };
	win.attach(com5);

	pi = { px , py + 1 * 20 };
	Text bold_line5{ pi, code };
	bold_line5.set_font(Font::times_bold);
	bold_line5.set_font_size(15);
	win.attach(bold_line5);

	pi = { px , py + 2 * 20 };
	Text bold_line51{ pi, code1 };
	bold_line51.set_font(Font::times_bold);
	bold_line51.set_font_size(15);
	win.attach(bold_line51);


	// --------------- BLOCK --------------- //

	pointH = { 320, 150 };

	header = "Window.h:";
	comment = "// window interface:";
	code = "class Window { ... };";
	code1 = "...";

	px = pointH.x;
	py = pointH.y;

	Graph_lib::Rectangle block6{ pointH, 150, 70 };
	block6.set_style(Line_style(Line_style::solid, 1));
	block6.set_fill_color(Color::white);
	win.attach(block6);

	ph = { px, py - 7 };
	Text theader6{ ph, header };
	theader6.set_font(Font::helvetica_bold);
	theader6.set_font_size(15);
	win.attach(theader6);

	px += 10;
	// comment
	py += 20;
	pc = { px, py };
	Text com6 = { pc, comment };
	win.attach(com6);

	pi = { px , py + 1 * 20 };
	Text bold_line6{ pi, code };
	bold_line6.set_font(Font::times_bold);
	bold_line6.set_font_size(15);
	win.attach(bold_line6);

	pi = { px , py + 2 * 20 };
	Text bold_line61{ pi, code1 };
	bold_line61.set_font(Font::times_bold);
	bold_line61.set_font_size(15);
	win.attach(bold_line61);


	// --------------- BLOCK --------------- //

	pointH = { 450, 280 };

	header = "GUI.h:";
	comment = "// GUI interface:";
	code = "struct In_box { ... };";
	code1 = "...";

	px = pointH.x;
	py = pointH.y;

	Graph_lib::Rectangle block7{ pointH, 150, 70 };
	block7.set_style(Line_style(Line_style::solid, 1));
	block7.set_fill_color(Color::white);
	win.attach(block7);

	ph = { px, py - 7 };
	Text theader7{ ph, header };
	theader7.set_font(Font::helvetica_bold);
	theader7.set_font_size(15);
	win.attach(theader7);

	px += 10;
	// comment
	py += 20;
	pc = { px, py };
	Text com7 = { pc, comment };
	win.attach(com7);

	pi = { px , py + 1 * 20 };
	Text bold_line7{ pi, code };
	bold_line7.set_font(Font::times_bold);
	bold_line7.set_font_size(15);
	win.attach(bold_line7);

	pi = { px , py + 2 * 20 };
	Text bold_line71{ pi, code1 };
	bold_line71.set_font(Font::times_bold);
	bold_line71.set_font_size(15);
	win.attach(bold_line71);

	// --------------- BLOCK --------------- //

	pointH = { 475, 400 };
	header = "GUI.cpp";
	comment = "// graphing interface:";
	code = "GUI code";


	px = pointH.x;
	py = pointH.y;

	Graph_lib::Rectangle block8{ pointH, 80, 30 };
	block8.set_style(Line_style(Line_style::solid, 1));
	block8.set_fill_color(Color::white);
	win.attach(block8);

	ph = { px, py - 7 };
	Text theader8{ ph,  header };
	theader8.set_font(Font::helvetica_bold);
	theader8.set_font_size(15);
	win.attach(theader8);

	px += 10;

	pi = { px , py + 1 * 20 };
	Text bold_line8{ pi, code };
	bold_line8.set_font(Font::times_bold);
	bold_line8.set_font_size(15);
	win.attach(bold_line8);


	// --------------- BLOCK SPECIAL --------------- //

	pointH = { 360, 20 };
	comment = "FLTK headers";

	px = pointH.x;
	py = pointH.y;

	Graph_lib::Rectangle bblock{ pointH, 110, 45 };
	bblock.set_style(Line_style(Line_style::solid, 1));
	bblock.set_fill_color(Color::white);
	win.attach(bblock);

	px += 3; py += 3; pointH = { px, py };
	Graph_lib::Rectangle bblock1{ pointH, 110, 45 };
	bblock1.set_style(Line_style(Line_style::solid, 1));
	bblock1.set_fill_color(Color::white);
	win.attach(bblock1);

	px += 3; py += 3; pointH = { px, py };
	Graph_lib::Rectangle bblock2{ pointH, 110, 45 };
	bblock2.set_style(Line_style(Line_style::solid, 1));
	bblock2.set_fill_color(Color::white);
	win.attach(bblock2);


	px += 10;
	// comment
	py += 20;
	pc = { px, py };
	Text bcom = { pc, comment };
	win.attach(bcom);


	// --------------- BLOCK SPECIAL --------------- //

	pointH = { 570, 70 };
	comment = "FLTK code";

	px = pointH.x;
	py = pointH.y;

	Graph_lib::Rectangle bblock0{ pointH, 90, 45 };
	bblock0.set_style(Line_style(Line_style::solid, 1));
	bblock0.set_fill_color(Color::white);
	win.attach(bblock0);

	px += 3; py += 3; pointH = { px, py };
	Graph_lib::Rectangle bblock01{ pointH, 90, 45 };
	bblock01.set_style(Line_style(Line_style::solid, 1));
	bblock01.set_fill_color(Color::white);
	win.attach(bblock01);

	px += 3; py += 3; pointH = { px, py };
	Graph_lib::Rectangle bblock02{ pointH, 90, 45 };
	bblock02.set_style(Line_style(Line_style::solid, 1));
	bblock02.set_fill_color(Color::white);
	win.attach(bblock02);


	px += 10;
	// comment
	py += 20;
	pc = { px, py };
	Text bcom0 = { pc, comment };
	win.attach(bcom0);

	// --------------- ARROW --------------- //

	int arrowN = 10; // arrow pointer length 
	int arrowA = 2; // arrow pointer half width
	int xd, yd;
	int xp1, xp2, yp1, yp2;

	Point p1{};
	Point p2{};

	int x0 = 175;   // vector start
	int y0 = 200;

	int x1 = 175;   // vector end
	int y1 = 100;

	Point begin { x0, y0 };
	Point end { x1, y1 };


	double cos = sqrt((x1 - x0) * (x1 - x0)) / sqrt((x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0));
	double sin = sqrt(1 - cos * cos);
		
	if (x1 < x0) xd = x1 + arrowN * cos;
	else xd = x1 - arrowN * cos;

	if (y1 < y0) yd = y1 + arrowN * sin;
	else yd = y1 - arrowN * sin;

	if (x1 > x0) {
		xp1 = xd - arrowA * sin;
		yp1 = yd - arrowA * cos;
		xp2 = xd + arrowA * sin;
		yp2 = yd + arrowA * cos;
	}
	else {
		xp1 = xd + arrowA * sin;
		yp1 = yd - arrowA * cos;
		xp2 = xd - arrowA * sin;
		yp2 = yd + arrowA * cos;
	}
	
	p1 = { xp1, yp1 };
	p2 = { xp2, yp2 };

	Graph_lib::Polygon poly;
	poly.add(p1);
	poly.add(end);
	poly.add(p2);

	poly.set_style(Graph_lib::Line_style(Graph_lib::Line_style::solid, 1));
	poly.set_fill_color(Color::black);
	win.attach(poly);

	Graph_lib::Line line (begin, end);
	win.attach(line);
	
	// --------------- ARROW --------------- //

	x0 = 175;   // vector start
	y0 = 200;

	x1 = 375;   // vector end
	y1 = 72;

	begin = { x0, y0 };
	end = { x1, y1 };

	cos = sqrt((x1 - x0) * (x1 - x0)) / sqrt((x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0));
	sin = sqrt(1 - cos * cos);

	if (x1 < x0) xd = x1 + arrowN * cos;
	else xd = x1 - arrowN * cos;

	if (y1 < y0) yd = y1 + arrowN * sin;
	else yd = y1 - arrowN * sin;

	if (x1 > x0) {
		xp1 = xd - arrowA * sin;
		yp1 = yd - arrowA * cos;
		xp2 = xd + arrowA * sin + 0.5;
		yp2 = yd + arrowA * cos + 0.5;
	}
	else {
		xp1 = xd + arrowA * sin;
		yp1 = yd - arrowA * cos;
		xp2 = xd - arrowA * sin;
		yp2 = yd + arrowA * cos;
	}

	p1 = { xp1, yp1 };
	p2 = { xp2, yp2 };

	Graph_lib::Polygon poly1;
	poly1.add(p1);
	poly1.add(end);
	poly1.add(p2);

	poly1.set_style(Graph_lib::Line_style(Graph_lib::Line_style::solid, 1));
	poly1.set_fill_color(Color::black);
	win.attach(poly1);

	Graph_lib::Line line1(begin, end);
	win.attach(line1);

	// --------------- ARROW --------------- //

	x0 = 130;   // vector start
	y0 = 400;

	x1 = 170;   // vector end
	y1 = 270;

	begin = { x0, y0 };
	end = { x1, y1 };

	cos = sqrt((x1 - x0) * (x1 - x0)) / sqrt((x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0));
	sin = sqrt(1 - cos * cos);

	if (x1 < x0) xd = x1 + arrowN * cos;
	else xd = x1 - arrowN * cos;

	if (y1 < y0) yd = y1 + arrowN * sin;
	else yd = y1 - arrowN * sin;

	if (x1 > x0) {
		xp1 = xd - arrowA * sin;
		yp1 = yd - arrowA * cos;
		xp2 = xd + arrowA * sin + 0.5;
		yp2 = yd + arrowA * cos + 0.5;
	}
	else {
		xp1 = xd + arrowA * sin;
		yp1 = yd - arrowA * cos;
		xp2 = xd - arrowA * sin;
		yp2 = yd + arrowA * cos;
	}

	p1 = { xp1, yp1 };
	p2 = { xp2, yp2 };

	Graph_lib::Polygon poly2;
	poly2.add(p1);
	poly2.add(end);
	poly2.add(p2);

	poly2.set_style(Graph_lib::Line_style(Graph_lib::Line_style::solid, 1));
	poly2.set_fill_color(Color::black);
	win.attach(poly2);

	Graph_lib::Line line2(begin, end);
	win.attach(line2);



	// --------------- ARROW --------------- //

	x0 = 220;   // vector start
	y0 = 530;

	x1 = 185;   // vector end
	y1 = 270;

	begin = { x0, y0 };
	end = { x1, y1 };

	cos = sqrt((x1 - x0) * (x1 - x0)) / sqrt((x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0));
	sin = sqrt(1 - cos * cos);

	if (x1 < x0) xd = x1 + arrowN * cos;
	else xd = x1 - arrowN * cos;

	if (y1 < y0) yd = y1 + arrowN * sin;
	else yd = y1 - arrowN * sin;

	if (x1 > x0) {
		xp1 = xd - arrowA * sin;
		yp1 = yd - arrowA * cos;
		xp2 = xd + arrowA * sin + 0.5;
		yp2 = yd + arrowA * cos + 0.5;
	}
	else {
		xp1 = xd + arrowA * sin + 0.5;
		yp1 = yd - arrowA * cos + 0.5;
		xp2 = xd - arrowA * sin;
		yp2 = yd + arrowA * cos;
	}

	p1 = { xp1, yp1 };
	p2 = { xp2, yp2 };

	Graph_lib::Polygon poly3;
	poly3.add(p1);
	poly3.add(end);
	poly3.add(p2);

	poly3.set_style(Graph_lib::Line_style(Graph_lib::Line_style::solid, 1));
	poly3.set_fill_color(Color::black);
	win.attach(poly3);

	Graph_lib::Line line3(begin, end);
	win.attach(line3);

	// --------------- ARROW --------------- //

	x0 = 220;   // vector start
	y0 = 530;

	x1 = 280;   // vector end
	y1 = 480;

	begin = { x0, y0 };
	end = { x1, y1 };

	cos = sqrt((x1 - x0) * (x1 - x0)) / sqrt((x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0));
	sin = sqrt(1 - cos * cos);

	if (x1 < x0) xd = x1 + arrowN * cos;
	else xd = x1 - arrowN * cos;

	if (y1 < y0) yd = y1 + arrowN * sin;
	else yd = y1 - arrowN * sin;

	if (x1 > x0) {
		xp1 = xd - arrowA * sin;
		yp1 = yd - arrowA * cos;
		xp2 = xd + arrowA * sin + 0.5;
		yp2 = yd + arrowA * cos + 0.5;
	}
	else {
		xp1 = xd + arrowA * sin + 0.5;
		yp1 = yd - arrowA * cos + 0.5;
		xp2 = xd - arrowA * sin;
		yp2 = yd + arrowA * cos;
	}

	p1 = { xp1, yp1 };
	p2 = { xp2, yp2 };

	Graph_lib::Polygon poly4;
	poly4.add(p1);
	poly4.add(end);
	poly4.add(p2);

	poly4.set_style(Graph_lib::Line_style(Graph_lib::Line_style::solid, 1));
	poly4.set_fill_color(Color::black);
	win.attach(poly4);

	Graph_lib::Line line4(begin, end);
	win.attach(line4);

	// --------------- ARROW --------------- //

	x0 = 320;   // vector start
	y0 = 320;

	x1 = 380;   // vector end
	y1 = 220;

	begin = { x0, y0 };
	end = { x1, y1 };

	cos = sqrt((x1 - x0) * (x1 - x0)) / sqrt((x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0));
	sin = sqrt(1 - cos * cos);

	if (x1 < x0) xd = x1 + arrowN * cos;
	else xd = x1 - arrowN * cos;

	if (y1 < y0) yd = y1 + arrowN * sin;
	else yd = y1 - arrowN * sin;

	if (x1 > x0) {
		xp1 = xd - arrowA * sin;
		yp1 = yd - arrowA * cos;
		xp2 = xd + arrowA * sin + 1;
		yp2 = yd + arrowA * cos + 1;
	}
	else {
		xp1 = xd + arrowA * sin + 0.5;
		yp1 = yd - arrowA * cos + 0.5;
		xp2 = xd - arrowA * sin;
		yp2 = yd + arrowA * cos;
	}

	p1 = { xp1, yp1 };
	p2 = { xp2, yp2 };

	Graph_lib::Polygon poly5;
	poly5.add(p1);
	poly5.add(end);
	poly5.add(p2);

	poly5.set_style(Graph_lib::Line_style(Graph_lib::Line_style::solid, 1));
	poly5.set_fill_color(Color::black);
	win.attach(poly5);

	Graph_lib::Line line5(begin, end);
	win.attach(line5);

	// --------------- ARROW --------------- //

	x0 = 335;   // vector start
	y0 = 150;

	x1 = 215;   // vector end
	y1 = 101;

	begin = { x0, y0 };
	end = { x1, y1 };

	cos = sqrt((x1 - x0) * (x1 - x0)) / sqrt((x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0));
	sin = sqrt(1 - cos * cos);

	if (x1 < x0) xd = x1 + arrowN * cos;
	else xd = x1 - arrowN * cos;

	if (y1 < y0) yd = y1 + arrowN * sin;
	else yd = y1 - arrowN * sin;

	if (x1 > x0) {
		xp1 = xd - arrowA * sin;
		yp1 = yd - arrowA * cos;
		xp2 = xd + arrowA * sin;
		yp2 = yd + arrowA * cos;
	}
	else {
		xp1 = xd + arrowA * sin + 0.5;
		yp1 = yd - arrowA * cos + 0.5;
		xp2 = xd - arrowA * sin + 0.5;
		yp2 = yd + arrowA * cos + 0.5;
	}

	p1 = { xp1, yp1 };
	p2 = { xp2, yp2 };

	Graph_lib::Polygon poly6;
	poly6.add(p1);
	poly6.add(end);
	poly6.add(p2);

	poly6.set_style(Graph_lib::Line_style(Graph_lib::Line_style::solid, 1));
	poly6.set_fill_color(Color::black);
	win.attach(poly6);

	Graph_lib::Line line6(begin, end);
	win.attach(line6);


	// --------------- ARROW --------------- //

	x0 = 400;   // vector start
	y0 = 410;

	x1 = 400;   // vector end
	y1 = 220;

	begin = { x0, y0 };
	end = { x1, y1 };

	cos = sqrt((x1 - x0) * (x1 - x0)) / sqrt((x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0));
	sin = sqrt(1 - cos * cos);

	if (x1 < x0) xd = x1 + arrowN * cos;
	else xd = x1 - arrowN * cos;

	if (y1 < y0) yd = y1 + arrowN * sin;
	else yd = y1 - arrowN * sin;

	if (x1 > x0) {
		xp1 = xd - arrowA * sin;
		yp1 = yd - arrowA * cos;
		xp2 = xd + arrowA * sin;
		yp2 = yd + arrowA * cos;
	}
	else {
		xp1 = xd + arrowA * sin + 0.5;
		yp1 = yd - arrowA * cos + 0.5;
		xp2 = xd - arrowA * sin + 0.5;
		yp2 = yd + arrowA * cos + 0.5;
	}

	p1 = { xp1, yp1 };
	p2 = { xp2, yp2 };

	Graph_lib::Polygon poly7;
	poly7.add(p1);
	poly7.add(end);
	poly7.add(p2);

	poly7.set_style(Graph_lib::Line_style(Graph_lib::Line_style::solid, 1));
	poly7.set_fill_color(Color::black);
	win.attach(poly7);

	Graph_lib::Line line7(begin, end);
	win.attach(line7);


	// --------------- ARROW --------------- //

	x0 = 400;   // vector start
	y0 = 150;

	x1 = 400;   // vector end
	y1 = 72;

	begin = { x0, y0 };
	end = { x1, y1 };

	cos = sqrt((x1 - x0) * (x1 - x0)) / sqrt((x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0));
	sin = sqrt(1 - cos * cos);

	if (x1 < x0) xd = x1 + arrowN * cos;
	else xd = x1 - arrowN * cos;

	if (y1 < y0) yd = y1 + arrowN * sin;
	else yd = y1 - arrowN * sin;

	if (x1 > x0) {
		xp1 = xd - arrowA * sin;
		yp1 = yd - arrowA * cos;
		xp2 = xd + arrowA * sin;
		yp2 = yd + arrowA * cos;
	}
	else {
		xp1 = xd + arrowA * sin + 0.5;
		yp1 = yd - arrowA * cos + 0.5;
		xp2 = xd - arrowA * sin + 0.5;
		yp2 = yd + arrowA * cos + 0.5;
	}

	p1 = { xp1, yp1 };
	p2 = { xp2, yp2 };

	Graph_lib::Polygon poly8;
	poly8.add(p1);
	poly8.add(end);
	poly8.add(p2);

	poly8.set_style(Graph_lib::Line_style(Graph_lib::Line_style::solid, 1));
	poly8.set_fill_color(Color::black);
	win.attach(poly8);

	Graph_lib::Line line8(begin, end);
	win.attach(line8);

	// --------------- ARROW --------------- //

	x0 = 400;   // vector start
	y0 = 410;

	x1 = 470;   // vector end
	y1 = 350;

	begin = { x0, y0 };
	end = { x1, y1 };

	cos = sqrt((x1 - x0) * (x1 - x0)) / sqrt((x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0));
	sin = sqrt(1 - cos * cos);

	if (x1 < x0) xd = x1 + arrowN * cos;
	else xd = x1 - arrowN * cos;

	if (y1 < y0) yd = y1 + arrowN * sin;
	else yd = y1 - arrowN * sin;

	if (x1 > x0) {
		xp1 = xd - arrowA * sin;
		yp1 = yd - arrowA * cos;
		xp2 = xd + arrowA * sin + 0.5;
		yp2 = yd + arrowA * cos + 0.5;
	}
	else {
		xp1 = xd + arrowA * sin + 0.5;
		yp1 = yd - arrowA * cos + 0.5;
		xp2 = xd - arrowA * sin + 0.5;
		yp2 = yd + arrowA * cos + 0.5;
	}

	p1 = { xp1, yp1 };
	p2 = { xp2, yp2 };

	Graph_lib::Polygon poly9;
	poly9.add(p1);
	poly9.add(end);
	poly9.add(p2);

	poly9.set_style(Graph_lib::Line_style(Graph_lib::Line_style::solid, 1));
	poly9.set_fill_color(Color::black);
	win.attach(poly9);

	Graph_lib::Line line9(begin, end);
	win.attach(line9);

	// --------------- ARROW --------------- //

	x0 = 545;   // vector start
	y0 = 400;

	x1 = 530;   // vector end
	y1 = 350;

	begin = { x0, y0 };
	end = { x1, y1 };

	cos = sqrt((x1 - x0) * (x1 - x0)) / sqrt((x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0));
	sin = sqrt(1 - cos * cos);

	if (x1 < x0) xd = x1 + arrowN * cos;
	else xd = x1 - arrowN * cos;

	if (y1 < y0) yd = y1 + arrowN * sin;
	else yd = y1 - arrowN * sin;

	if (x1 > x0) {
		xp1 = xd - arrowA * sin;
		yp1 = yd - arrowA * cos;
		xp2 = xd + arrowA * sin + 0.5;
		yp2 = yd + arrowA * cos + 0.5;
	}
	else {
		xp1 = xd + arrowA * sin + 2;
		yp1 = yd - arrowA * cos + 1;
		xp2 = xd - arrowA * sin + 0.5;
		yp2 = yd + arrowA * cos + 0.5;
	}

	p1 = { xp1, yp1 };
	p2 = { xp2, yp2 };

	Graph_lib::Polygon poly10;
	poly10.add(p1);
	poly10.add(end);
	poly10.add(p2);

	poly10.set_style(Graph_lib::Line_style(Graph_lib::Line_style::solid, 1));
	poly10.set_fill_color(Color::black);
	win.attach(poly10);

	Graph_lib::Line line10(begin, end);
	win.attach(line10);

	// --------------- ARROW --------------- //

	x0 = 560;   // vector start
	y0 = 280;

	x1 = 460;   // vector end
	y1 = 221;

	begin = { x0, y0 };
	end = { x1, y1 };

	cos = sqrt((x1 - x0) * (x1 - x0)) / sqrt((x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0));
	sin = sqrt(1 - cos * cos);

	if (x1 < x0) xd = x1 + arrowN * cos;
	else xd = x1 - arrowN * cos;

	if (y1 < y0) yd = y1 + arrowN * sin;
	else yd = y1 - arrowN * sin;

	if (x1 > x0) {
		xp1 = xd - arrowA * sin;
		yp1 = yd - arrowA * cos;
		xp2 = xd + arrowA * sin + 0.5;
		yp2 = yd + arrowA * cos + 0.5;
	}
	else {
		xp1 = xd + arrowA * sin + 0.5;
		yp1 = yd - arrowA * cos + 0.5;
		xp2 = xd - arrowA * sin + 0.5;
		yp2 = yd + arrowA * cos + 0.5;
	}

	p1 = { xp1, yp1 };
	p2 = { xp2, yp2 };

	Graph_lib::Polygon poly11;
	poly11.add(p1);
	poly11.add(end);
	poly11.add(p2);

	poly11.set_style(Graph_lib::Line_style(Graph_lib::Line_style::solid, 1));
	poly11.set_fill_color(Color::black);
	win.attach(poly11);

	Graph_lib::Line line11(begin, end);
	win.attach(line11);

	// --------------- ARROW --------------- //

	x0 = 560;   // vector start
	y0 = 280;

	x1 = 440;   // vector end
	y1 = 70;

	begin = { x0, y0 };
	end = { x1, y1 };

	cos = sqrt((x1 - x0) * (x1 - x0)) / sqrt((x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0));
	sin = sqrt(1 - cos * cos);

	if (x1 < x0) xd = x1 + arrowN * cos;
	else xd = x1 - arrowN * cos;

	if (y1 < y0) yd = y1 + arrowN * sin;
	else yd = y1 - arrowN * sin;

	if (x1 > x0) {
		xp1 = xd - arrowA * sin;
		yp1 = yd - arrowA * cos;
		xp2 = xd + arrowA * sin + 0.5;
		yp2 = yd + arrowA * cos + 0.5;
	}
	else {
		xp1 = xd + arrowA * sin + 0.5;
		yp1 = yd - arrowA * cos + 0.5;
		xp2 = xd - arrowA * sin + 0.5;
		yp2 = yd + arrowA * cos + 0.5;
	}

	p1 = { xp1, yp1 };
	p2 = { xp2, yp2 };

	Graph_lib::Polygon poly12;
	poly12.add(p1);
	poly12.add(end);
	poly12.add(p2);

	poly12.set_style(Graph_lib::Line_style(Graph_lib::Line_style::solid, 1));
	poly12.set_fill_color(Color::black);
	win.attach(poly12);

	Graph_lib::Line line12(begin, end);
	win.attach(line12);

	// --------------- ARROW --------------- //

	x0 = 570;   // vector start
	y0 = 95;

	x1 = 476;   // vector end
	y1 = 50;

	begin = { x0, y0 };
	end = { x1, y1 };

	cos = sqrt((x1 - x0) * (x1 - x0)) / sqrt((x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0));
	sin = sqrt(1 - cos * cos);

	if (x1 < x0) xd = x1 + arrowN * cos;
	else xd = x1 - arrowN * cos;

	if (y1 < y0) yd = y1 + arrowN * sin;
	else yd = y1 - arrowN * sin;

	if (x1 > x0) {
		xp1 = xd - arrowA * sin;
		yp1 = yd - arrowA * cos;
		xp2 = xd + arrowA * sin + 0.5;
		yp2 = yd + arrowA * cos + 0.5;
	}
	else {
		xp1 = xd + arrowA * sin + 0.5;
		yp1 = yd - arrowA * cos + 0.5;
		xp2 = xd - arrowA * sin + 0.5;
		yp2 = yd + arrowA * cos + 0.5;
	}

	p1 = { xp1, yp1 };
	p2 = { xp2, yp2 };

	Graph_lib::Polygon poly13;
	poly13.add(p1);
	poly13.add(end);
	poly13.add(p2);

	poly13.set_style(Graph_lib::Line_style(Graph_lib::Line_style::solid, 1));
	poly13.set_fill_color(Color::black);
	win.attach(poly13);

	Graph_lib::Line line13(begin, end);
	win.attach(line13);


	win.wait_for_button();
}