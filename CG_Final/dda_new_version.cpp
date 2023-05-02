#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

void dda(){
	
	int x1,y1,x2,y2,x,y;
	cout<<"Enter point 1: ";
	cout<<"Enter x1: ";
	cin>>x1;
	cout<<"Enter y1: ";
	cin>>y1;
	cout<<"Enter x2: ";
	cin>>x2;
	cout<<"Enter y2: ";
	cin>>y2;
	int gd = DETECT, gm ;
	char pathtodriver[] = "";
	initgraph(&gd, &gm, pathtodriver) ;
	if(x2<x1){
		int temp=x2;
		x2=x1;
		x1=temp;
		temp=y2;
		y2=y1;
		y1=temp;
	}
	
	int dy=y2-y1;
	int dx=x2-x1;
	
	int m=dy/dx;
	
	if(dx>=dy){
		int n=x2-x1+1;
		x=x1;
		y=y1;
		for(int i=0;i<n;i++){
			putpixel(x,round(y),11);
			x=x+1;
			y=y+m;
		}
	}
	else{
		int n=y2-y1+1;
		x=x1;
		y=y1;
		for(int i=0;i<n;i++){
			putpixel(round(x),y,10);
			x=x+1/m;
			y=y+1;
		}
	}
	getch() ;
	closegraph() ;	
}
int main(){
	dda();
}
