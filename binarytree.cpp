//binary search tree data structure with C++
#include<iostream>
#include<vector>
#include<utility>

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

    BinaryTree(const BinaryTree&);

    BinaryTree(BinaryTree&&) noexcept;

    //exception-safe assignment operator
    BinaryTree& operator=(const BinaryTree&);

    BinaryTree& operator=(BinaryTree&&) noexcept;

    virtual ~BinaryTree();
    
    //method to find an element in a tree, returns true if the element is found
    bool find (int) const;

    //this version of insert method inserts just one element into the tree
    void insert (int);

    //this version of insert method inserts an entire int vector element by element into the tree 
    void insert (const std::vector<int>&);

    //this methods copies all the elements of the tree into a vector
    //this methods uses in-order travesal of the tree
    void copyElementsToVector (std::vector<int>&) const;

    int getNodeCount () const;

    int getRootElement () const;
     
    //this method copies all the elements of the tree into a vector in the order they had been iserted
    void elementstoVectorinInsertionOrder (std::vector<int>&) const;


private:
    //structure for Node
    struct Node;
    
    //pointer pointed to the root node
    Node* root = nullptr;

    int nodeCount = 0;

    std::vector<int> treeElementsOrderofInsertion;

    //method for allocating a memory unit for one node, returns pointer to this memory unit
    Node* allocateMemoryUnit ();

    //helper recursive method for node insertion
    void nodeInsert (Node*, int);

    //helper recursive method for element finding
    bool findElement (Node*, int) const;

    //helper recursive method for tree traversal
    void inOrderTravese (Node*, std::vector<int>&) const;

    //helper recursive method for freeing the memory
    void clean (Node*) noexcept;

    void copy_elements (BinaryTree&, BinaryTree&) noexcept;

    //helper method used in move constructor and move assignment operator
    void forMovingFrom (BinaryTree&) noexcept;
    
};

