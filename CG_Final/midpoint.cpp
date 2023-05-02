#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;
void midpoint(int x1,int y1,int x2, int y2)
{
		if(x1 > x2) {
		swap(x1, x2) ;
		swap(y1, y2) ;
	}
	
	if(y1 > y2) {
		swap(y1, y2) ;
		swap(x1, x2) ;
	}
	int dx = x2-x1;
	int dy = y2-y1;
	if(dy<=dx)
	{
		int E = 2*dy;
		int NE = 2*(dy-dx);
		int d = 2*dy-dx;
		int x=x1;int y=y1;
		cout<<x<<","<<y<<endl;
		while(x<x2)
		{
			x++;
			if(d<=0)
			{
				d=d+E;
			}
			else
			{
				d+=NE;
				y++;
			}
			putpixel(round(x), round(y), 5);
		}
	}
	else if(dx<dy)
	{
		int E = 2*dx;
		int NE = 2*(dx-dy);
		int d = 2*dx-dy;
		int x = x1;int y=y1;
		cout<<x<<","<<y<<endl;
		while(y<y2)
		{
			y++;
			if(d<0)
			{
				d=d+E;
			}
			else
			{
				d+=NE;
				x++;
			}
			putpixel(round(x), round(y), 5);
		}
	}
}
int main()
{
	int gd = DETECT,gm;
	int x1 = 50,y1=300,x2=200,y2=10;
	initgraph(&gd,&gm,"");
	midpoint(x1,y1,x2,y2);
	getch();
	closegraph();
}
