#include <iostream>
using namespace std;

// Type casting is essentially the same as type conversion.
// There are two forms of type casting;
// 1. Implicit typecasting: performed automatically by the compiler;
// 2. Explicit typecasting: performed by the programmer;

// The program demonstrates the use of explicit type casting;
// The user enters the ASCII values (integers) corresponding to the characters in their name;
// The name of the user, displayed as a line of characters, is output.
int main () {
	int NumOfchars;
	cout << "Enter the number of characters in your name: ";
	cin >> NumOfchars;
	int name[NumOfchars];
	cout << "Enter the ASCII values: " << endl;
	for (int i = 0; i < NumOfchars; i++) {
		cout << "ASCII Value " << i+1 << ": ";
		cin >> name[i];
	}
	
	for (int i = 0; i < NumOfchars; i++) {
		cout << (char)name[i] << "";
	}
	return 0;
}

