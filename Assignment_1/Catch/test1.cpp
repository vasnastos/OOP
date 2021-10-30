#define CATCH_CONFIG_MAIN
#include "../catch.hpp"


int summary(int *a,int size)
{
    int s=0;
    for(int i=0;i<size;i++)
    {
        s+=a[i];
    }
    return s;
}

int max_element(int *a,int size)
{
    int max=a[0];
    for(int i=0;i<size;i++)
    {
        if(a[i]>max)
        {
            max=a[i];
        }
    }
    return max;
}

TEST_CASE("summary","summary_function")
{
    int a[4]{1,2,3,4};
    int b[]{1,3,8,4,5};
    int c[]{4,5,6};
    int d[]{5,6,1,2,7,9};
    REQUIRE(summary(a,sizeof(a)/sizeof(int))==10);
    REQUIRE(summary(b,sizeof(b)/sizeof(int))==21);
    REQUIRE(summary(c,sizeof(c)/sizeof(int))==15);
    REQUIRE(summary(d,sizeof(d)/sizeof(int))==30);
}

TEST_CASE("max element","max_element function")
{
    int a[4]{1,2,3,4};
    int b[]{1,3,8,4,5};
    int c[]{4,5,6};
    int d[]{5,6,1,2,7,9};
    REQUIRE(max_element(a,sizeof(a)/sizeof(int))==4);
    REQUIRE(max_element(b,sizeof(b)/sizeof(int))==8);
    REQUIRE(max_element(c,sizeof(c)/sizeof(int))==6);
    REQUIRE(max_element(d,sizeof(d)/sizeof(int))==9);
}