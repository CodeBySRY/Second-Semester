## Standard Template Library (STL)

### #include `<vector>`
 A vector collects a sequence of values, just like an array does, but its size can change.  
If you specify the size of the vector as undefined;
```cpp
vector<double> myVec;
```
then, it has its initial size as 0. This is contrary to arrays whereby the size of the array needs to be supplied.

If you need additional elements in the vector, use can simply use the `push_back` function to add an element to the end of the vector, thereby increasing its size by 1.  
When it comes to vectors and functions, you can define a vector as a function argument. An example to support this is as follows:
```cpp
// Defining a simple function to sum and return the values stored inside a vector;
double sum(vector <double> myVec) {
    double sum = 0;
    for (int i = 0; i < myVec.size(); i++) {
        sum = sum + myVec[i];
    }
    return sum;
}
```
If you want to modify the values inside the vector, then the vector will be passed by reference as a function argument. For example, if we wish to multiply with a factor:
```cpp
void multiply(vector<double>& values, double factor) {
   for (int i = 0; i < values.size(); i++) {
      values[i] = values[i] * factor;
   }
 }
```
Another useful way of using vectors and functions is that a function can return a vector, since vectors are no different from any other values in this regard. Simply build up the result in the function and return it. In the example below, I wrote the `PerfectSquares` function which returns all the perfect squares between 0 and n:
```cpp
#include <iostream>
#include <vector>

using namespace std;

// Function that has a return type as a vector;
vector<int> PerfectSquares(int n) {
	vector<int> results;
	for (int i = 0; i < n; i++) {
		vector<int> temp;
		temp.push_back(i * i);
		for (int j = 0; j < temp.size(); j++) {
			if (temp[j] <= n) {
				results.push_back(temp[j]);
			}
		}
		
	}
	return results;
}


int main() {
	
	// Set the result of the function to another defined vector;
	vector<int> myVec = PerfectSquares(100);
	for (int i = 0; i < myVec.size(); i++) { // Output the result in standard format;
		cout << myVec[i] << " "; 
	}
	
	
	
	return 0;
}
```
  
Apart from these, in order to use vectors with principles of OOP, check out the `vectors_as_obj.cpp`. It contains a comprehensive program which involves the usage of vectors as objects and in classes.

---

### #include `<numeric>`
This library in C++ STL contains mathematical functions, that are really useful. Among the various operations, `accumulate` sums up a range of elements.  
The function can be used with vectors, as is demonstrated in the `vector_mean_max_min.cpp`.