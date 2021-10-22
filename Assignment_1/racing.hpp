#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <random>
#include <chrono>
#include "horse.hpp"
#ifdef linux
#include <bits/stdc++.h>
#endif

class racing
{
    private:
        std::vector <horse> horses;
        std::map <int,std::string> horse_names;
        std::vector <std::pair<int,int>> ranking;
        int rounds;

    public:
        racing(int h=0,int rounds=0);
        racing(std::vector <std::string> &names,int rnds);
        ~racing() {}
        void print_race();
        void print_ranking();
        void game_started();
        void game_automatically_executed();
        void set_rounds(int number_of_rounds);
        void set_horses(int number_of_horses);
};

void press_any_key();