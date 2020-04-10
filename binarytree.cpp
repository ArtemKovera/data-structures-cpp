//binary search tree data structure with C++
#include<iostream>
#include<vector>

class BinaryTree
{
public:
    //parameterless constructor makes a tree with one node whose data member equals 0
    BinaryTree ();
    
    //this constructor makes a tree with one node whose data member equals the value of the parameter
    explicit BinaryTree (int);

    //this constructor makes a tree where the number of nodes equals the number of unique elements from the int vector passed as a parameter
    //data members of the nodes created are the values of the vector elements
    BinaryTree(const std::vector<int>&);

    //method to find an element in a tree, returns true if the element is found
    bool find (int) const;

    //this version of insert method inserts just one element into the tree
    void insert (int);

    //this version of insert method inserts an entire int vector element by element into the tree 
    void insert (const std::vector<int>&);

    //this methods copys all the elements of the tree into a vector
    void copyElementsToArray (std::vector<int>&);

    int getNodeCount () const;

   
    

private:
    //structure for Node
    struct Node;
    
    //pointer pointed to the root node
    Node* root = nullptr;

    int hight = 0;
    int nodeCount = 0;

    //method for allocating a memory unit for one node, returns pointer to this memory unit
    Node* allocateMemoryUnit ();

    //auxiliary recursive function for node insertion
    void nodeInsert (Node*, int);

    //auxiliary recursive function for element finding
    bool findElement (Node*, int) const;
    
};

int main ()
{
    BinaryTree myFirstTree (10);

    myFirstTree.insert(5);

    myFirstTree.insert(30);

    myFirstTree.insert(2);

    myFirstTree.insert(40);
    
    
    //
    if (myFirstTree.find(10))
    {
        std::cout << "10 is there " << std::endl;
    }
    else
    {
        std::cout << "10 is NOT there " << std::endl;
    }
    
    //
    if (myFirstTree.find(5))
    {
        std::cout << "5 is there " << std::endl;
    }
    else
    {
        std::cout << "5 is NOT there " << std::endl;
    }
    
    
    //
    if (myFirstTree.find(30))
    {
        std::cout << "30 is there " << std::endl;
    }
    else
    {
        std::cout << "30 is NOT there " << std::endl;
    }

    if (myFirstTree.find(2))
    {
        std::cout << "2 is there " << std::endl;
    }
    else
    {
        std::cout << "2 is NOT there " << std::endl;
    }    
  
    
    //
    if (myFirstTree.find(0))
    {
        std::cout << "0 is there " << std::endl;
    }
    else
    {
        std::cout << "0 is NOT there " << std::endl;
    }
    

    if (myFirstTree.find(40))
    {
        std::cout << "40 is there " << std::endl;
    }
    else
    {
        std::cout << "40 is NOT there " << std::endl;
    }
    
    myFirstTree.insert(30);
    myFirstTree.insert(40);
    myFirstTree.insert(10);
    myFirstTree.insert(5);
    
    std::cout << "node count is " << myFirstTree.getNodeCount() << std::endl;

    
    return 0;
}

struct BinaryTree::Node 
{
    int data;
    Node* leftLink = nullptr;        
    Node* rightLink = nullptr;     
};

BinaryTree::Node* BinaryTree::allocateMemoryUnit ()
{
    Node* pointer = new BinaryTree::Node; 
    return pointer; 
}

int BinaryTree::getNodeCount () const
{
    return nodeCount;
}

BinaryTree::BinaryTree ()
{
    root = allocateMemoryUnit();
    root->data = 0;
    nodeCount++;
}

BinaryTree::BinaryTree (int value)
{
    root = allocateMemoryUnit();
    root->data = value;
    nodeCount++;
}

void BinaryTree::insert (int value)
{
    nodeInsert(root, value);
    return;
}

void BinaryTree::nodeInsert (Node* temp, int value)
{
    if (temp->data == value) 
    {
        return;
    }

    if (temp->data < value)
    {
        Node *temp2 = temp->rightLink;
        if (temp2 == nullptr)
        {
            temp2 = allocateMemoryUnit();
            temp2->data = value;
            temp->rightLink = temp2;
            nodeCount++;
            return;
        }
        temp = temp2;
        nodeInsert(temp, value);
    }
    else if (temp->data > value)
    {
        Node* temp2 = temp->leftLink;
        if(temp2 == nullptr)
        {
            temp2 = allocateMemoryUnit();
            temp2->data = value;
            temp->leftLink = temp2;
            nodeCount++;
            return;
        }
        temp = temp2;
        nodeInsert(temp, value);
    }

}

bool BinaryTree::find (int value) const
{
    return findElement(root, value);
}

bool BinaryTree::findElement(Node* temp, int value) const
{
    if(temp->data == value) return true;

    if(temp->data < value)
    {
        temp = temp->rightLink;
        if (temp == nullptr) return false;
        findElement(temp, value);
    }
    else if(temp->data > value)
    {
        temp = temp->leftLink;
        if (temp == nullptr) return false;
        findElement(temp, value);        
    }
}