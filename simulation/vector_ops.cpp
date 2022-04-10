#include <vector>
#include <cmath>
#include "particle.hpp"
#include "vector_ops.hpp"

using namespace std;


namespace vector_ops{

//https://www.vobarian.com/collisions/2dcollisions2.pdf
vector<double> getVector(Particle p1, Particle p2)
{
    //x component and y component
    double xcomp, ycomp;
    xcomp = p2.getXpos() - p1.getXpos();
    ycomp = p2.getYpos() - p1.getYpos();

    vector<double> v{ xcomp, ycomp };

    return v;
}


vector<double> unitVec(vector<double> v1)
//Get magnitude of vector then divide contents of vector by magnitude
{
    
    vector<double> unitVec;
    double sqrt_inner = 0, magnitude = 0;
    for (int i=0; i < v1.size(); i++)
    {
        sqrt_inner += v1[i] * v1[i];
        unitVec.push_back(v1[i]);
    }
    
    magnitude = sqrt(sqrt_inner);
    for (int i=0; i < unitVec.size(); i++)
    {
        unitVec[i] = unitVec[i] / magnitude;
    }
    
    return unitVec;
}


double dotProd(vector<double> v1, vector<double> v2)
{
    //So far assumes v1 is same dimensions as v2

    double result = 0;
    for (int i=0; i < v1.size(); i++)
    {
        result += v1[i] * v2[i];
    }
    
    return result;
}


}