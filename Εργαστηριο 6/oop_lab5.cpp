#include <iostream>
#include <vector>

using namespace std;

vector <string> get_digits(vector <string> &v)
{
    vector <string> newx;
    for(auto &x:v)
    {
        for(int j=0;j<x.size();j++)
        {
            if(x.at(j)>='0' && x.at(j)<='9')
            {
                newx.push_back(x);
                break;
            }
        }
    }
    return newx;
}

int main()
{
    vector <string> strs{"trdf12","knnms","iou45","ghf90","vcba90","casdf21","hello","message"};
    vector <string> are_digits=get_digits(strs);
    for(auto &x:are_digits)
    {
        cout<<"Value:"<<x<<endl;
    }
    return EXIT_SUCCESS;
}