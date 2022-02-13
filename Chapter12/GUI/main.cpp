/*
	g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

//lineáris függvény
double one(double)
{
	return 1;
}

//parabola függvény
double square(double x)
{
	return x*x;
}

int main()
{
	using namespace Graph_lib;

	int xmax = 1280;
	int ymax = 720;

	int x_orig = xmax / 2;
	int y_orig = ymax / 2;

	int rmin = -11;
	int rmax = 11;

	int n_points = 400;

	//megadjuk, hogy hányszor-hányas legyen az ablak + a nevét
	Simple_window win {Point{100, 100}, xmax, ymax, "Canvas"};

	//középpont felvétele
	Point origo {x_orig, y_orig};

	int xlength = xmax - 40;
	int ylength = ymax - 40;

	int xscale = 30, yscale = 30;

	//lineáris, négyzetes és cosinus függvények felvétele
	Function s (one, rmin, rmax, origo, n_points, xscale, yscale);
	Function sq (square, rmin, rmax, origo, n_points, xscale, yscale);
	Function cos_func ( [] (double x) { return cos(x); } 
							, rmin, rmax, origo, n_points, xscale, yscale);

	//x és y tengelyek felírása
	Axis x {Axis::x, Point{20, y_orig}, xlength, xlength/xscale, "X Axis"};
	Axis y {Axis::y, Point{x_orig, ylength + 20}, ylength, ylength/yscale, "Y Axis"};

	//téglalap felírása
	Rectangle r {Point{200, 200}, 100, 50};
	r.set_fill_color(Color::yellow);
	r.set_style(Line_style(Line_style::dash, 4));

	//szöveg felírása
	Text t {Point{200, 400}, "Hello graphics!"};
	t.set_font(Font::times_bold);
	t.set_font_size(20);

	//kép felvétele
	Image ii {Point{100, 100}, "badge.jpg"};

	Circle c {Point{400, 400}, 50};

	//a tartalmak beszúrása az ablakra
	win.attach(ii);
	win.attach(c);
	win.attach(t);
	win.attach(r);
	win.attach(x);
	win.attach(y);
	win.attach(s);
	win.attach(sq);
	win.attach(cos_func);

	win.wait_for_button();
	
}
