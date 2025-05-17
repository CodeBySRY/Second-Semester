#include<iostream>
using namespace std;

class Test
{
private:
  int x;
public:
  Test(int x = 0) { this->x = x; }
  void change(Test t) { this->x = t->x; }
  void print() { cout << "x = " << x << endl; }
};

int main()
{
  Test obj(5);
  Test *ptr = new Test (10);
  obj.change(ptr);
  obj.print();
  return 0;
}






/*
#include <iostream>
using namespace std;

class Num {
	int num;
	
	public:
		
		Num& setNum(int n) {
			num = n;
			return *this;
		}
		
		// Public getter method to access the private variable;
		void getnum() {
			cout << "Num: " << num << endl;
		}
		
		Num& addNum(int num) {
			this->num += num;
			return *this;
		} 
};





int main () {
	
	Num mynum;
	mynum.setNum(45);
	mynum.getnum();
	
	mynum.addNum(5).addNum(7);
	
	mynum.getnum();
	
	
	return 0;
}
*/