#include <iostream>

// Ένας χώρος ονομάτων είναι μια δηλωτική περιοχή που παρέχει ένα πεδίο εφαρμογής των αναγνωριστικών (τα ονόματα των τύπων, των λειτουργιών, των μεταβλητών κ.λπ.) μέσα σε αυτό.
// Οι χώροι ονομάτων χρησιμοποιούνται για την οργάνωση κώδικα σε λογικές ομάδες και για την πρόληψη των συγκρούσεων ονόματος που μπορεί να συμβούν ειδικά 
// όταν η βάση κώδικα σας περιλαμβάνει πολλαπλές βιβλιοθήκες.

namespace foo
{
    int cout=12;
}

int main()
{
    std::cout<<foo::cout<<std::endl;
}