from graphics import *
from time import sleep
winX = 500
winY = 500
coordX = 500
coordY = 500
bound_color = "Red"
fill_color = "Blue"
win = GraphWin("", winX, winY)
win.setCoords(0, 0, coordX, coordY)
def get_color(x, y):
    pix = 'null'
    car = Circle(Point(x, y), 0.5)
    car.setOutline("White")
    car.draw(win)
    center = car.getCenter()
    overlapping = win.find_overlapping(center.x, center.y, center.x, center.y)
    if overlapping:
        pix = win.itemcget(overlapping[0], "fill")
    car.undraw()    
    return pix
def bound_fill(x, y, bound_color, fill_color):
    current_pixel = get_color(x, y)
    print(x, " ", y, " ", current_pixel)
    if ((current_pixel != bound_color) or (current_pixel != fill_color)):
        win.plot(x, y, fill_color)
        bound_fill(x+1, y, bound_color, fill_color)
        bound_fill(x, y+1, bound_color, fill_color)
        bound_fill(x-1, y, bound_color, fill_color)
        bound_fill(x, y-1, bound_color, fill_color)
Poly = Polygon(Point(100, 100), Point(300, 100), Point(300, 200), Point(100, 200))
Poly.setOutline(bound_color)
Poly.setWidth(1)
Poly.draw(win)
x = 200
y = 150
bound_fill(x, y, bound_color, fill_color)
win.getMouse()
win.close()