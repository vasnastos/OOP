#include <iostream>
#include <set>
#include <algorithm>
#include <exception>

using namespace std;

class Access
{
    private:
        set <unsigned> codes;
    public:
        void activate(unsigned code)
        {
            this->codes.insert(code);
        }
        void deactivate(unsigned code)
        {
            try {
                this->codes.erase(this->codes.find(code));
            }
            catch(exception &e)
            {
                cerr<<e.what()<<endl;
            }
        }

        bool isactive(unsigned code)
        {
            return this->codes.find(code)!=this->codes.end();
        }
};


int main()
{
    Access sec_access;
    for(auto &code:{1234,9999,9876})
    {
        sec_access.activate(code);
    }
    unsigned code;
    while(true)
    {
        cout<<"Please Give your access code:";
        cin>>code;
        if(sec_access.isactive(code))
        {
            cout<<"Door opens successfully"<<endl;
            break;
        }
        else
        {
            cout<<"You did not insert a valid code!!!"<<endl;
        }
    }
    sec_access.deactivate(code);
    if(code!=9876)
    sec_access.deactivate(9876);
    sec_access.activate(1111);
    return EXIT_SUCCESS;
}