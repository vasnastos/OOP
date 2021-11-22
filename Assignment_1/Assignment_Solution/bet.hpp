#include "racing.hpp"

class Bet_App
{
    private:
        double money_amount;
        Racing *rc;
        vector <pair<string,string>> bets;
    public:
        Bet_App();
        ~Bet_App();
        void betting();
        void bet_summary();
        friend istream &operator>>(istream &is,Bet_App &ba);
};