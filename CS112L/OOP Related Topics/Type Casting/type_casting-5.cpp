#include <iostream>
using namespace std;

// Class A is a base class with a virtual destructor to enable polymorphic behavior.
// Virtual destructor ensures proper cleanup of derived class objects when deleted via a base class pointer.
class A {
public:
    virtual ~A() {}
};

// Class B is an unrelated base class with a virtual destructor.
// It has no inheritance relationship with A or C.
class B {
public:
    virtual ~B() {}
};

// Class C inherits publicly from Class A, making C a derived class of A.
// C is not related to B in any way.
class C : public A {};

int main() {
    // Create a pointer of type A* pointing to a dynamically allocated C object.
    // This is valid because C is a derived class of A (polymorphic relationship).
    A *a = new C();

    // Create a pointer of type B* pointing to a dynamically allocated B object.
    // This is a straightforward instantiation of class B.
    B *b = new B();

    // dynamic_cast is used for safe downcasting or cross-casting in polymorphic hierarchies.
    // It requires at least one virtual function (e.g., virtual destructor) in the base class for runtime type information (RTTI).

    // Valid: Downcasting from A* to C* using dynamic_cast.
    // 'a' points to a C object, and C is a derived class of A.
    // dynamic_cast checks at runtime if the cast is valid and returns a valid C* pointer.
    C* c1 = dynamic_cast<C*>(a); // Valid
    // Note: c1 will be non-null because 'a' indeed points to a C object.

    // Invalid: Attempting to downcast from B* to C* using dynamic_cast.
    // 'b' points to a B object, and B has no inheritance relationship with C.
    // dynamic_cast fails at runtime and returns nullptr because the cast is not possible.
    C* c2 = dynamic_cast<C*>(b); // Invalid: C is not a derived class of B
    // Note: c2 will be nullptr, preventing undefined behavior.

    // Invalid: Attempting to cast from B* to A* using dynamic_cast.
    // A and B are unrelated classes (no inheritance hierarchy).
    // dynamic_cast fails at runtime and returns nullptr because the cast is not valid.
    A* a2 = dynamic_cast<A*>(b); // Invalid: A is not a derived class of B
    // Note: a2 will be nullptr.

    // Key Concept: dynamic_cast ensures type safety at runtime by returning nullptr for invalid casts.
    // It works only with polymorphic types (classes with at least one virtual function).

    // Uncommenting the following line introduces a static_cast:
    // C* c3 = static_cast<C*>(b); // Invalid cast from B* to C*

    // Explanation of static_cast:
    // static_cast performs compile-time type conversion without runtime type checking.
    // Here, static_cast attempts to convert a B* to a C*, but B and C are unrelated classes.
    // This line compiles because static_cast does not check inheritance relationships at compile time.
    // However, at runtime, this leads to undefined behavior because 'b' points to a B object, not a C object.
    // Unlike dynamic_cast, static_cast does not return nullptr for invalid casts, making it unsafe for this scenario.

    // Key Concept: static_cast is faster than dynamic_cast but less safe, as it assumes the programmer knows the cast is valid.
    // Use static_cast for well-defined conversions (e.g., upcasting or converting between related types with known safety).
    // Use dynamic_cast for safe downcasting or cross-casting in polymorphic hierarchies.

    // Clean up dynamically allocated memory to prevent memory leaks.
    delete a;
    delete b;

    return 0;
}