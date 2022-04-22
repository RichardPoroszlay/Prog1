#include <iostream>
#include <iomanip>
#include <cmath>
#include <complex>
#include <cerrno>
#include "Matrix.h"
#include "MatrixIO.h"

using namespace std;
using namespace Numeric_lib;

int main()
try{

	//Feladat #1 - Típusok memóriaméreteinek kiíratása.

	cout << "Size of char: " << sizeof(char) << endl;
	cout << "Size of short: " << sizeof(short) << endl;
	cout << "Size of int: " << sizeof(int) << endl;
	cout << "Size of long: " << sizeof(long) << endl;
	cout << "Size of float: " << sizeof(float) << endl;
	cout << "Size of double: " << sizeof(double) << endl;
	cout << "Size of int*: " << sizeof(int*) << endl;
	cout << "Size of double: " << sizeof(double*) << endl;
	cout << endl;

	//Feladat #2 - Kiírjuk a mátrixok memóriaméreteit.

	Matrix<int> a(10);
	Matrix<int> b(100);
	Matrix<double> c(10);
	Matrix<int,2> d(10,10);
	Matrix<int,3> e(10,10,10);
	cout << "Size of a: " << sizeof(a) << endl;
	cout << "Size of b: " << sizeof(b) << endl;
	cout << "Size of c: " << sizeof(c) << endl;
	cout << "Size of d: " << sizeof(d) << endl;
	cout << "Size of e: " << sizeof(e) << endl;
	cout << endl;

	//Feladat #3 - A #2-es feladatban lévő mátrixok elemeit kiírjuk.

	cout << "Number of elements in a matrix: " << a.size()<< endl;
	cout << "Number of elements in b matrix: " << b.size()<< endl;
	cout << "Number of elements in c matrix: " << c.size()<< endl;
	cout << "Number of elements in d matrix: " << d.size()<< endl;
	cout << "Number of elements in e matrix: " << e.size()<< endl;
	cout << endl;

	//Feladat #4 - Beolvasunk intet; ha az valid, akkor négyzetgyököt veszünk, másként error.

	int i;
	while(cin >> i){
		double d = sqrt(i);
		if (i < 0){
			cout << "no square root" << endl;
		}
		else{
			cout << "sqrt(" << i << ") = " << d << endl;	
		}
	}

	//Feladat #5 - 10 floatot olvasunk be és betoljuk őket egy double típusú mátrixba.

	cin.clear();
    cin.ignore();
	cout << endl;
	cout << "Enter 10 floats: ";
	Matrix<double> m2(10);
	double d2;
	for (int i = 0; i < m2.size(); ++i)
	{
		cin >> d2;
		m2[i] = d2;
	}
	cout << "Matrix:\n" << m2 << endl;
	cout << endl;

	//Feladat #6 - Szorzótábla (2D mátrixként)

	int n,m;
	cout << "n value of matrix: ";
	cin >> n;
	cout << "m value of matrix: ";
	cin >> m;
	cout << endl;
	Matrix<int, 2> mult (n,m);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			mult(i,j)=(i+1)*(j+1);
			cout << mult(i,j) << '\t';
		}
		cout << endl;
	}
	cout << endl;

	//Feladat #7 - 10 komplex double-t kell beolvasni és be kell rakni őket egy mátrixba,
	// majd ki kell számolni a 10 komplex szám összegét.

	Matrix<complex<double>> mc(10);
	cout << "Enter 10 complex numbers (Re, Im): ";
	complex<double> comp;
	for (int i = 0; i < 10; ++i)
	{
		cin >> comp;
		if (!cin) throw runtime_error("Problem reading complex number!");
		mc[i] = comp;
	}
	complex<double> sum;
	for (int i = 0; i < mc.size(); ++i)
	{
		sum += mc[i];
	}
	cout << "sum: " << sum << endl;
	cout << endl;
	
	//Feladat #8 - 6 integert kell beolvasni egy 2x3-mas mátrixba

	Matrix<int, 2> m3 (2,3);
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cin >> m3(i,j);
		}
	}

	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cout << m3(i,j) << '\t';
		}
		cout << endl;
	}

} catch(exception& e) {
	cerr << e.what() << '\n';
	return 1;
} catch(...) {
	cerr << "Unknown exception!" << '\n';
	return 2;
}