#include <iostream>
#include <vector>

using namespace std;

template <typename T>
vector<vector<T>> matrixMultiplication(vector<vector<T>> &A, vector<vector<T>> &B)
{
    int n = A.size();
    int m = B[0].size();
    int k = A[0].size();

    vector<vector<T>> result(n, vector<T>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int p = 0; p < k; p++)
            {
                result[i][j] += A[i][p] * B[p][j];
            }
        }
    }

    return result;
}

int main()
{
    vector<vector<int>> A{{1, 2, 3}, {4, 5, 6}};
    vector<vector<int>> B{{7, 8}, {9, 10}, {11, 12}};

    auto result = matrixMultiplication(A, B);
    for (auto &row : result)
    {
        for (auto &col : row)
        {
            cout << col << " ";
        }
        cout << endl;
    }

    cout<<endl<<endl;

    vector<vector<double>> C{{1.1, 2.2, 3.3}, {4.4, 5.5, 6.6}};
    vector<vector<double>> D{{7.7, 8.8}, {9.9, 10.1}, {11.1, 12.2}};

    auto resultDouble = matrixMultiplication(C, D);
    for (auto &row : resultDouble)
    {
        for (auto &col : row)
        {
            cout << col << " ";
        }
        cout << endl;
    }

    return 0;
}