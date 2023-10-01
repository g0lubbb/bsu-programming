#include <iostream>
#include<ctime>
#include <cmath>
using namespace std;
int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "ru");

    int cols, n;
    const int rows = 3;
    string button;
    int temchar, temval;
    cout << "Enter n: " << endl;
    cin >> n;
    cols = 2 * n;
    int* charact = new int[cols];
    int** arr = new int* [rows];

    for (int i = 0; i < rows; i++)
    {
        arr[i] = new int[cols];
    }
    system("cls");
    
    for (int i = 0; i < rows; i++)
    {
        int k = cols / 2;
        for (int j = 0; j < cols / 2; j++)
        {
            if (i <= 1 + cols / 2)
            {
                cin >> arr[i][j];
            }

            arr[i][k] = -arr[i][j];
            k++;
        }
    }
   
    cout << "Output of an array not sorted by characteristic values\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }

  
    for (int j = 0; j < cols; j++)
    {
        charact[j] = 0;
        for (int i = 0; i < rows; i++)
        {
            charact[j] += fabs(arr[i][j]);
        }
    }

    for (int i = 0; i < cols - 1; i++)
    {
        for (int j = 0; j < cols - i - 1; j++)
        {
            if (charact[j] < charact[j + 1])
            {
                int tempchar = charact[j];
                charact[j] = charact[j + 1];
                charact[j + 1] = tempchar;

                for (int k = 0; k < rows; k++)
                {
                    int tempval = arr[k][j];
                    arr[k][j] = arr[k][j + 1];
                    arr[k][j + 1] = tempval;
                }
            }
        }
    }

    cout << "Output of an array sorted by characteristic values\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
   
    for (int i = 0; i < rows; i++)
    {
        delete[] arr[i];
    }
    delete[]arr;
    delete[]charact;
}