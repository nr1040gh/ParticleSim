#include <vector>
#include "particle.hpp"

using namespace std;






//Templatize val
struct Node
{
public:
    vector<Particle> val;
    Node *left;
    Node *right;
    Node *back;

    Node(vector<Particle> p)
    : val(p)
    , left(nullptr)
    , right(nullptr)
    , back(nullptr)
    {}

    Node(vector<Particle> p, Node *left)
    : val(p)
    , left(left)
    , right(nullptr)
    , back(nullptr)
    {}

    Node(vector<Particle> p, Node *left, Node *right)
    : val(p)
    , left(left)
    , right(right)
    , back(nullptr)
    {}

    Node(vector<Particle> p, Node *left, Node *right, Node *back)
    : val(p)
    , left(left)
    , right(right)
    , back(back)
    {}


    bool isRoot()
    {
        return 0;
    }


    bool isLeaf()
    {
        return 0;
    }


};


//Templatize input container
//Add sort algorithm
//k-d tree space partition, as tree is being built, 
//  return possible collision pairs (leafs where vector size > 1)
// pre-sort points vector
//eventually return start and end index instead of storing vectors as value
//  saves memory
class KDTree_SP
{
private:
    vector<Particle> points;
    vector < vector<Particle> > possible_collisions;
    vector<Particle> x_sorted; //when we switch to storing start and end indexes
    vector<Particle> y_sorted; //when we switch to storing start and end indexes

public:

    KDTree_SP(vector<Particle> points)
    : points(points)
    {
        Node* root = new Node(points);

        build(root);
    }


    vector< vector<double> > build(Node* n)
    {
        vector< vector<double> > val;


        return val;
    }






};





// It divides the input array into two halves, 
//calls itself for the two halves, 
//and then merges the two sorted halves. 
//The merge() function is used for merging two halves. 
//The merge(arr, l, m, r) is a key process that assumes that arr[l..m] and arr[m+1..r] 
//are sorted and merges the two sorted sub-arrays into one
//https://www.geeksforgeeks.org/merge-sort/
//https://en.wikipedia.org/wiki/Merge_sort
//raise error if axis is not 0 or 1
vector<Particle> mergeSort(vector<Particle> p, int axis)
{
    vector<Particle> left;
    vector<Particle> right;

    int size = p.size();
    int mid_index = size/2;

    if (size <= 1)
        return p;

    for(int i=0; i < size; i++)
    {
        if (i <= mid_index)
        {
            left.push_back(p[i]);
        }
        else
        {
            right.push_back(p[i]);
        }
    }

    left = mergeSort(left, axis);
    right = mergeSort(right, axis);

    return merge(left,right,axis);

}


vector<Particle> merge(vector<Particle> left, vector<Particle> right, int axis)
{
    vector<Particle> result;

    double left_value, right_value;

    while (left.size() > 0 && right.size() > 0)
    {
        if (axis == 0)
        {   
            left_value = left[0].getXpos();
            right_value = right[0].getXpos();
        }
        else
        {
            left_value = left[0].getYpos();
            right_value = right[0].getYpos();
        }
        
        if (left_value <= right_value)
        {
            result.push_back(left[0]);
            left.erase(left.begin());
        }
        else
        {
            result.push_back(right[0]);
            right.erase(right.begin());
        }

    }


}






/*
class MergeSort
{
private:
    void merge()
    {

    }



public:
    MergeSort(vector<Particle> particles);
};
*/