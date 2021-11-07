#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Enter the size of array to create : ";
    cin >> n;

    //Δέσμευση μνήμης
    int *arr = new int[n];
    //int *arr = new int(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << " : ";
        cin >> arr[i];
    }
    
    cout << "You entered : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }

    //Αποδέσμευση μνήμης
    delete[] arr;

    //Αρχικοποίηση κατά τη δημιουργία
    int *array{ new int[5]{ 10, 7, 15, 3, 11 } };
    for(int i=0;i<5;i++)
    {
        cout << "array[" << i << "] = " << array[i] << endl;
    }

    delete[] array;
}