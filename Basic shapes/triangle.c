#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

int width=1000,
height =600,
channel =3;

char* img; 

typedef struct color
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
}pixel;

typedef struct position
{
	int x;
	int y;
} position;

void putpixel(position pos, pixel c)
{
	if(pos.x>=width || pos.y>=height ||c.r>255||c.g>255||c.b>255 || pos.x<0 || pos.y<0)
		return;
	int index = (pos.y * width ) * channel +pos.x * channel;
	img[index] = c.r;
	img[index+1]=c.g;
	img[index+2]=c.b;
}
void drawTriangle(float side)
{
    float altitude=(1.74*side)/2.0; //h=sqrt(3)*side/2
    //side AB
    for(double i=-(side/2);i<=0.0;i+=0.1)
    {
        position p;pixel c;
        p.x=(int)(i)+width/2;
        p.y=(int)(-(2.0*altitude*i/side)-(2.0*altitude/3.0))+height/2;        
        c.r=255; c.g = 0; c.b =0;
        putpixel(p,c);
    }
    //side AC
    for(double i=(side/2);i>=0.0;i-=0.1)
    {
        position p;pixel c;
        p.x=(int)(i)+width/2;
        p.y=(int)(+(2.0*altitude*i/side)-(2.0*altitude/3.0))+height/2;        
        c.r=0; c.g = 255; c.b =0;
        putpixel(p,c);
    }
    //side BC
    for(double i=(side/2);i>=-side/2;i-=0.1)
    {
        position p;pixel c;
        p.x=(int)(i)+width/2;
        p.y=(int)(altitude/3)+height/2;        
        c.r=0; c.g = 0; c.b =255;
        putpixel(p,c);
    }
}


void main()
{    
    img=malloc(height*width*channel);  //declaring pixels
    // setting the background to white
    for(int i = 0; i<width*height*channel ; i++)
	    img[i] = 255;

    //drawing triangle
    drawTriangle(400.0);
    stbi_write_jpg("triangle.jpg",width,height,channel,img,100);
    free(img);
    
}
