#include <vector>
#include <cmath>
#include "particle.hpp"

using namespace std;


Particle::Particle(double radius, double mass, double xpos, double ypos, double vel, double ang_v)
    : xpos(xpos)
    , ypos(ypos)
    , vel(vel)
    , mass(mass)
    , radius(radius)
    , ang_v(ang_v)
    , vel_x(vel * cos(ang_v))
    , vel_y(vel * sin(ang_v))
    , vel_vec{vel_x,vel_y}
    {}


void Particle::updateAng()
{
    //Get velocity angle based on velocity coordinate space
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


void Particle::updatePos(double deltaT)
{
    xpos += vel_x * deltaT;
    ypos += vel_y * deltaT;
}


void Particle::setXpos(double newPos)
{
    xpos = newPos;
}
void Particle::setYpos(double newPos)
{
    ypos = newPos;
}
void Particle::setVel(double newVel)
{
    vel = newVel;
    vel_x = (vel * cos(ang_v));
    vel_y = (vel * sin(ang_v));
}
void Particle::setVel_x(double newVel_x)
{
    vel_x = newVel_x;
    vel = sqrt( (vel_x*vel_x) + (vel_y*vel_y));
    vel_vec = {vel_x,vel_y};
    updateAng();
}
void Particle::setVel_y(double newVel_y)
{
    vel_y = newVel_y;
    vel = sqrt( (vel_x*vel_x) + (vel_y*vel_y));
    vel_vec = {vel_x,vel_y};
    updateAng();
}
void Particle::setAng(double newAng)
{
    ang_v = newAng;
    vel_x = (vel * cos(ang_v));
    vel_y = (vel * sin(ang_v));
    vel = sqrt( (vel_x*vel_x) + (vel_y*vel_y));
    vel_vec = {vel_x,vel_y};
}


double Particle::getXpos() const
{
    return xpos;
}
double Particle::getYpos() const
{
    return ypos;
}
double Particle::getVel() const
{
    return vel;
}
double Particle::getVel_x() const
{
    return vel_x;
}
double Particle::getVel_y() const
{
    return vel_y;
}
vector<double> Particle::getVel_vec() const
{
    return vel_vec;
}
double Particle::getAng() const
{
    return ang_v;
}
double Particle::getMass() const
{
    return mass;
}
double Particle::getRadius() const
{
    return radius;
}
