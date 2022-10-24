#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <int> nums;
    nums={1,4,5,7,12,45,78,21,56};
    auto summary=[](vector <int> &n){
        int s=0;
        for(int i=0;i<n.size();i++)
        {
            s+=n.at(i);
        }
        return s;
    };
    auto max_element=[](vector <int> &n){
        auto max=n.at(0);
        for(int i=0;i<n.size();i++)
        {
            if(n.at(i)>max)
            {
                max=n.at(i);
            }
        }
        return max;
    };

    cout<<"Numbers:"<<nums.size()<<endl;
    cout<<"Summary:"<<summary(nums)<<endl;
    cout<<"Max Element:"<<max_element(nums)<<endl;
    return EXIT_SUCCESS;
}