#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    srand(time(nullptr));
    int random_numbers_limit=101;
    const int numbers_will_be_genarated=10;
    for(int i=0;i<numbers_will_be_genarated;i++)
    {
        cout<<"Random Number:"<<rand()%random_numbers_limit<<endl;
    }
    return EXIT_SUCCESS;
}