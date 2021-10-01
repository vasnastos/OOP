#include<iostream>

using namespace std;

class Calc
{
    private:
        double first,second;
    public:
        Calc(double a, double b);
        double addition();
        double reduction();
        double multiplication();
        double division();
        ~Calc();
};  