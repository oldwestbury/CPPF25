#include "bmp.hpp"
#include <iostream>
#include <cmath>
using namespace std;
void draw_rectangle(BMP &bmp,int x, int y, int l, int h, int b){
    for(int i=0;i<l;i++){
        for(int ii=0;ii<b;ii++){
        bmp.set_pixel(i+x, y+ii, 0,0,0);
        bmp.set_pixel(i+x, y+h-ii, 0,0,0);
        }
    }
    for(int j=0;j<h;j++){
        for(int ii=0;ii<b;ii++){
            bmp.set_pixel(x+ii, y+j, 0,0,0);
            bmp.set_pixel(x+l-ii, y+j, 0,0,0);
        }
    }
}

color gradColor(color c1, color c2, int x, int y, int s){

    double t=sqrt(s*s*2);
    double d=sqrt(x*x+y*y);
    double ratio=d/t;
   color c;
   c.r=(c2.r-c1.r)*ratio+c1.r;
   c.g=(c2.g-c1.g)*ratio+c1.g;
   c.b=(c2.b-c1.b)*ratio+c1.b;
    return c;
}


color gradColor2(color c1, color c2, int x, int y, int s) {

    double t2 = (s * s * 2);
    double d2 = (x * x + y * y);
    
    double ratio =d2/t2; 
    
    color c;
    c.r = (c2.r - c1.r) * ratio + c1.r;
    c.g = (c2.g - c1.g) * ratio + c1.g;
    c.b = (c2.b - c1.b) * ratio + c1.b;
    
    return c;
}


color gradColor3(color c1, color c2, int x, int y, int s){

    double t = sqrt(s * s * 2);
    double d = sqrt(x * x + y * y);
    
    // Non-linear ratio using a sine function (scaled to [0, 1] range)
    double ratio = (sin(d / t * M_PI - M_PI / 2) + 1) / 2;  // Sinusoidal transition
    
    // Calculate the new color using the non-linear ratio
    color c;
    c.r = (c2.r - c1.r) * ratio + c1.r;
    c.g = (c2.g - c1.g) * ratio + c1.g;
    c.b = (c2.b - c1.b) * ratio + c1.b;
    return c;
}
int main() {
    
    color c1(255,255,255);
    color c2(0,255,0);
    BMP bmp(500, 500); 
    for(int i=0;i<=500;i++)
    for(int j=0;j<=500;j++){
        color c=gradColor(c1,c2,i,j,500);   
        bmp.set_pixel(i,j,c.r,c.b,c.g);
    }
    
    bmp.write("grad3.bmp"); // Save the image to a file

    return 0;
}
