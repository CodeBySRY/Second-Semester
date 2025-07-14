#include <iostream> 
#include <algorithm> // in order to use the next_permutation() function;
#include <vector>

using namespace std;

int main () {
	
	vector<int> myVec;
	cout << "Enter the size of the array: ";
	int mysize;
	cin >> mysize;
	cout << endl;
	for (int i = 0; i < mysize; i++) {
		cout << "Enter element # " << i+1 << ": ";
		int mynum;
		cin >> mynum;
		myVec.push_back(mynum);
	} 
	
	static int counter = 0;
	
	sort(myVec.begin(), myVec.end());
	do {
		for (int i = 0; i < myVec.size(); i++) {
			cout << myVec[i] << " ";	
		}
		cout << endl;
		counter++;
		
	} while (next_permutation(myVec.begin(), myVec.end()));
	
	
	cout << "The total number of permutation possible: " << counter << endl;
	
	
	
	
		
	return 0;

}