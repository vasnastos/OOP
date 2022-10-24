#include <cstdio>
#include <windows.h>
#include <iostream>
#define MAX_INPUT_LENGTH 255

std::string input(std::string prefix)
{

    SetConsoleOutputCP(65001);
    SetConsoleCP(CP_UTF8);
    wchar_t wstr[MAX_INPUT_LENGTH];
    char mb_str[MAX_INPUT_LENGTH * 3 + 1];

    unsigned long read;
    void *con = GetStdHandle(STD_INPUT_HANDLE);
    std::cout<<prefix;
    ReadConsole(con, wstr, MAX_INPUT_LENGTH, &read, NULL);

    int size = WideCharToMultiByte(CP_UTF8, 0, wstr, read, mb_str, sizeof(mb_str), NULL, NULL);
    mb_str[size] = 0;

    return std::string(mb_str);
}

int main()
{
    SetConsoleOutputCP(65001);
    std::string name=input("ΔΩΣΕ ΟΝΟΜΑ:");
    std::cout<<"Onoma:"<<name<<std::endl;
    return 0;
}