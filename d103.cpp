#include <iostream>
#include <fstream>
using namespace std;

class Student {
public:
    string name;
    int marks;
};

int main() {
    Student students[100];
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    ofstream out("students.txt");
    for (int i = 0; i < n; i++) {
        cout << "Enter name and marks: ";
        cin >> students[i].name >> students[i].marks;
        out << students[i].name << " " << students[i].marks << endl;
    }
    out.close();
    ifstream in("students.txt");
    Student s[100];
    int count = 0;
    while (count < n && in >> s[count].name >> s[count].marks) count++;
    in.close();
    int topper = 0;
    for (int i = 1; i < count; i++) {
        if (s[i].marks > s[topper].marks) {
            topper = i;
        }
    }

    if (count > 0) {
        cout << "\nTopper Details\n";
        cout << "Name: " << s[topper].name << endl;
        cout << "Marks: " << s[topper].marks << endl;
    }

    return 0;
}