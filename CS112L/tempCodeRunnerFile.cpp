#include <iostream>
using namespace std;

// NAME: Shayan Rizwan Yazdanie
// REG #: 2024585

void ReverseStrings(string& str) {
    const int cap = 100;    // max stack size
    char stack[cap];         // manual stack implemented as an array
    int top = -1;                 // stack pointer, -1 means empty stack

    // Push non-space characters onto the stack
    for (int i = 0; i < (int)str.size(); i++) {
        if (str[i] != ' ') {
            if (top < cap - 1) {   // check for overflow
                stack[++top] = str[i];  // push character onto stack
            }
        }
    }

 // Now top + 1 is the number of non-space chars

 // Since top is the index of the top element, and indexing is zero-based:
// Number of elements in the stack = top + 1.

    int newLength = top + 1;

    // Resize string to the number of non-space chars
    str.resize(newLength);

    // Pop characters from stack and assign to string indices

    // Because the stack stores characters in the original order, popping them (last-in-first-out) gives them in reversed order.
    for (int i = 0; i < newLength; i++) {
        str[i] = stack[top--];
    }

    // Using top-- (postfix decrement):
    // Reads the character at current top.
    // Then decrements top.
} 


int main() {

    string test;
    cout << "Enter a string: ";
    getline(cin, test);
    ReverseStrings(test);
    cout << test << endl;  // Output: dlrowolleh




    return 0;
}

