//binary tree data structure with C++
#include<iostream>

class BinaryTree
{
public:
    //parameterless constructor makes one node whose data member equals 0
    BinaryTree ();
    
    explicit BinaryTree (float);
    

private:
    //structure for Node
    struct Node;
    
    Node* root = nullptr;
    int hight = 0;
    int nodeCount = 0;

    Node* allocateMemoryUnit ();
    
};

int main ()
{

    return 0;
}

struct BinaryTree::Node 
{
    float data;
    Node* leftLink;        
    Node* rightLink;     
};

BinaryTree::Node* BinaryTree::allocateMemoryUnit ()
{
    Node* pointer = new BinaryTree::Node; 
    return pointer; 
}

BinaryTree::BinaryTree ()
{
    root = allocateMemoryUnit();
    root->data = 0;
}

BinaryTree::BinaryTree (float value)
{
    root = allocateMemoryUnit();
    root->data = value;
}