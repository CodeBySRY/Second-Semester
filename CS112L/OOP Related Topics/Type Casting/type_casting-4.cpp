#include <iostream>
using namespace std;

// TASK 2
// Complete following program by writing correct code in place of /* your code here */.
// Also answer by writing code in place of // What happens if you use static_cast instead?

// Virtual functions are used, which are used to overrride the method of the functions which are declared in the base class.
// In dynamic type casting, the base class pointer or reference is used to safely cast to derived class (called downncasting).
class Animal {
public:
    virtual ~Animal() {}
    virtual void speak() = 0;
};

class Dog : public Animal {
public:
    void speak() override { cout << "Woof!" << endl; } // Since this is a virtual function in the base class, the call to this function will override.
    void fetch() { cout << "Fetching..." << endl; } // NOT a virtual function;
};

class Cat : public Animal {
public:
    void speak() override { cout << "Meow!" << endl; } // An overriden function (i.e. virtual function);
    void climb() { cout << "Climbing..." << endl; } // NOT a virtual function;
};

void processAnimal(Animal* animal) { // The parameter to the function is a pointer to an object of class Animal (base class).
    animal->speak();
    // Try to dynamic_cast to Dog
    Dog *dog = dynamic_cast<Dog*>(animal); 
    if(dog) {
        dog->fetch();
    }
    
    // Try to dynamic_cast to Cat
    Cat* cat = dynamic_cast<Cat*>(animal);
    if(cat) {
        cat->climb();
    }
    
    // What happens if you use static_cast instead?
}

int main() {
    processAnimal(new Dog());
    processAnimal(new Cat());
}
