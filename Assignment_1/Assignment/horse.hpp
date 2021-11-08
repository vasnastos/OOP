#include <iostream>
#include <random>
#include <chrono>
using namespace std;
using namespace std::chrono;

class horse
{
    private:
        int id;
        std::string name;
        int power;
        int startup_speed;
        int stamina;
    
    public:
        horse(int h_id,string h_name,int h_power,int h_startup_speed,int h_stamina);
        horse(int h_id,string h_name);
        ~horse() {}
        bool operator==(const horse &h)const;
        bool move_forward(int step,double random_factor);
        string get_name()const;
        int get_id()const;
};