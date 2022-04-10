#include "box.hpp"


Box::Box(int size)
{
    height = size;
    width = size;
    rightWall = size;
    ceiling = size;

}


int Box::getLeftWall() const
{
    return leftWall;
}

int Box::getRightWall() const
{
    return rightWall;
}

int Box::getFloor() const
{
    return floor;
}

int Box::getCeiling() const
{
    return ceiling;
}
