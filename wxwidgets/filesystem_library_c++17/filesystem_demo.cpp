#include <iostream>
#include <experimental/filesystem>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>

// Specified at Compilation
// g++ filesystem_demo.cpp -std=c++17 -lstdc++fs
using namespace std;
namespace fs=std::experimental::filesystem;

string SEP()
{
    #ifdef __WIN32__
        return "\\";
    #elif __linux__
        return "/";
    #endif
    return "";
}

vector <int> Fopen(string filename)
{
    vector <int> contains;
    ifstream inputstream(filename);
    if(!inputstream.is_open())
    {
        cerr<<"File does not open properly"<<endl;
        return vector <int>();
    }
    string line;
    while(getline(inputstream,line))
    {
        contains.push_back(stoi(line));
    }
    inputstream.close();
    return contains;
}

int main()
{
    // Get Custom Seperator
   cout<<"My System seperator:"<<SEP()<<endl;
   cout<<"Current Path:"<<fs::current_path()<<endl;
   
   string primary_path="Source";
   fs::path inpath(fs::current_path());
   inpath.append(primary_path);
   vector <string> files{
       "numbers_100.txt",
       "numbers_1000.txt",
       "numbers_5000.txt",
       "numbers_10000.txt",
       "numbers_50000.txt"
   };
   map <string,string> filepaths;
   for(auto &file:files)
   {
       fs::path temp_path=inpath;
       temp_path.append(file);
       cout<<file<<"->"<<boolalpha<<fs::exists(temp_path)<<endl;
       cout<<file<<"->"<<fs::file_size(temp_path)<<"KB"<<std::endl;
       cout<<endl;
       filepaths.insert(make_pair(file,temp_path.c_str()));
   }
   cout<<"=== FULL PATHS ==="<<endl;
   for(auto &pth:filepaths)
   {
       cout<<pth.first<<"-->"<<pth.second<<endl;
   }
   cout<<endl<<"=== Amount of Lines ==="<<endl;
   for(auto &pth:filepaths)
   {
       cout<<pth.first<<"-->"<<Fopen(pth.second).size()<<endl;
   }
   return EXIT_SUCCESS;
}