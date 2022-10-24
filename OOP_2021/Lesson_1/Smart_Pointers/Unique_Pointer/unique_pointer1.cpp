#include <iostream>
#include <memory>

int main()
{
    std::unique_ptr <int> un_ptr;
    int *pa=new int(14);
    un_ptr=std::make_unique<int>(*pa);
    std::cout<<"Unique pointer memory position:"<<un_ptr.get()<<std::endl;
    std::cout<<"Unique pointer:"<<*un_ptr<<std::endl;
    un_ptr.reset();
    un_ptr=std::make_unique<int>(34);
    std::cout<<"New value:"<<*un_ptr<<std::endl;
    delete pa;
    return 0;
}