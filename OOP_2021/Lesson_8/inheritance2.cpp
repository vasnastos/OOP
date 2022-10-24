#include <iostream>
#include <vector>

using namespace std;

class Pet
{
    protected:
        string _name;
    public:
        Pet(string n):_name(n) {}
        ~Pet() {}
        virtual string sound()const=0;
        virtual void make_sound()const
        {
            cout<<_name<<" "<<sound()<<endl;
        }
};

class dog:public Pet
{
    public:
        dog(string n):Pet(n) {}
        string sound()const
        {
            return "Woof";
        }

        void make_sound()const
        {
            Pet::make_sound();
            cout<<"("<<this<<")-->dog"<<endl;            
        }
};

class cat:public Pet{
    public:
        cat(string n):Pet(n) {}
        string sound()const
        {
            return "Miao";
        }

        void make_sound()const
        {
            Pet::make_sound();
            cout<<"("<<this<<")-->Cat"<<endl;
        }
};

int main()
{
    vector <Pet*> pets{
        new dog("Bella"),
        new cat("Poppy"),
        new dog("Alfie"),
        new cat("Toby"),
        new dog("Oscar")
    };
    for(auto &x:pets)
    {
        x->make_sound();
        cout<<endl;
    }
    for(auto &x:pets)
    {
        delete x;
    }
    return EXIT_SUCCESS;
}