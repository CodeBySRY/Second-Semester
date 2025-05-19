#include <iostream>
//#include <string>  // Use std::string instead of char*

// There are no syntax errors in this code, initially;
// That infers that there is no need to uncomment and use the string library;

// IMP: Instead of using char pointers, we use strings;

// Const member functions are those which do not modify the object.
// Two const member functions used in this code are: float earnings() const;
// &...
// void print() const;

// BASE CLASS: Employee
// DERIVED CLASSES
// - SalariedEmployee 
// - HourlyWorker
// - CommissionWorker
// - BaseCommissionWorker (derived from CommissionWorker)


// It is good practice to declare all the 'getter' functions as const;




using namespace std;

class Employee {
public:
   Employee(const string &first, const string &last);
   virtual ~Employee() = default;  // Virtual destructor

   string getFirstName() const;    // Return by value (safe)
   string getLastName() const;


   // Defining two 'Pure Virtual Functions';
   // These functions will be defined in the derived class;
   virtual float earnings() const = 0;  // Pure virtual
   virtual void print() const = 0;

protected:
   string firstName;  // std::string manages memory automatically
   string lastName;
};

// Defining the constructor;
Employee::Employee(const string &first, const string &last)
   : firstName(first), lastName(last) {} // using the initializer list syntax;

string Employee::getFirstName() const { return firstName; }
string Employee::getLastName() const { return lastName; }






class SalariedEmployee : public Employee {
public:
    // The class only contains the prototypes of all the functions;
    // The functions are defined outside the class;

    // The first two parameters to the derived class constructor are the same as the base class constructor;
    // There is only an additional parameter that is passed here, and has been set by default to 0.0;
   SalariedEmployee(const string &first, const string &last, float s = 0.0);
   void setWeeklySalary(float s); // Local method; unique to the derived class;
   float earnings() const override; 
   void print() const override;
private:
   float weeklySalary;
};

// Defining the constructor;
SalariedEmployee::SalariedEmployee(const string &first, const string &last, float s)
   : Employee(first, last), weeklySalary(s > 0 ? s : 0) {}

// Defining the 'setWeeklySalary' function;
void SalariedEmployee::setWeeklySalary(float s) { weeklySalary = s > 0 ? s : 0; }
// The logic is that if the parameter s passed os greater than 0 ( > 0), then it will be assigned to weelySalary, otherwise, weeklySalary will be assigned 0.


// Defining the 'earnings' function;
float SalariedEmployee::earnings() const { return weeklySalary; }

void SalariedEmployee::print() const {
   cout << "\nSalaried Employee: " << getFirstName() << ' ' << getLastName();
}




class CommissionWorker : public Employee {
    public:
        CommissionWorker(const string &first, const string &last, float = 0.0, unsigned = 0);
        void setCommission(float);
        void setQuantity(unsigned);
        float earnings() const override;
        void print() const override;

    private:
        float commission; // amount per item sold;
        unsigned quantity; // total items sold for week;

};

CommissionWorker::CommissionWorker(const string &first, const string&last, float c, unsigned q) : Employee(first, last) {
    commission = c > 0 ? c : 0;
    quantity = q > 0 ? q : 0;
}

// Why use seperate functions to set values for qty and commission, if we already have a parameterized constructor?
void CommissionWorker::setCommission(float c) { commission = c > 0 ? c : 0; }

void CommissionWorker::setQuantity(unsigned q) { quantity = q > 0 ? q : 0; }

float CommissionWorker::earnings() const{ return commission * quantity; }

void CommissionWorker::print() const {
    cout << endl << "Commission worker: " << getFirstName() << ' ' << getLastName();
}

class HourlyWorker : public Employee {
    public:
        HourlyWorker(const string &first, const string &last, float = 0.0, float = 0.0);
        void setWage(float);
        void setHours(float);
        float earnings() const;
        void print() const;

    private:
        float wage; // wage per hour;
        float hours; // hours worked for week
};

HourlyWorker::HourlyWorker(const string &first, const string &last, float w, float h) : Employee(first, last) {
    wage = w > 0 ? w : 0;
    hours = h >= 0 && h < 168 ? h : 0; // condition: the parameterized 'hours' should be 0 hours and 168 (7 days);
}

void HourlyWorker::setWage(float w) { wage = w > 0 ? w : 0; }

void HourlyWorker::setHours(float h) { hours = h >= 0 && h < 1568 ? h : 0; }

float HourlyWorker::earnings() const { return wage * hours; }

void HourlyWorker::print() const {
    cout << endl << "Hourly worker: " << getFirstName() << ' ' << getLastName();
}




class BasePlusCommissionEmployee : public CommissionWorker {
    private:
        float baseSalary;
    
    public:
        BasePlusCommissionEmployee(const string &first, const string &last, float = 0.0, unsigned = 0, float = 0.0);

        void setBaseSalary(float sal) { baseSalary = sal; }

        float getBaseSalary() const { return baseSalary; }

        void print() const;
        float earnings() const;
};

BasePlusCommissionEmployee::BasePlusCommissionEmployee(const string &first, const string &last, float c, unsigned q, float sal) : CommissionWorker(first, last, c, q) {
    baseSalary = sal;
}

void BasePlusCommissionEmployee::print() const {
    cout << "\nBase-salaried commission employee: ";
	CommissionWorker::print();  // code reuse
}

// What if we use the private member, baseSalary, here, instead of the function, getBaseSalary() ?
float BasePlusCommissionEmployee::earnings() const {
    return getBaseSalary() + CommissionWorker::earnings();
}


int main() {

    cout << "\t\t\tRuntime Polymorphism using Virtual Functions in C++ (with Inheritance)" << endl;

    // Declaring an array of base class pointers;
    Employee *emps[4];
    emps[0] = new SalariedEmployee("Nauman", "Sarwar", 800.00);
    emps[1] = new CommissionWorker("Qasim", "Ali", 3.0, 150);
    emps[2] = new HourlyWorker("Samer", "Tufail", 13.75, 40);
    emps[3] = new BasePlusCommissionEmployee("Mehshan", "Mustafa", 2.5, 200, 1000.0);
    // The above code block demonstrates run time polymorphism;
    // The Employee* can point to any class that is derived from it;

    // Even though the 'BasePlusCommissionEmployee' class derives from 'CommissionWorker' class, the 'CommissionWorker' class itself derives from the base class, and hence the heirarchy is followed.


    for (int i = 0; i < 4; i++) {
        emps[i]->print();
        cout << endl;
        cout << "Earned $: " << emps[i]->earnings();
        cout << endl;
    }

    // to prevent memory leaks;
    for (int i = 0; i < 4; i++) {
        delete emps[i];
    }

    cout << endl << "END PROGRAM!" << endl;

   return 0;
}