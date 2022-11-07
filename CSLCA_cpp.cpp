
#include <graphics.h>
#include <math.h>
#include <iostream>
#include <conio.h>

using namespace std;

float xwmin,xwmax,ywmin,ywmax;
class P
 {
   public:
       float x=0;
       float y=0;
       int code[4]={0};
 };

void drawWindow();
void drawLine(P,P);
void setcode(P&);
int checkVisibility(P,P);
P clippingPoint(P,P);


int main()
 {
   int gd= DETECT,gm;
   initgraph(&gd,&gm,"c:\\turboc3\\bgi");

   int vis_code=0;
   P p1= P();
   P p2= P();
   P p3= P();
   P p4= P();

   cout<<"\nEnter x(min) and y(min) (top left) corner of clipping window: ";
   cin>>xwmin>>ywmin;

   cout<<"\nEnter x(max) and y(max) (bottom right) corner of clipping window: ";
   cin>>xwmax>>ywmax;

   drawWindow();

   cout<<"\nEnter x and y coordinate for starting point of line: ";
   cin>>p1.x>>p1.y;

   cout<<"\nEnter x and y coordinate for end point of line: ";
   cin>>p2.x>>p2.y;

   drawLine(p1,p2);

   setcode(p1);
   setcode(p2);

   cout<<"\nBitcode of Point P1 is: ";
   for(int i=0;i<4;++i)
    cout<<p1.code[i];


   cout<<"\nBitcode of Point P2 is: ";
   for(int i=0;i<4;++i)
    cout<<p2.code[i];

   vis_code = checkVisibility(p1,p2);

   switch(vis_code)
    {
      case 0: cout<<"\nLine is completely inside the clipping window!";
              cout<<"\nCoordinates of visible line: (" <<p1.x <<"," <<p1.y <<"),(" <<p2.x <<"," <<p2.y <<")";
              break;

      case 1: cout<<"\nLine is completely outside the clipping window!";
              break;

      case 2: cout<<"\nLine is partially clipped with 1 point inside the clipping window!";
              p3= clippingPoint(p1,p2);
              p4= clippingPoint(p2,p1);
              setcolor(YELLOW);
              drawLine(p3,p4);
              cout<<"\nCoordinates of visible line: (" <<p3.x <<"," <<p3.y <<"),(" <<p4.x <<"," <<p4.y <<")";
              break;


      case 3: cout<<"\nLine is partially clipped with both points outside the clipping window!";
              p3= clippingPoint(p1,p2);
              p4= clippingPoint(p2,p1);
              setcolor(YELLOW);
              drawLine(p3,p4);
              cout<<"\nCoordinates of visible line: (" <<p3.x <<"," <<p3.y <<"),(" <<p4.x <<"," <<p4.y <<")";
              break;

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

void drawLine(P p1,P p2)
 {
   line(p1.x,p1.y,p2.x,p2.y);
 }

 void setcode(P &p)
  {
     if(p.y < ywmin)
        p.code[0] = 1;

    else
        p.code[0] = 0;


    if(p.y > ywmax)
        p.code[1] = 1;

    else
        p.code[1] = 0;



    if(p.x > xwmax)
        p.code[2] = 1;

    else
        p.code[2] = 0;


    if(p.x < xwmin)
        p.code[3] = 1;

    else
        p.code[3] = 0;
  }


int checkVisibility(P p1, P p2)
 {
     int flag=0;

     for(int i=0;i<4;++i)
      {
        if(p1.code[i]!=0 || p2.code[i]!=0)
         {
           flag=1;
           break;
         }
      }

      if(flag==0)
        return 0;


      flag=0;


      for(int i=0;i<4;++i)
       {
         if(p1.code[i]==1 && p2.code[i]==1)
          {
            flag=1;
            break;
          }
       }

       if(flag==1)
        return 1;

       flag=0;

       for(int i=0;i<4;++i)
        {
          if(p1.code[i]!=0)
           {
             flag=1;
             break;
           }
        }

        if(flag==0)
            return 2;

        flag=0;
         for(int i=0;i<4;++i)
         {
          if(p2.code[i]!=0)
           {
             flag=1;
             break;
            }
         }

        if(flag==0)
            return 2;

        return 3;

 }


P clippingPoint(P p1, P p2)
  {
    P temp = P();
    float x,y,m,k;


    if(p1.code[3]==1)
        x = xwmin;


    if(p1.code[2]==1)
        x =xwmax;

    if(p1.code[3]==1 or p1.code[2]==1)
      {
        m=(float)(p2.y-p1.y)/(p2.x-p1.x);
        k=(p1.y+(m*(x-p1.x)));
        temp.y=k;
        temp.x=x;
      }


    if(temp.y<=350 and temp.y>=100)
        return (temp);


    if(p1.code[0]==1)
        y = ywmin;


    if(p1.code[1]==1)
        y =ywmax;


    if(p1.code[0]==1 or p1.code[1]==1)
     {
        m=(float)(p2.y-p1.y)/(p2.x-p1.x);
        k=(float)(p1.x+(float)(y-p1.y)/m);
        temp.x=k;
        temp.y=y;
        return temp;
      }

    else
        return p1;

  }
