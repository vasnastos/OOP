// Χρησιμοποιήστε αντικειμενοστραφή προγραμματισμό με τη γλώσσα C++ για να υλοποιήσετε 
// μια έκδοση του παιχνιδιού "rock paper scissors" που να εκτελείται από τη γραμμή εντολών
// και στην οποία οι αντίπαλοι να είναι ο χρήστης του προγράμματος και ο υπολογιστής.
// Ένας αγώνας θα έχει 7 γύρους και σε κάθε γύρο θα ζητείται από το χρήστη να 
// εισάγει την επιλογή του που θα μπορεί να είναι R ή P ή S για rock, paper ή scissors 
// αντίστοιχα. O υπολογιστής θα πραγματοποιεί τυχαία επιλογή και ο γύρος θα τελειώνει 
// όταν θα υπάρχει νικητής, ο οποίος και θα εμφανίζεται στην οθόνη (USER ή MACHINE).
// Στο τέλος των 7 γύρων θα εμφανίζεται ο νικητής και το σκορ

#include <iostream>
#include <random>
#include <chrono>
using namespace std;
using namespace std::chrono;

mt19937 mt(steady_clock::now().time_since_epoch().count());

class RPS
{
    private:
        int user_wins,computer_wins;
    public:
        RPS():user_wins(0),computer_wins(0) {}
        ~RPS() {}
        void round()
        {
            char player;
            cout<<"Insert you choice(R|P|S):";
            cin>>player;
            player=toupper(player);
            if(player!='R' && player!='S' && player!='P')
            {
                cout<<"Invallid choice!!Please insert a valid option(R|P|S):";
                cin>>player;
            }
            // Computers choice-->Συμπληρώστε εσείς
            // Εύρεση νικητή συμπληρώστε εσείς
        }

        void rounds(int number_of_rounds)
        {
            for(int j=0;j<number_of_rounds;j++)
            {
                this->round();
            }
            cout<<"***** RPS GAME *****"<<endl;
            cout<<"Player:"<<this->user_wins<<endl;
            cout<<"Computer:"<<this->computer_wins<<endl;
            if(this->user_wins>this->computer_wins)
            {
                cout<<"Player Wins"<<endl;
            }
            else if(this->computer_wins>this->user_wins)
            {
                cout<<"Computer wins"<<endl;
            }
            else
            {
                cout<<"Tie Game"<<endl;
            }
            cout<<endl;
        }
};

int main(int argc,char **argv)
{
    if(argc!=2)
    {
        cerr<<"Invallid amount of arguments"<<endl;
        return EXIT_FAILURE;
    }
    int number_of_rounds=atoi(argv[1]);
    RPS rps;
    rps.rounds(number_of_rounds);
    return EXIT_SUCCESS;
}