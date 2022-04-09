#ifndef VECTOR_OPS_HPP
#define VECTOR_OPS_HPP
#include <vector>


namespace vector_ops
{


std::vector<double> getNormalVector(Particle p1, Particle p2);


/**
 * @brief Get dot product between two vectors. Vectors should be same length
 * 
 * @param v1        vector1 same length as vector2
 * @param v2        vector2 same length as vector1
 * @return double   Result of the dot product operation
 */
double dotProd(std::vector<double> v1, std::vector<double> v2);


/**
 * @brief Get unit vector of a vector
 * 
 * @param v1                     vector1
 * @return std::vector<double>   New vector object representing unit vector
 */
std::vector<double> unitVec(std::vector<double> v1);


}

#endif