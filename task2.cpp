
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <stdexcept>
#include <iomanip>
using namespace std;

class Student {
protected:
    int rollNo;
    string name;

public:
    Student(int r, string n) : rollNo(r), name(n) {}
    virtual void display() const {
        cout << "Roll Number: " << rollNo << endl;
        cout << "Name: " << name << endl;
    }
    virtual ~Student() {}
};

class Result : public Student {
private:
    float marks[3];

public:
    Result(int r, string n, float m1, float m2, float m3)
        : Student(r, n) {
        if (m1 < 0 || m1 > 100 || m2 < 0 || m2 > 100 || m3 < 0 || m3 > 100)
            throw invalid_argument("Invalid marks");
        marks[0] = m1;
        marks[1] = m2;
        marks[2] = m3;
    }

    float totalMarks() const {
        return marks[0] + marks[1] + marks[2];
    }

    float percentage() const {
        return totalMarks() / 3.0;
    }

    void display() const override {
        Student::display();
        cout << "Subject 1: " << marks[0] << endl;
        cout << "Subject 2: " << marks[1] << endl;
        cout << "Subject 3: " << marks[2] << endl;
        cout << "Total Marks: " << totalMarks() << "/300" << endl;
        cout << "Percentage: " << percentage() << "%" << endl;
        cout << "Result: "<< (marks[0] >= 35 && marks[1] >= 35 && marks[2] >= 35 ? "PASS" : "FAIL") << endl;
        cout << "--------------------------" << endl;
    }

    void saveToFile(ofstream& file) const {
        file << rollNo << " " << quoted(name) << " "
             << marks[0] << " " << marks[1] << " "
             << marks[2] << endl;
    }
};

void displayStudents(const vector<Result>& students) {
    cout << "\n===== STUDENT RESULTS =====\n";
    for (const Result& s : students) {
        const Student* ptr = &s;
        ptr->display();
    }
}

void saveRecords(const vector<Result>& students) {
    ofstream file("students.txt");
    if (!file) {
        cout << "Unable to open file.\n";
        return;
    }
    for (const Result& s : students)
        s.saveToFile(file);
    file.close();
    cout << "\nRecords saved successfully.\n";
}

void loadRecords(vector<Result>& students) {
    ifstream file("students.txt");
    if (!file) {
        cout << "Unable to open file.\n";
        return;
    }
    students.clear();
    int roll;
    string name;
    float m1, m2, m3;
    while (file >> roll >> quoted(name) >> m1 >> m2 >> m3) {
        try {students.emplace_back(roll, name, m1, m2, m3);}
        catch (const invalid_argument& e) {cout << e.what() << endl;}
    }
    file.close();
    cout << "Records loaded successfully.\n";
}

void findTopStudents(const vector<Result>& students, float threshold) {
    cout << "\n===== STUDENTS ABOVE "
         << threshold << " MARKS =====\n";
    bool found = false;
    for_each(students.begin(), students.end(),
        [&](const Result& s) {
            if (s.totalMarks() > threshold) {
                s.display();
                found = true;
            }
        });
    if (!found)
        cout << "No students found.\n";
}

int main() {
    vector<Result> students;
    try {
        students.emplace_back(101, "Arun", 85, 90, 80);
        students.emplace_back(102, "Rahul", 70, 62, 66);
    }
    catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
        return 1;
    }
    displayStudents(students);
    saveRecords(students);
    vector<Result> loadedStudents;
    loadRecords(loadedStudents);
    findTopStudents(loadedStudents, 200);
    return 0;
}