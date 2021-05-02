/* Data Structures Homework 1
 * Author : Athulya Ganesh(lnuas @ mail.uc.edu)
 * Group members: Anusha Chitranshi(chitraaa@mail.uc.edu) & Abhigyan Acherjee(acherjan@mail.uc.edu)
 * Helpers : TA Madhav Lolla
 *
 */


#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Shape
{
private:
    double w, h;
public:
    Shape(double wi, double he)
    {
        w = wi;
        h = he;
    }
    Shape()
    {
        w = 0;
        h = 0;
    }

    void setW(double a)
    {
        w = a;
    }

    void setH(double a)
    {
        h = a;
    }
    double width()
    {
        return w;
    }

    double height()
    {
        return h;
    }


};



class Loc
{
private:
    double x, y;
public:
    Loc(double x1, double y1)
    {
       x = x1;
       y = y1;
    }
    Loc()
    {
        x = 0;
        y = 0;
    }
    void setX(double a)
    {
        x = a;
    }

    void setY(double b)
    {
        y = b;
    }
    double X()
    {
        return x;
    }
    double Y()
    {
        return y;
    }
};


class Frame
{
private:
    char * frameName;
    Loc location;
    Shape size;
public:
    Frame()
    {
        location.setX(0);
        location.setY(0);
        size.setH(0);
        size.setW(0);
    }
    Frame(char* name, Loc loc, Shape rect)
    {
        frameName = name;
       location = loc;
       size = rect;
    }
    void Resize(Shape newShape)
    {
        size = newShape;
    }
    void MoveTo(Loc newLoc)
    {
        location = newLoc;
    }

    void setCoordLoc(Loc loca)
    {
        location = loca;
    }

    void setCoordShape(Shape s)
    {
        size = s;
    }

    void setName(char * name)
    {
        frameName = name;
    }

    char * getName()
    {
        return frameName;
    }

    Shape getCoordShape()
    {
        return size;
    }
    Loc getCoordLoc()
    {
        return location;
    }
    ~Frame();
};


