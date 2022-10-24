#include <iostream>

using namespace std;

// Κατασκευάστε μια κλάση με όνομα cargo (φορτίο) με μέλη δεδομένων τα ακόλουθα:
// id (αναγνωριστικός αριθμός φορτίου) τύπου int.
// destination (προορισμός) τύπου string.
// weight (βάρος) τύπου double.
// fragile (εύθραυστο) τύπου bool.


class Cargo
{
    private:
        int id;
        string destination;
        double weight;
        bool fragile;
    
    public:
        Cargo()
        {
            id=0;
            destination="Undefined";
            weight=0;
            fragile=false;
        }
};