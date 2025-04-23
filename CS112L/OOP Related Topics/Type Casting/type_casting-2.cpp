#include <iostream>
using namespace std;

// Type casting is essentially the same as type conversion.
// There are two forms of type casting;
// 1. Implicit typecasting: performed automatically by the compiler;
// 2. Explicit typecasting: performed by the programmer;

// Dynamic type casting: typically used with classes and related to concepts of polymorphism;
// Often, with dynamic type casting, virtual functions are used, since we are to convert between the type of the objects of different classes.
// A virtual function (also known as virtual methods) is a member function that is declared within a base class and is re-defined (overridden) by a derived class.
// Pointers or references are used;

class Animal {
	private:
		int age;
	public:
		
		virtual void print () {
			cout << "Animal speaks!" << endl;
		}
		
};

class Dog : public Animal {
	public:
		void print () {
			cout << "Dog Speaks!" << endl;
		}
		
};
int main () {
	cout << "Using virtual functions..." << endl;
	Animal *a; // Creating a pointer to an object of the Animal class;
	Dog d1;
	a = &d1; // The pointer of the Animal class points to the address of the object of the Dog class;
	a->print();
	Animal a2;
	a2.print();
	
	
	
	
	return 0;
}
