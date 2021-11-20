#include "horse.hpp"
#include <vector>
#include <random>
#include <chrono>
#include <thread>
#include <algorithm>

using namespace std;
using namespace std::chrono;



class Racing
{
   private:
      int rounds;
      int n_horses;
      vector <horse> horses;
      vector <int> position;
      vector <pair <horse,int>> standings;
   public:
      Racing(int number_of_horses=4,int number_of_rounds=10);
      ~Racing();
      void race();
      void auto_race();
      void drawing();
      void reset_race();
      void display_standings();
      vector <horse> get_horses();
};