int main ()
{
    BinaryTree myFirstTree (10);
    myFirstTree.insert(5);
    myFirstTree.insert(30);
    myFirstTree.insert(2);
    myFirstTree.insert(40);
    
    //
    if (myFirstTree.find(10))  std::cout << "10 is there " << std::endl;
    else std::cout << "10 is NOT there " << std::endl;

    //
    if (myFirstTree.find(5)) std::cout << "5 is there " << std::endl;
    else  std::cout << "5 is NOT there " << std::endl;

    //
    if (myFirstTree.find(30)) std::cout << "30 is there " << std::endl;
    else std::cout << "30 is NOT there " << std::endl;

    //
    if (myFirstTree.find(2)) std::cout << "2 is there " << std::endl;
    else std::cout << "2 is NOT there " << std::endl; 
        
    //
    if (myFirstTree.find(0)) std::cout << "0 is there " << std::endl;
    else std::cout << "0 is NOT there " << std::endl;    
    
    //
    if (myFirstTree.find(40)) std::cout << "40 is there " << std::endl;
    else std::cout << "40 is NOT there " << std::endl;
 
    myFirstTree.insert(30);
    myFirstTree.insert(40);
    myFirstTree.insert(10);
    myFirstTree.insert(5);

    std::vector<int> vec1 {1, 3, 22, 11, 4, 7, 18};
    myFirstTree.insert(vec1);

    //
    if (myFirstTree.find(11)) std::cout << "11 is there " << std::endl;
    else std::cout << "11 is NOT there " << std::endl;

    //
    if (myFirstTree.find(7)) std::cout << "7 is there " << std::endl;
    else std::cout << "7 is NOT there " << std::endl;   
       
    //
    if (myFirstTree.find(8)) std::cout << "8 is there " << std::endl;
    else std::cout << "8 is NOT there " << std::endl;

    //
    std::cout << "node count of myFirstTree is " << myFirstTree.getNodeCount() << std::endl;

    std::vector<int> vec2 {5, 3, -7, 32, 1, 0, 45, -4, 11};

    BinaryTree mySecondTree(vec2);

    //
    if (mySecondTree.find(8)) std::cout << "8 is in mySecondTree" << std::endl;
    else std::cout << "8 is NOT in mySecondTree" << std::endl;

    //
    if (mySecondTree.find(5)) std::cout << "5 is in mySecondTree" << std::endl;
    else std::cout << "5 is NOT in mySecondTree" << std::endl;

    //
    if (mySecondTree.find(-7)) std::cout << "-7 is in mySecondTree" << std::endl;
    else std::cout << "-7 is NOT in mySecondTree" << std::endl;  

    mySecondTree.insert(14);

    //
    if (mySecondTree.find(14)) std::cout << "14 is in mySecondTree" << std::endl;
    else std::cout << "14 is NOT in mySecondTree" << std::endl; 

    //
    if (mySecondTree.find(13)) std::cout << "13 is in mySecondTree" << std::endl;
    else std::cout << "13 is NOT in mySecondTree" << std::endl;  

    //
    std::cout << "node count of mySecondTree is " << mySecondTree.getNodeCount() << std::endl; 
  
    std::vector<int> vec3;

    mySecondTree.copyElementsToVector(vec3);

    std::cout << "Elements of mySecondTree sorted: ";
    for (auto el : vec3)
       std::cout << el << " ";  
    std::cout << std::endl;

    BinaryTree myThirdTree(mySecondTree);

    std::vector<int> vec4;
    myThirdTree.copyElementsToVector(vec4);

    std::cout << "Elements of myThirdTree sorted:  ";
    for (auto el : vec4)
       std::cout << el << " ";  
    std::cout << std::endl; 
    std::cout << "node count of myThirdTree is " << myThirdTree.getNodeCount() << std::endl; 
    
    std::vector<int> vec5;
    myThirdTree.elementstoVectorinInsertionOrder(vec5);
    std::cout << "Elements of myThirdTree in the order they were  inserted:  ";
    for (auto el : vec5)
       std::cout << el << " ";  
    std::cout << std::endl; 

    std::vector<int> vec6;
    mySecondTree.elementstoVectorinInsertionOrder(vec6);
    std::cout << "Elements of mySecondTree in the order they were inserted:  ";
    for (auto el : vec6)
       std::cout << el << " ";  
    std::cout << std::endl; 

    std::vector<int> vec7 {100, 200, 99, 300};

    BinaryTree myFourthTree (vec7);

    myFourthTree = myThirdTree;

    std::vector<int> vec8;
    myFourthTree.elementstoVectorinInsertionOrder(vec8);
    std::cout << "Elements of myFourthTree in the order they were inserted:  ";
    for (auto el : vec8)
       std::cout << el << " ";  
    std::cout << std::endl; 

    std::vector<int> vec9;
    myFourthTree.copyElementsToVector(vec9);
    std::cout << "Elements of myFourthTree sorted:                           ";
    for (auto el : vec9)
       std::cout << el << " ";  
    std::cout << std::endl; 

    BinaryTree myFifthTree (std::move(myFourthTree));
    std::vector<int> vec10;
    myFifthTree.copyElementsToVector(vec10);
    std::cout << "Elements of myFifthTree  sorted:                           ";
    for (auto el : vec10)
       std::cout << el << " ";  
    std::cout << std::endl;     

    std::vector<int> vec11;
    myFifthTree.elementstoVectorinInsertionOrder(vec11);
    std::cout << "Elements of myFifthTree in the order they were inserted:   ";
    for (auto el : vec11)
       std::cout << el << " ";  
    std::cout << std::endl; 

    BinaryTree mySixthTree (1000);
    mySixthTree = std::move(myFifthTree);

    std::vector<int> vec12;
    mySixthTree.elementstoVectorinInsertionOrder(vec12);
    std::cout << "Elements of mySixthTree in the order they were inserted:   ";
    for (auto el : vec12)
       std::cout << el << " ";  
    std::cout << std::endl;

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
    treeElementsOrderofInsertion.push_back(0);
}

BinaryTree::BinaryTree (int value)
{
    root = allocateMemoryUnit();
    root->data = value;
    nodeCount++;
    treeElementsOrderofInsertion.push_back(value);
}

