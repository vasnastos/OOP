// Γράψτε συνάρτηση που να δέχεται ως παραμέτρους έναν δισδιάστατο πίνακα ακεραίων, 
// τον αριθμό γραμμών και τον αριθμό στηλών του και να εμφανίζει τα περιεχόμενα του 
// πίνακα. Καλέστε από το κύριο πρόγραμμα τη συνάρτηση για έναν δυναμικό πίνακα.
#include <iostream>
#include <random>
#include <chrono>

using namespace std;
using namespace std::chrono;

void random_fill(int **board,int n,int m)
{
    mt19937 mt(steady_clock::now().time_since_epoch().count());
    auto rand_int=uniform_int_distribution<int>(1,1000);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            board[i][j]=rand_int(mt);
        }
    }
}

void display(int **board,int n,int m)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            std::cout<<"board["<<i<<"]["<<j<<"]:"<<board[i][j]<<std::endl;
        }
    }
}

int main()
{
    int **board;
    board=new int*[6];
    for(int i=0;i<6;i++)
    {
        board[i]=new int[6];
    }
    random_fill(board,6,6);
    display(board,6,6);
    for(int i=0;i<6;i++)
    {
        delete[] board[i];
    }
    delete[] board;
    return EXIT_SUCCESS;
}