#include <iostream>
#include <graphics.h>
using namespace std;

void bresenhamLine(int x1, int y1, int x2, int y2, int val)
{
  if (x1 == x2 && y1 == y2)
  {
    putpixel(x2, y2, val);
  }
  else
  {
    int dx = x2 - x1;
    int dy = y2 - y1;

    float m = float(dy) / (float)(dx);

    if (m >1 || m < 0)
    {
      cout << "ERROR: Slope must be between 0 and 1." << endl;
      exit(1);
    }

    int d = 2 * dy - dx;
    int del_E = 2 * dy;
    int del_NE = 2 * (dy - dx);

    int x = x1;
    int y = y1;
    putpixel(x, y, val);

    while (x < x2)
    {
      if (d <= 0)
      {
        d += del_E;
        x += 1;
      }
      else
      {
        d += del_NE;
        x += 1;
        y += 1;
      }

      putpixel(x, y, val);
    }
  }

  return;
}


int main() {
    int gd = DETECT, gm ;
	char pathtodriver[] = "";
	initgraph(&gd, &gm, pathtodriver) ;
    int x1,y1,x2,y2;
	cout<<"Enter point 1: ";
	cout<<"Enter x1: ";
	cin>>x1;
	cout<<"Enter y1: ";
	cin>>y1;
	cout<<"Enter x2: ";
	cin>>x2;
	cout<<"Enter y2: ";
	cin>>y2;

	bresenhamLine(x1,y1,x2,y2,10);
    getch();
    closegraph();
    return 0;
}

