/*	
	1. Define an array of int s with the ten elements { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }.

	2. Define a vector<int> with those ten elements.

	3. Define a list<int> with those ten elements.

	4. Define a second array, vector, and list, each initialized as a copy of the first
array, vector, and list, respectively.

	5. Increase the value of each element in the array by 2; increase the value of
each element in the vector by 3; increase the value of each element in the
list by 5.
	
	6. Write a simple copy() operation,
template<typename Iter1, typename Iter2>
// requires Input_iterator<Iter1>() && Output_iterator<Iter2>()
Iter2 copy(Iter1 f1, Iter1 e1, Iter2 f2);
that copies [f1,e1) to [f2,f2+(e1–f1)) and returns f2+(e1–f1) just like the
standard library copy function. Note that if f1==e1 the sequence is empty,
so that there is nothing to copy.

	7. Use your copy() to copy the array into the vector and to copy the list into
the array.

	8. Use the standard library find() to see if the vector contains the value 3
and print out its position if it does; use find() to see if the list contains the
value 27 and print out its position if it does. The “position” of the first
element is 0, the position of the second element is 1, etc. Note that if find()
returns the end of the sequence, the value wasn’t found.
*/

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <array>
#include <algorithm>
#include <stdexcept>

using namespace std;

template<typename C>
void print(const C& c){
	for(auto& data : c){
		cout << data << ' ';
	}
	cout << endl;
}


// Feladat #5
template<typename C>
void inc(C& c, double n){
	for(auto& i : c){
		i += n;
	}
}

// Feladat #6
// iterator: olyan objektum, amely mutat egy elemre, legegyszerűbb formája a pointer
template<typename Iter1, typename Iter2>
Iter2 copy2(Iter1 f1, Iter1 e1, Iter2 f2){
	for(Iter1 p = f1; p != e1; ++p){
		*f2++=*p; //f2 memóriahely értéke legyen egyenlő f1(most p)-vel, majd léptetünk (++)
	}
	
	return f2;
}

int main(){

try{

	// Feladat #1

	constexpr int size = 10;

	int arr[size];
	for (int i = 0; i < size; ++i)
	{
		arr[i] = i;
	}
	
	array<int, size> ai;
	copy(arr, arr + size, ai.begin());

	// Feladat #2

	vector<int> vi(size);
	copy(arr, arr + size, vi.begin());

	// Feladat #3

	list<int> li(size);
	copy(arr, arr + size, li.begin());

	// Feladat #4

	array<int, size> ai2 = ai;
	vector<int> vi2 = vi;
	list<int> li2 = li;

	print(ai2);
	print(vi2);
	print(li2);

	// Feladat #5

	inc(ai2,2);
	inc(vi2,3);
	inc(li2,5);

	cout << "\nElements of ai2:\n";
	print(ai2);
	cout << "\nElements of vi2:\n";
	print(vi2);
	cout << "\nElements of li2:\n";
	print(li2);

	// Feladat #7

	copy2(ai2.begin(), ai2.end(), vi2.begin());
	copy2(li2.begin(), li2.end(), ai2.begin());

	cout << "\nElements of ai2: (elements from list)\n";
	print(ai2);
	cout << "\nElements of vi2: (elements from array)\n";
	print(vi2);
	cout << "\nElements of li2:\n";
	print(li2);

	// Feladat #8

	vector<int>::iterator vit;
	vit = find(vi2.begin(),vi2.end(),3);
	if (vit != vi2.end())
	{
		cout << "Found at: " << distance(vi2.begin(), vit) << '\n';
	}
	else{
		cout << "Not found" << '\n';
	}

}
catch(exception& e){
	cerr << e.what() << '\n';
}
catch(...){
	cerr << "Error" << '\n';
}

}