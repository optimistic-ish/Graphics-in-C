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
int factor=20;
char* img; 

typedef struct color
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
}pixel;

pixel color={0,0,0};

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
void axis()
{
    position p;
    for(int i=-500;i<500;i++)
    {
        p.x=i+width/2;
        p.y=0+height/2;
        putpixel(p,color);
    }
    for(int i=-300;i<300;i++)
    {
        p.x=0+width/2;
        p.y=i+height/2;
        putpixel(p,color);
    }
}

void head()
{
    position p;
    //ears
    for(float i=1.170107;i<=6.876455;i+=0.001)
    {
        p.x=(int)(3*factor*cos(i)-5*factor)+width/2;
        p.y=(int)factor*(3*sin(i)-6)+height/2;
        
        putpixel(p,color);
    }
    for(float i=2.54883196;i<=8.26079448;i+=0.001)
    {
        p.x=(int)(3*factor*cos(i)+5*factor)+width/2;
        p.y=(int)factor*(3*sin(i)-6)+height/2;
        
        putpixel(p,color);
    }
    //face outline
    for(float i=2.87235868;i<=6.55241928;i+=0.001)
    {
        p.x=(int)factor*(5*cos(i))+width/2;
        p.y=(int)factor*(5*sin(i))+height/2;
        
        putpixel(p,color);
    }
    
    for(float i=2.586533843;i<5.38;i+=0.0001)
    {
        p.x=(int)factor*(sqrt(6)*cos(i)-1.5)+width/2;
        p.y=(int)factor*(4.0*sin(i))+height/2;
        putpixel(p,color);
    }
    for(float i=4.044;i<6.84;i+=0.0001)
    {
        p.x=(int)factor*(sqrt(6)*cos(i)+1.5)+width/2;
        p.y=(int)factor*(4.0*sin(i))+height/2;
        putpixel(p,color);
    }
    for(float i=-3;i<=3;i+=0.001)
    {
        p.x=factor*i+width/2;        
        p.y=(factor*cos(0.75*i)+4.85*factor)+height/2;        
        putpixel(p,color);
    }
    for(float i=0;i<3.15*2;i+=0.0001)
    {
        p.x=(int)factor*(0.6581*cos(i)-1.2)+width/2;
        p.y=(int)factor*(1.3161*sin(i)+0)+height/2;
        putpixel(p,color);
    }
    for(float i=0;i<3.15*2;i+=0.0001)
    {
        p.x=(int)factor*(0.6581*cos(i)+1.2)+width/2;
        p.y=(int)factor*(1.3161*sin(i)+0)+height/2;
        putpixel(p,color);
    }
    for(float i=-2.5;i<2.5;i+=0.0001)
    {
        p.x=(int)factor*i+width/2;
        p.y=(int)factor*(0.1111*i*i+1.2)+height/2;
        putpixel(p,color);
    }
    for(float i=0;i<3.15*2;i+=0.0001)
    {
        p.x=(int)factor*(1.3161*cos(i))+width/2;
        p.y=(int)factor*(0.70711*sin(i)+2.3)+height/2;
        putpixel(p,color);
    }
    for(float i=-3.29;i<3.29;i+=0.0001)
    {
        p.x=(int)factor*i+width/2;
        p.y=(int)factor*(-0.14286*i*i+4.4)+height/2;
        putpixel(p,color);
    }
    for(float i=-2.079;i<=2.079;i+=0.001)
    {
        p.x=factor*i+width/2;        
        p.y=(factor*(cos(0.7854*i))+4.0*factor)+height/2;        
        putpixel(p,color);
    }
    for(float i=0;i<3.15*2;i+=0.0001)
    {
        p.x=(int)factor*(0.4*cos(i)-1.1)+width/2;
        p.y=(int)factor*(0.5*sin(i)+0.7)+height/2;
        putpixel(p,color);
    }
    for(float i=0;i<3.15*2;i+=0.0001)
    {
        p.x=(int)factor*(0.4*cos(i)+1.1)+width/2;
        p.y=(int)factor*(0.5*sin(i)+0.7)+height/2;
        putpixel(p,color);
    }   
    for(float i=-0.25;i<4;i+=0.0001)
    {
        p.x=(int)factor*(1.065*0.82*cos(i)-1.6855*0.5735*sin(i)-4.0)+width/2;
        p.y=(int)factor*(1.065*0.5735*sin(i)+1.6855*0.82*cos(i)+2.9)+height/2;
        putpixel(p,color);
    }
    for(float i=-2.7;i<1.9;i+=0.0001)
    {
        p.x=(int)factor*(1.065*0.82*cos(i)-1.6855*0.5735*sin(i)+4)+width/2;
        p.y=(int)factor*(+1.065*0.5735*cos(i)+1.6855*0.82*sin(i)+2.9)+height/2;
        putpixel(p,color);
    }

}


void main()
{
    img = malloc(width*height*channel);
    for(int i = 0; i<width*height*channel ; i++)
	    img[i] = 255;
    //axis();
    head();
    stbi_write_jpg("mickey.jpg",width,height,channel,img,100);
    free(img);
}
