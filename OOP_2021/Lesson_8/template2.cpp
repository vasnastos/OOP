#include <iostream>
#include <ctime>

using namespace std;

template <class T>
class Matrix
{
    private:
        T *board;
        int size;
    public:
        Matrix(int rows):board(new T[rows]),size(rows) {}
        ~Matrix() {delete[] board;}
        T get(int i)
        {
            return board[i];
        }
        int Size() {return this->size;}
        friend ostream &operator<<(ostream &os,const Matrix &m)
        {
            os<<"[";
            for(int i=0;i<m.size;i++)
            {
                os<<m.board[i]<<" ";
            }
            os<<"]";
            return os;
        }
        void fillran()
        {
            srand(time(nullptr));
            for(int i=0;i<this->size;i++)
            {
                this->board[i]=rand()%200;
            }
        }
};

int main()
{
    Matrix <int> m(12);
    m.fillran();
    cout<<m<<endl;
}