#ifndef EVENT_HANDLER_HPP
#define EVENT_HANDLER_HPP
#include <string>
#include "box.hpp"
#include "particle.hpp"


//Should break these down into horizontal and vertical walls
void resolveWallCollision(Particle &p, std::string side);



void checkWallcollision(Box &box, Particle &p);


//https://www.vobarian.com/collisions/2dcollisions2.pdf
void particleCollision2D(Particle &p1, Particle &p2);


void checkParticleCollision2D(Particle &p1, Particle &p2);


#endif