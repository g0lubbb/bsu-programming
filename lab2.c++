#include <iostream>
#include <ctime>
using namespace std;
int main()
{
    setlocale(LC_ALL, "ru");
    srand(NULL(time));
    int size, min, max, counter = 0, counter2 = 0;
    int buf = -1;
    cout << "������� ������ ����� ���������: ";
    cin >> min;
    cout << endl;
    cout << "������� ������� ����� ���������: ";
    cin >> max;
    cout << "������� ����������� �������: ";
    cin >> size;
    int* arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = min + rand() % (max - min + 1);
    }
    for (int k = 0; k < size; k++)
    {
        if (arr[k] > 0) {
            counter++;
        }

    }
    cout << "--------------------------------------------------------------------------" << endl;
    cout << "����� ���� ������������� �������� �������: " << counter << endl;

    for (int t = size - 1; t >= 0; t--)
    {
        if (arr[t] == 0)
        {
            buf = t;
            break;
        }
    }
    cout << "--------------------------------------------------------------------------" << endl;
    if (buf == -1)
    {
        std::cout << "����� � ������� ���\n";
    }
    else
    {
        for (int t = buf; t < size; t++)
        {
            counter2 += arr[t];
        }
        cout << "����� ���� ����. ������� ����� ���������� ����: " << counter2 << endl;
    }
    cout << "--------------------------------------------------------------------------" << endl;

    cout << "\n\n\n\n" << "��� �������� �������:\n";

    for (int j = 0; j < size; j++)
    {
        cout << arr[j] << "\t";
        if (j % 5 == 0 && j != 0)
        {
            cout << endl;
        }

    }
    cout << "\n��� �������� ����� ����������\n";
    //���������� �������������
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > 0)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (arr[j] > 0 && arr[i] > arr[j])
                {
                    int temp = arr[j];
                    arr[j] = arr[i];
                    arr[i] = temp;
                }
            }
        }
    }
    //���������� �������������
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < 0)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (arr[j] < 0 && arr[i] < arr[j])
                {
                    int temp = arr[j];
                    arr[j] = arr[i];
                    arr[i] = temp;
                }
            }
        }
    }
    for (int j = 0; j < size; j++)
    {
        cout << arr[j] << "\t";
        if (j % 5 == 0 && j != 0)
        {
            cout << endl;
        }
    }
    cout << endl;
    delete[]arr;
    system("pause");
}