# Object Oriented Programming
OOP is a crucial topic that is often the center of discussion in technical interviews at tech companies, being one of the core CS concepts.

---
**Base classes** are the building blocks of class hierarchies. A base class: 
- Has a destructor that is public and virtual or else protected and nonvirtual, and a nonpublic copy constructor and assignment operator. 
- Establishes interfaces through virtual functions. 
- Is usually instantiated dynamically on the heap and used via a (smart) pointer.  
    - Base classes are typically created on the heap and managed through smart pointers to enable polymorphism and proper resource management. There are some key details that needs to be kept in mind:
        - **Smart pointers**: Automatic memory management and exception safety 
        - **Factory patterns**: Create objects dynamically based on runtime conditions
        - **Polymorphic containers**: Store different derived types in the same container
      
An example to illustrate this can be the following:
```cpp
#include <iostream>
#include <memory>
#include <vector>
#include <string>

// Simple base class for different types of employees
class Employee {
protected:
    Employee(const std::string& name, double salary) 
        : name_(name), salary_(salary) {}
    
    // Prevent copying
    Employee(const Employee&) = delete;
    Employee& operator=(const Employee&) = delete;
    
    std::string name_;
    double salary_;
    
public:
    virtual ~Employee() = default;
    
    // Virtual interface
    virtual void work() const = 0;
    virtual double calculate_bonus() const = 0;
    
    // Common functionality
    const std::string& get_name() const { return name_; }
    double get_salary() const { return salary_; }
    
    void print_info() const {
        std::cout << "Employee: " << name_ << ", Salary: $" << salary_ << std::endl;
    }
};

class Developer : public Employee {
private:
    std::string programming_language_;
    
public:
    Developer(const std::string& name, double salary, const std::string& language)
        : Employee(name, salary), programming_language_(language) {}
    
    void work() const override {
        std::cout << name_ << " is coding in " << programming_language_ << std::endl;
    }
    
    double calculate_bonus() const override {
        return salary_ * 0.15;  // 15% bonus for developers
    }
};

class Manager : public Employee {
private:
    int team_size_;
    
public:
    Manager(const std::string& name, double salary, int team_size)
        : Employee(name, salary), team_size_(team_size) {}
    
    void work() const override {
        std::cout << name_ << " is managing a team of " << team_size_ << " people" << std::endl;
    }
    
    double calculate_bonus() const override {
        return salary_ * 0.20 + (team_size_ * 500);  // 20% + $500 per team member
    }
};

class Designer : public Employee {
private:
    std::string design_tool_;
    
public:
    Designer(const std::string& name, double salary, const std::string& tool)
        : Employee(name, salary), design_tool_(tool) {}
    
    void work() const override {
        std::cout << name_ << " is designing using " << design_tool_ << std::endl;
    }
    
    double calculate_bonus() const override {
        return salary_ * 0.12;  // 12% bonus for designers
    }
};

// Factory function to create employees dynamically
std::unique_ptr<Employee> create_employee(const std::string& type, 
                                         const std::string& name, 
                                         double salary) {
    if (type == "developer") {
        return std::make_unique<Developer>(name, salary, "C++");
    } else if (type == "manager") {
        return std::make_unique<Manager>(name, salary, 5);
    } else if (type == "designer") {
        return std::make_unique<Designer>(name, salary, "Photoshop");
    }
    return nullptr;
}

// Company class that manages employees
class Company {
private:
    std::vector<std::unique_ptr<Employee>> employees_;
    
public:
    void hire_employee(const std::string& type, const std::string& name, double salary) {
        auto employee = create_employee(type, name, salary);
        if (employee) {
            std::cout << "Hired " << name << " as a " << type << std::endl;
            employees_.push_back(std::move(employee));
        } else {
            std::cout << "Unknown employee type: " << type << std::endl;
        }
    }
    
    void run_workday() {
        std::cout << "\n=== Daily Work Activities ===" << std::endl;
        for (const auto& employee : employees_) {
            employee->work();
        }
    }
    
    void calculate_bonuses() {
        std::cout << "\n=== Year-End Bonuses ===" << std::endl;
        double total_bonuses = 0;
        
        for (const auto& employee : employees_) {
            double bonus = employee->calculate_bonus();
            total_bonuses += bonus;
            std::cout << employee->get_name() << " gets bonus: $" << bonus << std::endl;
        }
        
        std::cout << "Total bonuses: $" << total_bonuses << std::endl;
    }
    
    void print_all_employees() {
        std::cout << "\n=== All Employees ===" << std::endl;
        for (const auto& employee : employees_) {
            employee->print_info();
        }
    }
};

int main() {
    Company company;
    
    // Create employees dynamically - we don't know at compile time
    // which types will be created
    company.hire_employee("developer", "Alice", 80000);
    company.hire_employee("manager", "Bob", 90000);
    company.hire_employee("designer", "Carol", 70000);
    company.hire_employee("developer", "Dave", 85000);
    
    company.print_all_employees();
    company.run_workday();
    company.calculate_bonuses();
    
    return 0;
}
```
> [!NOTE]
> The delete functions that are used in the base class (`Employee(const Employee&) = delete;` and `Employee& operator=(const Employee&) = delete;`) are there to preserve polymorphic behavior, as it forces you to use pointers/references. It is simply a defensive programming practice that prevents a whole class of subtle bugs.



---

### Related to `sort_students.cpp`
It is a C++ program to manage and sort student data using **custom comparators** and **std::sort**.

> In C++, before calling a method on a pointer, you must ensure that the pointer points to a valid object.  

`->` is syntactic sugar for dereferencing a pointer to an object. When you have a pointer to an object (like Student* s), you use:  
```cpp
s->InputData();
```
So:
- `->` dereferences the pointer (*s)  
- Then accesses a member of the object (InputData())

There are two essential custom comparators in this program:
```cpp
// Sorts by firstname, then lastname (lexicographical order)
bool sort_by_name(const Student* a, const Student* b) {
    if (a->firstname != b->firstname) 
        return a->firstname < b->firstname;
    return a->lastname < b->lastname; // Tie-breaker
}

// Sorts by marks (descending) with name tie-breaker
bool sort_by_marks(const Student* a, const Student* b) {
    if (a->marks != b->marks)
        return a->marks > b->marks; // Descending order
    return sort_by_name(a, b); // Fallback to name sort
```

The array `Student* s[user]` is sorted using pointer arithmetic (which decays to iterators):
```cpp
sort(s, s + user, sort_by_name); 
// s       = pointer to first element
// s+user  = pointer to one past last element
```
---
