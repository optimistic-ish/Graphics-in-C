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

int w,h,chan;

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


int main(){
//unsigned char * radius = stbi_load("test.jpg",&w,&h,&chan,0);
img = malloc(width*height*channel);
for(int i = 0; i<width*height*channel ; i++)
	img[i] = 255;
double pi = asin(1)*2;

double R = 200;
for(double i = 0; i < 360; i+= 0.01)
{
	double y = R * sin( i * pi / 180);
	double x = R * cos( i * pi / 180);

	position p; pixel c;
	c.r=0; c.g = 0; c.b =255;
	p.x = x + width / 2; p.y=y + height / 2;

	putpixel(p,c);	
}
{position p;p.x=width/2;pixel c;
for(p.y=0;p.y<height;p.y++){
    c.r=0;c.g=0;c.b=0;
    putpixel(p,c);}}
{position p;p.y=height/2;pixel c;
for(p.x=0;p.x<width;p.x++){
    c.r=0;c.g=0;c.b=0;
    putpixel(p,c);
}}
// {position p;pixel c;
// for(int i=0;i<h;i++){
//     for(int j=0;j<w;j++){
//         c.r=radius[i*w*chan+j*chan];
//         c.g=radius[i*w*chan+j*chan+1];
//         c.b=radius[i*w*chan+j*chan+2];
//         p.x=j;
//         p.y=i;
//         putpixel(p,c);
//     }
// }
//}
stbi_write_jpg("circle.jpg",width,height,channel,img,100);
free(img);
//stbi_image_free(radius);
return 0;
}