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

void sine(float number,pixel c)
{
    position p;
    for(float i=-500;i<=500;i+=0.001)
    {
        p.x=40*i+width/2;        
        p.y=(40*sin(i))+height/number;        
        putpixel(p,c);
    }
}
void main()
{
    img=malloc(height*width*channel);
    for(int i = 0; i<width*height*channel ; i++)
	    img[i] = 255;
    
    pixel c;
    c.r=255;c.g=0;c.b=0;
    sine(3,c);
    c.r=0;c.g=255;
    sine(1.8,c);
    c.g=0;c.b=255;
    sine(1.2,c);
    stbi_write_jpg("sine.jpg",width,height,channel,img,100);
    free(img);
}
