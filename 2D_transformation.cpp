#include <iostream>
#include <graphics.h>
#include <math.h>
#include <stdlib.h>
using namespace std;
double b[3][3] = {1, 0, 0, 0, 1, 0, 0, 0, 1};
void multi(float p1[3][4], int pi[3][4])
{
    int temp = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 3; k++)
                temp += b[i][k] * p1[k][j];
            pi[i][j] = temp;
            temp = 0;
        }
    }
}
int main()
{
    int pii[3][4];
    float per[3][4] = {{50, 100, 100, 50}, {50, 50, 100, 100}, {1, 1, 1, 1}}; // main matrix
    float p1[10] = {50, 50, 100, 50, 100, 100, 50, 100, 50, 50};              // main matrix into array for drawing object

    cout << "Select Transformstion\n1.Translation\n2.Scaling\n3.Rotation\n";
    int ch;
    cout << "Enter your choice : ";
    cin >> ch;
    switch (ch)
    {
    case 1:
        cout << "Enter translation(tx,ty) : ";
        int tx, ty;
        cin >> tx >> ty;
        b[0][2] = tx;
        b[1][2] = ty;
        break;
    case 2:
        cout << "Enter Scaling Factor(sx,sy) : ";
        int sx, sy;
        cin >> sx >> sy;
        b[0][0] = sx;
        b[1][1] = sy;
        break;

    case 3:
        cout << "Enter the Roatation angle : ";
        int angle;
        cin >> angle;
        b[0][0] = cos(angle * 3.142 / 180);
        b[0][1] = sin(angle * 3.142 / 180);
        b[1][0] = -sin(angle * 3.142 / 180);
        b[1][1] = cos(angle * 3.142 / 180);
        break;
    }

    int gm, gd = DETECT;

    initgraph(&gd, &gm, NULL);

    int xmax = getmaxx();
    int ymax = getmaxy();
    int xmid = xmax / 2;
    int ymid = ymax / 2;
    setcolor(6);
    line(xmid, 0, xmid, ymax);
    line(0, ymid, xmax, ymid);
    setcolor(4);
    for (int i = 0; i < 8; i = i + 2)
    {
        line(p1[i] + xmid, ymid - p1[i + 1], xmid + p1[i + 2], ymid - p1[i + 3]);
    }
    multi(per, pii);
    int pi[10] = {pii[0][0], pii[1][0], pii[0][1], pii[1][1], pii[0][2], pii[1][2], pii[0][3], pii[1][3], pii[0][0], pii[1][0]};
    setcolor(2);
    for (int i = 0; i < 8; i = i + 2)
    {
        line(pi[i] + xmid, ymid - pi[i + 1], xmid + pi[i + 2], ymid - pi[i + 3]);
    }

    getch();
    closegraph();
    return 0;
}