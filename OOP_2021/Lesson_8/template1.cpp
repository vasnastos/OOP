#include <iostream>
#include <vector>
// Κατασκευάστε μια templated συνάρτηση που να δέχεται ένα διάνυσμα και ένα στοιχείο και να επιστρέφει πόσες
// φορές υπάρχει το στοιχείο μέσα στο διάνυσμα. Να κληθεί η συνάρτηση:
// 1. Για ένα διάνυσμα ακεραίων.
// 2. Για ένα διάνυσμα πραγματικών.
// 3. Για ένα διάνυσμα με εγγραφές σημείων (struct Point) όπου κάθε σημείο προσδιορίζεται από 2 ακέραιες τιμές.

using namespace std;

template <class T> int count_if(vector <T> &v,T searchv)
{
    int c=0;
    for(auto &x:v)
    {
        if(x==searchv)
        {
            c++;
        }
    }
    return c;
}

struct Point
{
    int x,y;
};

bool operator==(const Point &p1,const Point &p2)
{
    return p1.x==p2.x && p1.y==p2.y;
}

int main()
{
    vector <int> v1{1,4,5,9,12,34,9,5,9,7,1,9};
    vector <double> v2{2.1,3.4,5.7,3.1,3.4,6.7,5.2,9.1,3.4};
    vector <Point> v3{{1,3},{2,4},{12,45},{2,4}};
    cout<<"Number 9-:"<<count_if(v1,9)<<endl;
    cout<<"Number 3.4-:"<<count_if(v2,3.4)<<endl;
    cout<<"Point {2,4}-:"<<count_if(v3,{2,4})<<endl;
    return EXIT_SUCCESS;
}