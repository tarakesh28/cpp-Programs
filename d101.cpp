#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream file("nums.txt");

    if (!file) {
        cout << "Unable to open file!" << endl;
        return 1;
    }

    int num, count = 0;
    int sum = 0;
    int minVal, maxVal;

    while (file >> num) {
        if (count == 0) {
            minVal = maxVal = num;
        }

        sum += num;

        if (num < minVal)
            minVal = num;

        if (num > maxVal)
            maxVal = num;

        count++;
    }

    file.close();

    if (count == 0) {
        cout << "File is empty." << endl;
        return 0;
    }

    cout << "Count: " << count << endl;
    cout << "Sum: " << sum << endl;
    cout << "Minimum: " << minVal << endl;
    cout << "Maximum: " << maxVal << endl;

    return 0;
}