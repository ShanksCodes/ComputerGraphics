from graphics import *


win = GraphWin("BCDA", 600, 600)

def drawEllipse(xy,yc,x,y):

    Point(xc+x, yc+y).draw(win)
    Point(xc-x, yc+y).draw(win)
    Point(xc+x, yc-y).draw(win)
    Point(xc-x, yc-y).draw(win)


def midpointEllipse(rx,ry,xc,xy):
    x,y = 0,ry
    # Initial decision parameter of region 1
    drawEllipse(xc,yc,x,y)

    d1 = ((ry * ry) - (rx * rx * ry) +
                      (0.25 * rx * rx))
    
    
    

    while((2 * ry * ry * x)<=(2 * rx * rx * y)):
        x=x+1

        if(d1<=0):
            d1=d1+(2.0*ry*ry*x)+(ry*ry)
        else:
            y=y-1
            d1=d1+(2.0*ry*ry*x)+(ry*ry)-(2*rx*rx*y)

        drawEllipse(xc,yc,x,y)
        x=-1*x
        drawEllipse(xc,yc,x,y)
        x=-1*x



    x=rx
    y=0
    drawEllipse(xc,yc,x,y)
    d2 = (rx*rx)+2*(ry*ry*rx)+(ry*ry*0.25)
    

    while((2 * ry * ry * x)>(2 * rx * rx * y)):
        y=y+1

        if(d2>0):
            d2=d2-(2.0*rx*rx*y)+(rx*rx)
        else:
            x=x-1
            d2=d2+(2.0*ry*ry*x)+(rx*rx)-(2*rx*rx*y)
            #d2= d2+(2.0*rx*rx*y)+(ry*ry)-(2*rx*rx*y)

        drawEllipse(xc,yc,x,y)
        y=-1*y
        drawEllipse(xc,yc,x,y)
        y=-1*y


    """  drawEllipse(xc, yc, x, y)
    while (y >= x):
        x+=1
        if (d > 0):
            y-=1
            d = d + 4 * (x - y) + 10

        else:
            d = d + 4 * x + 6
        drawEllipse(xc, yc, x, y)"""

if __name__=='__main__':
    xc,yc= list(map(int,input("\n\nEnter x and y coordinate of center of ellipse: ").split()))
    rx,ry=list(map(int,input("Enter major and minor radius of ellipse respectively: ").split())) #semi major and semi minor axis respecitvely
    midpointEllipse(rx,ry,xc,yc)

    win.getMouse() # pause for click in window
    win.close()



    """
    
    Test Case:

    Center: (250,250)

    X axis length/major axis/rx/a: 200
    Y axis length/minor axis/ry/b: 80




    """