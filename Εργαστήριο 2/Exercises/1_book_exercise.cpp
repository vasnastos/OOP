#include <iostream>
using namespace std;

// TODO
// 1. Να προσθεθεί ένα νέο πεδίο(data member) copies που θα αντιστοιχεί στον αριθμό των αντιτύπων του βιβλίου που υπάρχουν
// 2. Να δημιουργηθούν getters και setters για το πεδίο copies
// 3. Να συμπληρωθεί η συνάρτηση read. H συνάρτηση read θα επιτρέπει στον χρήστη να εισάγει στοιχεία ενός βιβλίου από το πληκτρολόγιο
// 4. Να συμπληρωθεί η συνάρτηση discount, η οποία για βιβλία με αντίτυπα λιγότερα από 10 θα πραγματοποιεί έκπτωση 30% επί της τιμής, για βιβλία με αντίτυπα λιγότερα από 50 έκτωση 15%
// , για βιβλία με αντίτυπα λιγότερα από 100 έκτωση 10% και για βιβλία με παραπάνω αντίτυπα έκτωση 7%.
// Στην κύρια συνάρτηση ο χρήστης να εισάγει 5 βιβλία και στην συνέχεια για όλα τα αποθηκευμένα βιβλία να εφαρμοστεί η έκπτωση και να εμφανιστούν οι πληροφορίες για τα βιβλία πριν και μετά την εκπτωση


class Book
{
    private:
        string title;
        string author;
        double price;
        int copies;
    
    public:
        // Constructors
        Book():title("No title"),author("No author"),price(-1.0) {}
        Book(string title,string author,double price,int copies):title(title),author(author),price(price),copies(copies) {}

        // Destructor
        ~Book() {}

        // setters
        void set_title(string new_book_title) {this->title=new_book_title;}
        void set_author(string new_book_author) {this->author=new_book_author;}
        void set_price(double new_book_price) {this->price=new_book_price;}
        void set_copies(int new_book_copies) {this->copies=new_book_copies;}

        // getters
        string get_author()const {return this->author;}
        string get_title()const {return this->title;}
        double get_price()const {return this->price;}
        int get_copies()const {return this->copies;}

        // Display method
        void display()
        {
            cout<<"Title:"<<this->title<<"\tAuthor:"<<this->author<<"\tPrice:"<<this->price<<endl;
        }

        void read()
        {
            cin>>this->title>>this->author>>this->price>>this->copies;
        }

        void discount()
        {
            if(this->copies<=10)
            {
                // this->price-=(0.3*this->price);
                this->price*=0.7;
            }
            else if(this->copies<=50)
            {
                this->price*=0.85;
            }
            else if(this->copies<=100)
            {
                this->price*=0.9;
            }
            else
            {
                this->price*=0.93;
            }
        }
};


void bookstore_discount(Book *books,int number_of_books)
{
    cout.precision(4);
    for(int i=0;i<number_of_books; i++)
    {
        cout<<"===== Book information ====="<<endl;
        books[i].display();
        books[i].discount();
        books[i].display();
        cout<<endl<<endl;
    }
}

// 48 Laws of Power - Robert Greene 
// Be Here Now - Ram Dass
// Extreme Ownership - Jocko Willink and Leif Babin
// How to Eat - Thich Nhat Hanh
// How to Win Friends & Influence People - Dale Carnegie
// Radical Focus - Christina Wodtke
// ReWork - Jason Fried & David Hansson
// Sapiens - Yuval Noah Harari
// Shantaram - Gregory David Roberts
// Soft Skills - John Sonmez
// Tao of Wu - RZA
// The Alchemist - Paulo Coelho
// The Art of War - Sun Tzu
// The Book of Mistakes - Skip Prichard
// The Culture Code - Daniel Coyle
// The Four Agreements - Don Miguel Ruiz

int main()
{
    Book books[]{
        Book("48 Laws of Power","Robert Greene",45,45),
        Book("Be Here Now","Ram Dass",32,10),
        Book("Extreme Ownership","Jocko Willink and Leif Babin",56,5),
        Book("How to Eat","Thich Nhat Hanh",89.34,90),
        Book("Radical Focus","Christina Wodtke",56.78,7),
        Book("ReWork","Jason Fried & David Hansson",12.456,120),
        Book("Sapiens","Yuval Noah Harari",123.45,92),
        Book("Shantaram","Gregory David Roberts",23.89,34),
        Book("Soft Skills","John Sonmez",10.98,78),
        Book("Tao of Wu","RZA",67.89,5),
        Book("The Alchemist","Paulo Coelho",78.32,23),
        Book("The Art of War","Sun Tzu",234.56,190),
        Book("The Book of Mistakes","Skip Prichard",43.67,74),
        Book("The Culture Code","Daniel Coyle",55.77,23),
        Book("The Four Agreements","Daniel Coyle",77.985,45),
        Book("Death on the Nile","Agatha Christie",21.4598,9)
    };

    bookstore_discount(books,sizeof(books)/sizeof(books[0]));
    return 0;
}