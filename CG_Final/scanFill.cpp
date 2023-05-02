#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

struct Point {
    int x, y;
};

void scanlineFill(Point* polygon, int n) {
    int ymin = polygon[0].y;
    int ymax = polygon[0].y;
    for(int i = 1; i < n; i++) {
        if(polygon[i].y < ymin) {
            ymin = polygon[i].y;
        } else if(polygon[i].y > ymax) {
            ymax = polygon[i].y;
        }
    }
    for(int y = ymin; y <= ymax; y++) {
        int x1 = INT_MAX, x2 = INT_MIN;
        for(int i = 0; i < n; i++) {
            int j = (i + 1) % n;
            if((polygon[i].y <= y && polygon[j].y > y) || (polygon[i].y > y && polygon[j].y <= y)) {
                float xi = (float)(y - polygon[i].y) * (polygon[j].x - polygon[i].x) / (polygon[j].y - polygon[i].y) + polygon[i].x;
                if(xi < x1) {
                    x1 = (int)xi;
                }
                if(xi > x2) {
                    x2 = (int)xi;
                }
            }
        }
        for(int x = x1; x <= x2; x++) {
            putpixel(x, y, WHITE);
        }
    }
}

int main() {
   int gd = DETECT, gm ;
	char pathtodriver[] = "";
	initgraph(&gd, &gm, pathtodriver) ;
    int n;
    cout << "Enter the number of vertices of the polygon: ";
    cin >> n;

    Point* polygon = new Point[n];
    for(int i = 0; i < n; i++) {
        cout << "Enter the x-coordinate of vertex " << i + 1 << ": ";
        cin >> polygon[i].x;
        cout << "Enter the y-coordinate of vertex " << i + 1 << ": ";
        cin >> polygon[i].y;
    }

    scanlineFill(polygon, n);

    delete[] polygon;

    getch();
    closegraph();
    return 0;
}

