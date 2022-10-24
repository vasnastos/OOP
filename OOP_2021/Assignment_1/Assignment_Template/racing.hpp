#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include "horse.hpp"
#include "bet.hpp"
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
        int *positions;
        std::map <int,int> rank;

    public:
        racing(int h=0,int rounds=0);
        racing(std::vector <std::string> &names,int rnds);
        ~racing();
        void race();
        void auto_race();
        void draw_race();
};

void press_any_key();