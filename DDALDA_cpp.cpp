#include <graphics.h>
#include <math.h>
#include <iostream>
#include <conio.h>

using namespace std;

void DDA(float,float,float,float,float,float);

int main()
 {
   int gd= DETECT,gm;

   initgraph(&gd,&gm,"c:\\turboc3\\bgi");
   float xo = getmaxx()/2;
float yo= getmaxy()/2;
   float x1,x2,y1,y2;
   cout <<"\n\nEnter x and y coordinates for Point P1: ";
   cin>>x1>>y1;
   cout <<"\n\nEnter x and y coordinates for Point P2: ";
   cin>>x2>>y2;
   DDA(x1,y1,x2,y2,xo,yo);

   getch();
   return 0;
 }



 void DDA(float x1,float y1, float x2, float y2,float xo,float yo)
   {


     float dx= x2-x1;
     float dy = y2-y1;
     float x = round(x1);
     float y = round(y1);
     float xend= round(x2);
     int x_decreasing = 0;
     float steps=0;

     if(abs(dx)>abs(dy))
        steps=abs(dx);
     else
        steps=abs(dy);
     float x_inc= dx/steps;
     float y_inc= dy/steps;

     if(x_inc<0)
        x_decreasing=1;

    line(0,getmaxy()/2,getmaxx(),getmaxy()/2);    //to create a cartesian plane on the acreen
    line(getmaxx()/2,0,getmaxx()/2,getmaxy());
    cout<< "x:" <<round(x) <<" y:" <<round(y);
    putpixel(round(xo+x),round(yo-y),RED);

    while(1)
    {
      x= x+x_inc;
      y=y+y_inc;

     cout<< "\nx:" <<round(x) <<" y:" <<round(y);
      putpixel(round(xo+x),round(yo-y),RED);

      if((x_decreasing==1 && x<=xend) || (x_decreasing==0 && x>=xend))
         break;

    }


   }
