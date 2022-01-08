#include <iostream>
#include <map>

using namespace std;

class Access
{
    private:
        map <size_t,int> codes;
    public:
        void activate(size_t code,int security_level)
        {
            this->codes[code]=security_level;
        }
        void deactivate(size_t code)
        {
            this->codes.erase(code);
        }

        bool is_active(size_t code)
        {
            return this->codes.find(code)!=this->codes.end();
        }

        bool is_active(size_t code,int security_level)const
        {
            return this->codes.find(code)!=this->codes.end() && this->codes.at(code)==security_level;
        }

        int get_access_level(size_t code)const
        {
            if(this->codes.find(code)!=this->codes.end())
            {
                return this->codes.at(code);
            }
            return -1;
        }
};

int main()
{
    Access sec_access;
    pair <string,int> door1={"door1",5};
    pair <string,int> door2={"door2",7};
    sec_access.activate(1234,1);
    sec_access.activate(9999,5);
    sec_access.activate(9876,9);
    size_t code;
    int security_level;
    while(true)
    {
        cout<<"Door:"<<door1.first<<endl;
        cout<<"Give your security code:";
        cin>>code;
        if(sec_access.is_active(code))
        {   
            security_level=sec_access.get_access_level(code);
            if(security_level<door1.second)
            {
                cout<<"Code:"<<code<<endl;
                cout<<"Status:Active"<<endl;
                cout<<"Security Level:"<<security_level<<endl;
                cout<<"Access:Access forbiden!!!"<<endl;
                cout<<"Need code with security level >="<<door1.second<<endl;
            }
            else
            {
                cout<<"Code:"<<code<<endl;
                cout<<"Status:Active"<<endl;
                cout<<"Security Level:"<<security_level<<endl;
                cout<<"Door Opens!!!. You are in security level "<<security_level<<endl;
                sec_access.deactivate(code);
                sec_access.activate(9999,8);
                sec_access.activate(1111,7);
                break;
            }
        }
        else
        {
            cerr<<"Security code:"<<code<<"is not an active code!!!!"<<endl;
        }
    }

    while(true)
    {
        cout<<"Door:"<<door2.first<<endl;
        cout<<"Give your security code:";
        cin>>code;
        if(sec_access.is_active(code))
        {   
            security_level=sec_access.get_access_level(code);
            if(security_level<door2.second)
            {
                cout<<"Code:"<<code<<endl;
                cout<<"Status:Active"<<endl;
                cout<<"Security Level:"<<security_level<<endl;
                cout<<"Access:Access forbiden!!!"<<endl;
                cout<<"Need code with security level >="<<door2.second<<endl;
            }
            else
            {
                cout<<"Code:"<<code<<endl;
                cout<<"Status:Active"<<endl;
                cout<<"Security Level:"<<security_level<<endl;
                cout<<"Door Opens!!!. You are in security level "<<security_level<<endl;
                sec_access.deactivate(code);
                break;
            }
        }
        else
        {
            cerr<<"Security code:"<<code<<"is not an active code!!!!"<<endl;
        }
    }
}