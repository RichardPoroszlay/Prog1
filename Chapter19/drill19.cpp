/*	
	1. Define template<typename T> struct S { T val; }; .
	
	2. Add a constructor, so that you can initialize with a T .
	
	3. Define variables of types S<int> , S<char> , S<double> , S<string> , and
S<vector<int>> ; initialize them with values of your choice.
	
	4. Read those values and print them.
	5. Add a function template get() that returns a reference to val .
	6. Put the definition of get() outside the class.
	7. Make val private.
	8. Do 4 again using get() .
	9. Add a set() function template so that you can change val .
	10. Replace set() with an S<T>::operator=(const T&) . Hint: Much simpler
than §19.2.5.
	11. Provide const and non- const versions of get() .
	12. Define a function template<typename T> read_val(T& v) that reads from
cin into v .
	
	13. Use read_val() to read into each of the variables from 3 except the
S<vector<int>> variable.
	14. Bonus: Define input and output operators ( >> and << ) for vector<T> s.
For both input and output use a { val, val, val } format. That will allow
read_val() to also handle the S<vector<int>> variable.
*/

#include <iostream>
#include <string>
#include <vector>

// template osztály
// minden, amit T-vel jelölök az osztályban, az a template-re fog hivatkozni
// a T lehet pl. int, string, char, bool stb...
// a template compile time-ban "határozódik meg"

using namespace std;

// Feladat #1 

template<typename T>
struct S {

		S (T vv = 0)  : val{vv} {}			// Feladat #2
		T& get();							// Feladat #5
		void set(T new_t) {val = new_t;}	// Feladat #9
		void operator=(const T& s);			// Feladat #10
		const T& get() const;				// Feladat #11

	private:	// Feladat #7
		T val;
};

// Feladat #5 & Feladat #6
template<typename T>
T& S<T>::get() {
	return val;
}

// Feladat #11
template<typename T>
const T& S<T>::get() const{
	return val;
}

template<typename T>
void S<T>::operator=(const T& s) {
	val = s;
} 

// Feladat #12
template<typename T>
void read_val(T& v) {
	cin >> v;
}

// Feladat #14
template<typename T>
std::ostream& operator<<(ostream& os, vector<T>& v) {
	os << "{ ";
	for (int i = 0; i < v.size(); ++i) {
		os << v[i] << (i < v.size()-1 ? ", ": " ");
	}
	os << "}\n";
	return os;
} // cout << vec1 << vec2 << vec3 formátumban

template<typename T>
istream& operator>>(istream& is, vector<T>& v) {
	// {1, 1, 2, 3}
	char ch = 0;
	is >> ch;
	if (ch != '{') {
		is.unget();
		return is;
	}
	for (T val; is >> val;) {
		v.push_back(val);
		is >> ch;
		if (ch != ',') break;
	}

	return is;
}

int main() {

	// Feladat #3

	// constructorral inicializáljuk az alaptagokat
	S<int> s;	// S típusú, amelyhez integer érték tartozik!!
	S<int> si {37};
	S<char> sc {'c'};
	S<double> sd {3.2};
	S<string> ss {"Hello"};
	S<vector<int>> svi {std::vector<int> {1, 1, 2, 3, 5, 8}};

	// Feladat #4 & Feladat #8

	cout << "S<int> : " << s.get() << '\n'
		 << "S<int> : " << si.get() << '\n'
		 << "S<char> : " << sc.get() << '\n'
		 << "S<double> : " << sd.get() << '\n'
		 << "S<string> : " << ss.get() << '\n';

	// for-each-et választottunk a vector elemeinek kiíratására
	for (auto& a: svi.get()) {
		cout << a << ' ';
	}
	cout << '\n';

	// Feladat #8

	sc.set('s');
	cout << "S<char> : " << sc.get() << '\n';

	// Feladat #10

	sd = 42.1;
  	cout << "S<double> : " << sd.get() << '\n'; 
 
  	// Feladat #13

  	int ii;
  	cout << "Enter an integer value!\n";
  	read_val(ii);
  	S<int> si2 {ii};
 
  	double dd;
  	cout << "Enter a double value!\n";
  	read_val(dd);
  	S<double> sd2 {dd};
 
  	string ss2;
  	cout << "Enter a string value!\n";
  	read_val(ss2);
  	S<string> str {ss2};
 
  	cout << "S<int> : " << si2.get() << '\n';
  	cout << "S<double> : " << sd2.get() << '\n';
  	cout << "S<string> : " << str.get() << '\n';
 
  	// Feladat #14

  	cout << "Add a vector in this format: {val, val, val}: ";
  	vector<int> vint;
  	read_val(vint);
  	S<vector<int>> svi2 {vint};
  
 	cout << "S<vector<int>> : " << svi2.get() << '\n';

 
	return 0;
}
