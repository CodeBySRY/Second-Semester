#include <iostream>
#include <string>
#include <vector>
#include <numeric> // Imported in order to use the accumulate function;
#include <algorithm> // Imported in order to use the max_element and min_element functions;


using namespace std;

// Helper function;
void clearInputBuffer() {
    cin.clear(); // Reset any error flags in cin
    while (cin.get() != '\n') { // Read one character at a time
        continue; // Discard each character until newline
    }
}


int main () {
	
	double mean; // The double data type offers more precision than float.
	int max;
	int min;
	
	int user;
	cout << "Enter the size of the vector: ";
	while (!(cin >> user)||user <= 0) {
		cout << "Invalid Input! Please Entry Again." << endl;
		clearInputBuffer();
		cout << "Enter the size of the vector: ";
		
	}
	
	vector<int> myVec;
	int num;
	
	for (int i = 0; i < user; i++) {
		cout << "Enter a num: ";
		cin >> num;
		myVec.push_back(num);
		
	}
	
	cout << "Do you want to add more numbers? (Y/N) ";
	char moreNum;
	cin >> moreNum;
	if (moreNum == 'Y'||moreNum == 'y') {
		cout << "How many more number do you wish to enter: ";
		int moreNum;
		cin >> moreNum;
		for (int i = 0; i < moreNum; i++) {
			cout << "Enter a num: ";
			cin >> num;
			myVec.push_back(num);
		}
		
		
	}
	
	cout << endl;
	
	for (int i = 0; i < myVec.size(); i++) {
		cout << myVec[i] << " ";
	}
	cout << endl;
	cout << endl;
	
	
	mean = accumulate(myVec.begin(), myVec.end(), 0.0) / (myVec.size());
	
	cout << "The Mean = " << mean << endl;
	
	max = *max_element(myVec.begin(), myVec.end());
	
	cout << "The Maximum Element = " << max << endl;
	
	min = *min_element(myVec.begin(), myVec.end());
	
	cout << "The Minimum Element = " << min << endl;
	
	
	
	return 0;
}