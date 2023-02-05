#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

vector <double> load_temperatures()
{
    vector <string> data;
    vector <double> temperatures;
    string line,word;
    bool start=true;

    fstream fp;
    fp.open("datasets\\temperatures.txt");
    if(!fp.is_open())
    {
        cerr<<"Error on opening datasets\\temperatures.txt"<<endl;
        exit(EXIT_FAILURE);
    }
    while(getline(fp,line))
    {
        if(start)
        {
            start=false;
            continue;
        }
        data.clear();
        stringstream ss(line);
        while(getline(ss,word))
        {
            data.push_back(word);
        }
        temperatures.push_back(stod(data[1]));
    }
    fp.close();
    return temperatures;
}


int main()
{
    
}
