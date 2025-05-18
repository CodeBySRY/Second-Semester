#include <iostream>
using namespace std;

// We can assign a derived-class pointer of type 'DerivedClass* ' to a base-class pointer of type 'BaseClass* ';

//  The virtual reserved word must be used in the base class.




void init_matrix(int arr[3][3]) {
	int val = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			arr[i][j] = val;
			val = val +1;
		}
	}
}

void output_matrix(int arr[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

int main () {
	
	
	int p[3][3];
	
	init_matrix(p);
	cout << endl;
	output_matrix(p);
	
	
	cout << "PROGRAM END!" << endl;
	
	
	return 0;
} 