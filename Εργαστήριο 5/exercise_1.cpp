#include <iostream>
using namespace std;

class Rectangle
{
    protected:
        double pleyra1;
        double pleyra2;
    public:
        static int count;
        Rectangle(double p1,double p2):pleyra1(p1),pleyra2(p2) {Rectangle::count++;}
        
        ~Rectangle() {}
        
        double area()
        {
            return this->pleyra1*this->pleyra2;
        }

        virtual double volume()
        {
            return 0;
        }

        virtual void details()
        {
            cout<<"Shape id:"<<Rectangle::count<<endl;
            cout<<"Pleyra 1:"<<this->pleyra1<<endl;
            cout<<"Pleyra 2:"<<this->pleyra2<<endl;
            cout<<"Area:"<<this->area()<<endl;
            cout<<"Volume:"<<this->volume()<<endl<<endl;
        }
};

int Rectangle::count=0;

class Box:public Rectangle
{
    double pleyra3;
    public:
        Box(double pleyra1,double pleyra2,double pleyra3):Rectangle(pleyra1,pleyra2),pleyra3(pleyra3) {}
        ~Box() {}
        double volume() {
            return this->pleyra1*this->pleyra2*this->pleyra3;
        }
        void details()
        {
            cout<<"Shape id:"<<Rectangle::count<<endl;
            cout<<"Pleyra 1:"<<this->pleyra1<<endl;
            cout<<"Pleyra 2:"<<this->pleyra2<<endl;
            cout<<"Area:"<<this->area()<<endl;
            cout<<"Volume:"<<this->volume()<<endl<<endl;
        }

};

int main()
{
   Rectangle shape1(10,12);
   Box shape2(12.5,23.5,11.2);
   Rectangle *shape3=new Box(5.4,5.6,3.2);

   shape1.details();
   shape2.details();
   shape3->details();

   delete shape3;
   return 0;
}