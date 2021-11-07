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
pixel Choosecolor(char c)
{
    pixel color;
    if (c=='r' || c=='R'){
        color.r=255;color.b=0;color.g=0;
        return color;
    }
    if (c=='g' || c== 'G'){
        color.r=0;color.b=0;color.g=255;
        return color;
    }
    if (c=='b' || c== 'B'){
        color.r=0;color.b=255;color.g=0;
        return color;
    }    

}

void ellipse(float a, float b,pixel c)
{
    position p;
    for(float i=0;i<2*3.15;i+=0.0001)
    {
        p.x=(int)(a*10*cos(i))+width/2;
        p.y=(int)(b*10*sin(i))+height/2;
        putpixel(p,c);
    }
    for(float i=0;i<2*3.15;i+=0.0001)
    {
        p.x=(int)(a*10*cos(i))+width/2+1;
        p.y=(int)(b*10*sin(i))+height/2+1;
        putpixel(p,c);
    }
}
void parabola(float a,pixel c)
{
    position p;
    for(float i=-350.0;i<350.0;i+=0.0001)
    {
        p.x=(int)(10*i)+width/2;
        p.y=(int)(-a*10*i*i)+height/1.25;
        putpixel(p,c);
    }
    for(float i=-350.0;i<350.0;i+=0.0001)
    {
        p.x=(int)(10*i)+width/2+1;
        p.y=(int)(-a*10*i*i)+height/1.25+1;
        putpixel(p,c);
    }
}
void hyperbola(float a,float b, pixel c)
{
    position p;
    for(float i=0;i<2*3.15;i+=0.0001)
    {
        p.x=(int)(a*10/cos(i))+width/2;
        p.y=(int)(b*10*tan(i))+height/2;
        putpixel(p,c);
    }
    for(float i=0;i<2*3.15;i+=0.0001)
    {
        p.x=(int)(a*10/cos(i))+width/2+1;
        p.y=(int)(b*10*tan(i))+height/2+1;
        putpixel(p,c);
    }
}

int entry()
{
    img=malloc(height*width*channel);
    for(int i = 0; i<width*height*channel ; i++)
	    img[i] = 255;

    int choice;
    printf("What do you want to print?\n\t1)Ellipse\n\t2)Parabola\n\t3)Hyperbola\n\t4)Circle\n\n");    
    scanf("%d",&choice);
    return choice;
    
}

void main()
{
    int choice=entry();
    if(choice==1){
        float a, b;pixel colour;char c;
        printf("Enter the values of 'a' and 'b':");
        fflush(stdin);
        scanf("%f %f",&a,&b);
        printf("What color do you want the ellipse to be?\nEnter 'r' for red, 'g' for green and 'b' for blue:\n");
        fflush(stdin);
        scanf(" %c",&c);
        colour=Choosecolor(c);
        ellipse(a,b,colour);
        stbi_write_jpg("ellipse.jpg",width,height,channel,img,100);

    }
    if(choice==2)
    {   
        float a;char c;pixel colour;
        printf("Enter the coefficient of x squared:");
        scanf("%f",&a);
        printf("What color do you want the ellipse to be?\nEnter 'r' for red, 'g' for green and 'b' for blue:");
        fflush(stdin);
        scanf(" %c",&c);
        colour=Choosecolor(c);
        parabola(a,colour);
        stbi_write_jpg("parabola.jpg",width,height,channel,img,100);

    }
    if(choice==3)
    {
        float a, b;pixel colour;char c;
        printf("Enter the values of 'a' and 'b':");
        fflush(stdin);
        scanf("%f %f",&a,&b);
        printf("What color do you want the hyperbola to be?\nEnter 'r' for red, 'g' for green and 'b' for blue:\n");
        fflush(stdin);
        scanf(" %c",&c);
        colour=Choosecolor(c);
        hyperbola(a,b,colour);
        stbi_write_jpg("hyperbola.jpg",width,height,channel,img,100);
    }
    if(choice==4)
    {
        float a;char c;pixel colour;
        printf("Enter the radius of circle:");
        scanf("%f",&a);
        printf("What color do you want the circle to be?\nEnter 'r' for red, 'g' for green and 'b' for blue:");
        fflush(stdin);
        scanf(" %c",&c);
        colour=Choosecolor(c);
        ellipse(a,a,colour);
        stbi_write_jpg("circle.jpg",width,height,channel,img,100);
    }    
    free(img);
}
