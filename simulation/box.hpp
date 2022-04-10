#ifndef BOX_HPP
#define BOX_HPP

class Box
{

private:
    int height;
    int width;
    int leftWall=0, rightWall, floor=0, ceiling;


public:

    Box(int size);


    int getLeftWall() const;
    int getRightWall() const;
    int getFloor() const;
    int getCeiling() const;

};


#endif