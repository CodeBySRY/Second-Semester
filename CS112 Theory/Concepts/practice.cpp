#include <iostream>
using namespace std;

// We can assign a derived-class pointer of type 'DerivedClass* ' to a base-class pointer of type 'BaseClass* ';

//  The virtual reserved word must be used in the base class.

/*
void init_matrix(int arr[3][3]) {
	int val = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			arr[i][j] = val;
			val = val +1;
		}
	}
}

void output_matrix(int arr[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

int main () {
	
	
	int p[3][3];
	
	init_matrix(p);
	cout << endl;
    cout << "Output Matrix: " << endl;
	output_matrix(p);
	
	
	
	return 0;
} 
 */


/*
class Shape {
	public:
		virtual void area() {
			cout << "Base class (Shape) method called!" << endl;
		}
};

class Circle : public Shape {
	public:
		void area () {
			cout << "Area Of Circle = pi*(r^2) " << endl;
		}
};




int main () {
	
	// Creating a base class pointer;
	// The pointer stores the address of the object of the base class;
	Shape *s  = new Circle();
	s->area();
	
	// Circle c1;
	
	
	// s = &c1;
	
	// s->area();
	// Without the use of the virtual function in the base class, by default, the compiler will call the base class method.
	// With a virtual function, the correct method will be called.
	
	return 0;
} 
    */



// Define a class, pass two parameters, one is an integer, and the other number is the number which will increment to that int;
class Base {
    private:
        int x;
        const int inc;
    public:
        Base() = default;
        Base(int, int);
        void increment() {
            x = x + inc;

        }
        int getNum() {
            return x;

        }

};

// Testing with assignment;
// Checking to see if assignment of a const member var works;

// Aaanddddd, we get an error;

// Now, we use the member initializer list syntax;
// Since the data member 'inc' is a non-static const data member, it needs to be initialized using the initializer list syntax;
Base::Base(int num, int increment) : x(num), inc(increment) {}



int main () {

    Base b(7,34);
    cout << "Num = " << b.getNum() << endl;
    b.increment();
    int output = b.getNum();
    cout << "Incremented Num = " << output;


    return 0;
}
