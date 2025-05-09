class Book:
    def __init__(self, title, author, ISBN, status):
        self.author = author
        self.ISBN = ISBN
        self.status = status
        self.title = title
    
    def getBook(self): # it is important to add self as the parameter when defining methods within a class;
        print(f"Title: {self.title}\nAuthor: {self.author}\nStatus: {self.status}\nISBN: {self.ISBN}") 
        
class Library:
    def __init__(self, name, max_books):
        self.name = name
        self.max_books = max_books
        self.books = [] # A blank list to store books, that will be added in the library; since a function of the library class is that we can add a book to the library;
        
        
    def add_book(self, book):
        if len(self.books) < self.max_books:
            self.books.append(book)


    # enumerate() function adds a counter to each item in a list or other iterable. It turns the iterable into something we can loop through, where each item comes with its number (starting from 0 by default). We can also turn it into a list of (number, item) pairs using list().
    def display_books(self):
       for index, books in enumerate(self.books, start=1):
           print(f"\nBook #{index}:")
           books.getBook()
           
            

           
            
            
b1 = Book("The Art of War", "Sun Tzu", "978-1590302255", "Available")
b2 = Book("Emotional Intelligence", "Daniel Goleman", "978-0553383713", "Available")
b3 = Book("To Kill a Mockingbird", "Harper Lee", "978-0446310789", "Checked Out")
b4 = Book("1984", "George Orwell", "978-0451524935", "Available")
b5 = Book("The Great Gatsby", "F. Scott Fitzgerald", "978-0743273565", "On Hold")
b6 = Book("Atomic Habits", "James Clear", "978-0735211292", "Available")

lib = Library("Washington State Library", 5)
lib.add_book(b1)
lib.add_book(b2)
lib.add_book(b3)
lib.add_book(b4)
lib.add_book(b5)
lib.add_book(b6)

lib.display_books()