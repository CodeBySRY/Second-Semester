#include <iostream>
//#include <string>  // Use std::string instead of char*

// There are no syntax errors in this code, initially;
// That infers that there is no need to uncomment and use the string library;

// IMP: Instead of using char pointers, we use strings;

using namespace std;

class Employee {
public:
   Employee(const string &first, const string &last);
   virtual ~Employee() = default;  // Virtual destructor

   string getFirstName() const;    // Return by value (safe)
   string getLastName() const;


   // Defining two 'Pure Virtual Functions';
   // These functions will be defined in the derived class; with distinct definitions;
   virtual float earnings() const = 0;  // Pure virtual
   virtual void print() const = 0;

protected:
   string firstName;  // std::string manages memory automatically
   string lastName;
};

Employee::Employee(const string &first, const string &last)
   : firstName(first), lastName(last) {}

string Employee::getFirstName() const { return firstName; }
string Employee::getLastName() const { return lastName; }


class SalariedEmployee : public Employee {
public:
   SalariedEmployee(const string &first, const string &last, float s = 0.0);
   void setWeeklySalary(float s);
   float earnings() const override;
   void print() const override;
private:
   float weeklySalary;
};

SalariedEmployee::SalariedEmployee(const string &first, const string &last, float s)
   : Employee(first, last), weeklySalary(s > 0 ? s : 0) {}

void SalariedEmployee::setWeeklySalary(float s) { weeklySalary = s > 0 ? s : 0; }
float SalariedEmployee::earnings() const { return weeklySalary; }

void SalariedEmployee::print() const {
   cout << "\nSalaried Employee: " << getFirstName() << ' ' << getLastName();
}


int main() {
   SalariedEmployee b("Nauman", "Sarwar", 8000.00);
   b.print();
   cout << " earned Rs." << b.earnings();

   Employee *ptr = &b;  // Base class pointer
   ptr->print();
   cout << " earned Rs." << ptr->earnings();

   return 0;
}