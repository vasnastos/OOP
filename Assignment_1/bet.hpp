#include <iostream>
#include "racing.hpp"

class Bet
{
    private:
        double amount_of_money;
        double temporary_amount;
    public:
        Bet(double aom);
        ~Bet();
        void place_bet(double amount_of_bet);
        void calculate_profitability(racing &rc);
        void cash_out();
        friend std::ostream &operator<<(Bet &b,std::ostream &os);
};