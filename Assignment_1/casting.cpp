#include <iostream>

int main()
{
    int a1=19;
    double b1=19.45;
    char c1='a';
    std::cout<<"Ascii table val of "<<c1<<" is "<<int(c1)<<std::endl;
    std::cout<<"Convert "<<a1<<" to double "<<(double)a1<<" or "<<static_cast<double>(a1)<<std::endl;
    std::cout<<"Convert "<<b1<<" to int "<<int(b1)<<" or "<<static_cast<int>(b1)<<std::endl;
    return EXIT_SUCCESS;
}