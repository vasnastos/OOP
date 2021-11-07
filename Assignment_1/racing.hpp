#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include "horse.hpp"
#ifdef linux
#include <bits/stdc++.h>
#endif
#include "bet.hpp"

class racing
{
    private:
        std::vector <horse> horses;
        std::map <int,std::string> horse_names;
        std::vector <std::pair<horse,int>> ranking;
        int rounds;
        int *positions;
        std::map <int,int> rank;

    public:
        racing(int h=0,int rounds=0);
        racing(int horse_number,std::vector <std::string> &names,int rnds);
        ~racing();
        void race();
        void auto_race();
        void draw_race();
        void print_ranks();
        friend void Bet::calculate_profitability(racing &rc);
};

void press_any_key();