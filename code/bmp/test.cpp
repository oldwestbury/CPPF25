#include "bmp.hpp"
#include <iostream>

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

int main() {
    
    BMP bmp(500, 500); 

    for(int i=0;i<5;i++){
        uint8_t x=rand()%500;
        uint8_t y=rand()%500;
        uint8_t l=rand()%500;
        uint8_t h=rand()%500;
        
        draw_rectangle(bmp,x,y,l,h,5);

    }
    
    
    bmp.write("rect.bmp"); // Save the image to a file

    return 0;
}
