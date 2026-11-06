#include <iostream>
#include <stdexcept>
using namespace std;

class MathError : public runtime_error {
public:
    MathError() : runtime_error("Math Error!") {}
};

class DivideByZero : public MathError {
public:
    DivideByZero() {}
};

int main() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    try {
        if (b == 0) throw DivideByZero();
        cout << "Result: " << (float)a / b << endl;
    }

    catch (DivideByZero& e) {
        cout << "Caught DivideByZero Exception" << endl;
    }

    catch (MathError& e) {
        cout << "Caught MathError Exception" << endl;
    }

    return 0;
}