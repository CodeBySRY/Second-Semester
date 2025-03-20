class BankAccount:
    def __init__(self, account_holder, account_type, balance):
        # Public attribute: accessible from anywhere
        self.account_holder = account_holder  
        # Protected attribute: accessible within class and subclasses
        self._account_type = account_type     
        # Private attribute: accessible only inside this class
        self.__balance = balance              

    def deposit_amount(self, amount):
        # Public method to deposit money
        print(f"Depositing {amount} rupees...")
        self.__balance += amount  # Updating private attribute

    def withdraw_amount(self, withdraw):
        # Public method to withdraw money with a balance check
        if withdraw <= self.__balance:
            print(f"Withdrawing {withdraw} rupees...")
            self.__balance -= withdraw
        else:
            print("CANNOT Withdraw! Insufficient funds.")

    def __display_balance(self):
        # Private method to display current balance
        print(f"CURRENT BALANCE == {self.__balance} rupees")

    def check_balance(self):
        # Public method acting as a wrapper to call the private balance display
        self.__display_balance()


class SavingsAccount(BankAccount):
    # Subclass inheriting from BankAccount
    def show_account_type(self):
        # Public method accessing protected attribute from parent
        print(f"Account Type: {self._account_type}")


# Creating an object of BankAccount class
b1 = BankAccount("Usman", "Checking", 25000)
deposit = int(input("Enter the amount you wish to deposit: "))  # User input for deposit
b1.deposit_amount(deposit)  # Making deposit
b1.withdraw_amount(5000)    # Withdrawing amount
b1.check_balance()          # Checking balance via public wrapper method

# Creating an object of SavingsAccount subclass
s1 = SavingsAccount("Ali", "Savings", 15250)
s1.show_account_type()      # Displaying protected attribute via subclass
