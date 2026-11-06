#include <iostream>
using namespace std;

class Shape {
protected:
    string color;

public:
    Shape(string c) {
        color = c;
        cout << "Shape Constructor Called" << endl;
    }
};

class Polygon : public Shape {
protected:
    int sides;
public:
    Polygon(string c, int s) : Shape(c) {
        sides = s;
        cout << "Polygon Constructor Called" << endl;
    }
};

class Rectangle : public Polygon {
    float length, breadth;

public:
    Rectangle(string c, int s, float l, float b)
        : Polygon(c, s) {
        length = l;
        breadth = b;
        cout << "Rectangle Constructor Called" << endl;
    }

    void display() {
        cout << "\nColor: " << color << endl;
        cout << "Number of sides: " << sides << endl;
        cout << "Length: " << length << endl;
        cout << "Breadth: " << breadth << endl;
        cout << "Area: " << length * breadth << endl;
    }
};

int main() {
    Rectangle r("Blue", 4, 10, 5);
    r.display();
    return 0;
}