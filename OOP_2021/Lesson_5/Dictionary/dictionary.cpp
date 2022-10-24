// Γράψτε ένα πρόγραμμα που να εμπεριέχει μια κλάση Lexicon που να διαβάζει 
// τα περιεχόμενα ενός αρχείου με λέξεις της αγγλικής γλώσσας 
// (το αρχείο θα περιέχει μια λέξη ανά σειρά).

// Το πρόγραμμα να προσφέρει μέσω ενός μενού επιλογών τις ακόλουθες λειτουργίες:
// *Nα εμφανίζει το πλήθος και εφόσον ο χρήστης επιθυμεί όλες τις λέξεις που έχουν 
// το πλήθος γραμμάτων που θα δίνει ο χρήστης.
// *Nα εμφανίζει το πλήθος και εφόσον ο χρήστης επιθυμεί όλες τις λέξεις που ξεκινούν με μια ακολουθία
// γραμμάτων που θα δίνει ο χρήστης.
// Να γραφούν Unit tests για τα παρακάτω ερωτήματα
// H Παραπάνω λειτουργικότητα να επιτευχθεί με χρήση αντικειμενοστραφούς προγραμματισμού
// Το αρχείο δεδομένων εισόδου είναι το αρχείο wordlist.txt

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class dict
{
    private:
        vector <string> words;
    public:
        dict()
        {
            fstream fs("wordlist.txt",ios::in);
            if(!fs.is_open())
            {
                cerr<<"Error on file opening"<<endl;
                return;
            }
            string line;
            while(getline(fs,line))
            {
                this->words.emplace_back(line);
            }
            fs.close();
        }

        vector <string> equal_len(int l)
        {
            vector <string> eqs;
            for(auto &word:this->words)
            {
                if(word.length()==l)
                {
                    eqs.emplace_back(word);
                }
            }
            return eqs;
        }

        vector <string> startswith(string prefix)
        {
            vector <string> sw; 
            int prefix_equality=0;
            for(auto &word:this->words)
            {
                if(prefix.length()>word.length()) continue;
                prefix_equality=0;
                for(int i=0,t=prefix.length();i<t;i++)
                {
                    if(prefix.at(i)==word.at(i))
                    {
                        prefix_equality++;
                    }
                }
                if(prefix_equality==prefix.length())
                {
                    sw.emplace_back(word);
                }
            }
            return sw;
        }

        vector <string> get_words()const
        {
            return this->words;
        }
};

int main()
{
    dict d;
    vector <string> length_equality=d.equal_len(7);
    vector <string> starts_with=d.startswith("ab");
    cout<<"**** Word Length:7 ****"<<endl;
    for(auto &w:length_equality)
    {
        cout<<w<<endl;
    }
    cout<<"---"<<endl;
    cout<<"Words:"<<length_equality.size()<<endl;
    cout<<endl<<endl;
    cout<<"**** Starts with:\"ab\" ****"<<endl;
    for(auto &w:starts_with)
    {
        cout<<w<<endl;
    }
    cout<<"---"<<endl;
    cout<<"Words:"<<starts_with.size()<<endl;
    cout<<endl<<endl;
    return EXIT_SUCCESS;
}