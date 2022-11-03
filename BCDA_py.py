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

def circleBres(xc,yc,r):
    x,y = 0,r
    d = 3 - 2 * r
    drawCircle(xc, yc, x, y)
    while (y >= x):
        x+=1
        if (d > 0):
            y-=1
            d = d + 4 * (x - y) + 10

        else:
            d = d + 4 * x + 6
        drawCircle(xc, yc, x, y)

if __name__=='__main__':
    xc,yc= list(map(int,input("\n\nEnter x and y coordinate of center of circle: ").split()))
    r=int(input("Enter radius of circle: "))
    circleBres(xc,yc,r)

    win.getMouse() # pause for click in window
    win.close()