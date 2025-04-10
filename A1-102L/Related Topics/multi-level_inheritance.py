# Demonstrating the use of 'Multi-level Inheritance';
# Designing a simple university system;

class Person:
  def __init__(self, name, ID):
    self.name = name
    self.ID = ID

class Student(Person):
  def __init__(self, name, ID, program):
    super().__init__(name, ID)
    self.program = program

class GraduateStudent(Student):
  def __init__(self, name, ID, program, thesis_title):
    super().__init__(name, ID, program)
    self.thesis_title = thesis_title

  def Display(self):
    print("Lets Display All Your Info!")
    print(f"NAME          : {self.name}")
    print(f"ID            : {self.ID}")
    print(f"PROGRAM       : {self.program}")
    print(f"THESIS TITLE  : {self.thesis_title}")
    
name = input("Enter name: ")
id = int(input("Enter ID: "))
program = input("Enter the Program: ")
thesis = input("Enter the title of the thesis report: ")

g1 = GraduateStudent(name, id, program, thesis)
g1.Display()