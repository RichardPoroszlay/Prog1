/*	
1. Define a struct Person containing a string name and an int age.
	2. Define a variable of type Person , initialize it with “Goofy” and 63, and
write it to the screen ( cout ).
	3. Define an input ( >> ) and an output ( << ) operator for Person ; read in a
Person from the keyboard ( cin ) and write it out to the screen ( cout ).
	4. Give Person a constructor initializing name and age .
	5. Make the representation of Person private, and provide const member
functions name() and age() to read the name and age.
	6. Modify >> and << to work with the redefined Person .
	7. Modify the constructor to check that age is [0:150) and that name doesn’t
contain any of the characters ; : " ' [ ] * & ^ % $ # @ ! . Use error() in case
of error. Test.
	8. Read a sequence of Person s from input ( cin ) into a vector<Person> ;
write them out again to the screen ( cout ). Test with correct and errone-
ous input.
	9. Change the representation of Person to have first_name and second_name
instead of name . Make it an error not to supply both a first and a second
name. Be sure to fix >> and << also. Test.
*/


#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

using namespace std;

void error (string s) {
	throw runtime_error(s);
}


// Feladat #1
class Person {
	private:
		// Feladat #5
		string m_firstName {};
		string m_secondName {};
		int m_age {};
	public:
		// Feladat #4
		// constructorral inicializáljuk a változókat (member initializer lists)
		// illetve default értékeket is állítottam (erre is van több féle mód)
		Person(string firstName=" ", string secondName=" ", int age=0) : m_firstName{firstName}, m_secondName{secondName}, m_age{age} {
			// Feladat #7a
			if (age < 0 || age > 150) {
				error("Your age input is invalid!");
			}
			// vizsgáljuk, hogy milyen karakterek NE legyenek a firstName-ben
			for (int i = 0; i < firstName.length(); ++i) {
				switch(firstName[i]) {
					case ';':
						error("Your name contains invalid character!");
						break;
					case ':':
						error("Your name contains invalid character!");
						break;
					case '"':
						error("Your name contains invalid character!");
						break;
					case '\'':
						error("Your name contains invalid character!");
						break;
					case '[':
						error("Your name contains invalid character!");
						break;
					case ']':
						error("Your name contains invalid character!");
						break;
					case '*':
						error("Your name contains invalid character!");
						break;
					case '&':
						error("Your name contains invalid character!");
						break;
					case '^':
						error("Your name contains invalid character!");
						break;
					case '%':
						error("Your name contains invalid character!");
						break;
					case '#':
						error("Your name contains invalid character!");
						break;
					case '@':
						error("Your name contains invalid character!");
						break;
					case '!':
						error("Your name contains invalid character!");
						break;
				}
			}
		}
					// Feladat #5
		
					string get_firstName() const {
						return m_firstName;
					}

					string get_secondName() const {
						return m_secondName;
					}

					int get_age() const {
						return m_age;
					}


					void set_firstName(string fn) {
						m_firstName = fn;
					}

					void set_secondName(string sn) {
						m_secondName = sn;
					}

					void set_age(int a) {
						m_age = a;
					}
};

// Feladat #3 & Feladat #6

istream& operator>> (istream& is, Person& p) {
	string firstName {};
	string secondName {};
	int age {};

	is>> firstName>> secondName>> age;

	// setterrel megadom a bekért értékeket
	p.set_firstName(firstName);
	p.set_secondName(secondName);
	p.set_age(age);

	return is;
}

ostream& operator<< (ostream& os, Person& p) {

	os << p.get_firstName() << ' ' << p.get_secondName() << ' ' << p.get_age();
	return os;
}


int main() {
	
	
	Person p1{"Goofy", "GOO", 61};

	cout << p1.get_firstName() << " "  << p1.get_secondName() << " " << p1.get_age() << '\n';

	//cin >> p2;

	//cout << p2;

	Person p3{"Elem", "Ér", 41};
	cout << p3 << '\n';

	vector<Person> vec;
	Person p2;
	cout << "Enter 9 numbers (3 vectors will be printed with 3 elements)\n";
	// lekorlátoztam, hogy csak 3 elem férjen be, hogy könnyebb legyen tesztelni.
	while(vec.size() < 3) {
		cin >> p2;
		vec.push_back(p2);
	};


	for (int i = 0; i < vec.size(); ++i)
	{
		cout << vec[i] << endl;
	}

	return 0;
}
