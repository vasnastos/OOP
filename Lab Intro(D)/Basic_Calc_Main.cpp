#include "Basic_Calc.hpp"

int main()
{
    double x = 7;
    double y = 5;

    Calc c(x, y);

    cout << "Addition of x and y : " << c.addition() << endl;
    cout << "Reduction of x and y : " << c.reduction() << endl;
    cout << "Multiplication of x and y : " << c.multiplication() << endl;
    cout << "Division of x and y : " << c.division() << endl;
}

//Compilation of codes 
//g++ Basic_Calc.cpp Basic_Calc_Main.cpp -o calc
//calc.exe