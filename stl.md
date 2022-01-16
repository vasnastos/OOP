## ΑΣΚΗΣΕΙΣ ΣΤΗΝ STL

* Γράψτε ένα πρόγραμμα το οποίο θα αποθηκεύει τα αντικέιμενα που περιέχονται σε μία λίστα αγορών. Κατασκευάστε μία συνάρτηση print_shopping_list() η οποία θα δέχεται ως όρισμα ένα vector
και θα εμφανίζει τα στοιχεία της λίστας.
    Το κύριο πρόγραμμα θα επιτελεί την ακόλουθη λειτουργικότητα:
        1. Δημιουργία κενού διανύσματος και εμφάνιση του διανύσματος.
        2. Προσθήκη αντικειμένων("eggs", "milk", "sugar", "chocolate"), εκτύπωση του vector.
        3. Διαγραφή του τελευταίου στοιχείου, εκτύπωση του vector.
        4. Προσθηκη στοιχείου "coffee" και εκτύπωση του vector.
        5. Αντικατάσταση του στοιχείου "sugar" με το στοιχείο "honey" και εκτύπωση του vector.
        6. Διαγραφή αντικειμένου "milk" και εκτύπωση του vector.
        7. Εκτύπωση του vector ταξινομημένου.

ΛΥΣΗ:[vector.cpp](https://github.com/vasnastos/OOP/blob/main/Lesson_8/STL/vector_2(shopping_list).cpp)


* Επιτέλεστε  την λειτουργικότητα της παραπάνω άσκησης με την χρήση λίστας της STL.
ΛΥΣΗ:[list.cpp](https://github.com/vasnastos/OOP/blob/main/Lesson_8/STL/list.cpp)

* Μία εταιρία security χρησιμοποιεί ένα σύστημα το οποία ξεκλιδώνει πόρτες χρησιμοποιώντας ένας τετραψήφιο κωδικό οποίος αυθεντικοποιήται με χρήση αντικειμένου της παρακάτω διεπαφής:
    ```
        class Access
        {
        public:
        void activate(unsigned code);
        void deactivate(unsigned code);
        bool isactive(unsigned code) const;
        };
    ```
    Κάθε υπάλληλος έχει έναν μοναδικό κωδικό πρόσβασης  που ενεργοποιήται με χρήση της συνάρτησης activate(). Όταν ο υπάλληλος φεύγει από την εταιρία ο κωδικός απενεργοποιήται με χρήση της συνάρτησης deactivate.
    1. Υλοποιήστε την κλάση Access
    2. Υλοποιήστε την παρακάτω λειτουργικότητα
        * Δημιουργία αντικειμένου Access
        * Ενεργοποιήση κωδικών 1234,9999,9876
        * Είσοδος κωδικού από τον χρήστη
        * Ενημέρωση του χρήστη αν η πόρτα έχει ανοίξει η όχι
        * Επανάληψη των 2 τελευταίων βημάτων εως ότου η πόρτα ανοίξει.
        * Απενεργοποιήση κωδικού του χρήστη, και του κωδικού 9876.

ΛΥΣΗ:[set.cpp](https://github.com/vasnastos/OOP/blob/main/Lesson_8/STL/set.cpp)

* Η ίδια εταιρία με την προηγούμενη άσκηση σε αναβάθμηση λογισμικού έχει ορίσει και επίπεδα πρόσβασης για κάθε κωδικό. Τροποποιήστε κατάλληλα την κλάση Access. Η νέα διεπαφή είναι η ακόλουθη
    ```
        class Access
        {
        public:
        void activate(unsigned code, unsigned level);
        void deactivate(unsigned code);
        bool isactive(unsigned code, unsigned level) const;
        };
    ```
    Το καινούργιο κύριο πρόγραμμα θα αποτελείται από τα εξής βήματα:

        * Δημιουργία αντικειμένου Access
        * Ενεργοποιήση κωδικού 1234 με επίπεδο πρόσβασης 1, κωδικού 9999 με επίπεδο πρόσβασης 5 και κωδικού 9876 με επίπεδο πρόσβασης 9
        * Εισαγωγή κωδικού πρόσβασης από τον χρήστη.
        * Υποθέτωντας ότι η πόρτα που προσπαθεί να ανοίξει ο χρήστης χρειάζεται επίπεδο πρόσβασης 5, ενημερώστε τον χρήστη αν η πόρτα ανοίγει η όχι.
        * Απενεργοποιήστε τον κωδικό που χρησιμοποιήθηκε. Αλλάξτε το επίπεδο πρόσβασης του κωδικού 9999 σε 8 και ενεργοποιήστε τον κωδικό 1111 με επίπεδο πρόσβασης 7.
        * Εισαγωγή κωδικού πρόσβασης από τον χρήστη
        * Υποθέτωντας ότι η νέα πόρτα που προσπαθεί να ανοίξει ο χρήστης απαιτεί επίπεδο πρόσβασης 7, ενημερώστε τον χρήστη αν άνοιξε η πόρτα η όχι.
        * Επαναλάβετε τα 2 τελευταία βήματα εως ότου ανοίξει η πόρτα

ΛΥΣΗ:[map.cpp](https://github.com/vasnastos/OOP/blob/main/Lesson_8/STL/map.cpp)

* Κατασκευάστε ένα διάνυσμα το οποίο θα περιέχει αντικείμενα τύπου Item. 
    0. Εισάγεται τα ακόλουθα αντικείμενα 
        {"eggs",2.10},
        {"milk",0.6},
        {"sugar",1.3},
        {"chocolate",2.1}
    1. Ταξινομήστε το διάνυσμα  των αντικειμένων.
    2. Αναζητήστε στο διάνυσμα το αντικείμενο με όνομα sugar.
    3. Εισαγεται στο διάνυσμα το αντικείμενο {"honey",9.0},{"milk",0.6},{"eggs",2.10},{"eggs",2.10},{"sugar",1.3} 
    4. Εμφανίστε το τελικό ποσό που κοστίζουν τα αντικείμενα

    **Η κλάση Item θα είναι η ακόλουθη**
    
    ![stl](Read_Me(resources)/uml_stl.png)

ΛΥΣΗ:[vector_shopping_list.cpp](https://github.com/vasnastos/OOP/blob/main/Lesson_8/STL/vector_shooping_list.cpp)