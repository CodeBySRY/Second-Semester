# Demonstrating the use of 'Single Inheritance';
# Designing a simple billing system for an online store

class Product:
  def __init__(self, name, price):
    self.name = name
    self.price = price

  def show(self):
    print(f"NAME OF PRODUCT: {self.name}; PRICE OF PRODUCT: {self.price}")

class DiscountedProduct(Product):
  def __init__(self, name, price, discount_percentage):
    super().__init__(name, price)
    self.discount_percentage = discount_percentage

  def DisplayPrice(self):
    final_price = self.price*((100-self.discount_percentage)/100)
    print(f"The final price is == {final_price} rupees")

product = input("Enter the name of product: ")
price = int(input("Enter the price of product: "))
print(f"NAME OF PRODUCT: {product}")
print(f"PRICE OF PRODUCT: {price}")
discount = float(input("Enter the discount : "))
# It is necessary that the object is created of the derived class, since it has all the attributes, including those inherited from the parent class.
p1 = DiscountedProduct(product, price, discount)
p1.show()
p1.DisplayPrice()
