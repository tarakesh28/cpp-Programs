#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream input("in.txt");
    ofstream output("out.txt");

    if (!input || !output) {
        cout << "File opening error!" << endl;
        return 1;
    }

    string line;
    int lineNumber = 1;

    while (getline(input, line)) {
        output << lineNumber << ": " << line << endl;
        lineNumber++;
    }

    input.close();
    output.close();

    cout << "Line numbered copy completed!" << endl;

    return 0;
}