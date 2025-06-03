#include <iostream>
using namespace std;

int main () {
	int mychoice; // Variable to store initial array size from the user
	
	char choice;  // Variable to store user's choice (Y/N) for adding more numbers
	
	int morenum;  // Variable to store how many more numbers user wants to add

	cout << "Enter the size for the dynamic array: ";
	cin >> mychoice; // Input the initial size of the array
	
	int m = mychoice; // Save the original size to use later when adding more elements;
	// m is essentially a variable which holds the original array size.
	// It is necessary to ensure that this assignment is done after the value of mychoice has been input;
	// The above statement is correctly placed in the code, so that a valid value is copied into the variable, m.
	
	
	// m is assigned a COPY of the value of mychoice.
	// Therefore, m and mychoice are two independent variables.
	
	
	int *p = new int[mychoice]; // Dynamically allocate array of size 'mychoice'
	
	cout << "Enter the numbers: ";
	for (int i = 0; i < mychoice; i++) {
		cin >> p[i]; // Input elements into the dynamic array
	}
	
	cout << "Let's print your numbers!" << endl;
	for (int i = 0; i < mychoice; i++) {
		cout << p[i] << " "; // Print the array elements
	}
	cout << endl;
	
	// Ask user if they want to add more numbers
	cout << "Do you want to add more numbers? (Y/N): ";
	cin >> choice;
	
	// If user says yes (Y/y), allow them to add more numbers
	if (choice == 'Y' || choice == 'y') {
		cout << "How many MORE numbers do you want to add to the list? ";
		cin >> morenum; // Get how many more numbers to add
		
		mychoice = mychoice + morenum; // Update total size (old size + new numbers)
		
		int *temp = new int[mychoice]; // Allocate new larger array
		
		// Copy old elements into the new array
		for (int i = 0; i < m; i++) { // NOTE: m is used, since it holds the original array size, and hence, elements till that size, and those need to be copied.
			temp[i] = p[i];
		}
		
		delete[] p; // Deallocate old array to avoid memory leaks
		p = temp;   // Point 'p' to the new larger array
		
		cout << "Enter the new numbers: ";
		// Input the new numbers into the extended part of the array
		for (int i = m; i < mychoice; i++) {
			cin >> p[i];
		}
		
		cout << endl;
		// Print the updated array
		for (int i = 0; i < mychoice; i++) {
			cout << p[i] << " ";
		}
	}
	
	// Ending message
	cout << "THE END!" << endl 
	     << "No memory leaks will occur cuz space is deallocated;" << endl  
	     << "You are welcome!" << endl;
	
	return 0;
}
