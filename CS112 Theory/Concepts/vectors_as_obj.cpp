#include <iostream>
#include <vector>
#include <algorithm>

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
		cin >> age;
		cin.ignore();
		cout << "Enter grade: ";
		cin >> grade;
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
	for (int i = 0; i < myStu.size(); i++) {
		cout << "NAME: " << myStu[i].name << endl;
		cout << "AGE: " << myStu[i].age << endl;
		cout << "GRADE: " << myStu[i].grade << endl << endl;
		
	}
}

int main () {
	
	cout << "Welcome" << endl << endl;
	
	vector<Student> myStudents;
	
	InputData(myStudents);
	
	DisplayData(myStudents);
	
	
	
	return 0;
}