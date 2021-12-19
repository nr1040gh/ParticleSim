#include <iostream>
#include <string>
#include <cmath>


class Particle
{
private:
    double xpos;    //distance units
    double ypos;    //distance units
    double radius;  //distance units
    double mass;    //mass units (not standard)
    double vel;     //distance units / sec
    double ang_v;   //traveling angle wrt the particle in radians
    double vel_x;
    double vel_y;

public:
    Particle(double radius, double mass, double xpos=0.0, double ypos=0.0, double vel=0.0, double ang_v=0.0)
    {
        this->xpos = xpos;
        this->ypos = ypos;
        this->vel = vel;
        this->mass = mass;
        this->radius = radius;
        this->ang_v = ang_v;
        vel_x = vel * cos(ang_v);
        vel_y = vel * sin(ang_v);
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

    void setVel_x(double newVel_x)
    {
        vel_x = newVel_x;
    }

    void setVel_y(double newVel_y)
    {
        vel_y = newVel_y;
    }

    void setAng(double newAng)
    {
        ang_v = newAng;
    }

    void updateAng()
    {
        if (vel_x > 0 and vel_y >= 0)
            ang_v = atan(vel_y / vel_x)
        else if (vel_x <= 0 and vel_y > 0)
            ang_v = atan(vel_x / vel_y) + M_PI_2 // pi/2 in cmath
        else if (vel_x < 0 and vel_y <=0)
            ang_v = atan(vel_y / vel_x) + M_PI
        else if (vel_x >= 0 and vel_y < 0)
            ang_v = atan(vel_x / vel_y) + (3.0 * M_PI_2) // 3pi/2
        else
            ang_v = 0 // if vel_x and vel_y == 0
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

    double getVel_x()
    {
        return vel_x;
    }

    double getVel_y()
    {
        return vel_y;
    }

    double getAng()
    {
        return ang_v;
    }

    double getMass()
    {
        return mass;
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



class EventHandler
{
private:
    double simT;
    double deltaT;


public:
    EventHandler(double simT, double deltaT)
    {
        this->simT = simT;
        this->deltaT = deltaT;
    }

    void resolveParticleCollision(Particle p1, Particle p2)
    {

    }

    //Should break these down into horizontal and vertical walls
    void resolveWallCollision(Particle p1, int wallValue, std::string side)
    {
        switch(side) 
            {
            case "TOP" :
                cout << "Top wall collision!" << endl; 
                p1.setVel_y(p1.getVel_y * -1.0);
                break;
            case "BOTTOM" :
                cout << "Bottom wall collision!" << endl;
                p1.setVel_y(p1.getVel_y * -1.0);
                break;
            case "LEFT" :
                cout << "Left wall collision!" << endl;
                p1.setVel_x(p1.getVel_x * -1.0);
                break;
            case "RIGHT" :
                cout << "Right wall collision!" << endl;
                p1.setVel_x(p1.getVel_x * -1.0);
                break;

            //bad value
            default :
                cout << "Invalid grade" << endl;
            }

        p1.updateAng()


};
