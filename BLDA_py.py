from graphics import *


win = GraphWin("BLDA", 600, 600)


def bresenham(x1,y1,x2,y2):
    if(x2<x1):                #so that we start from left side of plane and dont hv to care for subtract operation
        x1,x2 = x2,x1
        y1,y2 = y2,y1  
        
    dx = x2-x1
    dy = y2-y1
    abdx = abs(dx)
    abdy = abs(dy)
    slope_negative = False 

    Point(x1,y1).draw(win) 
   
    print('x= %s, y= %s' %(x1,y1))
    if(y1>y2): #negative slope
      slope_negative = True
      y1 = -1*y1
      y2 = -1*y2    #creating mirror image across x axis, applying BLDA and reflecting back to original  
    
  
    
    
    if (abdx>abdy):   # 0<m<1
            D = 2*abdy - abdx
            #Point(x1,y1).draw(win) 
            y = y1
            for x in range(x1+1,x2+1):  #iterates from x1+1 to x2 both inclusive (x1, y1 already scanned above)
                if D > 0:
                    y += 1
                    if(slope_negative==True):
                        Point(x,-1*y).draw(win)
                        print('\nx= %s, y= %s' %(x,-1*y))
                    else:
                        Point(x,y).draw(win)
                        print('\nx= %s, y= %s' %(x,y))  
                    D += (2*abdy-2*abdx)
               
               
                else:
                    if(slope_negative==True):
                        Point(x,-1*y).draw(win)
                        print('\nx= %s, y= %s' %(x,-1*y)) 
                    else:
                        Point(x,y).draw(win)
                        print('\nx= %s, y= %s' %(x,y)) 
                    D += 2*abdy


    else:      # m>=1
            D = 2*abdx - abdy
           # Point(x1,y1).draw(win) 
            x = x1
            for y in range(y1+1,y2+1):  #iterates from x1+1 to x2 both inclusive (x1, y1 already scanned above)
                if D > 0:
                    x += 1
                    if(slope_negative==True):
                        Point(x,-1*y).draw(win)
                        print('\nx= %s, y= %s' %(x,-1*y))
                    else:
                        Point(x,y).draw(win)
                        print('\nx= %s, y= %s' %(x,y))  
                    D += (2*abdx-2*abdy)


                else:
                    if(slope_negative==True):
                        Point(x,-1*y).draw(win) 
                        print('\nx= %s, y= %s' %(x,-1*y))
                    else:
                        Point(x,y).draw(win) 
                        print('\nx= %s, y= %s' %(x,y))
                    D += 2*abdx

x1,y1= list(map(int,input("Enter x1 and y1 coordinate: ").split()))
x2,y2= list(map(int,input("Enter x2 and y2 coordinate: ").split()))

bresenham(x1,y1,x2,y2)
#bresenham(100,100,300,300)


win.getMouse() # pause for click in window
win.close()


"""
   Test Cases

   {(10,10),(30,30)}  simple slope to test incrementing values

   {(30,30),(10,10)}  when x2,y2 is entered first, picking the lower x and evaluating
   
   {(20,25),(400,60)}  positive slope with 0<m<1, i.e. dx>dy

   {(20,25),(60,400)}  positive slope with m>=1, i.e. dy>dx

   {(20,400),(100,20)}  negative slope with dy>dx

   {(20,100),(400,20)}  negative slope with dx>dy


"""