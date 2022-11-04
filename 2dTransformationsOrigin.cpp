//#include<stdio.h>
//#include<direct.h>
#include<graphics.h>
#include<math.h>
#include<iostream>
#include<conio.h>
#include<cstdlib>


const int xo=320;       //to make origin at center of the screen
const int yo=240;


void drawpolygon(int points[][2],int n);
void displaypoints(int points[][2],int n);
void translation(int (&points)[10][2],int n);
void rotation(int (&points)[10][2],int n);
void scaling(int (&points)[10][2],int n);

using namespace std;

int main()
{
    int gd=DETECT,gm;
    int points[10][2] ={0};
    int n=0;
    int ch=0;
    char cont='y';

    initgraph(&gd,&gm,"c:\\turboc3\\bgi");

    line(0,getmaxy()/2,getmaxx(),getmaxy()/2);    //to create a cartesian plane on the acreen
    line(getmaxx()/2,0,getmaxx()/2,getmaxy());

    cout<<"Enter number of points in polygon: ";
    cin>>n;

    for(int i=0;i<n;i++)
      {
        cout<<"Enter point P"<<i+1<<": ";
        for(int j=0;j<2;j++)
          {
            cin>>points[i][j];
          }
      }
    drawpolygon(points,n);
    system("cls");

     cout<<"\n\nPoints entered:\n";
     displaypoints(points,n);
    do
      {


        cout<<"\n\n\t\tTransformations:\n";
        cout<<endl<<"1. Translation";
        cout<<endl<<"2. Rotation";
        cout<<endl<<"3. Scaling";
        cout<<endl<<"Enter Choice: ";
        cin>>ch;

        switch(ch)
          {
            case 1:
                    translation(points,n);
                    break;
            case 2:
                    rotation(points,n);
                    break;
            case 3:
                    scaling(points,n);
                    break;
            default:
                    cout<<"Invalid Choice!";
          }
          setcolor(5);
          line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
          line(getmaxx()/2,0,getmaxx()/2,getmaxy());
        cout<<endl<<"Do you want to continue : ";
        cin>>cont;
      }while(cont=='y' || cont=='Y');


    getch();

    return 0;
}



void drawpolygon(int points[][2],int n)
 {

   //to adjust points wrt to new origin instead of default top left
   // xo+p, yo-q will put the point at (p,q) with respect to origin

   for(int i=0;i<n-1;i++)
      {
        line(xo+points[i][0],yo-points[i][1],xo+points[i+1][0],yo-points[i+1][1]);
      }
    line(xo+points[n-1][0],yo-points[n-1][1],xo+points[0][0],yo-points[0][1]);

 }

 void displaypoints(int points[][2],int n)
  {

    for(int i=0;i<n;i++)
      {
        cout<<"Point P"<<i+1<<" : ("<<points[i][0]<<","<<points[i][1]<<")\n";
      }

  }


  void translation(int (&points)[10][2],int n)
  {
    int tx,ty;
    cout<<endl<<"Translation : "<<endl;
    cout<<"Enter distance on x-axis : ";
    cin>>tx;
    cout<<"Enter distance on y axis : ";
    cin>>ty;
    for(int i=0;i<n;i++)
      {
        points[i][0]=points[i][0]+tx;
        points[i][1]=points[i][1]+ty;
      }
    cout<<"\n\nPoints after transformation:\n";
    displaypoints(points,n);
    setcolor(RED);
    drawpolygon(points,n);
  }

  void rotation(int (&points)[10][2],int n)
  {
    int x,y;
    float angle;
    char dir;
    cout<<endl<<"Rotation : "<<endl;
    cout<<"Enter the degree of rotation : ";
    cin>>angle;
    cout<<"Enter direction of rotation( C for clockwise, A for anticlockwise: ";
    cin>>dir;
    angle=(angle*3.1415)/180;  //converting to radian
   // cout<<endl<<cos(angle)<<endl<<sin(angle)<<endl;
    if(dir=='A')
      {
        for(int i=0;i<n;i++)
          {
            x=floor(points[i][0]*cos(angle)-points[i][1]*sin(angle));
            y=floor(points[i][0]*sin(angle)+points[i][1]*cos(angle));
            points[i][0]=x;
            points[i][1]=y;
          }
      }
    else
      {
        for(int i=0;i<n;i++)
          {
            x=floor(points[i][0]*cos(angle)+points[i][1]*sin(angle));
            y=floor(-points[i][0]*sin(angle)+points[i][1]*cos(angle));
            points[i][0]=x;
            points[i][1]=y;
          }
      }
    cout<<"\n\nPoints after transformation:\n";
    displaypoints(points,n);
    setcolor(GREEN);
    drawpolygon(points,n);
  }


  void scaling(int (&points)[10][2],int n)
  {

    float sx,sy;
    cout<<endl<<"Scaling : "<<endl;
    cout<<"Enter scaling factor on x axis : ";
    cin>>sx;
    cout<<"Enter scaling factor on y axis : ";
    cin>>sy;
    for(int i=0;i<n;i++)
      {
        points[i][0]=floor(points[i][0]*sx);
        points[i][1]=floor(points[i][1]*sy);
      }
    cout<<"\n\nPoints after transformation:\n";
    displaypoints(points,n);
    setcolor(YELLOW);
    drawpolygon(points,n);

  }
