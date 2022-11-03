from graphics import *


win = GraphWin("BCDA", 600, 600)

def drawCircle(xc, yc ,x, y):

    Point(xc+x, yc+y).draw(win)
    Point(xc-x, yc+y).draw(win)
    Point(xc+x, yc-y).draw(win)
    Point(xc-x, yc-y).draw(win)
    Point(xc+y, yc+x).draw(win)
    Point(xc-y, yc+x).draw(win)
    Point(xc+y, yc-x).draw(win)
    Point(xc-y, yc-x).draw(win)

def circleMP(xc,yc,r):
    x,y = 0,r
    d = 1-r
    drawCircle(xc, yc, x, y)
    while (y >= x):
        x+=1
        if (d > 0):
            y-=1
            d = d + (2*x-2*y+5)

        else:
            d = d + 2 * x + 3
        drawCircle(xc, yc, x, y)

if __name__=='__main__':
    xc,yc= list(map(int,input("\n\nEnter x and y coordinate of center of circle: ").split()))
    r=int(input("Enter radius of circle: "))
    circleMP(xc,yc,r)

    win.getMouse() # pause for click in window
    win.close()