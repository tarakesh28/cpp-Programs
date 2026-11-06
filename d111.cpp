#include <iostream>
using namespace std;

template <class T>
void swapVals(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

template <class T>
T findMax(T arr[], int n) {
    T maximum = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > maximum) {
            maximum = arr[i];
        }
    }

    return maximum;
}

int main() {
    int a = 10, b = 20;

    cout << "Before swapping: " << a << " " << b << endl;

    swapVals(a, b);

    cout << "After swapping: " << a << " " << b << endl;

    int arr1[] = {10, 40, 20, 50, 30};

    cout << "Maximum integer: "
         << findMax(arr1, 5) << endl;

    double x = 2.5, y = 5.5;

    swapVals(x, y);

    cout << "Double values after swapping: "
         << x << " " << y << endl;

    double arr2[] = {2.5, 8.5, 4.5, 9.5};

    cout << "Maximum double: "
         << findMax(arr2, 4) << endl;

    return 0;
}