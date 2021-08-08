#include<iostream>

using namespace std;

class Complex
{
    double real;
    double imag;

public:
    explicit Complex(double r=0.0, double i=0.0):real(r), imag(i){}

    bool operator == (Complex rhs)
    {
        return real == rhs.real && imag == rhs.imag;
    }
};

int main()
{
    Complex c1(2.5, 0);

    if(c1 == Complex(2.5))
        cout << "Same";
    else
        cout << "Different";
}
