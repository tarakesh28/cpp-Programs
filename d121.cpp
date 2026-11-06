#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<pair<string, int>> students = {
        {"Rahul", 85},
        {"Anu", 70},
        {"Kiran", 95},
        {"Ravi", 60},
        {"Priya", 80}
    };

    sort(students.begin(), students.end(),
         [](pair<string, int> a, pair<string, int> b) {
             return a.second < b.second;
         });

    cout << "Students sorted by marks:\n";

    for (auto p : students) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}