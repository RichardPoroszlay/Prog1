#include <iostream>
#include <string>
#include <vector>

// template osztály
// minden, amit T-vel jelölök az osztályban, az a template-re fog hivatkozni
// a T lehet pl. int, string, char, bool stb...
// a template compile time-ban "határozódik meg"

using namespace std;

template<typename T>
struct S {

		S (T vv = 0)  : val{vv} {}
		T& get();
		void set(T new_t) {val = new_t;}
		void operator=(const T& s);
		const T& get() const;

	private:
		T val;
};


template<typename T>
T& S<T>::get() {
	return val;
}

template<typename T>
const T& S<T>::get() const{
	return val;
}

template<typename T>
void S<T>::operator=(const T& s) {
	val = s;
} 

// template függvényt hozunk létre
template<typename T>
void read_val(T& v) {
	cin >> v;
}

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

	// constructorral inicializáljuk az alaptagokat
	S<int> s;	// S típusú, amelyhez integer érték tartozik!!
	S<int> si {37};
	S<char> sc {'c'};
	S<double> sd {3.2};
	S<string> ss {"Hello"};
	S<vector<int>> svi {std::vector<int> {1, 1, 2, 3, 5, 8}};

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

	sc.set('s');
	cout << "S<char> : " << sc.get() << '\n';

	sd = 42.1;
  	cout << "S<double> : " << sd.get() << '\n'; 
 
  	int ii;
  	read_val(ii);
  	S<int> si2 {ii};
 
  	double dd;
  	read_val(dd);
  	S<double> sd2 {dd};
 
  	string ss2;
  	read_val(ss2);
  	S<string> str {ss2};
 
  	cout << "S<int> : " << si2.get() << '\n';
  	cout << "S<double> : " << sd2.get() << '\n';
  	cout << "S<string> : " << str.get() << '\n';
 
  	cout << "Add a vector in this format: {val, val, val}: ";
  	
  	vector<int> vint;
  	read_val(vint);
  	S<vector<int>> svi2 {vint};
  
 	cout << "S<vector<int>> : " << svi2.get() << '\n';

 
	return 0;
}
