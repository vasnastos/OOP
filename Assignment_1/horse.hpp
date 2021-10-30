#include <iostream>

class horse
{
    private:
        int id;
        std::string name;
        int power;
        int startup_speed;
        int stamina;
        int position;
    public:
        horse(int h_id,std::string h_name,int h_power,int h_startup_speed,int h_stamina);
        ~horse() {}
        bool move_forward(int step,double random_factor);
        bool is_finished(int &number_of_rounds);
};