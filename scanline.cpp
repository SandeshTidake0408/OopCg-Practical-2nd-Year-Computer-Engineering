#include <iostream>
#include <graphics.h>
using namespace std;
void enter_poly(int a[][2], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the x" << i + 1 << " and y" << i + 1 << " ";
        cin >> a[i][0] >> a[i][1];
    }
    a[n][0] = a[0][0];
    a[n][1] = a[0][1];
}

int main()
{
    cout << "Enter the no. of vertices of polygon : ";
    int n;
    cin >> n;
    int arr[n + 1][2];

    enter_poly(arr, n);

    float slope[n];
    int active[20];
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    for (int i = 0; i < n; i++)
    {
        line(arr[i][0], arr[i][1], arr[i + 1][0], arr[i + 1][1]);
    }
    for (int i = 0; i < n; i++)
    {
        float dx, dy;
        dx = arr[i + 1][0] - arr[i][0];
        dy = arr[i + 1][1] - arr[i][1];
        if (dx == 0)
            slope[i] = 0;
        else if (dy == 0)
            slope[i] = 1;
        else
            slope[i] = dx / dy;
    }
    for (int y = 0; y < 500; y++)
    {
        int k = 0;
        for (int i = 0; i < n; i++)
        {
            if ((arr[i][1] <= y && arr[i + 1][1] > y) || (arr[i][1] > y && arr[i + 1][1] <= y))
            {
                active[k] = (int)(arr[i][0] + slope[i] * (y - arr[i][1]));
                k++;
            }
        }

        for (int j = 0; j < k - 1; j++)
        {
            for (int p = 0; p < k - 1; p++)
            {
                if (active[p] > active[p + 1])
                {
                    int temp = active[p];
                    active[p] = active[p + 1];
                    active[p + 1] = temp;
                }
            }
        }

        setcolor(2);
        for (int a = 0; a < k; a = a + 2)
        {
            line(active[a], y, active[a + 1] + 1, y);
            delay(150);
        }
    }

    return 0;
}