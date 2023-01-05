#include <iostream>
#include <graphics.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

void LINE(float x1, float y1, float x2, float y2)
{
	float step, dx, dy, x, y;
	dx = x2 - x1;
	dy = y2 - y1;

	if (dx >= dy)
		step = dx;
	else
		step = dy;

	dx = (dx / step);
	dy = (dy / step);

	x = x1;
	y = y1;

	int i = 1;
	while (i <= step)
	{
		putpixel(x, y, 5);
		x = x + dx;
		y = y + dy;
		i += 1;
		delay(5);
	}
}
void Display(int x1, int y1, int x, int y)
{

	putpixel(x + x1, y - y1, WHITE);
	putpixel(x + y1, y - x1, WHITE);
	putpixel(x - x1, y - y1, WHITE);
	putpixel(x - y1, y - x1, WHITE);
	putpixel(x - y1, y + x1, WHITE);
	putpixel(x - x1, y + y1, WHITE);
	putpixel(x + y1, y + x1, WHITE);
	putpixel(x + x1, y + y1, WHITE);
}

void Bres_circle(int x, int y, int rad)
{
	int x1 = 0;
	int y1 = rad;
	float dp = 3 - 2 * rad;
	while (x1 <= y1)
	{
		if (dp <= 0)
			dp += (4 * x1) + 6;
		else
		{
			dp += (4 * (x1 - y1)) + 10;
			y1--;
		}
		x1++;
		Display(x1, y1, x, y);
		delay(5);
	}
}

int main()
{

	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);

	LINE(100, 100, 200, 100); // Co-ordiantes for parallelogram
	LINE(200, 100, 200, 200);
	LINE(100, 100, 100, 200);
	LINE(100, 200, 200, 200);

	LINE(150, 100, 200, 150); // co-ordinates for trapazium
	LINE(150, 100, 100, 150);
	LINE(100, 150, 150, 200);
	LINE(150, 200, 200, 150);

	Bres_circle(150, 150, 35); // Drawing Circle

	delay(1000);
	closegraph();
	return 0;
}