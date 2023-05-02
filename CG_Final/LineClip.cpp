// C++ program to implement Cohen Sutherland algorithm
// for line clipping.
#include <stdio.h>
#include <iostream>
#include <graphics.h>
#include <math.h>
using namespace std;

// Defining region codes
const int INSIDE = 0; // 0000
const int LEFT = 1; // 0001
const int RIGHT = 2; // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8; // 1000


const int x_max = 10;
const int y_max = 8;
const int x_min = 4;
const int y_min = 4;

// Function to compute region code for a point(x, y)
int computeCode(double x, double y){
	// initialized as being inside
	int code = INSIDE;
	if (x < x_min) // to the left of rectangle
		code |= LEFT;
	else if (x > x_max) // to the right of rectangle
		code |= RIGHT;
	if (y < y_min) // below the rectangle
		code |= BOTTOM;
	else if (y > y_max) // above the rectangle
		code |= TOP;
	return code;
}


void cohenSutherlandClip(double x1, double y1,double x2, double y2){
	
	int code1 = computeCode(x1, y1);
	int code2 = computeCode(x2, y2);

	
	bool accept = false;
	while (true){
		if ((code1 == 0) && (code2 == 0)) {
			// If both endpoints lie within rectangle
			accept = true;
			break;
		}
		else if (code1 & code2) {
			// If both endpoints are outside rectangle,in same region
			break;
		}
		else {
			// Some segment of line lies within the rectangle
			int code_out;
			double x, y;

			// At least one endpoint is outside the rectangle, pick it.
			if (code1 != 0)
				code_out = code1;
			else
				code_out = code2;

			if (code_out & TOP) {
				// point is above the clip rectangle
				x = x1 + (x2 - x1) * (y_max - y1) / (y2 - y1);
				y = y_max;
			}
			else if (code_out & BOTTOM) {
				// point is below the rectangle
				x = x1 + (x2 - x1) * (y_min - y1) / (y2 - y1);
				y = y_min;
			}
			else if (code_out & RIGHT) {
				// point is to the right of rectangle
				y = y1 + (y2 - y1) * (x_max - x1) / (x2 - x1);
				x = x_max;
			}
			else if (code_out & LEFT) {
				// point is to the left of rectangle
				y = y1 + (y2 - y1) * (x_min - x1) / (x2 - x1);
				x = x_min;
			}

			// Now intersection point x, y is found,by intersection point
			if (code_out == code1) {
				x1 = x;
				y1 = y;
				code1 = computeCode(x1, y1);
			}
			else {
				x2 = x;
				y2 = y;
				code2 = computeCode(x2, y2);
			}
		}
	}
	if (accept) {
		cout << "Line accepted from " << x1 << ", "<< y1 << " to " << x2 << ", " << y2 << endl;
		line(x1*10,y1*10,x2*10,y2*10);
	}
	else
		cout << "Line rejected" << endl;
}

// Driver code
int main(){
	int window = initwindow(1000,1000,"");
	setbkcolor(BLACK);
	cleardevice();
    line(x_max*10,y_max*10,x_max*10,y_min*10);
	line(x_max*10,y_max*10,x_min*10,y_max*10);
	line(x_min*10,y_min*10,x_min*10,y_max*10);
	line(x_min*10,y_min*10,x_max*10,y_min*10);
	// First Line segment
	cohenSutherlandClip(5, 5, 7, 7);

	// Second Line segment
	cohenSutherlandClip(7, 9, 11, 4);

	// Third Line segment
	cohenSutherlandClip(1, 5, 4, 1);
	getch();
    closegraph(); 
	return 0;
}

