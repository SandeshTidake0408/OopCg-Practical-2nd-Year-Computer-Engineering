#include <iostream>
#include <graphics.h>
#include <math.h>
using namespace std;
static int LEFT = 1, RIGHT = 2, BOTTOM = 4, TOP = 8;
int xl, yl, xh, yh, x, y;
int getcode(int x, int y)
{
    int code = 0;
    if (x < xl)
    {
        code |= LEFT;
    }
    if (x > xh)
    {
        code |= RIGHT;
    }
    if (y < yl)
    {
        code |= BOTTOM;
    }
    if (y > yh)
    {
        code |= TOP;
    }
    return code;
}

int main()
{

    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    cout << "Enter the Diagonal Co-ordinate for Window :- " << endl;
    cin >> xl >> yl >> xh >> yh;
    setcolor(WHITE);
    rectangle(xl, yl, xh, yh);
    int x1, y1, x2, y2;
    cout << "Enter line Co-ordinate :- " << endl;
    cin >> x1 >> y1 >> x2 >> y2;
    line(x1, y1, x2, y2);
    delay(4000);
    setcolor(RED);

    int outcode1 = getcode(x1, y1);
    int outcode2 = getcode(x2, y2);
    int flag = 0;
    int temp;

    while (true)
    {
        float m = (y2 - y1) / (x2 - x1);
        if (outcode1 == 0 && outcode2 == 0)
        {
            flag = 1;
            break;
        }
        else if ((outcode1 & outcode2) != 0)
        {
            break;
        }
        else
        {
            if (outcode1 == 0)
            {
                temp = outcode2;
            }
            else
            {
                temp = outcode1;
            }

            if (temp & LEFT)
            {
                x = xl;
                y = y1 + m * (xl - x1);
            }
            else if (temp & RIGHT)
            {
                x = xh;
                y = y1 + m * (xh - x1);
            }
            else if (temp & BOTTOM)
            {
                y = yl;
                x = x1 + (yl - y1) / m;
            }

            else if (temp & TOP)
            {
                y = yh;
                x = x1 + (yh - y1) / m;
            }

            if (temp == outcode1)
            {
                x1 = x;
                y1 = y;
                outcode1 = getcode(x1, y1);
            }
            else
            {
                x2 = x;
                y2 = y;
                outcode2 = getcode(x2, y2);
            }
        }
    }
    if (flag)
    {
        cleardevice();
        rectangle(xl, yl, xh, yh);
        setcolor(WHITE);
        line(x1, y1, x2, y2);
        delay(100000);
        closegraph();
    }
    return 0;
}

// #include <iostream>
// #include <graphics.h>
// #include <math.h>
// using namespace std;

// void Window()
// {
//     line(200, 200, 350, 200);
//     line(350, 200, 350, 350);
//     line(200, 200, 200, 350);
//     line(200, 350, 350, 350);
// }
// void Code(char c[4], float x, float y)
// {
//     c[0] = (x < 200) ? '1' : '0';
//     c[1] = (x > 350) ? '1' : '0';
//     c[2] = (y < 200) ? '1' : '0';
//     c[3] = (y > 350) ? '1' : '0';
// }
// void Clipping(char c[], char d[], float &x, float &y, float m)
// {
//     int flag = 1, i = 0;
//     for (i = 0; i < 4; i++)
//     {
//         if (c[i] != '0' && d[i] != '0')
//         {
//             flag = 0;
//             break;
//         }
//         if (flag)
//         {
//             if (c[0] != '0')
//             {
//                 y = m * (200 - x) + y;
//                 x = 200;
//             }
//             else if (c[1] != '0')
//             {
//                 y = m * (350 - x) + y;
//                 x = 350;
//             }
//             else if (c[2] != '0')
//             {
//                 x = ((200 - y) / m) + x;
//                 y = 200;
//             }
//             else if (c[3] != '0')
//             {
//                 x = ((350 - y) / m) + x;
//                 y = 350;
//             }
//         }
//         if (flag == 0)
//             cout << "Line lying outside";
//     }
// }

// int main()
// {
//     int gd = DETECT, gm;
//     float x1, y1, x2, y2, m;
//     char c[4], d[4];
//     initgraph(&gd, &gm, NULL);
//     cout << "Enter coordinates : ";
//     cin >> x1 >> y1 >> x2 >> y2;
//     cout << "Before clipping : " << endl;
//     Window();
//     line(x1,y1,x2,y2);
//     getch();
//     cleardevice();
//     m = float((y2 - y1) / (x2 - x1));
//     Code(c, x1, y1);
//     Code(d, x2, y2);
//     Clipping(c,d,x1,y1,m);
//     Clipping(d,c,x2,y2,m);
//     cout<<"After Clipping : ";
//     Window();
//     line(x1,y1,x2,y2);
//     getch();
//     closegraph();

//     return 0;
// }
