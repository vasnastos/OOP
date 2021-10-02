#include<iostream>

void yes_ans()
{
    std::cout<<"You typed YES";
}

std::string no_ans()
{
    return "You typed NO";
}

std::string other_ans()
{
    return "You didn't type YES or NO";
}

int main()
{
    std::string inp,ans;
    std::cout<<"Type YES or NO"<<std::endl;
    std::cin>>inp;

    if(inp == "YES")
    {
        yes_ans();
    }
    else if(inp == "NO")
    {
        ans = no_ans();
        std::cout<<ans;
    }
    else
    {
        std::cout<<other_ans();
    }
        
    return 0;
}