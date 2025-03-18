# Demonstrating the use of 'Multiple Inheritance';
# Designing a simple HR system;

# A parent class; contains the constructor with distinct attributes;
class PersonalInfo:
  def __init__(self, name, age):
    self.name = name
    self.age = age

# A parent class; contains the constructor with distinct attributes;
class WorkInfo:
  def __init__(self, position, salary):
    self.position = position
    self.salary = salary

# Defining a child class, which inherits from both the above classes;
class StaffMember(PersonalInfo, WorkInfo):
  def __init__(self, name, age, position, salary):
    # Calling the constructors of both the parent classes manually; 
    # There is difference between the syntax of the super(). function and manually calling the constructors;
    PersonalInfo.__init__(self, name, age)
    WorkInfo.__init__(self, position, salary)

  def Display(self):
    print(f"NAME: {self.name}, AGE: {self.age}, POSITION: {self.position}, SALARY: {self.salary}")

s1 = StaffMember("Ali", 20, "Software Engineer", 250000)
s1.Display()

print("END PROGRAM!")