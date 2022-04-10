#include <map>
#include <cmath>
#include <string>
#include <iostream>
#include "box.hpp"
#include "particle.hpp"
#include "vector_ops.hpp"

using namespace std;


//Should break these down into horizontal and vertical walls
void resolveWallCollision(Particle &p, string side)
{

    map<string,int> mapping {
        {"TOP",0},
        {"BOTTOM",1},
        {"LEFT",2},
        {"RIGHT",3}
    };

    int sideInt = mapping[side];

    switch(sideInt) 
        {
        case 0 :
            cout << "Top wall collision!" << endl; 
            p.setVel_y(p.getVel_y() * -1.0);
            break;
        case 1 :
            cout << "Bottom wall collision!" << endl;
            p.setVel_y(p.getVel_y() * -1.0);
            break;
        case 2 :
            cout << "Left wall collision!" << endl;
            p.setVel_x(p.getVel_x() * -1.0);
            break;
        case 3 :
            cout << "Right wall collision!" << endl;
            p.setVel_x(p.getVel_x() * -1.0);
            break;

        //bad value - add exception here?
        default :
            cout << "Something Broke" << endl;
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
    vector<double> un, ut;             //unit normal and tangential
    double v1n_mag, v1t_mag, v2n_mag, v2t_mag;         //normal and tangential vel magnitudes (speed)
    double new_v1n_mag, new_v1t_mag, new_v2n_mag, new_v2t_mag;
    vector<double> new_v1n, new_v1t, new_v2n, new_v2t;

    un = vector_ops::getVector(p1,p2);
    ut = { -un[1], un[0] };

    v1n_mag = vector_ops::dotProd(un,p1.getVel_vec());
    v1t_mag = vector_ops::dotProd(ut,p1.getVel_vec());
    v2n_mag = vector_ops::dotProd(un,p2.getVel_vec());
    v2t_mag = vector_ops::dotProd(ut,p2.getVel_vec());

    new_v1t_mag = v1t_mag;
    new_v2t_mag = v2t_mag;

    new_v1n_mag = ( v1n_mag * (p1.getMass() - p2.getMass()) + 2*p2.getMass()*v2n_mag ) / (p1.getMass() + p2.getMass());
    new_v2n_mag = ( v2n_mag * (p2.getMass() - p1.getMass()) + 2*p1.getMass()*v1n_mag ) / (p1.getMass() + p2.getMass());

    new_v1n = { new_v1n_mag*un[0], new_v1n_mag*un[1] };
    new_v1t = { new_v1t_mag*ut[0], new_v1t_mag*ut[1] };
    new_v2n = { new_v2n_mag*un[0], new_v2n_mag*un[1] };
    new_v2t = { new_v2t_mag*ut[0], new_v2n_mag*ut[1] };

    p1.setVel_x( new_v1n[0] + new_v1t[0] );
    p1.setVel_y( new_v1n[1] + new_v1t[1] );
    p2.setVel_x( new_v2n[0] + new_v2t[0] );
    p2.setVel_y( new_v2n[1] + new_v2t[1] );

}


//check if distance between particles is <= sum of radii
void checkParticleCollision2D(Particle &p1, Particle &p2)
{
    double dist, radii, radicand_x, radicand_y;

    radicand_x = (p1.getXpos() - p2.getXpos()) * (p1.getXpos() - p2.getXpos());
    radicand_y = (p1.getYpos() - p2.getYpos()) * (p1.getYpos() - p2.getYpos());

    radii = p1.getRadius() + p2.getRadius();
    dist = sqrt(radicand_x + radicand_y);

    if (dist <= radii)
    {
        cout << "Particle Collision!" << endl;
        particleCollision2D(p1,p2);
    }

}