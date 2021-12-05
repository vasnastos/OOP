#include "lexicon.hpp"

Lexicon::Lexicon() {}

void Lexicon::open(std::string filename)
{

}

std::vector <std::string> Lexicon::equal_length(int length)
{
    std::vector <std::string> match;
    for(auto &word:this->words)
    {
        if(word.length()==length)
        {
            match.emplace_back(word);
        }
    }
    return match;
}

std::vector <std::string> Lexicon::startswith(std::string start_reg)
{
    std::regex reg("\b"+start_reg+".*");
    std::vector <std::string> match;
    for(auto &word:this->words)
    {
        if(std::regex_match(word,reg))
        {
            match.emplace_back(word);
        }
    }
    return match;
}

std::vector <std::string> Lexicon::endswith(std::string end_reg)
{
    std::regex reg(".*"+end_reg+"$");
    std::vector <std::string> match;
    for(auto &word:this->words)
    {
        if(std::regex_match(word,reg))
        {
            match.emplace_back(word);
        }
    }
    return match;
}

std::vector <std::string> Lexicon::contains(std::string pattern,int rep)
{
    std::vector <std::string> match;
    if(pattern.length()==1)
    {
        char search_character=pattern.at(0);
        std::vector <std::string> match;
        for(auto &word:this->words)
        {
            int counter=0;
            for(auto &ch:word)
            {
                if(ch==search_character)
                {
                    counter++;
                    if(counter==rep)
                    {
                        match.emplace_back(word);
                    }
                }
                else
                {
                    counter=0;
                }
            }
        }
        return match;
    }
    std::regex reg(".*"+pattern+"{"+std::to_string(rep)+"}.*");
    for(auto &word:words)
    {
        if(std::regex_match(word,reg))
        {
            match.emplace_back(word);
        }
    }
    return match;
}