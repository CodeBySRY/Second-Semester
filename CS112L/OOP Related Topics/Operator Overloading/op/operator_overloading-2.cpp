#include <iostream>
using namespace std;

// Defining a Date class, with attributes: day, month, year;
class Date {
	private:
		int day;
		int month;
		int year;
		
	public:
		// Parameterized constructor to initialize values;
		Date (int d, int m, int y) {
			day = d;
			month = m;
			year = y;
		}
		
		// Operator overloading of the relational operator '==';
		// The return type is kept as bool so that conditions can be easy to follow through;
		bool operator==(const Date &d) { // The Date class object, 'd', is taken to be a reference, which prevents copying and allows us to work with original data.
			if(day==d.day && month==d.month && year==d.year) {
				return true;
			}
			else {
				return false;
			}	
			
			
		} // This curly brace belongs to the operator overloading function declaration; 
		
		// In case of input/output operator overloading, we use ostream& for output, and, istream& for the input.
		// These are used to input and display objects of classes, with custom defined format and data type.
		
		// Friend function is used so that the private data members within the class can be accessed and...
		// ...since the left operands are not objects of the class.
		// Therefore, a non-member function (friend function) is used.
		friend ostream& operator<<(ostream& output, const Date &dOut) {
			output << dOut.day << "/" << dOut.month << "/" << dOut.year << endl;
			return output;  
		}	
};

int main () {
	cout << "Comparing Dates!" << endl;
	Date d1(12,9,2003), d2(12,9,2003); // Defining two objects;
	
	cout << d1; // outputting the dates, in the format that we defined in the operator overloading code block;
	cout << d2;
	
	// Since we defined the data type of the relational operator overloading function as bool, we can use standard cout statements.
	if(d1 == d2) {
		cout << "The two dates are equal!" << endl;
	}
	else {
		cout << "The two dates are NOT equal!" << endl;
	}
	
	return 0;
		
}