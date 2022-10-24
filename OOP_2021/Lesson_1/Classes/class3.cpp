#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
#include <string>

using namespace Catch::literals;

constexpr auto PI=3.14159;

class circle
{
    private:
       double center_x,center_y;
       double radius;
    public:
        circle():center_x(0.0), center_y(0.0), radius(1.0) {
            std::cout<<"Memory position:"<<this<<std::endl;
        }

        circle(double xa,double xb,double xr):center_x(xa),center_y(xb),radius(xr) {}

        ~circle() {}

        // Set Radius
        void set_center_x(int a)
        {
            this->center_x=a;
        }

        void set_center_y(int b)
        {
            this->center_y=b;
        }

        void set_radius(int c)
        {
            this->radius=c;
        }

        // getters
        int get_center_x()const
        {
            return this->center_x;
        }

        int get_center_y()const
        {
            return this->center_y;
        }

        int get_radius()const
        {
            return this->radius;
        }

        double area()const{
            // pr^2
            return PI * this->radius * this->radius;
        }

        double perimeter()const
        {
            // 2pr
            return 2.0 * PI * this->radius;
        }
};

TEST_CASE("Circle","Getters")
{
    circle c;
    circle c1(2,3,4);
    REQUIRE(c.get_center_x()==0);
    REQUIRE(c.get_center_y()==0);
    REQUIRE(c1.get_radius()==4);
    REQUIRE(c1.get_center_x()==2);
}

TEST_CASE("Circle_1","Area")
{
    circle *circles=new circle[5];
    for(int i=1;i<=5;i++)
    {
        circles[i-1]=circle(i,i+1,i+2);
    }
    double results[5]{28.27,50.26,78.55,113.04,153.86};
    for(int i=0;i<=sizeof(circles)/sizeof(circles[0]);i++)
    {
        Approx target=Approx(results[i]).margin(0.1);
        CHECK(circles[i].area()==target);
    }
}