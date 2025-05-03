#include <iostream>
using namespace std;

class Account {
	protected:
		float balance;
		float zakat = 2.5;
		float increment = 5.2;
	public:
		Account(double b) {
			balance = b;
		}
		virtual double calc_zakat() = 0;
		virtual double calc_increment() {
			cout << "Balance (AFTER Increment) == " << (((100+increment)/100)*calc_zakat());
		}
		void Show() {
			cout << "Account Balance (BEFORE Zakat Deduction) == " << balance << endl;
			cout << "Account Balance (AFTER Zakat Deduction) == " << calc_zakat() << endl;
		}
};

class CurrentAccount : public Account {
	public:
		CurrentAccount(double b):Account(b) {}
		double calc_zakat() {
			return ((100-zakat)/100)*balance;
		}
		
		
};

class SavingsAccount : public Account {
	public:
		SavingsAccount(double b):Account(b) {}
		double calc_zakat() {
			return ((100-zakat)/100)*balance;
		}
		
};

int main () {
	double mybalance;
	cout << "Enter the account balance: ";
	cin >> mybalance;
	
	Account *p1 = new CurrentAccount(mybalance);
	Account *p2 = new SavingsAccount(mybalance);
	
	p1->Show();
	p2->Show();
	p2->calc_increment();
	
	
	// To prevent memory leaks;
	delete p1;
	delete p2;
	
	return 0;
}