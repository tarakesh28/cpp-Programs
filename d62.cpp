#include <iostream>
using namespace std;

class Fraction
{
    int numerator, denominator;

    int gcd(int a, int b)
    {
        if (a < 0)
            a = -a;

        while (b != 0)
        {
            int temp = b;
            b = a % b;
            a = temp;
        }

        return a;
    }

    void simplify()
    {
        int g = gcd(numerator, denominator);

        numerator /= g;
        denominator /= g;
    }

public:
    Fraction(int n = 0, int d = 1)
    {
        numerator = n;
        denominator = d;
        simplify();
    }

    friend istream &operator>>(istream &in, Fraction &f)
    {
        cout << "Enter numerator: ";
        in >> f.numerator;

        cout << "Enter denominator: ";
        in >> f.denominator;

        if (f.denominator == 0)
        {
            cout << "Denominator cannot be zero." << endl;
            f.denominator = 1;
        }

        f.simplify();

        return in;
    }

    friend ostream &operator<<(ostream &out, const Fraction &f)
    {
        out << f.numerator << "/" << f.denominator;
        return out;
    }
};

int main()
{
    Fraction f;

    cin >> f;

    cout << "Simplified Fraction: " << f << endl;

    return 0;
}