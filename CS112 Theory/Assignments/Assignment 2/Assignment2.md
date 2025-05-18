# Employee Management System using Runtime Polymorphism in C++

## 📌 Overview

This project demonstrates **runtime polymorphism** in C++ using **inheritance** and **virtual functions**. It simulates an employee payroll system with different types of employees, such as:

- `SalariedEmployee`
- `CommissionWorker`
- `HourlyWorker`
- `BasePlusCommissionEmployee`

All employee types inherit from the abstract base class `Employee`, which defines a common interface for calculating earnings and printing employee details.

---

## 🧱 Class Structure

### 🔹 `Employee` (Abstract Base Class)

- Contains two `std::string` members: `firstName` and `lastName`
- Declares two **pure virtual functions**:
  ```cpp
  virtual float earnings() const = 0;
  virtual void print() const = 0;
### 🔹 `SalariedEmployee`
- Has a private `weeklySalary` variable.

- Constructor accepts firstName, lastName, and weeklySalary.

- earnings() returns the weeklySalary.

- print() prints the employee type and name.
### 🔹 `CommissionWorker`
- Private members: `commission` (rate per item), `quantity` (items sold).

- earnings() = commission * quantity.

- print() displays the employee name and type.
### 🔹 `HourlyWorker`
- Private members: `wage` (per hour), `hours` (worked in a week).

- earnings() = wage * hours.

- Includes validation to ensure hours < 168 (max hours in a week).
### 🔹 `BasePlusCommissionEmployee` (Derived from CommissionWorker)
- Adds `baseSalary` to the commission logic.

- earnings() = baseSalary + (commission * quantity).

- Uses **code reuse** by calling CommissionWorker::earnings().

---
## 🎯 Key Concepts Demonstrated
### ✅ Inheritance
- All employee types inherit from the base class `Employee`.

- The `BasePlusCommissionEmployee` is a multi-level derived class.

## ✅ Polymorphism
- An array of base class pointers (`Employee* emps[4]`) is used to refer to objects of derived types.

- At runtime, the correct version of earnings() and print() is resolved using **virtual dispatch**.

### ✅ Virtual Functions
- Used to ensure that the derived class methods override base class stubs.

- Ensures extensibility and reuse.

### ✅ Memory Management
- Dynamically allocated objects are deleted using delete to prevent memory leaks.

- A **virtual destructor** is used in the base class to ensure proper cleanup:

```cpp
virtual ~Employee() = default;