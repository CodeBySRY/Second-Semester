#include <iostream>
using namespace std;
// In overriden functions, the derived class object calls the derived class method (function), and the base class object calls the base class method (function);
// Overriden functions are those which have the same name and parameters;
class Base
{
public:
    void show()
    {
        cout << "Base class\n";
    }
};

class Derived : public Base
{
public:
    void show()
    {
        cout << "Derived Class\n";
    }
};

int main()
{
    Base* b;    // Base class pointer
    Derived d;  // Derived class object
    b = &d;     // Base class pointer pointing to Derived class object
    
    b->show();  // Early Binding occurs (calls Base::show() since show() is not virtual)
    // bp is a pointer to Base, but it's pointing to an object of type Derived.
	// Even though bp points to a Derived object, the type of the pointer is still Base*, not Derived*.
	// C++ decides which function to call at compile time based on the type of the pointer, not the type of the object it points to, if the function is not virtual.

    return 0;
}