/*
	g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

int main()
{
	int max_width = 600;
	int max_height = 400;

	//felvettük a rajzoló ablakot
	Simple_window win{Point{100,100}, max_width, max_height, "Graphics classes"};

	Line l (Point{200,200}, Point{300,300});

	win.attach(l);

	win.wait_for_button();
}