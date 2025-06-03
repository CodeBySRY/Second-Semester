#include <iostream>
using namespace std;

class Myclass {
	public:
		int x;
		int y;
		
    // Parameterized constructor;
	Myclass(int mynum, int mynum2) {
		x = mynum;
		y = mynum2;
	}
	Myclass(Myclass &c) {
		x = c.x;
		y = c.y;
	}
};
int main() {
	Myclass c1(3,5);
	Myclass c2(c1);
	cout << c1.x << endl;
	cout << c1.y << endl;
	cout << c2.x << endl;
	cout << c2.y;
   
    return 0;
}


/* int mynum;
	cout << "Enter a num: ";
	cin >> mynum;
	const int* ptr = &mynum;
	cout << "Your Num == " << *ptr << endl;
	cout << endl;
	cout << "The pointer is NOT constant, and hence can point to another variable or number. " << endl;
	cout << "Do you want to store another number? (Y/N)";
	char user;
	cin >> user;
	if (user == 'Y'||user == 'y') {
		int mynum2;
		cout << "Enter a second number: ";
		cin >> mynum2;
		ptr = &mynum2;
		cout << endl;
		cout << "Your Num == " << *ptr << endl;
	}
	else {
		cout << "No Changes Made." << endl;
		cout << "Your Num == " << *ptr << endl;
	}
	*/
	