
#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    int rollNo;
    string name;
    float marks;
    static int studentCount;

public:
    Student(int r, string n, float m) {
        rollNo = r;
        name = n;
        marks = m;
        studentCount++;
    }

    void display() {
        cout << "Roll Number: " << rollNo << endl;
        cout << "Name: " << name << endl;
        cout << "Marks: " << marks << endl;
        cout << endl;
    }

    void display(string message) {
        cout << message << endl;
        display();
    }

    static void showCount() {cout << "Total Students: " << studentCount << endl;}
    friend void compareMarks(Student s1, Student s2);

    bool operator>(Student s) {
        return marks > s.marks;
    }
};

int Student::studentCount = 0;

void compareMarks(Student s1, Student s2) {
    cout << "\nComparing Students using Friend Function:\n";
    if (s1.marks > s2.marks)
        cout << s1.name << " has higher marks.\n";
    else if (s2.marks > s1.marks)
        cout << s2.name << " has higher marks.\n";
    else
        cout << "Both students have equal marks.\n";
}

int main() {
    Student s1(101, "Arun", 85.5);
    Student s2(102, "Rahul", 92.0);
    Student s3(103, "Priya", 78.5);

    cout << "STUDENT DETAILS\n\n";

    s1.display();
    s2.display("Second Student Details:");
    s3.display();
    Student::showCount();
    compareMarks(s1, s2);
    cout << "\nComparing Students using Overloaded > Operator:\n";
    (s1 > s2)? cout << "Student 1 has higher marks than Student 2.\n" :cout << "Student 2 has higher marks than Student 1.\n";
    return 0;
}