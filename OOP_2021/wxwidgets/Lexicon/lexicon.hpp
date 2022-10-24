#include <iostream>
#include <vector>
#include <regex>

class Lexicon
{
    private:
        std::vector <std::string> words;
    public:
        Lexicon();
        void open(std::string filename);
        std::vector <std::string> equal_length(int length);
        std::vector <std::string> startswith(std::string start_reg);
        std::vector <std::string> endswith(std::string end_reg);
        std::vector <std::string> contains(std::string pattern,int rep);
        std::vector <std::string> contains_pattern(std::string pcon);
};