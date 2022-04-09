#ifndef PARTICLE_HPP
#define PARTICLE_HPP
#include <vector>


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
    std::vector<double> vel_vec;


public:
    Particle(double radius, double mass, double xpos=0.0, double ypos=0.0, double vel=0.0, double ang_v=0.0);


    void updateAng();


    void updatePos(double deltaT);


    void setXpos(double newPos);
    void setYpos(double newPos);
    void setVel(double newVel);
    void setVel_x(double newVel_x);
    void setVel_y(double newVel_y);
    void setAng(double newAng);

    double getXpos() const;
    double getYpos() const;
    double getVel() const;
    double getVel_x() const;
    double getVel_y() const;
    std::vector<double> getVel_vec() const;
    double getAng() const;
    double getMass() const;
    double getRadius() const;

};

#endif