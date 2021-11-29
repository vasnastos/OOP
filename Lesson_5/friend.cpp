// Δημιουργήστε μια κλάση Α με ένα ακέραιο ιδιωτικό μέλος x. 
// Συμπληρώστε μια φίλη συνάρτηση fun που να εκτυπώνει την τιμή του x για 
// ένα αντικείμενο της κλάσης Α.
#include <iostream> 

class A
{
    private:
        int x;
    public:
        A(int x_):x(x_) {}
        friend void fun(const A &a)
        {
            std::cout<<"X="<<a.x<<std::endl;
        }
};


int main()
{
    A a1(10);
    A a2(11);
    A a3(13);
    fun(a1);
    fun(a2);
    fun(a3);
    return EXIT_SUCCESS;
}
