#include <iostream>
#include <cmath>
using namespace std;

class Converter
{
    private:
        char type;
        string binary;
        int decimal;
    public:
        Converter():decimal(0),binary("") {}

        void read()
        {
            cout<<"Give type of number you want to convert(b(binary)|d(decimal)):";
            cin>>this->type;
            while(this->type!='b' && this->type!='d'){
                cout<<"You did not enter the right type of Number"<<endl<<"Give type of number you want to convert(b(binary)|d(decimal)):"<<endl;
                cin>>this->type;
            }

            if(this->type=='b')
            {
                cout<<"Type("<<this->type<<"). Give binary number:";
                cin>>this->binary;
            }
            else
            {
                cout<<"Type("<<this->type<<"). Give decimal number:";
                cin>>this->decimal;
            }
        }

        void binary2decimal()
        {
            this->decimal=0;
            int rightmost_operator=this->binary.length()-1;
            for(int i=0;i<this->binary.length();i++)
            {
                this->decimal+=(this->binary[i]-'0') * pow(2,rightmost_operator);
                rightmost_operator--;
            }
        }

        void decimal2binary()
        {
            int decimal_number_copy=this->decimal;
            string output="";
            while(decimal_number_copy>0)
            {
                output+=(decimal_number_copy%2)+'0';
                decimal_number_copy/=2;
            }
            for(int i=output.length()-1;i>=0;i--)
            {
                this->binary+=output[i];
            }
        }

        friend void convert(Converter &conv);
    };

void convert(Converter &conv)
{
    conv.read();
    cout<<"Action:"<<(conv.type=='b'?"Binary to decimal":"decimal to binary")<<endl;
    if(conv.type=='b')
    {
        cout<<"Binary:"<<conv.binary<<endl;
        conv.binary2decimal();
        cout<<"Decimal:"<<conv.decimal<<endl;
    }
    else
    {
        cout<<"Decimal:"<<conv.decimal<<endl;
        conv.decimal2binary();
        cout<<"Binary:"<<conv.binary<<endl;
    }
}

int main()
{
    Converter conv;
    convert(conv);
    return 0;
}