#include <iostream>

void draw(int *position,int horses,int rounds)
{
    for(int j=0;j<=horses;j++)
    {
        std::cout<<"|";
        for(int i=1;i<=rounds;i++)
        {
            if(position[j]==i)
            {
                std::cout<<position[j];
            }
            else
            {
                std::cout<<".";
            }
        }
        std::cout<<"|"<<std::endl;
    }
}

int main()
{
    int positions[]{2,1,7};
    int horses=3;
    int rounds=10;
    draw(positions,horses,rounds);
    return EXIT_SUCCESS;
}