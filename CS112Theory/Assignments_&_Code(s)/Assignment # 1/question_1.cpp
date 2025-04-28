#include <iostream>
using namespace std;

// Function to calculate the sum of digits of a number using recursion
int sum_of_digits(int n) {
	
    // Base case: if number becomes 0, there are no more digits left to add
    if (n == 0) {
        return 0;
    }
    
    // Recursive case:
    // (n % 10) extracts the last digit of n
    // (n / 10) removes the last digit from n
    // We add the last digit to the result of sum_of_digits called on the smaller number;
    return (n % 10) + sum_of_digits(n/10);
}

int main() {
    int mynum;
    
    // Prompt the user to enter a number
    cout << "Enter a num: ";
    cin >> mynum; 

    // Call the recursive function to compute sum of digits
    int output = sum_of_digits(mynum);

    // Display the result
    cout << "Sum Of Digits === " << output;
    
    // Understanding of the logic (for future review);
    // Example: mynum = 472
    // Step 1: sum_of_digits(472) -> 2 + sum_of_digits(47)
    // Step 2: sum_of_digits(47)  -> 7 + sum_of_digits(4)
    // Step 3: sum_of_digits(4)   -> 4 + sum_of_digits(0)
    // Step 4: sum_of_digits(0)   -> returns 0 (base case)
    // So: 2 + 7 + 4 + 0 = 13
}