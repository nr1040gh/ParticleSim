#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <map>
#include "box.hpp"
#include "particle.hpp"
#include "event_handler.hpp"


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