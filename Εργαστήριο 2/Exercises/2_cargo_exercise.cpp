// Κατασκευάστε μια κλάση με όνομα cargo (φορτίο) με μέλη δεδομένων τα ακόλουθα:
//     id (αναγνωριστικός αριθμός φορτίου) τύπου int.
//     destination (προορισμός) τύπου string.
//     weight (βάρος) τύπου double.
//     fragile (εύθραυστο) τύπου bool.
// Δημιουργήστε προκαθορισμένο κατασκευαστή που να δίνει τις εξής τιμές: 0, “Undefined”, 0, false.
// Δημιουργήστε έναν κατασκευαστή που να θέτει όλα τα μέλη δεδομένων σε τιμές που θα δέχεται ως παραμέτρους.
// Δημιουργήστε getters και setters μόνο το πεδίο weight.
// Δημιουργήστε μια συνάρτηση show() που να εμφανίζει τις τιμές όλων των πεδίων του αντικειμένου.
// Δημιουργήστε μια συνάρτηση μέλος make_safe() που εφόσον ένα φορτίο δεν είναι fragile να το κάνει και να αυξάνει το βάρος του κατά 5 κιλά (για υλικά συσκευασίας).
// Στη main:
//     Εισάγετε σε έναν πίνακα 5 θέσεων αντικείμενα cargo ως εξής:
//         1, Patras, 1000, false
//         2, Athens, 200, true
//         3, Kalamata, 2000, false
//         4, Patras, 1500, true
//         5, Athens, 1100, false
//     Με μια επανάληψη πραγματοποιήστε κλήση της make_safe για όλα τα αντικείμενα.
//     Εμφανίστε όλα τα αντικείμενα

#include <iostream>
using namespace std;


class Cargo
{
    private:
        int id;
        string destination;
        double weight;
        bool fragile;
    public:
        static int count_object;
        Cargo():id(0),destination("Undefined"),weight(0.0),fragile(false) {}
        Cargo(int cargo_id,string cargo_destination,double cargo_weight,bool is_fragile):id(cargo_id),destination(cargo_destination),weight(cargo_weight),fragile(is_fragile) {Cargo::count_object++;}
        ~Cargo() {}
        void set_weight(double cargo_weight) {this->weight=cargo_weight;}
        double get_weight()const {return this->weight;}
        void show()
        {
            cout<<"Id:"<<this->id<<"\tDestination:"<<this->destination<<"\tWeight:"<<this->weight<<"\tIs_Fragile:"<<boolalpha<<this->fragile<<endl;
        }
        void make_safe()
        {
            if(!this->fragile)
            {
                this->fragile=true;
                this->weight+=5;
            }
        }

};

int Cargo::count_object=0;

int main(){
    Cargo cargos[]{
        {1, "Patras", 1000, false},
        {2, "Athens", 200, true},
        {3, "Kalamata", 2000, false},
        {4, "Patras", 1500, true},
        {5, "Athens", 1100, false}
    };
    cout<<"Cargos created:"<<Cargo::count_object<<endl;
    for(auto &cargo:cargos)
    {
        cargo.make_safe();
        cargo.show();
    }
}