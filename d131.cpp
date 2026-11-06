#include <iostream>
#include <memory>
using namespace std;

class Student {
    string name;
    int marks;

public:
    Student(string n, int m) {
        name = n;
        marks = m;
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Marks: " << marks << endl;
    }
};

int main() {
    unique_ptr<Student> s =
        make_unique<Student>("Tarakesh", 95);

    cout << "Student Details\n";

    s->display();

    return 0;
}