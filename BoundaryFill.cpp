#include<iostream>
#include<graphics.h>
//#include<dos.h>
using namespace std;

void makePolygon(int points[][2], int n); //for array of points, each point having [2] coordinates
void boundaryFill(int x, int y, int bdcolor, int fillcolor);


int main()
{

    int gd=DETECT,gm;
    initgraph(&gd,&gm,"c:\\turboc3\\bgi");
    int n=0,bdcolor=0,fillcolor=0;
    int points[12][2] ={0};
    int xm=0,ym=0,xin=0,yin=0;


    cout<<"\nEnter number of points in the polygon(max 12): ";
    cin>>n;

    for(int i=0; i<n;++i)
     {
       cout <<"\nEnter polygon coordinate x and y for Point P" <<(i+1) <<": ";
       for(int j=0;j<2;++j)
        {
          cin>>points[i][j];
        }
     }

     cout<<"\n\nEnter integer color code for boundary: ";
     cin>>bdcolor;
     setcolor(bdcolor);
     cout<<"\nEnter integer color code for filling: ";
     cin>>fillcolor;
     cleardevice();
     makePolygon(points,n);

     xm=(points[0][0]+points[1][0])/2;
     ym=(points[0][1]+points[1][1])/2;
     xin=(xm+points[2][0])/2;
     yin=(ym+points[2][1])/2;


     boundaryFill(xin,yin,bdcolor,fillcolor);

     getch();
     return 0;
}


void makePolygon(int points[][2], int n)
 {
    int i;
    for(i=0;i<n-1;i++)
      {
        line(points[i][0],points[i][1],points[i+1][0],points[i+1][1]);
      }
    line(points[n-1][0],points[n-1][1],points[0][0],points[0][1]);
 }


void boundaryFill(int x,int y,int bdcolor,int fillcolor)
{

    if(getpixel(x,y)!=bdcolor && getpixel(x,y)!=fillcolor)
    {

        putpixel(x,y,fillcolor);

        boundaryFill(x+1,y,bdcolor,fillcolor);
        boundaryFill(x,y+1,bdcolor,fillcolor);
        boundaryFill(x-1,y,bdcolor,fillcolor);
        boundaryFill(x,y-1,bdcolor,fillcolor);

    }


}



/* Test run



        n=7
        points:  {365,325, 400,290, 450,290, 485,325, 450,360, 400,360, 365,325};
        bdcolor:  4  (RED)
        fillcolor: 14 (YELLOW)



*/