BinaryTree::BinaryTree (const std::vector<int>& vec)
{
    if (vec.empty())
    {
        root = allocateMemoryUnit();
        root->data = 0;
        nodeCount++;
        treeElementsOrderofInsertion.push_back(0);
        return;        
    }

    root = allocateMemoryUnit();
    root->data = vec[0];
    nodeCount++;
    treeElementsOrderofInsertion.push_back(vec[0]); 

    for (int i = 1; i < vec.size(); i++) insert(vec[i]);  
}

BinaryTree::BinaryTree (const BinaryTree& src)
{
    std::vector<int> vect;
    vect.reserve(src.nodeCount);
    src.elementstoVectorinInsertionOrder(vect);
    root = allocateMemoryUnit();
    root->data = src.getRootElement();
    nodeCount++;
    treeElementsOrderofInsertion.push_back(root->data);
    insert(vect);
}

BinaryTree::BinaryTree(BinaryTree&& src) noexcept
{
    forMovingFrom(src);
}

BinaryTree::~BinaryTree()
{
    clean(root);
}

BinaryTree& BinaryTree::operator= (const BinaryTree& src)
{
    if (this == &src) return *this;

    clean(this->root);
    
    BinaryTree temp (src);
    copy_elements (*this, temp);
    return *this;
}

BinaryTree& BinaryTree::operator= (BinaryTree&& src) noexcept
{
    if (this == &src) return *this;

    clean(root);

    forMovingFrom(src);

    return *this;    
}

void BinaryTree::insert (int value)
{
    nodeInsert(root, value);
    return;
}

void BinaryTree::insert (const std::vector<int>& vec)
{
    for (auto el : vec) nodeInsert(root, el);

    return;
}

void BinaryTree::nodeInsert (Node* temp, int value)
{
    if (temp->data == value) return;

    if (temp->data < value)
    {
        Node *temp2 = temp->rightLink;
        if (temp2 == nullptr)
        {
            temp2 = allocateMemoryUnit();
            temp2->data = value;
            temp->rightLink = temp2;
            nodeCount++;
            treeElementsOrderofInsertion.push_back(value);
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
            treeElementsOrderofInsertion.push_back(value);
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

void BinaryTree::copyElementsToVector (std::vector<int>& vec) const
{
    inOrderTravese(root, vec);
}

void BinaryTree::inOrderTravese(BinaryTree::Node* node, std::vector<int>& vec) const
{
    if(node)
    {
        if(node->leftLink) inOrderTravese(node->leftLink, vec);
        
        vec.push_back(node->data);

        if(node->rightLink) inOrderTravese(node->rightLink, vec);
    }
    else 
        return;
}

void BinaryTree::clean(BinaryTree::Node* node) noexcept
{
    if(node)
    {
        if(node->leftLink) clean(node->leftLink);
        
        if(node->rightLink) clean(node->rightLink);
    
        delete node;
        node = nullptr;      
    }
}

int BinaryTree::getRootElement () const
{
    return root->data;
}

void BinaryTree::elementstoVectorinInsertionOrder (std::vector<int>& vec) const
{
    vec = treeElementsOrderofInsertion;
    return;
}

void BinaryTree::copy_elements (BinaryTree& first, BinaryTree& second) noexcept
{
    first.root = allocateMemoryUnit();
    first.treeElementsOrderofInsertion.clear();
    first.root->data = second.root->data;
    first.treeElementsOrderofInsertion.push_back(first.root->data);
    for (int i = 1; i<second.treeElementsOrderofInsertion.size(); i++)
    {
        first.insert(second.treeElementsOrderofInsertion[i]);
    }
    return;
}

void BinaryTree::forMovingFrom (BinaryTree& src) noexcept
{
    root = src.root;
    nodeCount = src.nodeCount;
    treeElementsOrderofInsertion = src.treeElementsOrderofInsertion;

    src.root = nullptr;
    src.treeElementsOrderofInsertion.clear();
    src.nodeCount = 0;    
}