#include <graphics.h>
#include <math.h>
#include <iostream>
#include <conio.h>

using namespace std;

void drawEllipse(float,float,float,float,float,float);
void ellipse(float,float,float,float,float,float);

int main()
 {
   int gd= DETECT,gm;

   initgraph(&gd,&gm,"c:\\turboc3\\bgi");
   float xo = getmaxx()/2;
float yo= getmaxy()/2;
   float xc,yc;
   float rx,ry;
   cout <<"\n\nEnter x and y coordinates for center of ellipse: ";
   cin>>xc>>yc;
   cout <<"\n\nEnter major and minor axis respectively: ";
   cin>>rx>>ry;
   ellipse(rx,ry,xc,yc,xo,yo);
   getch();
   return 0;
 }

void drawEllipse(float xc,float yc,float x,float y,float xo,float yo)
{

  putpixel(xo+xc+x,yo-yc+y,RED);
  putpixel(xo+xc-x,yo-yc+y,RED);
  putpixel(xo+xc+x,yo-yc-y,RED);
  putpixel(xo+xc-x,yo-yc-y,RED);

}



 void ellipse(float rx, float ry, float xc,float yc,float xo,float yo)
   {
     float x = 0;
     float y=ry;
     drawEllipse(xc,yc,x,y,xo,yo);

     float d1 = ((ry * ry) - (rx * rx * ry) +
                      (0.25 * rx * rx));

    line(0,getmaxy()/2,getmaxx(),getmaxy()/2);    //to create a cartesian plane on the acreen
    line(getmaxx()/2,0,getmaxx()/2,getmaxy());

     while((2 * ry * ry * x)<=(2 * rx * rx * y))
     {

        x=x+1;

        if(d1<=0)
            d1=d1+(2.0*ry*ry*x)+(ry*ry);
        else
        {
            y=y-1;
            d1=d1+(2.0*ry*ry*x)+(ry*ry)-(2*rx*rx*y);
        }

        drawEllipse(xc,yc,x,y,xo,yo);
        x=-1*x;
        drawEllipse(xc,yc,x,y,xo,yo);
        x=-1*x;
     }



    x=rx;
    y=0;
    drawEllipse(xc,yc,x,y,xo,yo);
    float d2 = (rx*rx)+2*(ry*ry*rx)+(ry*ry*0.25);


    while((2 * ry * ry * x)>(2 * rx * rx * y))
     {
        y=y+1;

        if(d2>0)
            d2=d2-(2.0*rx*rx*y)+(rx*rx);
        else
          {
            x=x-1;
            d2=d2+(2.0*ry*ry*x)+(rx*rx)-(2*rx*rx*y);
          }

        drawEllipse(xc,yc,x,y,xo,yo);
        y=-1*y;
        drawEllipse(xc,yc,x,y,xo,yo);
        y=-1*y;

     }
   }




