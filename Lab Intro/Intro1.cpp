#include<iostream>

using namespace std;

int main()
{
    //Output stream
    //printf("This is an output stream \n");
    cout<<"This is an output stream"<<endl;

    int a;

    //Input stream
    //scanf("%d", &a);
    cin>>a;
    cout<<"This is the value of a: "<<a<<endl;

    //Alphanumeric values
    //char str* = "This is an alphanumeric value";
    string str = "This is an alphanumeric value";
    cout<<str<<endl;

    //String functions
        //length of string
            cout<<"Length of string str is : "<<str.length()<<endl;
        //point to position of string
            cout<<"Letter at position 5 of string str "<<str.at(5)<<endl;

    //return 0;
}