#include <iostream>

using namespace std;

void input_board(int *a,int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<"Give a["<<i<<"]:";
        cin>>a[i];
    }
}

void print_board(int *a,int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<"a["<<i<<"]:"<<a[i]<<endl;
    }
}

int main()
{
    int board[6];
    input_board(board,6);
    print_board(board,6);
    return EXIT_SUCCESS;
}