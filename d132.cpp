#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class Shape {
public:
    virtual void area() = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
    float radius;

public:
    Circle(float r) {radius = r;}
    void area() override {cout << "Area of Circle: " << 3.14 * radius * radius << endl;}
};

class Rectangle : public Shape {
    float length, breadth;

public:
    Rectangle(float l, float b) {length = l;breadth = b;}
    void area() override {cout << "Area of Rectangle: "<< length * breadth << endl;}
};

class Triangle : public Shape {
    float base, height;

public:
    Triangle(float b, float h) {base = b;height = h;}
    void area() override {cout << "Area of Triangle: "<< 0.5 * base * height << endl;}
};

int main() {
    vector<unique_ptr<Shape>> shapes;
    string choice;
    while (true) {
        cout << "\nEnter shape (Circle/Rectangle/Triangle)";
        cout << " or Exit: ";
        cin >> choice;

        if (choice == "Exit" || choice == "exit") {break;}

        if (choice == "Circle") {
            float r;
            cout << "Enter radius: ";
            cin >> r;
            shapes.push_back(make_unique<Circle>(r));
        }

        else if (choice == "Rectangle") {
            float l, b;
            cout << "Enter length and breadth: ";
            cin >> l >> b;
            shapes.push_back(make_unique<Rectangle>(l, b));
        }

        else if (choice == "Triangle") {
            float b, h;
            cout << "Enter base and height: ";
            cin >> b >> h;
            shapes.push_back(make_unique<Triangle>(b, h));
        }

        else {
            cout << "Invalid shape!" << endl;
        }
    }

    cout << "\nShape Areas:\n";
    for (auto &s : shapes) s->area();
    return 0;
}