#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

class Student {
	
	public:
		int age;
		string name;
		int grade;
		
		// Defining the constructor;
		Student(string myName, int myAge, int myGrade) {
			name = myName;
			age = myAge;
			grade = myGrade;
		}
		
		
};

void displayMenu() {
    cout << "MAIN MENU:\n";
    cout << "1. Add Student Data\n";
    cout << "2. Display All Students\n";
    cout << "3. Search Student\n";
    cout << "4. Sort Students\n";
    cout << "5. Exit\n";
}



// Helper function;
void clearInputBuffer() {
    cin.clear(); // Reset any error flags in cin
    while (cin.get() != '\n') { // Read one character at a time
        continue; // Discard each character until newline
    }
}

void InputData(vector<Student> &myStu) {
	
	int age;
	string name;
	int grade;
	
	cout << "Enter the number of data you wish to enter: ";
	int user;
	cin >> user;
	cin.ignore();
	
	for (int i = 0; i < user; i++) {
		cout << "Enter name: ";
		getline(cin, name);
		cout << "Enter age: ";
        while (!(cin >> age) || age <= 0) {
            cout << "Invalid age! Please enter a positive number: ";
            clearInputBuffer();
        }
		cin.ignore();
		cout << "Enter grade: ";
        while (!(cin >> grade) || grade <= 0) {
            cout << "Invalid grade! Please enter a positive number: ";
            clearInputBuffer();
            }
		cin.ignore();
		
		Student newStudent(name, age, grade);
		myStu.push_back(newStudent);
		
		cout << endl;
	}
	
	cout << "Do you want to add more data? (Y/N) ";
	char moreData;
	cin >> moreData;
	if (moreData == 'Y'||moreData == 'y') {
		cout << "Enter the number of data you wish to enter: ";
	int userChoice;
	cin >> userChoice;
	cin.ignore();
	
	for (int i = 0; i < userChoice; i++) {
		cout << "Enter name: ";
		getline(cin, name);
		cout << "Enter age: ";
		cin >> age;
		cin.ignore();
		cout << "Enter grade: ";
		cin >> grade;
		cin.ignore();
		
		Student newStudent(name, age, grade);
		myStu.push_back(newStudent);
		
		cout << endl;
	}
	
	}
	else {
		cout << endl;
	}
	cout << endl;
}


void DisplayData(const vector<Student> &myStu) {
     cout << "\n--- STUDENT RECORDS ---\n";
    cout << left << setw(30) << "NAME" << setw(10) << "AGE" << setw(10) << "GRADE" << endl;
    cout << string(50, '-') << endl;

	for (int i = 0; i < myStu.size(); i++) {
		cout << left << setw(30) << myStu[i].name << setw(10)<< myStu[i].age << setw(10) << myStu[i].grade << endl;
		
	}

    cout << endl;
}

int main () {
    int user;

    vector<Student> myStudents;
	cout << "Welcome" << endl << endl;

    while(true) {
        displayMenu();

   
    cout << "Enter your choice: ";
    cin >> user;

    switch(user) {

    
        case 1:
            InputData(myStudents);
            break;
        
        case 2:
            DisplayData(myStudents);
            break;

        case 3:
            cout << "Yet To Code! " << endl;
            break;

        case 4:
            cout << "Yet To Code! " << endl;
            break;

        case 5:
            exit(0);
            break;

    }
    
	cout << endl;

    } // This curly brace corresponds to the while loop.
    
    


	return 0;
}