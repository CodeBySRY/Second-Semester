class Car:
    def __init__(self, brand, model, engine_number):
        self.brand = brand # Public attribute;
        self._model = model # Protected attribute;
        self.__engine_number = engine_number # Private attribute;
        # It is very necessary to remember the syntax of all the attributes.
        
    def display_info(self):
        print(f"BRAND: {self.brand}")
        print(f"MODEL: {self._model}")
        
    def __display_engine_info(self):
        print(f"ENGINE NUMBER: {self.__engine_number}")
        
    def display_private_method(self):
        self.__display_engine_info()
    
class ElectricCar(Car):
    def show_model(self):
        print(f"MODEL (Electric Car): {self._model}")
        

c = Car("Suzuki", "Mehran", 2020)
print(c.brand)
print(f"Printing The Protected Attribute Directly: {c._model}")
c.display_info()
c.display_private_method()

e = ElectricCar("Tesla", "Model X", 2024)
e.display_info()
e.show_model()


print("END PROGRAM!")