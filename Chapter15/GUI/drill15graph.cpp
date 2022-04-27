/*	
	I. Function graphing drill:
		
		1. Make an empty 600-by-600 Window labeled “Function graphs.”
		
		2. Note that you’ll need to make a project with the properties specified in the
“installation of FLTK” note from the course website.
		
		3. You’ll need to move Graph.cpp and Window.cpp into your project.
		
		4. Add an x axis and a y axis each of length 400, labeled “1 = = 20 pixels”
and with a notch every 20 pixels. The axes should cross at (300,300).
	
		5. Make both axes red.
	II. In the following, use a separate Shape for each function to be graphed:
		
		1. Graph the function double one(double x) { return 1; } in the range [–10,11]
with (0,0) at (300,300) using 400 points and no scaling (in the window).
		
		2. Change it to use x scale 20 and y scale 20.
		
		3. From now on use that range, scale, etc. for all graphs.
		
		4. Add double slope(double x) { return x/2; } to the window.
		
		5. Label the slope with a Text "x/2" at a point just above its bottom left end
point.
		
		6.Add double square(double x) { return x*x; } to the window.
		
		7.Add a cosine to the window (don’t write a new function).
		
		8.Make the cosine blue.
		
		9.Write a function sloping_cos() that adds a cosine to slope() (as defined
above) and add it to the window.
*/

// g++ drill15graph.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill15graph `fltk-config --ldflags --use-images`

#include "Graph.h"
#include "Simple_window.h"

#include <iostream>
#include <string>
#include <stdexcept> // runtime_error() innen jön

// felvesszük a megadott function-öket
// II. Feladat #1
double one(double x) { 
	return 1; 
}

// II. Feladat #4
double slope(double x) { 
	return x/2; 
}

// II. Feladat #6
double square(double x) {
 	return x*x; 
 }


// II. Feladat #9
// "lineáris cosinus görbe"
double sloping_cos(double x) {
	return cos(x) + slope(x);
}


int main() {
	// I. Feladat #1
	// ablak helyezkedése az outputon futtatáskor
	Point tl(500,250);
	
	// felvesszük az ablakot
	constexpr int xmax = 600;
	constexpr int ymax = 600;
	Simple_window win {tl, xmax, ymax, "Function graphs"};

	
	// I. Feladat #4
	// function-ökhöz tartozó részletek
	// felvettük az origo pontjait
	constexpr int x_orig = xmax/2;
	constexpr int y_orig = ymax/2;
	Point orig {x_orig, y_orig};

	// felvesszük a range értékeket
	constexpr int r_min = -10;
	constexpr int r_max = 11;

	// number of points used in range
	constexpr int n_points = 400;

	// scaling értékek
	constexpr int x_scale = 20;
	constexpr int y_scale = 20;



	// tengelyek felvétele
	// a lengthekkel megszabjuk, hogy távolabb legyenek a tengelyek végei az ablak szélétől
	constexpr int xlength = xmax - 40;
	constexpr int ylength = ymax - 40;
	// x
	Axis xa {Axis::x, Point{20,y_orig}, xlength, xlength/x_scale, "1 == 20 pixels"};
	xa.set_color(Color::red);

	// y
	Axis ya {Axis::y, Point{x_orig,ylength+20}, ylength, ylength/y_scale, "1 = 20 pixels"};
	ya.set_color(Color::red);



	// function declaration
	Function s {one, r_min, r_max, orig, n_points, x_scale, y_scale};

	Function s2 {slope, r_min, r_max, orig, n_points, x_scale, y_scale};
	Text ts2 {Point{100, y_orig+y_orig/2-20}, "x/2"};

	Function s3 {square, r_min, r_max, orig, n_points, x_scale, y_scale};

	Function s4 {cos, r_min, r_max, orig, n_points, x_scale, y_scale};
	s4.set_color(Color::blue);

	Function s5 {sloping_cos, r_min, r_max, orig, n_points, x_scale, y_scale};

	// function draw
	win.attach(xa);
	win.attach(ya);
	win.attach(s);
	win.attach(s2);
	win.attach(ts2);
	win.attach(s3);
	win.attach(s4);
	win.attach(s5);
	win.wait_for_button();

};
