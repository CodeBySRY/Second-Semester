#include <iostream>
#include <vector>
using namespace std;

// 2D coordinate class
class Coord {
public:
    int x, y;
    
    Coord(int xVal, int yVal) : x(xVal), y(yVal) {}  // Constructor
    
    Coord operator+(const Coord& other) const {  // Overload + for coordinate addition
        return Coord(x + other.x, y + other.y);
    }
};

// Abstract base class for geometric objects
class GeoObj {
public:
    virtual void move(Coord) = 0;  // Pure virtual - must be implemented
    virtual void draw() const = 0; // Pure virtual - must be implemented
    virtual ~GeoObj() = default;   // Virtual destructor for proper cleanup
};

// Circle class inherits from GeoObj
class Circle : public GeoObj {
private:
    Coord center;  // Center coordinates
    int rad;       // Radius
    
public:
    Circle(Coord c, int r) : center(c), rad(r) {}  // Constructor
    
    void move(Coord c) override {  // Move circle by offset
        center = center + c;
    }
    
    void draw() const override {  // Draw circle implementation
        cout << "Drawing Circle at (" << center.x << "," << center.y 
             << ") with radius " << rad << endl;
    }
};

// Line class inherits from GeoObj
class Line : public GeoObj {
private:
    Coord from, to;  // Start and end points
    
public:
    Line(Coord f, Coord t) : from(f), to(t) {}  // Constructor
    
    void move(Coord c) override {  // Move line by offset
        from = from + c;
        to = to + c;
    }
    
    void draw() const override {  // Draw line implementation
        cout << "Drawing Line from (" << from.x << "," << from.y 
             << ") to (" << to.x << "," << to.y << ")" << endl;
    }
};

// Creates a vector of geometric objects
vector<GeoObj*> createFig() {
    vector<GeoObj*> f;
    f.push_back(new Line{Coord{1,2}, Coord{3,4}});  // Heap-allocated Line
    f.push_back(new Circle{Coord{5,5}, 2});         // Heap-allocated Circle
    return f;
}

// Draws all elements in vector
void drawElems(const vector<GeoObj*>& v) {
    for (GeoObj* gp : v) {
        gp->draw();  // Polymorphic call
    }
}

int main() {
    vector<GeoObj*> fig = createFig();  // Create figures
    drawElems(fig);                    // Draw all figures
    
    // Clean up memory
    for (GeoObj* & geoPtr : fig) {
        delete geoPtr;     // Free memory
        geoPtr = nullptr;  // Nullify pointer
    }
    /*geoPtr is a reference to a pointer (GeoObj* &), meaning we can modify the actual pointer stored in the vector.
    delete geoPtr deallocates the memory on the heap that geoPtr points to, ensuring no memory leaks.
    geoPtr = nullptr; --> basically helps prevent dangling pointers (undefined behavior).
    */ 
    fig.clear();  // Clear vector
    
    return 0;
}