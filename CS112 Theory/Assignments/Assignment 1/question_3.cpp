/* Before Correction:

#include <iostream>
using namespace std;

// Creating a custom type using enum, called as 'Color';
// Uses named integer constants;
enum Color { RED, GREEN, BLUE };

typedef struct {
    int x;
    int y;
    Color pixelColor;
} Pixel;

// We use array style indexing to map the values of enum to their respective strings;
void printPixel(Pixel p) {
    const char* colorNames[] = {"BLUE", "GREEN", "RED" }; // The mapping is out of order, since the value at the array indexes do not match the enum values.
    cout << "The pixel at " << p.x << "," << p.y << " is " << colorNames[p.pixelColor] << endl;
}

int main() {
    Pixel p1, p2, p3;
    p1.x = 10; p1.y = 10; p1.pixelColor = RED;
    p2.x = 20; p2.y = 20; p2.pixelColor = GREEN;
    p3.x = 30; p3.y = 30; p3.pixelColor = BLUE;

    printPixel(p1); // Output: BLUE
    printPixel(p2); // Output: GREEN
    printPixel(p3); // Output: RED
    
    // Therefore, the colors are printed wrong, as compared to being defined in the Color enum, and explicitly stated in the initialization.

    return 0;
}
*/

// After Correction:

#include <iostream>
using namespace std;

/*
 * Enumeration (enum) definition:
 * - Creates a custom type 'Color' with three possible values
 * - Under the hood, these are just integers:
 *   RED = 0, GREEN = 1, BLUE = 2 (automatic numbering)
 * - Enums make code more readable than using raw numbers
 */
enum Color { RED, GREEN, BLUE };

/*
 * Structure definition with typedef:
 * - 'typedef struct' creates a custom data type called 'Pixel'
 * - The struct contains three members:
 *   - x, y: integers representing coordinates
 *   - pixelColor: variable of our Color enum type
 */
typedef struct {
    int x;            // x-coordinate of the pixel
    int y;            // y-coordinate of the pixel
    Color pixelColor; // Color of the pixel (using our enum)
} Pixel;

/*
 * Function to print pixel information:
 * - Takes a Pixel struct as parameter (passed by value)
 * - Demonstrates how to convert enum values to strings
 */
void printPixel(Pixel p) {
    /*
     * String array that maps enum values to color names:
     * - Index 0: "RED" (matches Color::RED which is 0)
     * - Index 1: "GREEN" (matches Color::GREEN which is 1)
     * - Index 2: "BLUE" (matches Color::BLUE which is 2)
     * - 'const char*' means constant character pointer (unchangeable strings)
     */
    const char* colorNames[] = {"RED", "GREEN", "BLUE"};
    
    /*
     * Printing the pixel information:
     * - p.x, p.y: Accessing struct members with dot notation
     * - colorNames[p.pixelColor]:
     *   - p.pixelColor is a Color enum value (0, 1, or 2)
     *   - Using it as an array index gives us the corresponding string
     */
    cout << "The pixel at " << p.x << "," << p.y << " is " 
         << colorNames[p.pixelColor] << endl;
}

int main() {
    // Declare three Pixel variables
    Pixel p1, p2, p3;
    
    // Initialize p1 (RED pixel at 10,10)
    p1.x = 10;            // Set x-coordinate
    p1.y = 10;            // Set y-coordinate
    p1.pixelColor = RED;  // Set color (RED is 0)
    
    // Initialize p2 (GREEN pixel at 20,20)
    p2.x = 20;
    p2.y = 20;
    p2.pixelColor = GREEN; // GREEN is 1
    
    // Initialize p3 (BLUE pixel at 30,30)
    p3.x = 30;
    p3.y = 30;
    p3.pixelColor = BLUE;  // BLUE is 2

    // Print all pixels by calling our function
    printPixel(p1);
    printPixel(p2);
    printPixel(p3);

    return 0;
}

