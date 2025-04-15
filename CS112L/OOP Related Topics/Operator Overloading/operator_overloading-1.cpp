// C++ program to overload the binary operator +
// This program adds two complex numbers

#include <iostream>
using namespace std;

class Complex {
    private:
        float real;
        float img;

    public:
         // Default constructor (in case the value is not provided);
         Complex() : real(0), img(0) {}
         // Parameterized constructor;
         Complex(float real, float img) : real(real), img(img){}

       // overload the + operator
       // 'friend' is used as it will allow us to access the private members of the class;
       // It is good practice to initially work with this, and have the data members of the class as private and access using friend func.
         friend  Complex operator + (const Complex& obj1, const Complex& obj2) {
             Complex temp;
              temp.real = obj1.real + obj2.real;
              temp.img = obj1.img + obj2.img;
              return temp;
    }

    void display() {
        if (img < 0)
            cout << "Output Complex number: " << real << img << "i";
      else
           cout << "Output Complex number: " << real << "+" << img << "i";
    }
};

int main() {
    Complex c1(1.0f, 2.0f);
    Complex c2(1.0f, 3.0f);
    // The reason for writing the parameters as 1.0f and NOT 1.0 simply, comes down to floating point precision.
    // Since the constructor of the 'Complex' class expects values to be in the data type of float;
    // Simply writing 1.0 declares the number as a double, since by default, the data type of floating point numbers is type double.
    // Therefore, writing 1.0f ensures that the number is treated as a float, which is designed for less memory usage and precision requirements.
    

    // calls the overloaded + operator
    Complex result = c1 + c2;
    result.display();

    return 0;
}