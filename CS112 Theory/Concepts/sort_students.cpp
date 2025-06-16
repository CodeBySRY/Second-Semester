#include <iostream>
#include <algorithm> // Imported in order to use the sort() function;

using namespace std;

class Student {
	
	public:
		// It is good practice to declare all the 'getter' functions as const;
		// These variables are made public, initially, and hence will NOT require public getter methods.
		string firstname;
		string lastname;
		int marks;
		
		Student(const string &first, const string &last, const int mark); // Constructor
		
		virtual ~Student() = default;  // Virtual destructor		
		
		// The class contains two methods;
		void InputData();

		void DisplayData(); 
		
};

// Defining the custom comparator function (Sort By Name);
bool sort_by_name(const Student *s1, const Student *s2) {
			if (s1->firstname != s2->firstname) {
				return s1->firstname < s2->firstname;
			}
			else {
				return s1->lastname < s2->lastname;
			}
		}

// Defining the custom comparator function (Sort By Marks);
bool sort_by_marks(const Student *s1, const Student *s2) {
	if (s1->marks != s2->marks) {
		return s1->marks < s2->marks;
	}
	else if (s1->marks == s2->marks) {
		return s1->firstname < s2->firstname;
	}
}


// Defining the constructor;
Student::Student(const string &first, const string &last, const int mark)
   : firstname(first), lastname(last), marks(mark) {} // using the initializer list syntax;


void Student::InputData() {
		
		cout << "Enter The First Name: ";
		cin >> firstname;
		cout << "Enter The Last Name: ";
		cin >> lastname;
		cout << "Enter The Marks: ";
		cin >> marks;
		
}


void Student::DisplayData() {
	
	cout << "Name	: " << firstname << " " << lastname << '\n';
	cout << "Marks	: " << marks << '\n';
	cout << '\n';
 	
}

int main () {
	
	int user;
	cout << "Enter The Number Of Students: ";
	cin >> user;
	
	Student *s[user];
	
	for (int i = 0; i < user; i++) {
		
    	s[i] = new Student("", "", 0);  // Allocate memory with default values
    	cout << "Student # " << i+1 << ": \n";
    	s[i]->InputData();              // Now safe to call
    	
	}

	
	cout << " ------------------------ \n";
	cout << "     Student Database \n";
	cout << " ------------------------ \n";
	
	for (int i = 0; i < user; i++) {
		s[i]->DisplayData();
	}
	
	
	
	for (int i = 0; i < user; i++) {
    	delete s[i];  // Free memory
	}

	// Call the sort() function, which expects two iterators as the parameters;
	// An iterator is an object that can iterate over elements in a C++ Standard Library container and provide access to individual elements.
	// Since pointers can allow for pointer arithmetic operations to be carried out, it basically leads to iterator navigation.
	// Since the name of an array is a pointer to the first element of an array, and incrementing to it, leads to accessing different values of the array...
	// We pass the name of the array as the start of the array, and arr + (last element #), as the iterator to the last element.
	
	cout << "Would You Like The Sort The Data by: (1) Name or (2) Marks? ";
	int userChoice;
	cin >> userChoice;
	if (userChoice == 1) {
		sort(s, s + user, sort_by_name);
	}
	else if (userChoice == 2) {
		sort(s, s + user, sort_by_marks);
	}

	
	cout << "Sorted Data \n";

	for (int i = 0; i < user; i++) {
		s[i]->DisplayData();
	}

	return 0;
}

