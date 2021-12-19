#include <iostream>
#include <fstream>
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
    double vel_x;   //distance units / sec
    double vel_y;   //distance units / sec

    double leftMost = 

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

    void updatePos(double deltaT)
    {
        xpos += vel_x * deltaT;
        ypos += vel_y * deltaT;
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

    void getLeftWall()
    {
        return leftWall;
    }

    void getRightWall()
    {
        return leftWall;
    }

    void getFloor()
    {
        return floor;
    }

    void getCeiling()
    {
        return ceiling;
    }

};


/*
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
    void resolveWallCollision(Particle p, int wallValue, std::string side)
    {
        switch(side) 
            {
            case "TOP" :
                cout << "Top wall collision!" << endl; 
                p.setVel_y(p.getVel_y * -1.0);
                break;
            case "BOTTOM" :
                cout << "Bottom wall collision!" << endl;
                p.setVel_y(p.getVel_y * -1.0);
                break;
            case "LEFT" :
                cout << "Left wall collision!" << endl;
                p.setVel_x(p.getVel_x * -1.0);
                break;
            case "RIGHT" :
                cout << "Right wall collision!" << endl;
                p.setVel_x(p.getVel_x * -1.0);
                break;

            //bad value
            default :
                cout << "Something Broke" << endl;
            }

        p1.updateAng()


};

*/

//Should break these down into horizontal and vertical walls
void resolveWallCollision(Particle p, std::string side)
{
    switch(side) 
        {
        case "TOP" :
            cout << "Top wall collision!" << endl; 
            p.setVel_y(p.getVel_y * -1.0);
            break;
        case "BOTTOM" :
            cout << "Bottom wall collision!" << endl;
            p.setVel_y(p.getVel_y * -1.0);
            break;
        case "LEFT" :
            cout << "Left wall collision!" << endl;
            p.setVel_x(p.getVel_x * -1.0);
            break;
        case "RIGHT" :
            cout << "Right wall collision!" << endl;
            p.setVel_x(p.getVel_x * -1.0);
            break;

        //bad value
        default :
            cout << "Something Broke" << endl;
        }

    p.updateAng()

bool checkWallcollision(Box box, Particle p)
{
    if (p.getXpos() - p.getRadius()) <= p.getLeftWall()
    {
        resolveWallCollision(p,"LEFT")
    } 
}

void runSim(Box box, Particle p, double simT, double deltaT)
{
    double elapsed_time = 0;

    std::ofstream results;
    restults.open ("results/results.csv");
    results << p.getXpos() << p.getYpos() << elapsed_time();

    while (elapsed_time <= simT)
    {
        elapsed_time += deltaT;
        p.updatePos(deltaT);

        
        results << p.getXpos() << p.getYpos() << elapsed_time();

    }
    results << p.getXpos() << p.getYpos() << elapsed_time();
    results.close();
}

int main()
{
    Box box = Box(30);
    Particle p = Particle(double radius=2.0, double mass=0.0, double xpos=3.0, double ypos=3.0, double vel=5.0, double ang_v=M_PI/6.0)
    double simT = 10.0;
    double deltaT = 0.1;

    runSim(box,p,simT,deltaT);

    return 0;

}