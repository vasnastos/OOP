#include <iostream>
using namespace std;

class Complex
{
    double real;
    double imaginary;
    public:
        Complex(double r,double im):real(r),imaginary(im) {}
        ~Complex() {}
        friend Complex add(const Complex &c1,const Complex &c2);
        void display()
        {
            cout<<this->real<<(this->imaginary>0?"+":"-")<<this->imaginary<<"i"<<endl;
        }
};

Complex add(const Complex &c1,const Complex &c2)
{
    return Complex(c1.real+c2.real,c1.imaginary+c2.imaginary);
}

int main()
{
    Complex c1(2,5);
    Complex c2(4,7);
    Complex c3=add(c1,c2);
    c1.display();
    c2.display();
    c2.display();
    return 0;
}