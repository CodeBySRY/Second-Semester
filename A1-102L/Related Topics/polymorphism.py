class Payment:
    def process_payment(self, amount):
        print(f"Processing The Payment of {amount}$...")
        
    
class CreditCard(Payment):
    def process_payment(self, amount):
        print(f"Processing payments related to 'Credit Cards' of {amount}$!")

class PayPal(Payment):
     def process_payment(self, amount):
        print(f"Processing payments of 'PayPal' of {amount}$!")
        
class BankTransfer(Payment):
     def process_payment(self, amount):
        print(f"Processing payments related to bank transfers of {amount}$!")
        
payments = [Payment(), CreditCard(), PayPal(), BankTransfer()]
p = input("Enter the amount for initial payment: ")
for pM in payments:
    pM.process_payment(p)
    
    
print("END PROGRAM!")

