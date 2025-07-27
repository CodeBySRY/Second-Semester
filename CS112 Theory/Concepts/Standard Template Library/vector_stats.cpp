#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Validate a single number between 0 and 100
bool CheckNum(int num) {
    if (num < 0 || num > 100) {
        cout << "Invalid input. Number must be between 0 and 100." << endl;
        return false;
    }
    return true;
}

// Display the vector
void Display(const vector<int>& s) {
    for (auto pos = s.begin(); pos != s.end(); pos++) {
        cout << *pos << " ";
    }
}

// Show statistics
void ShowStats(const vector<int>& s) {
    if (s.empty()) return;

    cout << "\n--- Statistics ---" << endl;
    cout << "Minimum: " << s.front() << endl;
    cout << "Maximum: " << s.back() << endl;

    double sum = 0;
    for (int num : s) {
        sum += num;
    }
    cout << "Average: " << sum / s.size() << endl;
}

int main() {
    char choice;

    do {
        vector<int> myVec;
        int size;

        // Get array size with simple input check
        cout << "Enter the size of the array (positive integer): ";
        cin >> size;

        while (cin.fail() || size <= 0) {
            cin.clear(); // reset fail flag
            cin.ignore(1000, '\n'); // discard input
            cout << "Invalid input. Please enter a positive integer: ";
            cin >> size;
        }

        // Read 'size' numbers with validation
        cout << "Now enter " << size << " integers between 0 and 100:" << endl;
        int num;

        for (int i = 0; i < size; ++i) {
            cin >> num;
            while (cin.fail() || !CheckNum(num)) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Enter a valid number: ";
                cin >> num;
            }
            myVec.push_back(num);
        }

        // Sort and display
        sort(myVec.begin(), myVec.end());

        cout << "\nSorted Array: ";
        Display(myVec);

        // Statistics
        ShowStats(myVec);

        // Search
        int searchNum;
        cout << "\nEnter a number to search for: ";
        cin >> searchNum;

        while (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Enter a valid number: ";
            cin >> searchNum;
        }

        if (binary_search(myVec.begin(), myVec.end(), searchNum)) {
            cout << searchNum << " is in the list." << endl;
        } else {
            cout << searchNum << " is not in the list." << endl;
        }

        // Run again?
        cout << "\nWould you like to run the program again? (y/n): ";
        cin >> choice;
        cin.ignore(1000, '\n');
        cout << endl;

    } while (choice == 'y' || choice == 'Y');

    cout << "Goodbye!" << endl;
    return 0;
}
