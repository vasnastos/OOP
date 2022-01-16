/*
Implement different operations on maps.
Input:
The first line of input contains an integer T denoting the no of test cases . Then T test cases follow. The first line of input contains an integer Q denoting the no of queries . Then in the next line are Q space separated queries .
A query can be of three types 
1. a x y (adds a value with key x and value y to the map)
2. b x (print value of  x is present in the map else print -1. )
3. c (prints values x and y separated by space i.e., contents of map)
Output:
The output for each test case will  be space separated integers denoting the results of each query . 

Constraints:
1<=T<=100
1<=Q<=100

Example:

Input
2
4
a 1 2 a 66 3 b 66 c
3
a 1 66 b 5 c

Output
3 1 2 66 3
-1 1 66
*/
#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <exception>

using namespace std;

void append_query(map <int,int> &queries,int xval,int yval)
{
    queries[xval]=yval;
    // queries[xval]=yval;
}

string show_queries(map <int,int> &queries)
{
    string msg="";
    for(auto &k:queries)
    {
        msg+=to_string(k.first)+" "+to_string(k.second)+" ";
    }
    return msg;
}

string search_query(map <int,int> &queries,int key)
{
    auto itr=queries.find(key);
    if(itr!=queries.end())
    {
        return to_string(itr->second)+" ";
    }
    return "-1 ";
}

int main(int argc,char **argv)
{
    map <int,int> queries;
    int testcases,nqueries,search_key;
    string query;
    int xval,yval,count_spaces;
    string val,action;
    cin>>testcases;
    bool one_factor,two_factor;
    string message="";
    for(int i=0;i<testcases;i++)
    {
        vector <string> data;
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
                try
                {
                    xval=stoi(data.at(count+1));
                    yval=stoi(data.at(count+2));
                }
                catch(exception &e)
                {
                    cerr<<e.what()<<endl;
                }
                append_query(queries,xval,yval);
                count+=3;
            }
            else if(action=="b")
            {
                try
                {
                    search_key=stoi(data.at(count+1));
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                }
                message+=search_query(queries,search_key);
                count+=2;
            }
            else 
            {
                message+=show_queries(queries);
                count+=1;
            }
        }
        message+="\n";
    }
    cout<<"Queries:"<<queries.size()<<endl;
    cout<<"Results:"<<endl;
    cout<<"*****"<<endl;
    cout<<message<<endl;
    return EXIT_SUCCESS;
}   