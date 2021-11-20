#include "racing.hpp"
#include <cstdlib>

int main(int argc,char **argv)
{
   int number_of_horses=4;
   int number_of_rounds=10;
   if(argc==3)
   {
      number_of_horses=atoi(argv[1]);
      number_of_rounds=atoi(argv[2]);
   }
   Racing rc(number_of_horses,number_of_rounds);
   int option;
   cout<<"0.Race with button"<<endl;
   cout<<"1.Auto race"<<endl;
   cout<<"========="<<endl;
   cout<<"Select:";
   cin>>option;
   if(option==0)
   {
      rc.race();
   }
   else if(option==1)
   {
      rc.auto_race();
   }
   else
   {
      cout<<"You select an invallid choice"<<endl;
   }
   return EXIT_SUCCESS;
}