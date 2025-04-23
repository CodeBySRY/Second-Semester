#include <iostream>
using namespace std;
// TASK 1
// Complete following program by writing correct code in place of /* your code here */

// Convert between fundamental types using static_cast
int main() {
    double d = 3.14;
    // Use static_cast to convert double to int
    int i = static_cast<int>(d);
    cout << i << endl;
    
    
    // Try the same with dynamic_cast (what happens?)
    // int j = dynamic_cast<int>(d);
    
    // We cannot try the same with dynamic type cast since it requires a pointer or reference to objects of derived classes, from which, we access functions.
}
