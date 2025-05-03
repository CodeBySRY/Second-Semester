# 📘 CS112 – Assignment A  
**Semester:** Spring 2025  
**Course Code:** CS112  
**Assignment:** A  

---

## 🧠 Question 1 – Recursive Function: Sum of Digits

**Task:**  
Write a recursive function `sum_of_digits()` that takes a single integer as input.  
The function returns the **sum of all digits** in the integer input.

**Example:**  
If input is `175`, the function returns `13` (since 1 + 7 + 5 = 13).

**Requirements:**  
- Implement the recursive function.
- Write a main program to demonstrate the correct execution of `sum_of_digits()`.

---

## ⚙️ Question 2 – Static Variables & Scope

**Task:**  
Convert the following code into a complete program.  
Run the program and explain the output displayed by it.

```cpp
void some_function(void);
int x = 5;

int main() {
    int x = 20;
    cout << " " << x << endl;
    {
        int x = 66;
        cout << " " << x << endl;
    }
    some_function();
    some_function();
    {
        int y = 66;
        cout << " " << x + y << endl;
    }
}

void some_function(void) {
    static int z = 10;
    cout << " " << x + z << endl;
    if (z < 11) {
        z++;
        ++z;
        x = x * 2;
    }
}
```
---

## 🎨 Question 3 – Enum Mapping & Structs
**Task:**  
Convert the following snippet into a working program.
Run the program, observe the output, and then correct it so the output is accurate.
Explain the output **before** and **after** correction.
```cpp
enum Color { RED, GREEN, BLUE };

typedef struct {
    int x;
    int y;
    Color pixelColor;
} Pixel;

void printPixel(Pixel p) {
    const char* colorNames[] = {"BLUE", "GREEN", "RED"};
    cout << " The pixel at " << p.x << "," << p.y << " is " << colorNames[p.pixelColor] << endl;
}

int main() {
    Pixel p1, p2, p3;
    p1.x = 10; p1.y = 10; p1.pixelColor = RED;
    p2.x = 20; p2.y = 20; p2.pixelColor = GREEN;
    p3.x = 30; p3.y = 30; p3.pixelColor = BLUE;

    printPixel(p1);
    printPixel(p2);
    printPixel(p3);

    return 0;
}
```

---
