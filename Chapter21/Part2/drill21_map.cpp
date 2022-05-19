/*	1.Define a map<string,int> called msi .
	
	2.Insert ten (name,value) pairs into it, e.g., msi["lecture"]=21 .
	
	3.Output the (name,value) pairs to cout in some format of your choice.

	4.Erase the (name,value) pairs from msi .
	
	5.Write a function that reads value pairs from cin and places them in msi .
	
	6.Read ten pairs from input and enter them into msi .
	
	7.Write the elements of msi to cout .
	
	8.Output the sum of the (integer) values in msi .
	
	9.Define a map<int,string> called mis .
	
	10.Enter the values from msi into mis ; that is, if msi has an element
( " lecture",21 ), mis should have an element ( 21,"lecture" ).
	
	11. Output the elements of mis to cout .*/

#include <iostream>
#include <stdexcept>
#include <map>
#include <string>
#include <numeric>

using namespace std;

// Feladat #3

template<typename T, typename U>
void print(map<T,U>& m){

	for (const auto& i : m)
	{
		cout << i.first << '\t' << i.second << endl;
	}

}

// Feladat #5

template<typename T, typename U>
void read(map<T,U>& m, int l){

	string k;
    int v;  
    for (int i = 0; i < l; i++){

        cin >> k >> v;
        m.insert(make_pair(k, v));

    }

}

// Feladat #8

template<typename T, typename U>
int sum(map<T,U>& m){
	int s = 0;
	for (const auto& i : m)
	{
		s+=i.second;
	}
	return s;
}

int main()
try {

	// Feladat #1

	map<string,int> msi;

	// Feladat #2

	msi["Robert"] = 4;
	msi["Margret"] = 34;
	msi["Irene"] = 6;
	msi["Gregory"] = 38;
	msi["Lyle"] = 64;
	msi["Anne"] = 62;
	msi["Barbara"] = 33;
	msi["Young"] = 24;
	msi["Turk"] = 13;
	msi["Chloe"] = 9;

	// Feladat #3

	print(msi);
	cout << endl;

	// Feladat #4

	msi.erase(msi.begin(), msi.end());

	// Feladat #6

	cout << "Add 10 pair of key and value." << endl;
	read(msi, 10);
	cout << endl;

	// Feladat #7

	print(msi);
	cout << endl;

	// Feladat #8

	cout << "The sum of the msi values: " << sum(msi) << endl;
	cout << endl;

	// Feladat #9

	map<int,string> mis;

	// Feladat #10

	for (const auto& a : msi)
	{
	   	mis[a.second] = a.first;
	}

	// Feladat #11

	print(mis);

}
catch (exception& e) {
    cerr << e.what() << '\n';
    return 1;
}
catch (...) {
    cerr << "Unknown exception!" << '\n';
    return 2;
}