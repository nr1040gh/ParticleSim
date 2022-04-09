#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <map>


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

public:
    Particle(double radius, double mass, double xpos=0.0, double ypos=0.0, double vel=0.0, double ang_v=0.0):
    xpos(xpos),
    ypos(ypos),
    vel(vel),
    mass(mass),
    radius(radius),
    ang_v(ang_v),
    vel_x(vel * cos(ang_v)),
    vel_y(vel * sin(ang_v))
    {}

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
            ang_v = atan(vel_y / vel_x);
        else if (vel_x <= 0 and vel_y > 0)
            ang_v = atan(vel_x / vel_y) + M_PI_2; // pi/2 in cmath
        else if (vel_x < 0 and vel_y <=0)
            ang_v = atan(vel_y / vel_x) + M_PI;
        else if (vel_x >= 0 and vel_y < 0)
            ang_v = atan(vel_x / vel_y) + (3.0 * M_PI_2); // 3pi/2
        else
            ang_v = 0; // if vel_x and vel_y == 0
    }

    void updatePos(double deltaT)
    {
        xpos += vel_x * deltaT;
        ypos += vel_y * deltaT;
    }

    double getXpos() const
    {
        return xpos;
    }

    double getYpos() const
    {
        return ypos;
    }

    double getVel() const
    {
        return vel;
    }

    double getVel_x() const
    {
        return vel_x;
    }

    double getVel_y() const
    {
        return vel_y;
    }

    double getAng() const
    {
        return ang_v;
    }

    double getMass() const
    {
        return mass;
    }

    double getRadius() const
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

    int getLeftWall()
    {
        return leftWall;
    }

    int getRightWall()
    {
        return rightWall;
    }

    int getFloor()
    {
        return floor;
    }

    int getCeiling()
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
void resolveWallCollision(Particle &p, std::string side)
{

    std::map<std::string,int> mapping {
        {"TOP",0},
        {"BOTTOM",1},
        {"LEFT",2},
        {"RIGHT",3}
    };

    int sideInt = mapping[side];

    switch(sideInt) 
        {
        case 0 :
            std::cout << "Top wall collision!" << std::endl; 
            p.setVel_y(p.getVel_y() * -1.0);
            break;
        case 1 :
            std::cout << "Bottom wall collision!" << std::endl;
            p.setVel_y(p.getVel_y() * -1.0);
            break;
        case 2 :
            std::cout << "Left wall collision!" << std::endl;
            p.setVel_x(p.getVel_x() * -1.0);
            break;
        case 3 :
            std::cout << "Right wall collision!" << std::endl;
            p.setVel_x(p.getVel_x() * -1.0);
            break;

        //bad value
        default :
            std::cout << "Something Broke" << std::endl;
        }

    p.updateAng();
}

void checkWallcollision(Box &box, Particle &p)
{
    //Left wall
    if ((p.getXpos() - p.getRadius()) <= box.getLeftWall())
    {
        resolveWallCollision(p,"LEFT");
    } 

    //Right wall
    else if ((p.getXpos() + p.getRadius()) >= box.getRightWall())
    {
        resolveWallCollision(p,"RIGHT");
    }

    //Top
    else if ((p.getYpos() + p.getRadius()) >= box.getCeiling())
    {
        resolveWallCollision(p,"TOP");
    }

    //Bottom
    else if ((p.getYpos() - p.getRadius()) <= box.getFloor())
    {
        resolveWallCollision(p,"BOTTOM");
    }

}


//https://www.vobarian.com/collisions/2dcollisions2.pdf
void particleCollision2D(Particle &p1, Particle &p2)
{

}



void runSim(Box &box, Particle &p, double simT, double deltaT, double fps)
{
    double elapsed_time = 0;

    std::ofstream results;
    results.open("../results/results.csv");
    results << box.getLeftWall() << "," << box.getRightWall() << "," << box.getCeiling() << "," << box.getFloor() << "," << fps << "\n"; 
    results << p.getXpos() << "," << p.getYpos() << "," << p.getRadius() << "\n";

    while (elapsed_time <= simT)
    {
        elapsed_time += deltaT;
        checkWallcollision(box,p); 
        p.updatePos(deltaT);
        
        
        results << p.getXpos() << "," << p.getYpos() << "," << p.getRadius() << "\n";

    }
    results << p.getXpos() << "," << p.getYpos() << "," << p.getRadius() << "\n";
    results.close();
}

int main()
{
    Box box(30);
    Particle p(0.5, 0.0, 3.0, 3.0, 9.0, (5.0*M_PI/4.02));
    double simT = 15.0;
    double fps = 60;
    double deltaT = 1 / fps;
    std::cout << deltaT << std::endl;

    runSim(box,p,simT,deltaT,fps);

    return 0;

}