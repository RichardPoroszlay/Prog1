#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

using namespace std;

void error (std::string s) {
	throw runtime_error(s);
}

class Person {
	private:
		std::string m_firstName {};
		std::string m_secondName {};
		int m_age {};
	public:
		// constructorral inicializáljuk a változókat (member initializer lists)
		Person(std::string firstName, std::string secondName, int age) : m_firstName{firstName}, m_secondName{secondName}, m_age{age} {
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

		
		const std::string firstName() { return m_firstName; }
		const std::string secondName() { return m_secondName; }
		const int age() { return m_age; }
};


istream& operator>> (istream& is, Person& p) {
	std::string firstName {};
	std::string secondName {};
	int age {};
	is>> firstName>> secondName>> age;

	p = Person(firstName, secondName, age);
	return is;
}

ostream& operator<< (ostream& os, Person& p) {

	os << p.firstName() << ' ' << p.secondName() << ' ' << p.age();
	return os;
}


int main() {
	
	/*
	Person p;
	p.m_firstName = "Goofy";
	p.m_secondName = "Goof";
	p.m_age = 63;
	
	std::cout << p.m_firstName << ' ' << p.m_secondName << ' ' << p.m_age << '\n';
	*/
	
	// inicializálom a constructor miatt, máskülönben errort dob vissza
	Person p2 {"Goofy", "Goof", 63};


	// ebbe a vektorba fogom beolvasni az elemeket
	vector<Person> vec;
	
	// lekorlátoztam, hogy csak 3 elem férjen be, hogy könnyebb legyen tesztelni.
	while(vec.size() < 3) {
		cin>> p2;
		vec.push_back(p2);
	}

	for (int i = 0; i < vec.size(); ++i) {
		cout<< vec[i] << '\n';
	}


	return 0;
}
