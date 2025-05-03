#include<iostream>
using namespace std;

// A virtual function is a member function of the base class, that is overridden in derived class.
// The Shape class is an abstract class, because it contains a pure virtual function.

class Shape {
	public:
		virtual double CalculateArea() = 0;
	
		virtual void DisplayArea() = 0;	 
};

class Circle : public Shape {
	
	public:
		int radius;
		Circle(int r) {
			radius = r;
		}
		double CalculateArea() {
			return 3.142*radius*radius;
		}
		void DisplayArea() {
			cout << "Area Of Circle == " << CalculateArea() << endl;
		}
};

class Triangle : public Shape {
	public:
		int base, height;
		Triangle(int b, int h) {
			base = b;
			height = h;
		}
		
		double CalculateArea() {
			return 0.5*base*height;
		}
		
		void DisplayArea() {
			cout << "Area Of Triangle == " << CalculateArea() << endl;
		}
};

int main () {
	/*
	Circle c1(7);
	c1.DisplayArea();
	
	// Since the DisplayArea() function explicitly calls the CalculateArea() function, there is no need to call it seperately for both the objects of the class;
	
	Triangle t(5,9);
	t.DisplayArea();
	*/
	
	Shape *shapes[3];
	shapes[0] = new Circle(6);
	shapes[1] = new Triangle(5,7);
	shapes[2] = new Triangle(4,9);
	
	for (int i = 0; i < 3; i++) {
		shapes[i]->DisplayArea();
	}
	
	return 0;
}
