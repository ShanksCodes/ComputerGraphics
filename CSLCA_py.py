from tempfile import tempdir
from graphics import *
import numpy as np

#win = GraphWin("BCDA", 600, 600)
#win2 = GraphWin("CSLCA-Clip", 600, 600)

class P:
    def __init__(self):
        self.code = np.empty(4,dtype=np.int64)
        self.x = 0
        self.y = 0




def drawWindow(xwmin,ywmin,xwmax,ywmax,win):
    Line(Point(xwmin,ywmin),Point(xwmax,ywmin)).draw(win)
    Line(Point(xwmax,ywmin),Point(xwmax,ywmax)).draw(win)
    Line(Point(xwmax,ywmax),Point(xwmin,ywmax)).draw(win)
    Line(Point(xwmin,ywmax),Point(xwmin,ywmin)).draw(win)

def drawLine(p1,p2,win):
    Line(Point(p1.x,p1.y),Point(p2.x,p2.y)).draw(win)

def setCode(p):
    

    if(p.y < ywmin):
        p.code[0] = 1
        
    else:
        p.code[0] = 0
        

    if(p.y > ywmax):
        p.code[1] = 1
        
    else:
        p.code[1] = 0
        


    if(p.x > xwmax):
        p.code[2] = 1
        
    else:
        p.code[2] = 0
        

    if(p.x < xwmin):
        p.code[3] = 1
       
    else:
        p.code[3] = 0
        

  
def checkVisibility(p1,p2):
    flag = 0
    for x,y in zip(p1.code,p2.code):
        if(x!=0 or y!=0):   
            flag = 1 
            break 
    if(flag==0):     #if both bitcodes comprise of 0 only, then line is completely visible, case 0
        return 0

    flag = 0  #reset flag

    for x,y in zip(p1.code,p2.code):
        if(x==y and (x==1)):
            flag = 1
            break
    if(flag==1):    # if the bitcodes share a common 1 at any bit position, they are completely invisible
        return 1
    
    #print(np.all(p1.code), np.all(p2.code))
    if(all(p1.code==0) or all(p2.code==0)):    # partially visible with 1 point inside the 
        return 2
    else:    
        return 3                   #partially visible with both points outside window


def clippingPoint(p1, p2,xwmin,ywmin,xwmax,ywmax):
    temp = P()
    x=0
    y=0
    m = 0.0
    k = 0.0
    if(p1.code[3]==1):
        x = xwmin 
    if(p1.code[2]==1):
        x =xwmax
    if(p1.code[3]==1 or p1.code[2]==1):
        m=(float)(p2.y-p1.y)/(p2.x-p1.x)
        k=(p1.y+(m*(x-p1.x)))
        temp.y=k
        temp.x=x   
        if(temp.y<=350 and temp.y>=100):
          return (temp)


    if(p1.code[0]==1):
        y = ywmin 
    if(p1.code[1]==1):
        y =ywmax
    if(p1.code[0]==1 or p1.code[1]==1):
        m=(float)(p2.y-p1.y)/(p2.x-p1.x)
        k=(float)(p1.x+(float)(y-p1.y)/m)
        temp.x=k
        temp.y=y; 
        return temp

    else:
        return p1           

        

if __name__=='__main__':
    
    p1 = P()
    p2 = P()
    p3 = P()
    p4 = P() 
    win = GraphWin("BCDA", 600, 600)
    
    xwmin,ywmin= list(map(int,input("\nEnter x(min) and y(min) of clipping window: ").split()))
    xwmax,ywmax= list(map(int,input("Enter x(max) and y(max) of clipping window: ").split()))
    drawWindow(xwmin,ywmin,xwmax,ywmax,win)
    
    p1.x, p1.y= list(map(int,input("\nEnter x1 and y1 coordinate for startpoint of line: ").split()))
    p2.x, p2.y= list(map(int,input("Enter x2 and y2 coordinate for endpoint of line: ").split()))

    drawLine(p1,p2,win)
    
    setCode(p1)
    setCode(p2)

    print("\nBitcode of Point P1: ", p1.code)
    print("\nBitcode of Point P2: ", p2.code,"\n")

    vis_code = checkVisibility(p1,p2)

    if(vis_code==0):
        print("Line completely inside the clipping window already!")
        print("Coordinates of visible line: (",p1.x, ",",p1.y,") and (",p2.x,",",p2.y,")" )

    if(vis_code==1):
        print("Line is completely outside the clipping window!")

    if(vis_code==2):
        print("Line is partially clipped with one point inside the clipping window")
        p3 = clippingPoint(p1,p2,xwmin,ywmin,xwmax,ywmax)
        p4 = clippingPoint(p2,p1,xwmin,ywmin,xwmax,ywmax)
        win2 = GraphWin("Post-Clipping", 600, 600)
        drawWindow(xwmin,ywmin,xwmax,ywmax,win2)
        drawLine(p3,p4,win2)
        print("Coordinates of visible line: (",p3.x, ",",p3.y,") and (",p4.x,",",p4.y,")" )


    if(vis_code==3):
        print("Line is partially clipped with both endpoints outside the clipping window!")
        p3 = clippingPoint(p1,p2,xwmin,ywmin,xwmax,ywmax)
        p4 = clippingPoint(p2,p1,xwmin,ywmin,xwmax,ywmax)
        win2 = GraphWin("Post-Clipping", 600, 600)
        drawWindow(xwmin,ywmin,xwmax,ywmax,win2)
        drawLine(p3,p4,win2)
        print("Coordinates of visible line: (",p3.x, ",",p3.y,") and (",p4.x,",",p4.y,")" )

        
        
            
    

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