#include "Graph.h"
#include "Simple_window.h"

#include <iostream>
#include <string>

#include <stdlib.h>

using namespace Graph_lib;

int main()
try
{
	Point tl(300,50);
	Simple_window win(tl, 800, 1000, "My Window");
	//win.wait_for_button();

	//rácsvonalak kirajzolása, 800x800
	Lines grid;
	int x_size = 800;
	int y_size = 800;


	for(int i = 1; i <= x_size; i+=100)	//+100-zal egy négyzetrácsnyit megyünk odébb
	{
		grid.add(Point(i,0), Point(i, y_size));
		grid.add(Point(0,i), Point(x_size, i));
	}
	
	win.attach(grid);

	// ez király megoldás a piros négyzetekre
	Vector_ref<Rectangle> rect;

	for (int i = 0; i < 8; ++i)
		for (int j = 0; j < 8; ++j ) {
			rect.push_back(new Rectangle{Point{i*100, i*100}, 100, 100});
			rect[rect.size()-1].set_fill_color(Color::red);
			win.attach(rect[rect.size()-1]);
		}


	// beszúrom a 200x200-as képeket különböző helyekre

	Image pic1 {Point{0, 300}, "200x200.jpg"};
	Image pic2 {Point{500, 0}, "200x200.jpg"};
	Image pic3 {Point{300, 600}, "200x200.jpg"};

	win.attach(pic1);
	win.attach(pic2);
	win.attach(pic3);

	// 100x100-as kép, amely random fog ugrálni

	for (int i = 1; i <= 9; ++i) {
		int px = rand() % 8;
		int py = rand() % 8;
		Image pic100up {Point{px*100, py*100}, "100x100.jpg"};
		win.attach(pic100up);
		win.wait_for_button();

	}

	// az alsó kommentelt megoldás egy szabály szerint mozgatja a képeket

	/*
	for (int i = 1; i <= 7; ++i) {
		Image pic100down {Point{(i*100)-100, i*100}, "100x100.jpg"};
		Image pic100up {Point{i*100, (i*100)-100}, "100x100.jpg"};
		win.attach(pic100down);
		win.attach(pic100up);
		win.wait_for_button();

	}
	*/

	win.wait_for_button();

}

catch (exception& e)
{
	cerr << "exception: " << e.what() << '\n';
	return 1;
}

catch (...)
{
	cerr << "exception\n";
	return 2;
}


// "bénább" megoldás a piros négyzetekre, azért van kikommentelve
/*
	Rectangle r1 {Point{0,0}, 100, 100};
	Rectangle r2 {Point{100,100}, 100, 100};
	Rectangle r3 {Point{200,200}, 100, 100};
	Rectangle r4 {Point{300,300}, 100, 100};
	Rectangle r5 {Point{400,400}, 100, 100};
	Rectangle r6 {Point{500,500}, 100, 100};
	Rectangle r7 {Point{600,600}, 100, 100};
	Rectangle r8 {Point{700,700}, 100, 100};
	r1.set_fill_color(Color::red);
	r2.set_fill_color(Color::red);
	r3.set_fill_color(Color::red);
	r4.set_fill_color(Color::red);
	r5.set_fill_color(Color::red);
	r6.set_fill_color(Color::red);
	r7.set_fill_color(Color::red);
	r8.set_fill_color(Color::red);


	//win.attach(grid);

	win.attach(r1);
	win.attach(r2);
	win.attach(r3);
	win.attach(r4);
	win.attach(r5);
	win.attach(r6);
	win.attach(r7);
	win.attach(r8);
*/