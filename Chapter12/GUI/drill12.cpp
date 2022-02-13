#include <stdexcept>

#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

int main()
try
{
	//ez fogja az ablak bal felső sarkát jelenteni
	Point tl {100, 100};

	//létrehozunk egy 600x400-as ablakot "My window" néven
	Simple_window win {tl, 600, 400, "My window"};

	//létrehozom az x tengelyt, 20-300ig, 280 pixel hosszú, 10 "notcha" van
	Axis xa {Axis::x, Point{20, 300}, 280, 10, "X axis"};

	//létrehozom az y tengelyt, s színeket módosítok rajta
	Axis ya {Axis::y, Point{20, 300}, 280, 10, "Y axis"};
	ya.set_color(Color::cyan);
	ya.label.set_color(Color::dark_red);

	//Szinusz görbe, 1000 ponton megy, 50esével növekszik x-en és y-on
	Function sine {sin, 0, 100, Point{20, 150}, 1000, 50, 50};
	sine.set_color(Color::blue);

	//felveszünk egy 3 pontú poligont (háromszöget)
	Polygon poly;
	poly.add(Point{300, 200});
	poly.add(Point{350, 100});
	poly.add(Point{400, 200});

	poly.set_color(Color::red);
	poly.set_style(Line_style(Line_style::dash, 2));

	//téglalap készítése a Rectangle class-al
	Rectangle r {Point{200, 200}, 100, 50};

	r.set_fill_color(Color::yellow);

	//sokszög készítése
	Closed_polyline poly_rect;
	poly_rect.add(Point{100, 50});
	poly_rect.add(Point{200, 50});
	poly_rect.add(Point{200, 100});
	poly_rect.add(Point{100, 100});
	poly_rect.add(Point{50, 75});

	poly_rect.set_style(Line_style(Line_style::dash, 2));
	poly_rect.set_fill_color(Color::green);

	//szöveg bevitele a képernyőre
	Text t {Point(150, 150), "Hello, graphical world!"};
	t.set_font(Font::times_bold);
	t.set_font_size(20);

	//Kép felvétele
	Image ii {Point{100, 50}, "badge.jpg"};

	//kör felvétele
	Circle c {Point(100, 200), 50};

	//Elipszis felvétele
	Ellipse e {Point(100, 200), 75, 25};
	e.set_color(Color::dark_red);

	//marker felvétele
	Mark m {Point(100, 200), 'x'};

	win.attach(ii);
	win.attach(c);
	win.attach(e);
	win.attach(m);
	win.attach(t);
	win.attach(poly_rect);
	win.attach(r);
	win.attach(poly);
	win.attach(sine);
	win.attach(ya);
	win.attach(xa);

	win.wait_for_button();
}

catch(exception& e)
{
	return 1;
}

catch(...)
{
	return 2;
}