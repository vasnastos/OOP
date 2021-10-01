#include "Basic_Calc.hpp"

Calc::Calc(double a, double b)
{
    first = a;
    second = b;
}

double Calc::addition()
{
    return first + second;
}

double Calc::reduction()
{
    return first - second;
}

double Calc::multiplication()
{
    return first * second;
}

double Calc::division()
{
    return first / second;
}

Calc::~Calc() {}