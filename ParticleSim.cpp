#include <iostream>
#include <string>
#include <cmath>


class Particle
{
private:
    double xpos;
    double ypos;
    double radius;
    double mass;
    double vel;
    double momentum;
    double angle; //traveling angle wrt the origin (bottom left corner for now) - this will require transforming

public:
    Particle(double radius, double mass, double xpos=0.0, double ypos=0.0, double vel=0.0)
    {
        this->xpos = xpos;
        this->ypos = ypos;
        this->vel = vel;
        this->mass = mass;
        this->radius = radius;
    }

    void setXpos(double newPos)
    {
        xpos = newPos;
    }

    void setYpos(double newPos)
    {
        ypos = newPos;
    }

    void setVel(double newVel)
    {
        vel = newVel;
    }

    double getXpos()
    {
        return xpos;
    }

    double getYpos()
    {
        return ypos;
    }

    double getVel()
    {
        return vel;
    }

    double getRadius()
    {
        return radius;
    }

};


//not currently used, may be used later for more complex box geometries
/*
//Side struct used to store x,y coord for wall, floor, ceiling of the box
struct Side
{
    int xpos, ypos;
    Side(int xpos, int ypos)
    {
        this->xpos = xpos;
        this->ypos = ypos;
    }
};



//Simulation box with 0,0 being the bottom left corner
class Box
{

private:
    int height;
    int width;
    int top, bottom, left, right;
    Side leftWall, rightWall, floor, ceiling;


public:

    Box(int size)
    {
        height = size;
        width = size;
        leftWall = Side(xpos=0,ypos=size);
        RightWall = Side(xpos=size,ypos=size);
        floor = Side(xpos=size,ypos=0);
        ceiling = Side(xpos=0,ypos=size);

    }

};

*/

//Starting with a simple 2D box with (0,0) being the bottom left corner
class Box
{

private:
    int height;
    int width;
    int leftWall=0, rightWall, floor=0, ceiling;


public:

    Box(int size)
    {
        height = size;
        width = size;
        rightWall = size;
        ceiling = size;

    }

};


/*
class EventHandler
{

};
*/