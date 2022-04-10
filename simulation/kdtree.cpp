#include <vector>
#include "particle.hpp"

using namespace std;






//Templatize val
struct Node
{
public:
    Particle val;
    Node *left;
    Node *right;
    Node *back;

    Node(Particle p)
    : val(p)
    , left(nullptr)
    , right(nullptr)
    , back(nullptr)
    {}

    Node(Particle p, Node *left)
    : val(p)
    , left(left)
    , right(nullptr)
    , back(nullptr)
    {}

    Node(Particle p, Node *left, Node *right)
    : val(p)
    , left(left)
    , right(right)
    , back(nullptr)
    {}

    Node(Particle p, Node *left, Node *right, Node *back)
    : val(p)
    , left(left)
    , right(right)
    , back(back)
    {}


    bool isRoot()
    {

    }


    bool isLeaf()
    {

    }


};


//Templatize input container
//Add sort algorithm
class KDTree
{
private:
    vector<double> points;

public:

    KDTree(vector<double> points)
    : points(points)
    {}






};