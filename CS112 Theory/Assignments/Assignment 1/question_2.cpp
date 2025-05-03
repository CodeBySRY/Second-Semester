#include <iostream>
using namespace std;

void some_function(void);

int x = 5;  // Global variable

int main() {
    int x = 20;  // Local variable in main
    cout << " " << x << endl; // Output: 20

	// We can create blocks within the main() function;
	// In the case below, the variable x, is hidden from the outside local variable x.
	// Therefore, the value of x in the inner code block below, is printed;
    { 
        int x = 66;  // Local variable in inner block
        cout << " " << x << endl; // Output: 66
    }

	
    some_function(); // Output: 15
    some_function(); // Output: 22

	// In this second inner code block, the local variable x, with the value, x = 20, is used, since another value is not explicitly declared;
    { 
        int y = 66;
        cout << " " << x + y << endl; // Output: 86
    }

    return 0;
}

void some_function(void) {
    static int z = 10;  // Static variable, retains value between calls
    cout << " " << x + z << endl; // Uses the x value that is in the global variable;

    if (z < 11) {
    	// In this code, pre-increment and post-increment does not matter, as both play the same role: increment the value of z by 1;
        z++;
        ++z;
        x = x * 2;
    }
}
