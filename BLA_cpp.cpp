#include <graphics.h>
#include <math.h>
#include <iostream>
#include <conio.h>

using namespace std;

void bresenham(float,float,float,float,float,float);

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
   bresenham(x1,y1,x2,y2,xo,yo);

   getch();
   return 0;
 }



 void bresenham(float x1,float y1, float x2, float y2,float xo,float yo)
   {
     float temp=0;
     float dx=0,dy=0;
     float x=0,y=0;
     if(x2<x1)
      {
        temp=x1;
        x1=x2;
        x2=temp;

        temp=y1;
        y1=y2;
        y2=temp;
      }


      dx=x2-x1;
      dy=y2-y1;
      float abdx=abs(dx);
      float abdy=abs(dy);
      float D=0.0;
      int slope_negative=0;
      line(0,getmaxy()/2,getmaxx(),getmaxy()/2);    //to create a cartesian plane on the acreen
      line(getmaxx()/2,0,getmaxx()/2,getmaxy());
      putpixel(xo+x1,yo-y1,RED);
      cout<<"\nx: " <<x1 <<" y:" <<y1;

      if(y1>y2)
       {
         slope_negative=1;
         y1= -1*y1;
         y2=-1*y2;
       }


      if(abdx>abdy)
       {
         D= 2*abdy-abdx;
         y=y1;

         for (x=x1+1;x<=x2;++x)
          {
            if(D>0)
             {
               ++y;
               if(slope_negative==1)
                {
                  putpixel(xo+x,(yo+y),RED);
                  cout<<"\nx: " <<x <<" y:" <<-1*y;
                }

               else
                {
                  putpixel(xo+x,yo-y,RED);
                  cout<<"\nx: " <<x <<" y:" <<y;
                }
               D+=2*abdy-2*abdx;

             }


              else
               {

               if(slope_negative==1)
                {
                  putpixel(xo+x,-1*(yo+y),RED);
                  cout<<"\nx: " <<x <<" y:" <<-1*y;
                }

               else
                {
                  putpixel(xo+x,yo-y,RED);
                  cout<<"\nx: " <<x <<" y:" <<y;
                }
               D+=2*abdy;

               }
           }

         }




      else
       {
         D= 2*abdx-abdy;
         x=x1;

         for (y=y1+1;y<=y2;++y)
          {
            if(D>0)
             {
               ++x;
               if(slope_negative==1)
                {
                  putpixel(xo+x,(yo+y),RED);
                  cout<<"\nx: " <<x <<" y:" <<-1*y;
                }

               else
                {
                  putpixel(xo+x,yo-y,RED);
                  cout<<"\nx: " <<x <<" y:" <<y;
                }
               D+=2*abdx-2*abdy;

             }


              else
               {

               if(slope_negative==1)
                {
                  putpixel(xo+x,(yo+y),RED);
                  cout<<"\nx: " <<x <<" y:" <<-1*y;
                }

               else
                {
                  putpixel(xo+x,yo-y,RED);
                  cout<<"\nx: " <<x <<" y:" <<y;
                }
               D+=2*abdx;

               }
           }

         }



   }

