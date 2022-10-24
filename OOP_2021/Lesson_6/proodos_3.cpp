#include <iostream>
#include <vector>
using namespace std;

class task
{
    private:
        int from;
        int to;
        string description;
    public:
        task(int f,int t,string d):from(f),to(t),description(d) {}
        
        // setters
        void set_from(int f)
        {
            this->from=f;
        }

        void set_to(int t)
        {
            this->to=t;
        }

        void set_desc(string d)
        {
            this->description=d;
        }

        // getters
        int get_from()const
        {
            return this->from;
        }

        int get_to()const
        {
            return this->to;
        }

        string get_desc()const
        {
            return this->description;
        }

        bool has_conflict(const task &t)
        {
            return (this->from<=t.from  && this->to>=t.to);
        }

        friend std::ostream &operator<<(ostream &os,const task &t)
        {
            return os<<t.from<<" "<<t.to<<" "<<t.description;
        }
};

int main()
{
    vector <task> tasks{{1,10,"task1"},{2,5,"task2"},{11,20,"task3"},{7,13,"task4"}};
    for(auto &t:tasks)
    {
        for(auto &t1:tasks)
        {
            if(t.get_from()==t1.get_from() && t1.get_to()==t.get_to())
            {
                continue;
            }
            if(t.has_conflict(t1))
            {
                cout<<t<<" conflicts "<<t1<<endl;
            }
        }
    }
    return EXIT_SUCCESS;
}