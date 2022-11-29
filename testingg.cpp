#include <graphics.h>
#include <iostream>
#include <math.h>
#include <dos.h>
using namespace std;
int main( )
{

//int a=11, b=22, c;

      //  c = a + b + a++ + b++ + ++a + ++b;
       //  cout<<c;

       int x=5,y=5,z;
       x=++x;y=--y;

       z=x+++x;
       cout<<z;

}
