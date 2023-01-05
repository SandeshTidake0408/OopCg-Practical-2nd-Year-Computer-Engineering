#include <iostream>
using namespace std;
#define size 20
template <class T>
void selection_sort(T A[size], int n)
{
    int i, j, min;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (A[j] < A[min])
                min = j;
        }
        T temp = A[i];
        A[i] = A[min];
        A[min] = temp;
    }

    cout << "printing the sorted array:" << endl;
    cout << "\nSorted array: ";
    for (i = 0; i < n; i++)
    {
        cout << " " << A[i];
    }
}

int main()
{
    int choice;
    int A[size];
    float B[size];
    int i, n;
    do
    {
        cout << "\n 1. Integer : ";
        cout << "\n 2. Float : ";
        cout << "\n 3. Exit : " << endl;
        cout << "\n Enter Choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "\nEnter Total Number Of Integer Elements:";
            cin >> n;
            cout << "\nEnter Integer Elements:";
            for (i = 0; i < n; i++)
            {
                cin >> A[i];
            }
            selection_sort(A, n);
            break;
        }
        case 2:
        {
            cout << "\nEnter Total Number Of Float Elements:";
            cin >> n;
            cout << "\nEnter Float Elememts:";
            for (i = 0; i < n; i++)
            {
                cin >> B[i];
            }
            selection_sort(B, n);
            break;
        }
        case 3:
        {
            cout << "**Program Exited Successfully**" << endl;
            exit(0);
        }
        }
    } while (choice != 3);
    return 0;
}