from tempfile import tempdir
from tkinter import E
from graphics import *
import numpy as np

#win = GraphWin("BCDA", 600, 600)
#win2 = GraphWin("CSLCA-Clip", 600, 600)


def drawWindow(xwmin,ywmin,xwmax,ywmax,win):
    Line(Point(xwmin,ywmin),Point(xwmax,ywmin)).draw(win)
    Line(Point(xwmax,ywmin),Point(xwmax,ywmax)).draw(win)
    Line(Point(xwmax,ywmax),Point(xwmin,ywmax)).draw(win)
    Line(Point(xwmin,ywmax),Point(xwmin,ywmin)).draw(win)


    
        

if __name__=='__main__':
  
    win = GraphWin("LBLCA", 600, 600)
    win2 = GraphWin("Post Clipping", 600, 600)
    t1,t2,temp =0.0,0.0,0.0
    p = np.empty(4, dtype=np.float64)
    q = np.empty(4, dtype=np.float64)
    flag =0


  
    xwmin,ywmin= list(map(int,input("\nEnter x(min) and y(min) of clipping window: ").split()))
    xwmax,ywmax= list(map(int,input("Enter x(max) and y(max) of clipping window: ").split()))
    drawWindow(xwmin,ywmin,xwmax,ywmax,win)
    
    x1, y1= list(map(int,input("\nEnter x1 and y1 coordinate for startpoint of line: ").split()))
    x2, y2= list(map(int,input("Enter x2 and y2 coordinate for endpoint of line: ").split()))
    Line(Point(x1,y1),Point(x2,y2)).draw(win)
    
    dx = x2-x1
    dy = y2-y1

    p[0]= -1 *dx
    p[1]= dx
    p[2]= -1 *dy
    p[3]= dy 

    q[0]= x1-xwmin
    q[1]= xwmax-x1
    q[2]= y1-ywmin
    q[3]= ywmax-y1

    for i in range(p.shape[0]):
        if(p[i]==0):
            print("Line is parallel to clipping window")
            flag = 1
            if(q[i]>=0):  #line not outside
                if(i<2):  #find if line is parallel to x axis or y axis of window and assign point accordingly
                    if(y1<ywmin):
                        y1 = ywmin
                    if(y2>ywmax):
                        y2 = ywmax
                    drawWindow(xwmin,ywmin,xwmax,ywmax,win2)    
                    print("Coordinates of visible line: (",x1, ",",y1,") and (",x2,",",y2,")" )
                    Line(Point(x1,y1),Point(x2,y2)).draw(win2) 
       
                if(i>1):
                    if(x1<xwmin):
                        x1 = xwmin
                    if(x2>xwmax):
                        x2 = xwmax
                    drawWindow(xwmin,ywmin,xwmax,ywmax,win2) 
                    print("Coordinates of visible line: (",x1, ",",y1,") and (",x2,",",y2,")" )   
                    Line(Point(x1,y1),Point(x2,y2)).draw(win2) 

    t1,t2= 0,1
    for i in range(p.shape[0]):
        if(flag==1):  #p[i] is 0
            break
        temp = q[i]/p[i]
        if(p[i]<0):
            if(t1<=temp):
                t1=temp    #find max between 0 and q[i]/p[i] to allocate to t1
        else:
            if(t2>temp): #find min between 1 and q[i]/p[i] to allocate to t2, when p[i]>=0
                t2=temp

    if(t1<t2 and (flag==0)):   #flag 0 means line is not parallel but clipping the window at some point(s)
        xx1 = x1 + t1*p[1]
        xx2 = x1 + t2*p[1]
        yy1 = y1 + t1*p[3]
        yy2 = y1 + t2*p[3]
        drawWindow(xwmin,ywmin,xwmax,ywmax,win2)
        print("Coordinates of visible line: (",xx1, ",",yy1,") and (",xx2,",",yy2,")" )
        Line(Point(xx1,yy1),Point(xx2,yy2)).draw(win2)

            
    win.getMouse() # pause for click in window
    win.close()



    """
    top left ( xwmin, ywmin): (150,100)
    bottom right (xwmax,ywmax): (450,350)

    test point: (100,200), (300,450) for both points outside and partial clipping
    test point:  (160,160), (180,180) for both points inside
    test point:  (100,200), (250,250) for one point inside
    test point:  (100,200), (100,50) for both points outside and full clipping




    """