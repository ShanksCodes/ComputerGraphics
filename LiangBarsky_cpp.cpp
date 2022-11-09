
#include <graphics.h>
#include <math.h>
#include <iostream>
#include <conio.h>

using namespace std;

float xwmin,xwmax,ywmin,ywmax;


void drawWindow();


int main()
 {
   int gd= DETECT,gm;
   initgraph(&gd,&gm,"c:\\turboc3\\bgi");
   float t1,t2,temp;
   float p[4]={0.0};
   float q[4]={0.0};
   float x1,x2,y1,y2;
   float xx1,xx2,yy1,yy2;
   float dx,dy;
   int flag=0;


   cout<<"\nEnter x(min) and y(min) (top left) corner of clipping window: ";
   cin>>xwmin>>ywmin;

   cout<<"\nEnter x(max) and y(max) (bottom right) corner of clipping window: ";
   cin>>xwmax>>ywmax;

   drawWindow();

   cout<<"\nEnter x and y coordinate for starting point of line: ";
   cin>>x1>>y1;

   cout<<"\nEnter x and y coordinate for end point of line: ";
   cin>>x2>>y2;

   line(x1,y1,x2,y2);

   dx=x2-x1;
   dy=y2-y1;

    p[0]= -1 *dx;
    p[1]= dx;
    p[2]= -1 *dy;
    p[3]= dy;

    q[0]= x1-xwmin;
    q[1]= xwmax-x1;
    q[2]= y1-ywmin;
    q[3]= ywmax-y1;

    for(int i=0;i<4;++i)
     {
       if(p[i]==0)
        {
          cout<<"\nLine is parallel to clipping window!";
          flag=1;


        if(q[i]>=0)
         {
           if(i<2)
            {
              if(y1<ywmin)
               {
                 y1=ywmin;
               }
              if(y2>ywmax)
               {
                  y2=ywmax;
               }
              drawWindow();
              cout<<"\nCoordinates of visible line: (" <<x1 <<"," <<y1 <<"),(" <<x2 <<"," <<y2 <<")";
              setcolor(YELLOW);
              line(x1,y1,x2,y2);
            }

            if(i>1)
             {
               if(x1<xwmin)
                {
                  x1=xwmin;
                }
               if(x2>xwmax)
                {
                  x2=xwmax;
                }
               drawWindow();
               cout<<"\nCoordinates of visible line: (" <<x1 <<"," <<y1 <<"),(" <<x2 <<"," <<y2 <<")";
               setcolor(YELLOW);
               line(x1,y1,x2,y2);
             }
         }}
     }

    t1=0;
    t2=1;
    for(int i=0;i<4;++i)
     {
       if(flag==1)
        break;
       temp=q[i]/p[i];
       if(p[i]<0)
        {
          if(t1<=temp)
           {
             t1=temp;
           }
        }
       else
           if(t2>temp)
             {
               t2=temp;
             }
      }

      if(t1<t2 && (flag==0))
       {
        xx1 = x1 + t1*p[1];
        xx2 = x1 + t2*p[1];
        yy1 = y1 + t1*p[3];
        yy2 = y1 + t2*p[3];
        drawWindow();
        cout<<"\nCoordinates of visible line: (" <<xx1 <<"," <<yy1 <<"),(" <<xx2 <<"," <<yy2 <<")";
        setcolor(YELLOW);
        line(xx1,yy1,xx2,yy2);
       }

   getch();
   return 0;
 }


 void drawWindow()
  {
    line(xwmin,ywmin,xwmax,ywmin);
    line(xwmax,ywmin,xwmax,ywmax);
    line(xwmax,ywmax,xwmin,ywmax);
    line(xwmin,ywmax,xwmin,ywmin);
  }





