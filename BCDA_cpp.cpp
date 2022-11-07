#include <graphics.h>
#include <math.h>
#include <iostream>
#include <conio.h>

using namespace std;

void drawCircle(float,float,float,float,float,float);
void bresCircle(float,float,float,float,float);

int main()
 {
   int gd= DETECT,gm;

   initgraph(&gd,&gm,"c:\\turboc3\\bgi");
   float xo = getmaxx()/2;
float yo= getmaxy()/2;
   float xc,yc;
   float r;
   cout <<"\n\nEnter x and y coordinates for center of circle: ";
   cin>>xc>>yc;
   cout <<"\n\nEnter radius of circle ";
   cin>>r;
   bresCircle(xc,yc,r,xo,yo);
   getch();
   return 0;
 }

void drawCircle(float xc,float yc,float x,float y,float xo,float yo)
{

  putpixel(xo+xc+x,yo-yc+y,RED);
  putpixel(xo+xc-x,yo-yc+y,RED);
  putpixel(xo+xc+x,yo-yc-y,RED);
  putpixel(xo+xc-x,yo-yc-y,RED);
  putpixel(xo+xc+y,yo-yc+x,RED);
  putpixel(xo+xc-y,yo-yc+x,RED);
  putpixel(xo+xc+y,yo-yc-x,RED);
  putpixel(xo+xc-y,yo-yc-x,RED);
}



 void bresCircle(float xc, float yc, float r,float xo,float yo)
   {
     float x = 0;
     float y=r;
     float D = 3-2*r;
    line(0,getmaxy()/2,getmaxx(),getmaxy()/2);    //to create a cartesian plane on the acreen
    line(getmaxx()/2,0,getmaxx()/2,getmaxy());
     drawCircle(xc,yc,x,y,xo,yo);

     while(y>=x)
      {
        x++;
        if(D>0)
         {
           y-=1;
           D+=4*x-4*y+10;
         }
        else
          D+=4*x+6;
        drawCircle(xc,yc,x,y,xo,yo);
      }

   }


