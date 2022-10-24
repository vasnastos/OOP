#include <iostream>
#include <string>


int main()
{
    freopen("input.txt","r",stdin);
    int words=0;
    int chars=0;
    std::string s;
    while(std::cin>>s)
    {
        std::cout<<s<<" ";
        words++;
        chars+=s.length();
    }
    std::cout<<std::endl<<"Words:"<<words<<"\t Characters:"<<chars<<std::endl;
    return 0;
}