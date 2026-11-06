
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    unordered_map<string, int> frequency;
    string word;
    int n;

    cout << "Enter number of words: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid number of words!" << endl;
        return 0;
    }

    cout << "Enter " << n << " words:" << endl;

    for (int i = 0; i < n; i++) {
        cin >> word;
        frequency[word]++;
    }

    cout << "\nWord Frequencies:" << endl;

    string mostFrequent = "";
    int maxCount = 0;

    for (const auto& p : frequency) {
        cout << p.first << " : " << p.second << endl;

        if (p.second > maxCount) {
            maxCount = p.second;
            mostFrequent = p.first;
        }
    }

    cout << "\nMost Frequent Word: " << mostFrequent << endl;
    cout << "Frequency: " << maxCount << endl;

    return 0;
}
