from pickle import TRUE
from graphics import *


win = GraphWin("DDLA", 600, 600)

def DDA(x1,y1,x2,y2):

    dx = (x2-x1)
    dy = (y2-y1)
    x,y = round(x1),round(y1)
    xend = round(x2)
    x_decreasing = False 
      
    
    steps = abs(dx) if (abs(dx)>abs(dy)) else abs(dy) 

    x_inc = dx/steps
    y_inc = dy/steps 

    if(x_inc<0):   #if x2 is greater than x1, ix_inc will be auto negative and keep on decreasing
     x_decreasing = TRUE

    print('\nx= %s, y= %s' %(x,y))
    Point(round(x),round(y)).draw(win)
    while True:
        x = x + x_inc
        y = y + y_inc
        print('\nx= %s, y= %s' %(round(x),round(y)))
        Point(round(x),round(y)).draw(win)
        if((x_decreasing == False and x>=xend) or (x_decreasing == True and x<=xend)):
            break

   
   
x1,y1= list(map(int,input("Enter x1 and y1 coordinate: ").split()))
x2,y2= list(map(int,input("Enter x2 and y2 coordinate: ").split()))

DDA(x1,y1,x2,y2)
#bresenham(100,100,300,300)


win.getMouse() # pause for click in window
win.close()


"""
   Test Cases

   {(10,10),(30,30)}  simple slope to test incrementing values
   
   {(20,25),(400,60)}  positive slope with 0<m<1, i.e. dx>dy

   {(20,25),(60,400)}  positive slope with m>=1, i.e. dy>dx

   {(20,400),(100,20)}  negative slope with dy>dx

   {(20,100),(400,20)}  negative slope with dx>dy


"""