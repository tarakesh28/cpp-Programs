#include <iostream>
using namespace std;

class Money
{
    int rupees, paise;

public:
    Money(int r = 0, int p = 0)
    {
        rupees = r;
        paise = p;

        if (paise >= 100)
        {
            rupees += paise / 100;
            paise = paise % 100;
        }
    }

    Money operator+(Money m)
    {
        Money temp;

        temp.rupees = rupees + m.rupees;
        temp.paise = paise + m.paise;

        if (temp.paise >= 100)
        {
            temp.rupees += temp.paise / 100;
            temp.paise = temp.paise % 100;
        }

        return temp;
    }

    Money operator-(Money m)
    {
        Money temp;

        temp.rupees = rupees - m.rupees;
        temp.paise = paise - m.paise;

        if (temp.paise < 0)
        {
            temp.rupees--;
            temp.paise += 100;
        }

        return temp;
    }

    void display()
    {
        cout << "Rs. " << rupees << ".";

        if (paise < 10)
            cout << "0";

        cout << paise << endl;
    }
};

int main()
{
    Money m1(100, 75);
    Money m2(50, 50);

    Money sum = m1 + m2;
    Money difference = m1 - m2;

    cout << "Money 1: ";
    m1.display();

    cout << "Money 2: ";
    m2.display();

    cout << "Sum: ";
    sum.display();

    cout << "Difference: ";
    difference.display();

    return 0;
}