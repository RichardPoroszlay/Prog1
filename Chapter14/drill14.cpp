#include <iostream>
#include <string>

//ABSZTRAKT OSZTÁLYT NEM TUDOK PÉLDÁNYOSÍTANI --> ERRORT FOG VISSZADOBNI
//Az is absztrakt osztály, amely egy absztrakt osztályból öröklődik
//A virtual kulcsszó azt hivatott jelezni, hogy a függvény felül lesz írva

using namespace std;

class B1
{
	public:

		virtual void vf() {cout << "B1::vf()" << '\n';}
		void f() {cout << "B1::f()" << '\n';}
		virtual void pvf() = 0; //azért egyenlő 0-val, mert ez működés nélküli függvény. Egy ilyen tisztán virtuális függvény egy absztrakt függvény.
};

//public a B1, így megmaradnak a láthatóságok. Legmagasabb szintű láthatóság.
class D1 : public B1
{
	public:

		virtual void vf() {cout << "D1::vf()" << '\n';}
		void f() {cout << "D1::f()" << '\n';}
};

class D2 : public D1
{
	public:

		void pvf() {cout << "D2::pvf()" << '\n';}
};

class B2
{
	public:

		virtual void pvf() = 0;
};

class D21 : public B2
{
	public:

		string s;
		void pvf() {cout << s << '\n';}
};

class D22 : public B2
{
	public:

		int i;
		void pvf() {cout << i << '\n';}
};

void f(B2& b2)
{
	b2.pvf();
}


int main()
{
	/*
	B1 b1; //létrehoztam egy b1 példányt (objektumot)
	b1.vf();
	b1.f();

	D1 d1;
	d1.vf();
	d1.f();

	B1& b1ref = d1;
	b1ref.vf();
	b1ref.f();
	*/

	D2 d2;
	d2.f();
	d2.vf();
	d2.pvf();

	/*
	B2 b2;
	b2.pvf()
	*/

	D21 d21;
	d21.s = "d21.s";
	d21.pvf();

	D22 d22;
	d22.i = 22;
	d22.pvf();

	f(d21);
	f(d22);

	return 0;
}