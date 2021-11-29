// Γράψτε πρόγραμμα που να δεσμεύει θέσεις μνήμης για έναν int, έναν double 
// και έναν char, να αναθέτει μια τιμή 
// σε κάθε δεσμευμένη θέση μνήμης και στη συνέχεια να απελευθερώνει τη μνήνη.
#include <iostream>

class myclass
{
    private:
        int *a;
        double *b;
        char *c;
    public:
        myclass(int a1,double b1,char c1):a(new int(a1)),b(new double(b1)),c(new char(c1)) {}
        ~myclass()
        {
            delete this->a;
            delete this->b;
            delete this->c;
        }

        int get_a()
        {
            return *(this->a);
        }

        double get_b()
        {
            return *(this->b);
        }

        char get_c()
        {
            return *(this->c);
        }
};


int main()
{
    myclass aclass(10,10.5,'c');
    std::cout<<"Object at:"<<&aclass<<std::endl;
    std::cout<<aclass.get_a()<<std::endl;
    std::cout<<aclass.get_b()<<std::endl;
    std::cout<<aclass.get_c()<<std::endl;
    return EXIT_SUCCESS;
}