#include <iostream>
using namespace std;
class complex
{
    int real, img;

public:
    complex()
    {
        real = 0;
        img = 0;
    }
    complex(int x, int y)
    {
        real = x;
        img = y;
    }

    complex operator+(complex);
    friend ostream &operator<<(ostream &out, complex &obj);
    friend istream &operator>>(istream &in, complex &obj);
};

complex complex ::operator+(complex object)
{
    complex temp;
    temp.real = real + object.real;
    temp.img = img + object.img;
    return temp;
}

ostream &operator<<(ostream &out, complex &obj)
{
    out << obj.real << "+";
    out << obj.img << "i" << endl;
    return out;
}

istream &operator>>(istream &in, complex &obj)
{
    cout << "Enter the Real Part of Complex No : ";
    in >> obj.real;
    cout << "Enter the Imaginary Part of Complex No : ";
    in >> obj.img;
    return in;
}

int main()
{
    complex C1(10, 20), C2, TEMP;
    cin >> C2;
    cout << C1;
    cout << C2;
    TEMP = C1 + C2;
    cout << "The sum of two complex no is : " << TEMP << endl;
    return 0;
}