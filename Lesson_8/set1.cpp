// The first line of input contains an integer T denoting the no of test cases . Then T test cases follow. The first line of input contains an integer Q denoting the no of queries . Then in the next line are Q space separated queries .
// A query can be of four types 
// 1. a x (inserts an element x to the set s)
// 2. b (prints the contents of the set s)
// 3. c x (erases an element x from the set s)
// 4. d x (prints 1 if the element x is present in the set else print -1)
// 5. e (prints the size of the set s)

// Output:
// The output for each test case will  be space separated integers denoting the results of each query . 

// Constraints:
// 1<=T<=100
// 1<=Q<=100
// Example:

// Input
// 2
// 6
// a 1 a 2 a 3 b c 2 b
// 5
// a 1 a 5 e d 5 d 2
#include <iostream>
#include <sstream>
#include <vector>
#include <set>

using namespace std;

void append_query(set <int> &queries,int value)
{
    queries.insert(value);
}

string show_queries(set <int> &queries)
{
    string message="";
    for(auto &x:queries)
    {
        message+=to_string(x)+" ";
    }
    return message;
}

void erase_query(set <int> &queries,int key)
{
    if(queries.find(key)!=queries.end())
    {
      queries.erase(queries.find(key));  
    }
}

string query_exists(set <int> &queries,int key)
{
    return queries.find(key)!=queries.end()?"1 ":"-1 ";
}

int main()
{
    int testcases,nqueries,query_value;
    string query,val,action;
    set <int> queries;
    vector <string> data;
    string message="";
    cin>>testcases;
    for(int i=0;i<testcases;i++)
    {
        data.clear();
        cin>>nqueries;
        cin.ignore();
        getline(cin,query);
        stringstream ss(query);
        while(ss>>val)
        {
            data.push_back(val);
        }
        int count=0;
        while(count<data.size())
        {
            action=data.at(count);
            if(action=="a")
            {
                query_value=stoi(data.at(count+1));
                append_query(queries,query_value);    
                count+=2;
            }
            else if(action=="b")
            {
                message+=show_queries(queries);
                count++;      
            }
            else if(action=="c")
            {
                query_value=stoi(data.at(count+1));
                erase_query(queries,query_value);
                count+=2;
            } 
            else if(action=="d")
            {
                query_value=stoi(data.at(count+1));
                message+=query_exists(queries,query_value);
                count+=2;
            }          
            else
            {
                count++;
                message+=to_string(queries.size())+" ";
            }
        }
        message+="\n";
    }
    cout<<"Queries:"<<queries.size()<<endl;
    cout<<"Results:"<<endl;
    cout<<"******"<<endl;
    cout<<message<<endl;
    return EXIT_SUCCESS;
}