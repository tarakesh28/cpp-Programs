#include <iostream>
using namespace std;

class Person {
protected:
    string name;
public:
    Person(string n) {name = n;}
    void displayPerson() {cout << "Name: " << name << endl;}
};

class Student : virtual public Person {
protected:
    int rollNo;
public:
    Student(string n, int r) : Person(n) {rollNo = r;}
};

class Employee : virtual public Person {
protected:
    int empId;
public:
    Employee(string n, int e) : Person(n) {empId = e;}
};

class TA : public Student, public Employee {
public:
    TA(string n, int r, int e) : Person(n), Student(n, r), Employee(n, e) {}
    void display() {
        displayPerson();
        cout << "Roll Number: " << rollNo << endl;
        cout << "Employee ID: " << empId << endl;
    }
};

int main() {
    TA t("Tarakesh", 25, 501);
    cout << "Teaching Assistant Details\n";
    t.display();
    return 0;
}